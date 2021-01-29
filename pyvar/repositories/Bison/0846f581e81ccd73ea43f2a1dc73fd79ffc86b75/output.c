@@ -1108,6 +1108,7 @@ output (void)
   if (semantic_parser)
     output_stos ();
   output_rule_data ();
+  XFREE (user_toknums);
   output_actions ();
 
 #if 0
