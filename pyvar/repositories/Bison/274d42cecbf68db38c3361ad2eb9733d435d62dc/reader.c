@@ -63,9 +63,6 @@ static int typed;
 /* Incremented for each %left, %right or %nonassoc seen */
 static int lastprec;
 
-/* Incremented for each generated symbol */
-static int gensym_count;
-
 static bucket *errtoken;
 static bucket *undeftoken;
 
@@ -1178,9 +1175,14 @@ record_rule_line (void)
 static bucket *
 gensym (void)
 {
+  /* Incremented for each generated symbol */
+  static int gensym_count = 0;
+  static char buf[256];
+
   bucket *sym;
 
-  sprintf (token_buffer, "@%d", ++gensym_count);
+  sprintf (buf, "@%d", ++gensym_count);
+  token_buffer = buf;
   sym = getsym (token_buffer);
   sym->class = nterm_sym;
   sym->value = nvars++;
@@ -1866,8 +1868,6 @@ reader (void)
   typed = 0;
   lastprec = 0;
 
-  gensym_count = 0;
-
   semantic_parser = 0;
   pure_parser = 0;
 
