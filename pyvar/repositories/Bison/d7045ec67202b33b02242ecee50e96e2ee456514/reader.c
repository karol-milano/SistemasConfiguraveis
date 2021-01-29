@@ -793,7 +793,7 @@ parse_union_decl (void)
     {
       obstack_1grow (&attrs_obstack, c);
       if (defines_flag)
-	obstack_grow_literal_string (&defines_obstack, c);
+	obstack_1grow (&defines_obstack, c);
 
       switch (c)
 	{
