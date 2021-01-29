@@ -90,6 +90,7 @@ main(argc, argv)
   /* output the tables and the parser to ftable.  In file output. */
   output();
   done(failure);
+  return failure;
 }
 
 /* functions to report errors which prevent a parser from being generated */
@@ -100,7 +101,7 @@ main(argc, argv)
 
 char *
 printable_version(c)
-     char c;
+     int c;
 {
   static char buf[10];
   if (c < ' ' || c >= '\177')
