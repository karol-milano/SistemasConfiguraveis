@@ -976,6 +976,36 @@ parse_expect_decl (void)
 
 /* that's all of parsing the declaration section */
 
+/* FINPUT is pointing to a location (i.e., a `@').  Output to FOUTPUT
+   a reference to this location. STACK_OFFSET is the number of values
+   in the current rule so far, which says where to find `$0' with
+   respect to the top of the stack.  */
+static inline void
+copy_at (FILE *finput, FILE *foutput, int stack_offset)
+{
+  int c;
+
+  c = getc (finput);
+  if (c == '$')
+    {
+      fprintf (foutput, "yyloc");
+      yylsp_needed = 1;
+    }
+  else if (isdigit(c) || c == '-')
+    {
+      int n;
+
+      ungetc (c, finput);
+      n = read_signed_integer (finput);
+
+      fprintf (foutput, "yylsp[%d]", n - stack_offset);
+      yylsp_needed = 1;
+    }
+  else
+    warns (_("@%s is invalid"), printable_version (c));
+}
+
+
 /* Get the data type (alternative in the union) of the value for symbol n in rule rule.  */
 
 char *
@@ -1130,26 +1160,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 	  break;
 
 	case '@':
-	  c = getc (finput);
-	  if (c == '$')
-	    {
-	      fprintf (fguard, "yyloc");
-	      yylsp_needed = 1;
-	    }
-	  else if (isdigit(c) || c == '-')
-	    {
-	      ungetc (c, finput);
-	      n = read_signed_integer (finput);
-	      c = getc (finput);
-	      fprintf (fguard, "yylsp[%d]", n - stack_offset);
-	      yylsp_needed = 1;
-	      continue;
-	    }
-	  else
-	    {
-	      warns (_("@%s is invalid"), printable_version (c));
-	      n = 1;
-	    }
+	  copy_at (finput, fguard, stack_offset);
 	  break;
 
 	case EOF:
@@ -1167,12 +1178,12 @@ copy_guard (symbol_list *rule, int stack_offset)
 
   fprintf(fguard, ";\n    break;}");
   if (c == '{')
-    copy_action(rule, stack_offset);
+    copy_action (rule, stack_offset);
   else if (c == '=')
     {
       c = getc(finput);	/* why not skip_white_space -wjh */
       if (c == '{')
-	copy_action(rule, stack_offset);
+	copy_action (rule, stack_offset);
     }
   else
     ungetc(c, finput);
@@ -1289,26 +1300,7 @@ copy_action (symbol_list *rule, int stack_offset)
 	      break;
 
 	    case '@':
-	      c = getc (finput);
-	      if (c == '$')
-		{
-		  fprintf (faction, "yyloc");
-		  yylsp_needed = 1;
-		}
-	      else if (isdigit(c) || c == '-')
-		{
-		  ungetc (c, finput);
-		  n = read_signed_integer (finput);
-		  c = getc (finput);
-		  fprintf (faction, "yylsp[%d]", n - stack_offset);
-		  yylsp_needed = 1;
-		  continue;
-		}
-	      else
-		{
-		  warns (_("@%s is invalid"), printable_version (c));
-		  n = 1;
-		}
+	      copy_at (finput, faction, stack_offset);
 	      break;
 
 	    case EOF:
