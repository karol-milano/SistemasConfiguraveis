@@ -1,5 +1,5 @@
 /* Load needed message catalogs.
-   Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
+   Copyright (C) 1995-1999, 2000, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -15,29 +15,68 @@
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
 
+#include <ctype.h>
+#include <errno.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
-#if defined STDC_HEADERS || defined _LIBC
-# include <stdlib.h>
+#ifdef __GNUC__
+# define alloca __builtin_alloca
+# define HAVE_ALLOCA 1
+#else
+# if defined HAVE_ALLOCA_H || defined _LIBC
+#  include <alloca.h>
+# else
+#  ifdef _AIX
+ #pragma alloca
+#  else
+#   ifndef alloca
+char *alloca ();
+#   endif
+#  endif
+# endif
 #endif
 
+#include <stdlib.h>
+#include <string.h>
+
 #if defined HAVE_UNISTD_H || defined _LIBC
 # include <unistd.h>
 #endif
 
-#if (defined HAVE_MMAP && defined HAVE_MUNMAP) || defined _LIBC
+#ifdef _LIBC
+# include <langinfo.h>
+# include <locale.h>
+#endif
+
+#if (defined HAVE_MMAP && defined HAVE_MUNMAP && !defined DISALLOW_MMAP) \
+    || (defined _LIBC && defined _POSIX_MAPPED_FILES)
 # include <sys/mman.h>
+# undef HAVE_MMAP
+# define HAVE_MMAP	1
+#else
+# undef HAVE_MMAP
 #endif
 
 #include "gettext.h"
 #include "gettextP.h"
 
+#ifdef _LIBC
+# include "../locale/localeinfo.h"
+#endif
+
 /* @@ end of prolog @@ */
 
 #ifdef _LIBC
@@ -51,32 +90,275 @@
 # define munmap __munmap
 #endif
 
+/* Names for the libintl functions are a problem.  They must not clash
+   with existing names and they should follow ANSI C.  But this source
+   code is also used in GNU C Library where the names have a __
+   prefix.  So we have to make a difference here.  */
+#ifdef _LIBC
+# define PLURAL_PARSE __gettextparse
+#else
+# define PLURAL_PARSE gettextparse__
+#endif
+
+/* For those losing systems which don't have `alloca' we have to add
+   some additional code emulating it.  */
+#ifdef HAVE_ALLOCA
+# define freea(p) /* nothing */
+#else
+# define alloca(n) malloc (n)
+# define freea(p) free (p)
+#endif
+
+/* For systems that distinguish between text and binary I/O.
+   O_BINARY is usually declared in <fcntl.h>. */
+#if !defined O_BINARY && defined _O_BINARY
+  /* For MSC-compatible compilers.  */
+# define O_BINARY _O_BINARY
+# define O_TEXT _O_TEXT
+#endif
+#ifdef __BEOS__
+  /* BeOS 5 has O_BINARY and O_TEXT, but they have no effect.  */
+# undef O_BINARY
+# undef O_TEXT
+#endif
+/* On reasonable systems, binary I/O is the default.  */
+#ifndef O_BINARY
+# define O_BINARY 0
+#endif
+
 /* We need a sign, whether a new catalog was loaded, which can be associated
    with all translations.  This is important if the translations are
    cached by one of GCC's features.  */
