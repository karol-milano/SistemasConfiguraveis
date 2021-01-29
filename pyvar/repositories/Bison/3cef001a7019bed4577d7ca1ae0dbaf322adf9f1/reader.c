@@ -1030,6 +1030,57 @@ copy_string (FILE *finput, FILE *foutput, int match)
   putc(c, foutput);
 }
 
+
+/* Dump the comment from FINPUT to FOUTPUT.  C is either `*' or `/',
+   depending upon the type of comments used.  */
+
+void
+copy_comment (FILE *finput, FILE *foutput, int c)
+{
+  int cplus_comment;
+  register int match;
+  register int ended;
+
+  cplus_comment = (c == '/');
+  putc (c, foutput);
+  c = getc (finput);
+
+  ended = 0;
+  while (!ended)
+    {
+      if (!cplus_comment && c == '*')
+	{
+	  while (c == '*')
+	    {
+	      putc(c, foutput);
+	      c = getc(finput);
+	    }
+
+	  if (c == '/')
+	    {
+	      putc(c, foutput);
+	      ended = 1;
+	    }
+	}
+      else if (c == '\n')
+	{
+	  lineno++;
+	  putc (c, foutput);
+	  if (cplus_comment)
+	    ended = 1;
+	  else
+	    c = getc(finput);
+	}
+      else if (c == EOF)
+	fatal (_("unterminated comment"));
+      else
+	{
+	  putc (c, foutput);
+	  c = getc (finput);
+	}
+    }
+}
+
 /* After `%guard' is seen in the input file, copy the actual guard
    into the guards file.  If the guard is followed by an action, copy
    that into the actions file.  STACK_OFFSET is the number of values
@@ -1043,11 +1094,8 @@ copy_guard (symbol_list *rule, int stack_offset)
   register int c;
   register int n;
   register int count;
-  register int match;
-  register int ended;
   register char *type_name;
   int brace_flag = 0;
-  int cplus_comment;
 
   /* offset is always 0 if parser has already popped the stack pointer */
   if (semantic_parser) stack_offset = 0;
@@ -1092,50 +1140,11 @@ copy_guard (symbol_list *rule, int stack_offset)
 	  break;
 
 	case '/':
-	  putc(c, fguard);
-	  c = getc(finput);
+	  putc (c, fguard);
+	  c = getc (finput);
 	  if (c != '*' && c != '/')
 	    continue;
-
-	  cplus_comment = (c == '/');
-	  putc(c, fguard);
-	  c = getc(finput);
-
-	  ended = 0;
-	  while (!ended)
-	    {
-	      if (!cplus_comment && c == '*')
-		{
-		  while (c == '*')
-		    {
-		      putc(c, fguard);
-		      c = getc(finput);
-		    }
-
-		  if (c == '/')
-		    {
-		      putc(c, fguard);
-		      ended = 1;
-		    }
-		}
-	      else if (c == '\n')
-		{
-		  lineno++;
-		  putc(c, fguard);
-		  if (cplus_comment)
-		    ended = 1;
-		  else
-		    c = getc(finput);
-		}
-	      else if (c == EOF)
-		fatal(_("unterminated comment"));
-	      else
-		{
-		  putc(c, fguard);
-		  c = getc(finput);
-		}
-	    }
-
+	  copy_comment (finput, fguard, c);
 	  break;
 
 	case '$':
@@ -1252,10 +1261,7 @@ copy_action (symbol_list *rule, int stack_offset)
   register int c;
   register int n;
   register int count;
-  register int match;
-  register int ended;
   register char *type_name;
-  int cplus_comment;
 
   /* offset is always 0 if parser has already popped the stack pointer */
   if (semantic_parser)
@@ -1295,46 +1301,7 @@ copy_action (symbol_list *rule, int stack_offset)
 	      c = getc(finput);
 	      if (c != '*' && c != '/')
 		continue;
-
-	      cplus_comment = (c == '/');
-	      putc(c, faction);
-	      c = getc(finput);
-
-	      ended = 0;
-	      while (!ended)
-		{
-		  if (!cplus_comment && c == '*')
-		    {
-		      while (c == '*')
-		        {
-			  putc(c, faction);
-			  c = getc(finput);
-			}
-
-		      if (c == '/')
-			{
-			  putc(c, faction);
-			  ended = 1;
-			}
-		    }
-		  else if (c == '\n')
-		    {
-		      lineno++;
-		      putc(c, faction);
-		      if (cplus_comment)
-			ended = 1;
-		      else
-		        c = getc(finput);
-		    }
-		  else if (c == EOF)
-		    fatal(_("unterminated comment"));
-		  else
-		    {
-		      putc(c, faction);
-		      c = getc(finput);
-		    }
-		}
-
+	      copy_comment (finput, faction, c);
 	      break;
 
 	    case '$':
