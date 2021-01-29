@@ -491,7 +491,7 @@ print_grammar (FILE *out, int level)
 }
 
 void
-xml_puts (FILE *out, int level, char *s)
+xml_puts (FILE *out, int level, char const *s)
 {
   int i;
   level *= 2;
