@@ -38,8 +38,8 @@ extern char *realloc ();
 #endif
 #endif  /* NEED_DECLARATION_REALLOC */
 
-char *xmalloc PARAMS((register unsigned));
-char *xrealloc PARAMS((register char *, register unsigned));
+extern char *xmalloc PARAMS((register unsigned));
+extern char *xrealloc PARAMS((register char *, register unsigned));
 
 extern void done PARAMS((int));
 
