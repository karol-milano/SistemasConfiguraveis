@@ -117,6 +117,40 @@ read_signed_integer (FILE *stream)
   return sign * n;
 }
 
+/*--------------------------------------------------------------.
+| Get the data type (alternative in the union) of the value for |
+| symbol N in rule RULE.                                        |
+`--------------------------------------------------------------*/
+
+static char *
+get_type_name (int n, symbol_list * rule)
+{
+  int i;
+  symbol_list *rp;
+
+  if (n < 0)
+    {
+      complain (_("invalid $ value"));
+      return NULL;
+    }
+
+  rp = rule;
+  i = 0;
+
+  while (i < n)
+    {
+      rp = rp->next;
+      if (rp == NULL || rp->sym == NULL)
+	{
+	  complain (_("invalid $ value"));
+	  return NULL;
+	}
+      i++;
+    }
+
+  return rp->sym->type_name;
+}
+
 /*-------------------------------------------------------------------.
 | Dump the string from FINPUT to FOUTPUT.  MATCH is the delimiter of |
 | the string (either ' or ").                                        |
@@ -271,6 +305,78 @@ copy_at (FILE *fin, FILE *fout, int stack_offset)
       complain (_("%s is invalid"), quote (buf));
     }
 }
+
+
+/*-------------------------------------------------------------------.
+| FIN is pointing to a wannabee semantic value (i.e., a `$').        |
+|                                                                    |
+| Possible inputs: $[<TYPENAME>]($|integer)                          |
+|                                                                    |
+| Output to FOUT a reference to this semantic value. STACK_OFFSET is |
+| the number of values in the current rule so far, which says where  |
+| to find `$0' with respect to the top of the stack.                 |
+`-------------------------------------------------------------------*/
+
+static inline void
+copy_dollar (FILE *fin, FILE *fout,
+	     symbol_list *rule, int stack_offset)
+{
+  int c = getc (fin);
+  char *type_name = NULL;
+
+  /* Get the typename if explicit. */
+  if (c == '<')
+    {
+      char *cp = token_buffer;
+
+      while ((c = getc (fin)) != '>' && c > 0)
+	{
+	  if (cp == token_buffer + maxtoken)
+	    cp = grow_token_buffer (cp);
+
+	  *cp++ = c;
+	}
+      *cp = 0;
+      type_name = token_buffer;
+      value_components_used = 1;
+
+      c = getc (fin);
+    }
+
+  if (c == '$')
+    {
+      fprintf (fout, "yyval");
+      if (!type_name)
+	type_name = get_type_name (0, rule);
+      if (type_name)
+	fprintf (fout, ".%s", type_name);
+      if (!type_name && typed)
+	complain (_("$$ of `%s' has no declared type"),
+		  rule->sym->tag);
+    }
+  else if (isdigit (c) || c == '-')
+    {
+      int n;
+      ungetc (c, fin);
+      n = read_signed_integer (fin);
+
+      if (!type_name && n > 0)
+	type_name = get_type_name (n, rule);
+
+      fprintf (fout, "yyvsp[%d]", n - stack_offset);
+      if (type_name)
+	fprintf (fout, ".%s", type_name);
+      if (!type_name && typed)
+	complain (_("$%d of `%s' has no declared type"),
+		  n, rule->sym->tag);
+    }
+  else
+    {
+      char buf[] = "$c";
+      buf[1] = c;
+      complain (_("%s is invalid"), quote (buf));
+    }
+}
 
 /*-------------------------------------------------------------------.
 | Copy the contents of a `%{ ... %}' into the definitions file.  The |
@@ -448,43 +554,6 @@ parse_start_decl (void)
     }
 }
 
-
-
-/*--------------------------------------------------------------.
-| Get the data type (alternative in the union) of the value for |
-| symbol n in rule rule.                                        |
-`--------------------------------------------------------------*/
-
-static char *
-get_type_name (int n, symbol_list * rule)
-{
-  int i;
-  symbol_list *rp;
-
-  if (n < 0)
-    {
-      complain (_("invalid $ value"));
-      return NULL;
-    }
-
-  rp = rule;
-  i = 0;
-
-  while (i < n)
-    {
-      rp = rp->next;
-      if (rp == NULL || rp->sym == NULL)
-	{
-	  complain (_("invalid $ value"));
-	  return NULL;
-	}
-      i++;
-    }
-
-  return rp->sym->type_name;
-}
-
-
 /*-----------------------------------------------------------.
 | read in a %type declaration and record its information for |
 | get_type_name to access                                    |
@@ -724,7 +793,7 @@ parse_expect_decl (void)
   ungetc (c, finput);
 
   if (count <= 0 || count > 10)
-    complain ("%s", _("argument of %expect is not an integer"));
+    complain (_("argument of %%expect is not an integer"));
   expected_conflicts = atoi (buffer);
 }
 
@@ -805,7 +874,8 @@ parse_thong_decl (void)
   symval->alias = symbol;
   symbol->alias = symval;
 
-  nsyms--;			/* symbol and symval combined are only one symbol */
+  /* symbol and symval combined are only one symbol.  */
+  nsyms--;
 }
 
 