-int _nl_msg_cat_cntr = 0;
+int _nl_msg_cat_cntr;
+
+#if (defined __GNUC__ && !defined __APPLE_CC__) \
+    || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L)
+
+/* These structs are the constant expression for the germanic plural
+   form determination.  It represents the expression  "n != 1".  */
+static const struct expression plvar =
+{
+  .nargs = 0,
+  .operation = var,
+};
+static const struct expression plone =
+{
+  .nargs = 0,
+  .operation = num,
+  .val =
+  {
+    .num = 1
+  }
+};
+static struct expression germanic_plural =
+{
+  .nargs = 2,
+  .operation = not_equal,
+  .val =
+  {
+    .args =
+    {
+      [0] = (struct expression *) &plvar,
+      [1] = (struct expression *) &plone
+    }
+  }
+};
+
+# define INIT_GERMANIC_PLURAL()
+
+#else
+
+/* For compilers without support for ISO C 99 struct/union initializers:
+   Initialization at run-time.  */
+
+static struct expression plvar;
+static struct expression plone;
+static struct expression germanic_plural;
+
+static void
+init_germanic_plural ()
+{
+  if (plone.val.num == 0)
+    {
+      plvar.nargs = 0;
+      plvar.operation = var;
+
+      plone.nargs = 0;
+      plone.operation = num;
+      plone.val.num = 1;
+
+      germanic_plural.nargs = 2;
+      germanic_plural.operation = not_equal;
+      germanic_plural.val.args[0] = &plvar;
+      germanic_plural.val.args[1] = &plone;
+    }
+}
+
+# define INIT_GERMANIC_PLURAL() init_germanic_plural ()
+
+#endif
+
+
+/* Initialize the codeset dependent parts of an opened message catalog.
+   Return the header entry.  */
+const char *
+internal_function
+_nl_init_domain_conv (domain_file, domain, domainbinding)
+     struct loaded_l10nfile *domain_file;
+     struct loaded_domain *domain;
+     struct binding *domainbinding;
+{
+  /* Find out about the character set the file is encoded with.
+     This can be found (in textual form) in the entry "".  If this
+     entry does not exist or if this does not contain the `charset='
+     information, we will assume the charset matches the one the
+     current locale and we don't have to perform any conversion.  */
+  char *nullentry;
+  size_t nullentrylen;
+
+  /* Preinitialize fields, to avoid recursion during _nl_find_msg.  */
+  domain->codeset_cntr =
+    (domainbinding != NULL ? domainbinding->codeset_cntr : 0);
+#ifdef _LIBC
+  domain->conv = (__gconv_t) -1;
+#else
+# if HAVE_ICONV
+  domain->conv = (iconv_t) -1;
+# endif
+#endif
+  domain->conv_tab = NULL;
 
+  /* Get the header entry.  */
+  nullentry = _nl_find_msg (domain_file, domainbinding, "", &nullentrylen);
+
+  if (nullentry != NULL)
+    {
+#if defined _LIBC || HAVE_ICONV
+      const char *charsetstr;
+
+      charsetstr = strstr (nullentry, "charset=");
+      if (charsetstr != NULL)
+	{
+	  size_t len;
+	  char *charset;
+	  const char *outcharset;
+
+	  charsetstr += strlen ("charset=");
+	  len = strcspn (charsetstr, " \t\n");
+
+	  charset = (char *) alloca (len + 1);
+# if defined _LIBC || HAVE_MEMPCPY
+	  *((char *) mempcpy (charset, charsetstr, len)) = '\0';
+# else
+	  memcpy (charset, charsetstr, len);
+	  charset[len] = '\0';
+# endif
+
+	  /* The output charset should normally be determined by the
+	     locale.  But sometimes the locale is not used or not correctly
+	     set up, so we provide a possibility for the user to override
+	     this.  Moreover, the value specified through
+	     bind_textdomain_codeset overrides both.  */
+	  if (domainbinding != NULL && domainbinding->codeset != NULL)
+	    outcharset = domainbinding->codeset;
+	  else
+	    {
+	      outcharset = getenv ("OUTPUT_CHARSET");
+	      if (outcharset == NULL || outcharset[0] == '\0')
+		{
+# ifdef _LIBC
+		  outcharset = (*_nl_current[LC_CTYPE])->values[_NL_ITEM_INDEX (CODESET)].string;
+# else
+#  if HAVE_ICONV
+		  extern const char *locale_charset (void);
+		  outcharset = locale_charset ();
+#  endif
+# endif
+		}
+	    }
+
+# ifdef _LIBC
+	  /* We always want to use transliteration.  */
+	  outcharset = norm_add_slashes (outcharset, "TRANSLIT");
+	  charset = norm_add_slashes (charset, NULL);
+	  if (__gconv_open (outcharset, charset, &domain->conv,
+			    GCONV_AVOID_NOCONV)
+	      != __GCONV_OK)
+	    domain->conv = (__gconv_t) -1;
+# else
+#  if HAVE_ICONV
+	  /* When using GNU libiconv, we want to use transliteration.  */
+#   if _LIBICONV_VERSION >= 0x0105
+	  len = strlen (outcharset);
+	  {
+	    char *tmp = (char *) alloca (len + 10 + 1);
+	    memcpy (tmp, outcharset, len);
+	    memcpy (tmp + len, "//TRANSLIT", 10 + 1);
+	    outcharset = tmp;
+	  }
+#   endif
+	  domain->conv = iconv_open (outcharset, charset);
+#   if _LIBICONV_VERSION >= 0x0105
+	  freea (outcharset);
+#   endif
+#  endif
+# endif
+
+	  freea (charset);
+	}
+#endif /* _LIBC || HAVE_ICONV */
+    }
+
+  return nullentry;
+}
+
+/* Frees the codeset dependent parts of an opened message catalog.  */
+void
+internal_function
+_nl_free_domain_conv (domain)
+     struct loaded_domain *domain;
+{
+  if (domain->conv_tab != NULL && domain->conv_tab != (char **) -1)
+    free (domain->conv_tab);
+
+#ifdef _LIBC
+  if (domain->conv != (__gconv_t) -1)
+    __gconv_close (domain->conv);
+#else
+# if HAVE_ICONV
+  if (domain->conv != (iconv_t) -1)
+    iconv_close (domain->conv);
+# endif
+#endif
+}
 
 /* Load the message catalogs specified by FILENAME.  If it is no valid
    message catalog do nothing.  */
 void
 internal_function
