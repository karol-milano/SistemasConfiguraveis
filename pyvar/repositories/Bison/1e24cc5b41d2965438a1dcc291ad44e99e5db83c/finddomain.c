@@ -1,6 +1,6 @@
 /* Handle list of needed message catalogs
-   Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
-   Written by Ulrich Drepper <drepper@gnu.ai.mit.edu>, 1995.
+   Copyright (C) 1995-1999, 2000, 2001 Free Software Foundation, Inc.
+   Written by Ulrich Drepper <drepper@gnu.org>, 1995.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -20,45 +20,20 @@
 # include <config.h>
 #endif
 
-#include <ctype.h>
-#include <errno.h>
 #include <stdio.h>
 #include <sys/types.h>
-
-#if defined STDC_HEADERS || defined _LIBC
-# include <stdlib.h>
-#else
-# ifdef HAVE_MALLOC_H
-#  include <malloc.h>
-# else
-void free ();
-# endif
-#endif
-
-#if defined HAVE_STRING_H || defined _LIBC
-# include <string.h>
-#else
-# include <strings.h>
-# ifndef memcpy
-#  define memcpy(Dst, Src, Num) bcopy (Src, Dst, Num)
-# endif
-#endif
-#if !HAVE_STRCHR && !defined _LIBC
-# ifndef strchr
-#  define strchr index
-# endif
-#endif
+#include <stdlib.h>
+#include <string.h>
 
 #if defined HAVE_UNISTD_H || defined _LIBC
 # include <unistd.h>
 #endif
 
-#include "gettext.h"
 #include "gettextP.h"
 #ifdef _LIBC
 # include <libintl.h>
 #else
-# include "libgettext.h"
+# include "libgnuintl.h"
 #endif
 
 /* @@ end of prolog @@ */
@@ -71,10 +46,11 @@ static struct loaded_l10nfile *_nl_loaded_domains;
    established bindings.  */
 struct loaded_l10nfile *
 internal_function
-_nl_find_domain (dirname, locale, domainname)
+_nl_find_domain (dirname, locale, domainname, domainbinding)
      const char *dirname;
      char *locale;
      const char *domainname;
+     struct binding *domainbinding;
 {
   struct loaded_l10nfile *retval;
   const char *language;
@@ -120,7 +96,7 @@ _nl_find_domain (dirname, locale, domainname)
       int cnt;
 
       if (retval->decided == 0)
-	_nl_load_domain (retval);
+	_nl_load_domain (retval, domainbinding);
 
       if (retval->data != NULL)
 	return retval;
@@ -128,7 +104,7 @@ _nl_find_domain (dirname, locale, domainname)
       for (cnt = 0; retval->successor[cnt] != NULL; ++cnt)
 	{
 	  if (retval->successor[cnt]->decided == 0)
-	    _nl_load_domain (retval->successor[cnt]);
+	    _nl_load_domain (retval->successor[cnt], domainbinding);
 
 	  if (retval->successor[cnt]->data != NULL)
 	    break;
@@ -175,14 +151,14 @@ _nl_find_domain (dirname, locale, domainname)
     return NULL;
 
   if (retval->decided == 0)
-    _nl_load_domain (retval);
+    _nl_load_domain (retval, domainbinding);
   if (retval->data == NULL)
     {
       int cnt;
       for (cnt = 0; retval->successor[cnt] != NULL; ++cnt)
 	{
 	  if (retval->successor[cnt]->decided == 0)
-	    _nl_load_domain (retval->successor[cnt]);
+	    _nl_load_domain (retval->successor[cnt], domainbinding);
 	  if (retval->successor[cnt]->data != NULL)
 	    break;
 	}
@@ -192,6 +168,10 @@ _nl_find_domain (dirname, locale, domainname)
   if (alias_value != NULL)
     free (locale);
 
+  /* The space for normalized_codeset is dynamically allocated.  Free it.  */
+  if (mask & XPG_NORM_CODESET)
+    free ((void *) normalized_codeset);
+
   return retval;
 }
 
@@ -208,6 +188,7 @@ free_mem (void)
       if (runp->data != NULL)
 	_nl_unload_domain ((struct loaded_domain *) runp->data);
       runp = runp->next;
+      free ((char *) here->filename);
       free (here);
     }
 }
