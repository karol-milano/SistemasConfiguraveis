@@ -1832,6 +1832,22 @@ packsymbols (void)
 
   error_token_number = errtoken->value;
 
+  if (startval->class == unknown_sym)
+    fatal (_("the start symbol %s is undefined"), startval->tag);
+  else if (startval->class == token_sym)
+    fatal (_("the start symbol %s is a token"), startval->tag);
+
+  start_symbol = startval->value;
+}
+
+
+/*-----------------------------------.
+| Output definition of token names.  |
+`-----------------------------------*/
+
+static void
+symbols_output (void)
+{
   {
     struct obstack tokendefs;
     obstack_init (&tokendefs);
@@ -1846,13 +1862,6 @@ packsymbols (void)
     output_token_defines (&table_obstack);
 #endif
 
-  if (startval->class == unknown_sym)
-    fatal (_("the start symbol %s is undefined"), startval->tag);
-  else if (startval->class == token_sym)
-    fatal (_("the start symbol %s is a token"), startval->tag);
-
-  start_symbol = startval->value;
-
   if (defines_flag)
     {
       output_token_defines (&defines_obstack);
@@ -2020,6 +2029,7 @@ reader (void)
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
+  symbols_output ();
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
 }