-_nl_load_domain (domain_file)
+_nl_load_domain (domain_file, domainbinding)
      struct loaded_l10nfile *domain_file;
+     struct binding *domainbinding;
 {
   int fd;
   size_t size;
+#ifdef _LIBC
+  struct stat64 st;
+#else
   struct stat st;
+#endif
   struct mo_file_header *data = (struct mo_file_header *) -1;
-#if (defined HAVE_MMAP && defined HAVE_MUNMAP && !defined DISALLOW_MMAP) \
-    || defined _LIBC
   int use_mmap = 0;
-#endif
   struct loaded_domain *domain;
+  const char *nullentry;
 
   domain_file->decided = 1;
   domain_file->data = NULL;
 
+  /* Note that it would be useless to store domainbinding in domain_file
+     because domainbinding might be == NULL now but != NULL later (after
+     a call to bind_textdomain_codeset).  */
+
   /* If the record does not represent a valid locale the FILENAME
      might be NULL.  This can happen when according to the given
      specification the locale file name is different for XPG and CEN
@@ -85,28 +367,32 @@ _nl_load_domain (domain_file)
     return;
 
   /* Try to open the addressed file.  */
-  fd = open (domain_file->filename, O_RDONLY);
+  fd = open (domain_file->filename, O_RDONLY | O_BINARY);
   if (fd == -1)
     return;
 
   /* We must know about the size of the file.  */
-  if (fstat (fd, &st) != 0
-      || (size = (size_t) st.st_size) != st.st_size
-      || size < sizeof (struct mo_file_header))
+  if (
+#ifdef _LIBC
+      __builtin_expect (fstat64 (fd, &st) != 0, 0)
+#else
+      __builtin_expect (fstat (fd, &st) != 0, 0)
+#endif
+      || __builtin_expect ((size = (size_t) st.st_size) != st.st_size, 0)
+      || __builtin_expect (size < sizeof (struct mo_file_header), 0))
     {
       /* Something went wrong.  */
       close (fd);
       return;
     }
 
-#if (defined HAVE_MMAP && defined HAVE_MUNMAP && !defined DISALLOW_MMAP) \
-    || defined _LIBC
+#ifdef HAVE_MMAP
   /* Now we are ready to load the file.  If mmap() is available we try
      this first.  If not available or it failed we try to load it.  */
   data = (struct mo_file_header *) mmap (NULL, size, PROT_READ,
 					 MAP_PRIVATE, fd, 0);
 
-  if (data != (struct mo_file_header *) -1)
+  if (__builtin_expect (data != (struct mo_file_header *) -1, 1))
     {
       /* mmap() call was successful.  */
       close (fd);
@@ -130,12 +416,15 @@ _nl_load_domain (domain_file)
       do
 	{
 	  long int nb = (long int) read (fd, read_ptr, to_read);
-	  if (nb == -1)
+	  if (nb <= 0)
 	    {
+#ifdef EINTR
+	      if (nb == -1 && errno == EINTR)
+		continue;
+#endif
 	      close (fd);
 	      return;
 	    }
-
 	  read_ptr += nb;
 	  to_read -= nb;
 	}
@@ -146,11 +435,11 @@ _nl_load_domain (domain_file)
 
   /* Using the magic number we can test whether it really is a message
      catalog file.  */
-  if (data->magic != _MAGIC && data->magic != _MAGIC_SWAPPED)
+  if (__builtin_expect (data->magic != _MAGIC && data->magic != _MAGIC_SWAPPED,
+			0))
     {
       /* The magic number is wrong: not a message catalog file.  */
-#if (defined HAVE_MMAP && defined HAVE_MUNMAP && !defined DISALLOW_MMAP) \
-    || defined _LIBC
+#ifdef HAVE_MMAP
       if (use_mmap)
 	munmap ((caddr_t) data, size);
       else
@@ -159,17 +448,13 @@ _nl_load_domain (domain_file)
       return;
     }
 
-  domain_file->data
-    = (struct loaded_domain *) malloc (sizeof (struct loaded_domain));
-  if (domain_file->data == NULL)
+  domain = (struct loaded_domain *) malloc (sizeof (struct loaded_domain));
+  if (domain == NULL)
     return;
+  domain_file->data = domain;
 
-  domain = (struct loaded_domain *) domain_file->data;
   domain->data = (char *) data;
-#if (defined HAVE_MMAP && defined HAVE_MUNMAP && !defined DISALLOW_MMAP) \
-    || defined _LIBC
   domain->use_mmap = use_mmap;
-#endif
   domain->mmap_size = size;
   domain->must_swap = data->magic != _MAGIC;
 
@@ -187,9 +472,8 @@ _nl_load_domain (domain_file)
 	((char *) data + W (domain->must_swap, data->hash_tab_offset));
       break;
     default:
-      /* This is an illegal revision.  */
-#if (defined HAVE_MMAP && defined HAVE_MUNMAP && !defined DISALLOW_MMAP) \
-    || defined _LIBC
+      /* This is an invalid revision.  */
+#ifdef HAVE_MMAP
       if (use_mmap)
 	munmap ((caddr_t) data, size);
       else
@@ -200,9 +484,62 @@ _nl_load_domain (domain_file)
       return;
     }
 
-  /* Show that one domain is changed.  This might make some cached
-     translations invalid.  */
-  ++_nl_msg_cat_cntr;
+  /* Now initialize the character set converter from the character set
+     the file is encoded with (found in the header entry) to the domain's
+     specified character set or the locale's character set.  */
+  nullentry = _nl_init_domain_conv (domain_file, domain, domainbinding);
+
+  /* Also look for a plural specification.  */
+  if (nullentry != NULL)
+    {
+      const char *plural;
+      const char *nplurals;
+
+      plural = strstr (nullentry, "plural=");
+      nplurals = strstr (nullentry, "nplurals=");
+      if (plural == NULL || nplurals == NULL)
+	goto no_plural;
+      else
+	{
+	  /* First get the number.  */
+	  char *endp;
+	  unsigned long int n;
+	  struct parse_args args;
+
+	  nplurals += 9;
+	  while (*nplurals != '\0' && isspace (*nplurals))
+	    ++nplurals;
+#if defined HAVE_STRTOUL || defined _LIBC
+	  n = strtoul (nplurals, &endp, 10);
+#else
+	  for (endp = nplurals, n = 0; *endp >= '0' && *endp <= '9'; endp++)
+	    n = n * 10 + (*endp - '0');
+#endif
+	  domain->nplurals = n;
+	  if (nplurals == endp)
+	    goto no_plural;
+
+	  /* Due to the restrictions bison imposes onto the interface of the
+	     scanner function we have to put the input string and the result
+	     passed up from the parser into the same structure which address
+	     is passed down to the parser.  */
+	  plural += 7;
+	  args.cp = plural;
+	  if (PLURAL_PARSE (&args) != 0)
+	    goto no_plural;
+	  domain->plural = args.res;
+	}
+    }
+  else
+    {
+      /* By default we are using the Germanic form: singular form only
+         for `one', the plural form otherwise.  Yes, this is also what
+         English is using since English is a Germanic language.  */
+    no_plural:
+      INIT_GERMANIC_PLURAL ();
+      domain->plural = &germanic_plural;
+      domain->nplurals = 2;
+    }
 }
 
 
@@ -212,9 +549,16 @@ internal_function
 _nl_unload_domain (domain)
      struct loaded_domain *domain;
 {
+  if (domain->plural != &germanic_plural)
+    __gettext_free_exp (domain->plural);
+
+  _nl_free_domain_conv (domain);
+
+# ifdef _POSIX_MAPPED_FILES
   if (domain->use_mmap)
     munmap ((caddr_t) domain->data, domain->mmap_size);
   else
+# endif	/* _POSIX_MAPPED_FILES */
     free ((void *) domain->data);
 
   free (domain);