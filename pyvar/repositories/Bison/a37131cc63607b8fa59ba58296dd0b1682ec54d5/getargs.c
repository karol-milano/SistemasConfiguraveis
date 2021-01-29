@@ -556,7 +556,7 @@ command_line_location (void)
 {
   location res;
   /* "<command line>" is used in GCC's messages about -D. */
-  boundary_set (&res.start, uniqstr_new ("<command line>"), optind, -1);
+  boundary_set (&res.start, uniqstr_new ("<command line>"), optind - 1, -1);
   res.end = res.start;
   return res;
 }
