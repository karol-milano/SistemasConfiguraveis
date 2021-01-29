@@ -43,13 +43,6 @@ void exit ();
 
 #include "complain.h"
 
-#ifndef HAVE_DECL_STRERROR_R
-"this configure-time declaration test was not run"
-#endif
-#if !HAVE_DECL_STRERROR_R
-char *strerror_r ();
-#endif
-
 #ifndef _
 # define _(String) String
 #endif
@@ -76,14 +69,14 @@ char *strerror_r ();
    name of the executing program.  */
 extern char *program_name;
 
-# ifdef HAVE_STRERROR_R
-#  define __strerror_r strerror_r
+# if HAVE_STRERROR
+#  ifndef HAVE_DECL_STRERROR
+"this configure-time declaration test was not run"
+#  endif
+#  if !HAVE_DECL_STRERROR && !defined strerror
+char *strerror PARAMS ((int));
+#  endif
 # else
-#  if HAVE_STRERROR
-#   ifndef strerror		/* On some systems, strerror is a macro */
-char *strerror ();
-#   endif
-#  else
 static char *
 private_strerror (errnum)
      int errnum;
@@ -95,9 +88,8 @@ private_strerror (errnum)
     return _(sys_errlist[errnum]);
   return _("Unknown system error");
 }
-#   define strerror private_strerror
-#  endif /* HAVE_STRERROR */
-# endif	/* HAVE_STRERROR_R */
+#  define strerror private_strerror
+# endif /* HAVE_STRERROR */
 #endif	/* not _LIBC */
 
 /* This variable is incremented each time `warn' is called.  */
