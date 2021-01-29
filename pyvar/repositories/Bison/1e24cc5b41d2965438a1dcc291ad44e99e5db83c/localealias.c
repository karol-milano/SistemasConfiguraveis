@@ -1,6 +1,5 @@
 /* Handle aliases for locale names.
-   Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
-   Written by Ulrich Drepper <drepper@gnu.ai.mit.edu>, 1995.
+   Copyright (C) 1995-1999, 2000, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -16,6 +15,13 @@
    along with this program; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
+/* Tell glibc's <string.h> to provide a prototype for mempcpy().
+   This must come before <config.h> because <config.h> may include
+   <features.h>, and once <features.h> has been included, it's too late.  */
+#ifndef _GNU_SOURCE
+# define _GNU_SOURCE    1
+#endif
+
 #ifdef HAVE_CONFIG_H
 # include <config.h>
 #endif
@@ -41,35 +47,15 @@ char *alloca ();
 # endif
 #endif
 
-#if defined STDC_HEADERS || defined _LIBC
-# include <stdlib.h>
-#else
-char *getenv ();
-# ifdef HAVE_MALLOC_H
-#  include <malloc.h>
-# else
-void free ();
-# endif
-#endif
+#include <stdlib.h>
 
-#if defined HAVE_STRING_H || defined _LIBC
-# ifndef _GNU_SOURCE
-#  define _GNU_SOURCE	1
-# endif
-# include <string.h>
-#else
-# include <strings.h>
-# ifndef memcpy
-#  define memcpy(Dst, Src, Num) (bcopy (Src, Dst, Num), Dst)
-# endif
-#endif
+#include <string.h>
 #if !HAVE_STRCHR && !defined _LIBC
 # ifndef strchr
 #  define strchr index
 # endif
 #endif
 
-#include "gettext.h"
 #include "gettextP.h"
 
 /* @@ end of prolog @@ */
@@ -80,7 +66,9 @@ void free ();
    file and the name space must not be polluted.  */
 # define strcasecmp __strcasecmp
 
-# define mempcpy __mempcpy
+# ifndef mempcpy
+#  define mempcpy __mempcpy
+# endif
 # define HAVE_MEMPCPY	1
 
 /* We need locking here since we can be called from different places.  */
@@ -89,41 +77,27 @@ void free ();
 __libc_lock_define_initialized (static, lock);
 #endif
 
+#ifndef internal_function
+# define internal_function
+#endif
 
-/* For those loosing systems which don't have `alloca' we have to add
+/* For those losing systems which don't have `alloca' we have to add
    some additional code emulating it.  */
 #ifdef HAVE_ALLOCA
-/* Nothing has to be done.  */
-# define ADD_BLOCK(list, address) /* nothing */
-# define FREE_BLOCKS(list) /* nothing */
+# define freea(p) /* nothing */
 #else
-struct block_list
-{
-  void *address;
-  struct block_list *next;
-};
-# define ADD_BLOCK(list, addr)						      \
-  do {									      \
-    struct block_list *newp = (struct block_list *) malloc (sizeof (*newp));  \
-    /* If we cannot get a free block we cannot add the new element to	      \
-       the list.  */							      \
-    if (newp != NULL) {							      \
-      newp->address = (addr);						      \
-      newp->next = (list);						      \
-      (list) = newp;							      \
-    }									      \
-  } while (0)
-# define FREE_BLOCKS(list)						      \
-  do {									      \
-    while (list != NULL) {						      \
-      struct block_list *old = list;					      \
-      list = list->next;						      \
-      free (old);							      \
-    }									      \
-  } while (0)
-# undef alloca
-# define alloca(size) (malloc (size))
-#endif	/* have alloca */
+# define alloca(n) malloc (n)
+# define freea(p) free (p)
+#endif
+
+#if defined _LIBC_REENTRANT || defined HAVE_FGETS_UNLOCKED
+# undef fgets
+# define fgets(buf, len, s) fgets_unlocked (buf, len, s)
+#endif
+#if defined _LIBC_REENTRANT || defined HAVE_FEOF_UNLOCKED
+# undef feof
+# define feof(s) feof_unlocked (s)
+#endif
 
 
 struct alias_map
@@ -133,18 +107,18 @@ struct alias_map
 };
 
 
-static char *string_space = NULL;
-static size_t string_space_act = 0;
-static size_t string_space_max = 0;
+static char *string_space;
+static size_t string_space_act;
+static size_t string_space_max;
 static struct alias_map *map;
-static size_t nmap = 0;
-static size_t maxmap = 0;
+static size_t nmap;
+static size_t maxmap;
 
 
 /* Prototypes for local functions.  */
 static size_t read_alias_file PARAMS ((const char *fname, int fname_len))
      internal_function;