@@ -917,12 +987,10 @@ read_declarations (void)
 `-------------------------------------------------------------------*/
 
 static void
-copy_action (symbol_list * rule, int stack_offset)
+copy_action (symbol_list *rule, int stack_offset)
 {
   int c;
-  int n;
   int count;
-  char *type_name;
 
   /* offset is always 0 if parser has already popped the stack pointer */
   if (semantic_parser)
@@ -966,61 +1034,7 @@ copy_action (symbol_list * rule, int stack_offset)
 	      break;
 
 	    case '$':
-	      c = getc (finput);
-	      type_name = NULL;
-
-	      if (c == '<')
-		{
-		  char *cp = token_buffer;
-
-		  while ((c = getc (finput)) != '>' && c > 0)
-		    {
-		      if (cp == token_buffer + maxtoken)
-			cp = grow_token_buffer (cp);
-
-		      *cp++ = c;
-		    }
-		  *cp = 0;
-		  type_name = token_buffer;
-		  value_components_used = 1;
-
-		  c = getc (finput);
-		}
-	      if (c == '$')
-		{
-		  fprintf (faction, "yyval");
-		  if (!type_name)
-		    type_name = get_type_name (0, rule);
-		  if (type_name)
-		    fprintf (faction, ".%s", type_name);
-		  if (!type_name && typed)
-		    complain (_("$$ of `%s' has no declared type"),
-			      rule->sym->tag);
-		}
-	      else if (isdigit (c) || c == '-')
-		{
-		  ungetc (c, finput);
-		  n = read_signed_integer (finput);
-		  c = getc (finput);
-
-		  if (!type_name && n > 0)
-		    type_name = get_type_name (n, rule);
-
-		  fprintf (faction, "yyvsp[%d]", n - stack_offset);
-		  if (type_name)
-		    fprintf (faction, ".%s", type_name);
-		  if (!type_name && typed)
-		    complain (_("$%d of `%s' has no declared type"),
-			      n, rule->sym->tag);
-		  continue;
-		}
-	      else
-		{
-		  char buf[] = "$c";
-		  buf[1] = c;
-		  complain (_("%s is invalid"), quote (buf));
-		}
-
+	      copy_dollar (finput, faction, rule, stack_offset);
 	      break;
 
 	    case '@':
@@ -1059,12 +1073,10 @@ copy_action (symbol_list * rule, int stack_offset)
 `-------------------------------------------------------------------*/
 
 static void
-copy_guard (symbol_list * rule, int stack_offset)
+copy_guard (symbol_list *rule, int stack_offset)
 {
   int c;
-  int n;
   int count;
-  char *type_name;
   int brace_flag = 0;
 
   /* offset is always 0 if parser has already popped the stack pointer */
@@ -1119,60 +1131,7 @@ copy_guard (symbol_list * rule, int stack_offset)
 	  break;
 
 	case '$':
-	  c = getc (finput);
-	  type_name = NULL;
-
-	  if (c == '<')
-	    {
-	      char *cp = token_buffer;
-
-	      while ((c = getc (finput)) != '>' && c > 0)
-		{
-		  if (cp == token_buffer + maxtoken)
-		    cp = grow_token_buffer (cp);
-
-		  *cp++ = c;
-		}
-	      *cp = 0;
-	      type_name = token_buffer;
-
-	      c = getc (finput);
-	    }
-
-	  if (c == '$')
-	    {
-	      fprintf (fguard, "yyval");
-	      if (!type_name)
-		type_name = rule->sym->type_name;
-	      if (type_name)
-		fprintf (fguard, ".%s", type_name);
-	      if (!type_name && typed)
-		complain (_("$$ of `%s' has no declared type"),
-			  rule->sym->tag);
-	    }
-	  else if (isdigit (c) || c == '-')
-	    {
-	      ungetc (c, finput);
-	      n = read_signed_integer (finput);
-	      c = getc (finput);
-
-	      if (!type_name && n > 0)
-		type_name = get_type_name (n, rule);
-
-	      fprintf (fguard, "yyvsp[%d]", n - stack_offset);
-	      if (type_name)
-		fprintf (fguard, ".%s", type_name);
-	      if (!type_name && typed)
-		complain (_("$%d of `%s' has no declared type"),
-			  n, rule->sym->tag);
-	      continue;
-	    }
-	  else
-	    {
-	      char buf[] = "$c";
-	      buf[1] = c;
-	      complain (_("%s is invalid"), quote (buf));
-	    }
+	  copy_dollar (finput, fguard, rule, stack_offset);
 	  break;
 
 	case '@':
