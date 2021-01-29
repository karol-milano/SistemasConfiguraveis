@@ -153,20 +153,17 @@ get_type_name (int n, symbol_list * rule)
   return rp->sym->type_name;
 }
 
-/*-----------------------------------------------------------------.
-| Dump the string from FIN to FOUT and OOUT if non null.  MATCH is |
-| the delimiter of the string (either ' or ").                     |
-`-----------------------------------------------------------------*/
+/*------------------------------------------------------------.
+| Dump the string from FIN to OOUT if non null.  MATCH is the |
+| delimiter of the string (either ' or ").                    |
+`------------------------------------------------------------*/
 
 static inline void
-copy_string (FILE *fin, FILE *fout, struct obstack *oout, int match)
+copy_string (FILE *fin, struct obstack *oout, int match)
 {
   int c;
 
-  if (fout)
-    putc (match, fout);
-  if (oout)
-    obstack_1grow (oout, match);
+  obstack_1grow (oout, match);
 
   c = getc (fin);
 
@@ -182,20 +179,14 @@ copy_string (FILE *fin, FILE *fout, struct obstack *oout, int match)
 	  continue;
 	}
 
-      if (fout)
-	putc (c, fout);
-      if (oout)
-	obstack_1grow (oout, c);
+      obstack_1grow (oout, c);
 
       if (c == '\\')
 	{
 	  c = getc (fin);
 	  if (c == EOF)
 	    fatal (_("unterminated string at end of file"));
-	  if (fout)
-	    putc (c, fout);
-	  if (oout)
-	    obstack_1grow (oout, c);
+	  obstack_1grow (oout, c);
 
 	  if (c == '\n')
 	    lineno++;
@@ -204,34 +195,27 @@ copy_string (FILE *fin, FILE *fout, struct obstack *oout, int match)
       c = getc (fin);
     }
 
-  if (fout)
-    putc (c, fout);
-  if (oout)
-    obstack_1grow (oout, c);
+  obstack_1grow (oout, c);
 }
 
 
-/*----------------------------------------------------------------.
-| Dump the wannabee comment from IN to OUT1 and OUT2.  In fact we |
-| just saw a `/', which might or might not be a comment.  In any  |
-| case, copy what we saw.                                         |
-|                                                                 |
-| OUT2 might be NULL.                                             |
-`----------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Dump the wannabee comment from IN to OUT1 and OUT2 (which can be |
+| NULL).  In fact we just saw a `/', which might or might not be a |
+| comment.  In any case, copy what we saw.                         |
+|                                                                  |
+| OUT2 might be NULL.                                              |
+`-----------------------------------------------------------------*/
 
 static inline void
