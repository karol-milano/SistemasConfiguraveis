@@ -334,9 +334,16 @@ copy_at (FILE *fin, struct obstack *oout, int stack_offset)
 
       ungetc (c, fin);
       n = read_signed_integer (fin);
-
-      obstack_fgrow1 (oout, "yylsp[%d]", n - stack_offset);
-      locations_flag = 1;
+      if (n > stack_offset)
+	complain (_("invalid value: %s%d"), "@", n);
+      else
+	{
+	  /* Offset is always 0 if parser has already popped the stack
+	     pointer.  */
+	  obstack_fgrow1 (oout, "yylsp[%d]",
+			  n - (semantic_parser ? 0 : stack_offset));
+	  locations_flag = 1;
+	}
     }
   else
     {
@@ -391,16 +398,24 @@ copy_dollar (FILE *fin, struct obstack *oout,
       ungetc (c, fin);
       n = read_signed_integer (fin);
 
-      if (!type_name && n > 0)
-	type_name = get_type_name (n, rule);
-
-      obstack_fgrow1 (oout, "yyvsp[%d]", n - stack_offset);
-
-      if (type_name)
-	obstack_fgrow1 (oout, ".%s", type_name);
-      if (!type_name && typed)
-	complain (_("$%d of `%s' has no declared type"),
-		  n, rule->sym->tag);
+      if (n > stack_offset)
+	complain (_("invalid value: %s%d"), "$", n);
+      else
+	{
+	  if (!type_name && n > 0)
+	    type_name = get_type_name (n, rule);
+
+	  /* Offset is always 0 if parser has already popped the stack
+	     pointer.  */
+	  obstack_fgrow1 (oout, "yyvsp[%d]",
+			  n - (semantic_parser ? 0 : stack_offset));
+
+	  if (type_name)
+	    obstack_fgrow1 (oout, ".%s", type_name);
+	  if (!type_name && typed)
+	    complain (_("$%d of `%s' has no declared type"),
+		      n, rule->sym->tag);
+	}
     }
   else
     {
@@ -882,6 +897,7 @@ parse_thong_decl (void)
   nsyms--;
 }
 
+
 static void
 parse_muscle_decl (void)
 {
@@ -1081,8 +1097,8 @@ read_declarations (void)
 | values in the current rule so far, which says where to find `$0'   |
 | with respect to the top of the stack.                              |
 |                                                                    |
-| This routine is used both for actions and guards.  Only the        |
-| actions_obstack is used, but this is fine, since we use only       |
+| This routine is used both for actions and guards.  Only            |
+| ACTION_OBSTACK is used, but this is fine, since we use only        |
 | pointers to relevant portions inside this obstack.                 |
 `-------------------------------------------------------------------*/
 
@@ -1092,10 +1108,6 @@ parse_braces (symbol_list *rule, int stack_offset)
   int c;
   int count;
 
-  /* offset is always 0 if parser has already popped the stack pointer */
-  if (semantic_parser)
-    stack_offset = 0;
-
   count = 1;
   while (count > 0)
     {