-static void extend_alias_table PARAMS ((void));
+static int extend_alias_table PARAMS ((void));
 static int alias_compare PARAMS ((const struct alias_map *map1,
 				  const struct alias_map *map2));
 
@@ -190,11 +164,12 @@ _nl_expand_alias (name)
 	{
 	  const char *start;
 
-	  while (locale_alias_path[0] == ':')
+	  while (locale_alias_path[0] == PATH_SEPARATOR)
 	    ++locale_alias_path;
 	  start = locale_alias_path;
 
-	  while (locale_alias_path[0] != '\0' && locale_alias_path[0] != ':')
+	  while (locale_alias_path[0] != '\0'
+		 && locale_alias_path[0] != PATH_SEPARATOR)
 	    ++locale_alias_path;
 
 	  if (start < locale_alias_path)
@@ -217,16 +192,12 @@ read_alias_file (fname, fname_len)
      const char *fname;
      int fname_len;
 {
-#ifndef HAVE_ALLOCA
-  struct block_list *block_list = NULL;
-#endif
   FILE *fp;
   char *full_fname;
   size_t added;
   static const char aliasfile[] = "/locale.alias";
 
   full_fname = (char *) alloca (fname_len + sizeof aliasfile);
-  ADD_BLOCK (block_list, full_fname);
 #ifdef HAVE_MEMPCPY
   mempcpy (mempcpy (full_fname, fname, fname_len),
 	   aliasfile, sizeof aliasfile);
@@ -236,11 +207,9 @@ read_alias_file (fname, fname_len)
 #endif
 
   fp = fopen (full_fname, "r");
+  freea (full_fname);
   if (fp == NULL)
-    {
-      FREE_BLOCKS (block_list);
-      return 0;
-    }
+    return 0;
 
   added = 0;
   while (!feof (fp))
@@ -253,7 +222,7 @@ read_alias_file (fname, fname_len)
       char buf[BUFSIZ];
       char *alias;
       char *value;
-      unsigned char *cp;
+      char *cp;
 
       if (fgets (buf, sizeof buf, fp) == NULL)
 	/* EOF reached.  */
@@ -272,7 +241,7 @@ read_alias_file (fname, fname_len)
 	  while (strchr (altbuf, '\n') == NULL);
 	}
 
-      cp = (unsigned char *) buf;
+      cp = buf;
       /* Ignore leading white space.  */
       while (isspace (cp[0]))
 	++cp;
@@ -280,7 +249,7 @@ read_alias_file (fname, fname_len)
       /* A leading '#' signals a comment line.  */
       if (cp[0] != '\0' && cp[0] != '#')
 	{
-	  alias = (char *) cp++;
+	  alias = cp++;
 	  while (cp[0] != '\0' && !isspace (cp[0]))
 	    ++cp;
 	  /* Terminate alias name.  */
@@ -296,7 +265,7 @@ read_alias_file (fname, fname_len)
 	      size_t alias_len;
 	      size_t value_len;
 
-	      value = (char *) cp++;
+	      value = cp++;
 	      while (cp[0] != '\0' && !isspace (cp[0]))
 		++cp;
 	      /* Terminate value.  */
@@ -312,7 +281,8 @@ read_alias_file (fname, fname_len)
 		*cp++ = '\0';
 
 	      if (nmap >= maxmap)
-		extend_alias_table ();
+		if (__builtin_expect (extend_alias_table (), 0))
+		  return added;
 
 	      alias_len = strlen (alias) + 1;
 	      value_len = strlen (value) + 1;
@@ -325,10 +295,19 @@ read_alias_file (fname, fname_len)
 					? alias_len + value_len : 1024));
 		  char *new_pool = (char *) realloc (string_space, new_size);
 		  if (new_pool == NULL)
+		    return added;
+
+		  if (__builtin_expect (string_space != new_pool, 0))
 		    {
-		      FREE_BLOCKS (block_list);
-		      return added;
+		      size_t i;
+
+		      for (i = 0; i < nmap; i++)
+			{
+			  map[i].alias += new_pool - string_space;
+			  map[i].value += new_pool - string_space;
+			}
 		    }
+
 		  string_space = new_pool;
 		  string_space_max = new_size;
 		}
@@ -355,12 +334,11 @@ read_alias_file (fname, fname_len)
     qsort (map, nmap, sizeof (struct alias_map),
 	   (int (*) PARAMS ((const void *, const void *))) alias_compare);
 
-  FREE_BLOCKS (block_list);
   return added;
 }
 
 
-static void
+static int
 extend_alias_table ()
 {
   size_t new_size;
@@ -371,10 +349,11 @@ extend_alias_table ()
 						* sizeof (struct alias_map)));
   if (new_map == NULL)
     /* Simply don't extend: we don't have any more core.  */
-    return;
+    return -1;
 
   map = new_map;
   maxmap = new_size;
+  return 0;
 }
 
 