-copy_comment2 (FILE *fin, FILE *out1,
-	       struct obstack *oout2, struct obstack *oout)
+copy_comment2 (FILE *fin, struct obstack *oout1, struct obstack *oout2)
 {
   int cplus_comment;
   int ended;
   int c;
 
   /* We read a `/', output it. */
-  if (out1)
-    putc ('/', out1);
-  if (oout)
-    obstack_1grow (oout, '/');
+  obstack_1grow (oout1, '/');
   if (oout2)
     obstack_1grow (oout2, '/');
 
@@ -248,10 +232,7 @@ copy_comment2 (FILE *fin, FILE *out1,
       return;
     }
 
-  if (out1)
-    putc (c, out1);
-  if (oout)
-    obstack_1grow (oout, c);
+  obstack_1grow (oout1, c);
   if (oout2)
     obstack_1grow (oout2, c);
   c = getc (fin);
@@ -263,10 +244,7 @@ copy_comment2 (FILE *fin, FILE *out1,
 	{
 	  while (c == '*')
 	    {
-	      if (out1)
-		putc (c, out1);
-	      if (oout)
-		obstack_1grow (oout, c);
+	      obstack_1grow (oout1, c);
 	      if (oout2)
 		obstack_1grow (oout2, c);
 	      c = getc (fin);
@@ -274,10 +252,7 @@ copy_comment2 (FILE *fin, FILE *out1,
 
 	  if (c == '/')
 	    {
-	      if (out1)
-		putc (c, out1);
-	      if (oout)
-		obstack_1grow (oout, c);
+	      obstack_1grow (oout1, c);
 	      if (oout2)
 		obstack_1grow (oout2, c);
 	      ended = 1;
@@ -286,10 +261,7 @@ copy_comment2 (FILE *fin, FILE *out1,
       else if (c == '\n')
 	{
 	  lineno++;
-	  if (out1)
-	    putc (c, out1);
-	  if (oout)
-	    obstack_1grow (oout, c);
+	  obstack_1grow (oout1, c);
 	  if (oout2)
 	    obstack_1grow (oout2, c);
 	  if (cplus_comment)
@@ -301,10 +273,7 @@ copy_comment2 (FILE *fin, FILE *out1,
 	fatal (_("unterminated comment"));
       else
 	{
-	  if (out1)
-	    putc (c, out1);
-	  if (oout)
-	    obstack_1grow (oout, c);
+	  obstack_1grow (oout1, c);
 	  if (oout2)
 	    obstack_1grow (oout2, c);
 	  c = getc (fin);
@@ -315,35 +284,32 @@ copy_comment2 (FILE *fin, FILE *out1,
 
 /*-------------------------------------------------------------------.
 | Dump the comment (actually the current string starting with a `/') |
-| from FIN to FOUT.                                                  |
+| from FIN to OOUT.                                                  |
 `-------------------------------------------------------------------*/
 
 static inline void
-copy_comment (FILE *fin, FILE *fout, struct obstack *oout)
+copy_comment (FILE *fin, struct obstack *oout)
 {
-  copy_comment2 (fin, fout, NULL, oout);
+  copy_comment2 (fin, oout, NULL);
 }
 
 
 /*-----------------------------------------------------------------.
-| FIN is pointing to a location (i.e., a `@').  Output to FOUT a   |
+| FIN is pointing to a location (i.e., a `@').  Output to OOUT a   |
 | reference to this location. STACK_OFFSET is the number of values |
 | in the current rule so far, which says where to find `$0' with   |
 | respect to the top of the stack.                                 |
 `-----------------------------------------------------------------*/
 
 static inline void
-copy_at (FILE *fin, FILE *fout, struct obstack *oout, int stack_offset)
+copy_at (FILE *fin, struct obstack *oout, int stack_offset)
 {
   int c;
 
   c = getc (fin);
   if (c == '$')
     {
-      if (fout)
-	fprintf (fout, "yyloc");
-      if (oout)
-	obstack_grow_string (oout, "yyloc");
+      obstack_grow_string (oout, "yyloc");
       locations_flag = 1;
     }
   else if (isdigit (c) || c == '-')
@@ -354,11 +320,7 @@ copy_at (FILE *fin, FILE *fout, struct obstack *oout, int stack_offset)
       ungetc (c, fin);
       n = read_signed_integer (fin);
 
-      sprintf (buf, "yylsp[%d]", n - stack_offset);
-      if (fout)
-	fputs (buf, fout);
-      if (oout)
-	obstack_grow (oout, buf, strlen (buf));
+      obstack_fgrow1 (oout, "yylsp[%d]", n - stack_offset);
       locations_flag = 1;
     }
   else
@@ -375,13 +337,13 @@ copy_at (FILE *fin, FILE *fout, struct obstack *oout, int stack_offset)
 |                                                                    |
 | Possible inputs: $[<TYPENAME>]($|integer)                          |
 |                                                                    |
-| Output to FOUT a reference to this semantic value. STACK_OFFSET is |
+| Output to OOUT a reference to this semantic value. STACK_OFFSET is |
 | the number of values in the current rule so far, which says where  |
 | to find `$0' with respect to the top of the stack.                 |
 `-------------------------------------------------------------------*/
 
 static inline void
-copy_dollar (FILE *fin, FILE *fout, struct obstack *oout,
+copy_dollar (FILE *fin, struct obstack *oout,
 	     symbol_list *rule, int stack_offset)
 {
   int c = getc (fin);
@@ -398,20 +360,12 @@ copy_dollar (FILE *fin, FILE *fout, struct obstack *oout,
 
   if (c == '$')
     {
-      if (fout)
-	fputs ("yyval", fout);
-      if (oout)
-	obstack_grow_string (oout, "yyval");
+      obstack_grow_string (oout, "yyval");
 
       if (!type_name)
 	type_name = get_type_name (0, rule);
       if (type_name)
-	{
-	  if (fout)
-	    fprintf (fout, ".%s", type_name);
-	  if (oout)
-	    obstack_fgrow1 (oout, ".%s", type_name);
-	}
+	obstack_fgrow1 (oout, ".%s", type_name);
       if (!type_name && typed)
 	complain (_("$$ of `%s' has no declared type"),
 		  rule->sym->tag);
@@ -425,18 +379,10 @@ copy_dollar (FILE *fin, FILE *fout, struct obstack *oout,
       if (!type_name && n > 0)
 	type_name = get_type_name (n, rule);
 
-      if (fout)
-	fprintf (fout, "yyvsp[%d]", n - stack_offset);
-      if (oout)
-	obstack_fgrow1 (oout, "yyvsp[%d]", n - stack_offset);
+      obstack_fgrow1 (oout, "yyvsp[%d]", n - stack_offset);
 
       if (type_name)
-	{
-	  if (fout)
-	    fprintf (fout, ".%s", type_name);
-	  if (oout)
-	    obstack_fgrow1 (oout, ".%s", type_name);
-	}
+	obstack_fgrow1 (oout, ".%s", type_name);
       if (!type_name && typed)
 	complain (_("$%d of `%s' has no declared type"),
 		  n, rule->sym->tag);
@@ -484,11 +430,11 @@ copy_definition (void)
 
 	case '\'':
 	case '"':
-	  copy_string (finput, 0, &attrs_obstack, c);
+	  copy_string (finput, &attrs_obstack, c);
 	  break;
 
 	case '/':
-	  copy_comment (finput, 0, &attrs_obstack);
+	  copy_comment (finput, &attrs_obstack);
 	  break;
 
 	case EOF:
@@ -805,7 +751,7 @@ parse_union_decl (void)
 	  break;
 
 	case '/':
-	  copy_comment2 (finput, 0, &defines_obstack, &attrs_obstack);
+	  copy_comment2 (finput, &defines_obstack, &attrs_obstack);
 	  break;
 
 	case '{':
@@ -1079,20 +1025,20 @@ copy_action (symbol_list *rule, int stack_offset)
 
 	    case '\'':
 	    case '"':
-	      copy_string (finput, 0, &action_obstack, c);
+	      copy_string (finput, &action_obstack, c);
 	      break;
 
 	    case '/':
-	      copy_comment (finput, 0, &action_obstack);
+	      copy_comment (finput, &action_obstack);
 	      break;
 
 	    case '$':
-	      copy_dollar (finput, 0, &action_obstack,
+	      copy_dollar (finput, &action_obstack,
 			   rule, stack_offset);
 	      break;
 
 	    case '@':
-	      copy_at (finput, 0, &action_obstack,
+	      copy_at (finput, &action_obstack,
 		       stack_offset);
 	      break;
 
@@ -1175,19 +1121,19 @@ copy_guard (symbol_list *rule, int stack_offset)
 
 	case '\'':
 	case '"':
-	  copy_string (finput, 0, &guard_obstack, c);
+	  copy_string (finput, &guard_obstack, c);
 	  break;
 
 	case '/':
-	  copy_comment (finput, 0, &guard_obstack);
+	  copy_comment (finput, &guard_obstack);
 	  break;
 
 	case '$':
-	  copy_dollar (finput, 0, &guard_obstack, rule, stack_offset);
+	  copy_dollar (finput, &guard_obstack, rule, stack_offset);
 	  break;
 
 	case '@':
-	  copy_at (finput, 0, &guard_obstack, stack_offset);
+	  copy_at (finput, &guard_obstack, stack_offset);
 	  break;
 
 	case EOF:
