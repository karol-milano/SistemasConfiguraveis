@@ -312,7 +312,6 @@ copy_at (FILE *fin, struct obstack *oout, int stack_offset)
   else if (isdigit (c) || c == '-')
     {
       int n;
-      char buf[4096];
 
       ungetc (c, fin);
       n = read_signed_integer (fin);
@@ -344,7 +343,7 @@ copy_dollar (FILE *fin, struct obstack *oout,
 	     symbol_list *rule, int stack_offset)
 {
   int c = getc (fin);
-  char *type_name = NULL;
+  const char *type_name = NULL;
 
   /* Get the type name if explicit. */
   if (c == '<')
