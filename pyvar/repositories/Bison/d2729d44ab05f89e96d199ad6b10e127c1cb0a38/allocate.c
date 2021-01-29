@@ -29,13 +29,15 @@ extern char *calloc ();
 extern char *realloc ();
 #endif
 
-extern void done ();
+char *xmalloc PARAMS((register unsigned));
+char *xrealloc PARAMS((register char *, register unsigned));
+
+extern void done PARAMS((int));
 
 extern char *program_name;
 
 char *
-xmalloc (n)
-     register unsigned n;
+xmalloc (register unsigned n)
 {
   register char *block;
 
@@ -53,9 +55,7 @@ xmalloc (n)
 }
 
 char *
-xrealloc (block, n)
-     register char *block;
-     register unsigned n;
+xrealloc (register char *block, register unsigned n)
 {
   /* Avoid uncertainty about what an arg of 0 will do.  */
   if (n == 0)
