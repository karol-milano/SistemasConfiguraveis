@@ -248,7 +248,7 @@ b4_syncline([@oline@], [@ofile@])[
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#ifndef lint
+#if !defined (lint) || defined (__GNUC__)
 # define YYUSE(e) ((void) (e))
 #else
 # define YYUSE(e) /* empty */
