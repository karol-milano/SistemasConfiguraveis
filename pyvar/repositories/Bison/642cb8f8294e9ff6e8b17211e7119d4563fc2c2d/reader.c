@@ -759,6 +759,7 @@ parse_union_decl (void)
 
   typed = 1;
 
+  MUSCLE_INSERT_INT ("stype_line", lineno);
   obstack_init (&union_obstack);
   obstack_sgrow (&union_obstack, "union");
 
