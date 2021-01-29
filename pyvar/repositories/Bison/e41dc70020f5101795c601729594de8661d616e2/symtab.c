@@ -49,6 +49,9 @@ hash (const char *key)
 static bucket *
 bucket_new (const char *tag, int hashval)
 {
+  /* Hack, until we have a Bison parser. */
+  extern int lineno;
+
   bucket *res = XMALLOC (bucket, 1);
 
   res->link = symtab[hashval];
@@ -61,6 +64,7 @@ bucket_new (const char *tag, int hashval)
   res->user_token_number = SUNDEF;
   res->alias = NULL;
   res->class = unknown_sym;
+  res->line = lineno;
 
   nsyms++;
 
