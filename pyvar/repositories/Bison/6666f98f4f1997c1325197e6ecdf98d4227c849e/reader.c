@@ -36,10 +36,27 @@
 #include "gram.h"
 #include "machine.h"
 
-#define	LTYPESTR	"\n#ifndef YYLTYPE\ntypedef\n  struct yyltype\n\
-    {\n      int timestamp;\n      int first_line;\n      int first_column;\
-\n      int last_line;\n      int last_column;\n      char *text;\n   }\n\
-  yyltype;\n\n#define YYLTYPE yyltype\n#endif\n\n"
+#define	LTYPESTR	"\
+\n\
+#ifndef YYLTYPE\n\
+typedef\n\
+  struct yyltype\n\
+\
+    {\n\
+      int timestamp;\n\
+      int first_line;\n\
+      int first_column;\
+\n\
+      int last_line;\n\
+      int last_column;\n\
+      char *text;\n\
+   }\n\
+\
+  yyltype;\n\
+\n\
+#define YYLTYPE yyltype\n\
+#endif\n\
+\n"
 
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 int rline_allocated;
@@ -329,10 +346,8 @@ read_declarations (void)
         fatal(_("no input grammar"));
       else
 	{
-		char buff[100];
-		sprintf(buff, _("unknown character: %s"), printable_version(c));
-		warn(buff);
-		skip_to_char('%');
+	  warns (_("unknown character: %s"), printable_version(c));
+	  skip_to_char('%');
 	}
     }
 }
@@ -1156,39 +1171,43 @@ copy_guard (symbol_list *rule, int stack_offset)
 	      fprintf(fguard, "yyvsp[%d]", n - stack_offset);
 	      if (type_name)
 		fprintf(fguard, ".%s", type_name);
-	      if(!type_name && typed)
-		warnss(_("$%s of `%s' has no declared type"), int_to_string(n), rule->sym->tag);
+	      if (!type_name && typed)
+		warnss (_("$%s of `%s' has no declared type"),
+			int_to_string(n), rule->sym->tag);
 	      continue;
 	    }
 	  else
 	    warns(_("$%s is invalid"), printable_version(c));
-
 	  break;
 
 	case '@':
-	  c = getc(finput);
-	  if (isdigit(c) || c == '-')
+	  c = getc (finput);
+	  if (c == '$')
+	    {
+	      fprintf (fguard, "yyloc");
+	      yylsp_needed = 1;
+	    }
+	  else if (isdigit(c) || c == '-')
 	    {
 	      ungetc (c, finput);
-	      n = read_signed_integer(finput);
-	      c = getc(finput);
+	      n = read_signed_integer (finput);
+	      c = getc (finput);
+	      fprintf (fguard, "yylsp[%d]", n - stack_offset);
+	      yylsp_needed = 1;
+	      continue;
 	    }
 	  else
 	    {
-	      warns(_("@%s is invalid"), printable_version(c));
+	      warns (_("@%s is invalid"), printable_version (c));
 	      n = 1;
 	    }
-
-	  fprintf(fguard, "yylsp[%d]", n - stack_offset);
-	  yylsp_needed = 1;
-
-	  continue;
+	  break;
 
 	case EOF:
-	  fatal(_("unterminated %%guard clause"));
+	  fatal (_("unterminated %%guard clause"));
 
 	default:
-	  putc(c, fguard);
+	  putc (c, fguard);
 	}
 
       if (c != '}' || count != 0)
@@ -1394,23 +1413,27 @@ copy_action (symbol_list *rule, int stack_offset)
 	      break;
 
 	    case '@':
-	      c = getc(finput);
-	      if (isdigit(c) || c == '-')
+	      c = getc (finput);
+	      if (c == '$')
+		{
+		  fprintf (faction, "yyloc");
+		  yylsp_needed = 1;
+		}
+	      else if (isdigit(c) || c == '-')
 		{
 		  ungetc (c, finput);
-		  n = read_signed_integer(finput);
-		  c = getc(finput);
+		  n = read_signed_integer (finput);
+		  c = getc (finput);
+		  fprintf (faction, "yylsp[%d]", n - stack_offset);
+		  yylsp_needed = 1;
+		  continue;
 		}
 	      else
 		{
-		  warn(_("invalid @-construct"));
+		  warns (_("@%s is invalid"), printable_version (c));
 		  n = 1;
 		}
-
-	      fprintf(faction, "yylsp[%d]", n - stack_offset);
-	      yylsp_needed = 1;
-
-	      continue;
+	      break;
 
 	    case EOF:
 	      fatal(_("unmatched `{'"));
@@ -1651,21 +1674,25 @@ readgram (void)
 	  else if (t == LEFT_CURLY)
 	    {
 		/* This case never occurs -wjh */
-	      if (actionflag)  warn(_("two actions at end of one rule"));
+	      if (actionflag)
+		warn(_("two actions at end of one rule"));
 	      copy_action(crule, rulelength);
 	      actionflag = 1;
 	      xactions++;	/* -wjh */
 	      t = lex();
 	    }
-	  /* If $$ is being set in default way,
-	     warn if any type mismatch.  */
-	  else if (!xactions && first_rhs && lhs->type_name != first_rhs->type_name)
+	  /* If $$ is being set in default way, warn if any type
+	     mismatch.  */
+	  else if (!xactions
+		   && first_rhs
+		   && lhs->type_name != first_rhs->type_name)
 	    {
-	      if (lhs->type_name == 0 || first_rhs->type_name == 0
+	      if (lhs->type_name == 0
+		  || first_rhs->type_name == 0
 		  || strcmp(lhs->type_name,first_rhs->type_name))
 		warnss(_("type clash (`%s' `%s') on default action"),
-			lhs->type_name ? lhs->type_name : "",
-			first_rhs->type_name ? first_rhs->type_name : "");
+		       lhs->type_name ? lhs->type_name : "",
+		       first_rhs->type_name ? first_rhs->type_name : "");
 	    }
 	  /* Warn if there is no default for $$ but we need one.  */
 	  else if (!xactions && !first_rhs && lhs->type_name != 0)
