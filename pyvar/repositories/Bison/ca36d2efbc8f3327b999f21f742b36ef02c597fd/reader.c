@@ -989,6 +989,47 @@ get_type_name (int n, symbol_list *rule)
 }
 
 
+/* Dump the string from FINPUT to FOUTPUT.  MATCH is the delimiter of
+   the string (either ' or ").  */
+
+void
+copy_string (FILE *finput, FILE *foutput, int match)
+{
+  int c;
+
+  putc (match, foutput);
+  c = getc (finput);
+
+  while (c != match)
+    {
+      if (c == EOF)
+	fatal(_("unterminated string at end of file"));
+      if (c == '\n')
+	{
+	  warn (_("unterminated string"));
+	  ungetc (c, finput);
+	  c = match;		/* invent terminator */
+	  continue;
+	}
+
+      putc(c, foutput);
+
+      if (c == '\\')
+	{
+	  c = getc (finput);
+	  if (c == EOF)
+	    fatal (_("unterminated string"));
+	  putc (c, foutput);
+	  if (c == '\n')
+	    lineno++;
+	}
+
+      c = getc(finput);
+    }
+
+  putc(c, foutput);
+}
+
 /* After `%guard' is seen in the input file, copy the actual guard
    into the guards file.  If the guard is followed by an action, copy
    that into the actions file.  STACK_OFFSET is the number of values
@@ -1047,38 +1088,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 
 	case '\'':
 	case '"':
-	  match = c;
-	  putc(c, fguard);
-	  c = getc(finput);
-
-	  while (c != match)
-	    {
-	      if (c == EOF)
-		fatal(_("unterminated string at end of file"));
-	      if (c == '\n')
-		{
-		  warn(_("unterminated string"));
-		  ungetc(c, finput);
-		  c = match;		/* invent terminator */
-		  continue;
-		}
-
-	      putc(c, fguard);
-
-	      if (c == '\\')
-		{
-		  c = getc(finput);
-		  if (c == EOF)
-		    fatal(_("unterminated string"));
-		  putc(c, fguard);
-		  if (c == '\n')
-		    lineno++;
-		}
-
-	      c = getc(finput);
-	    }
-
-	  putc(c, fguard);
+	  copy_string (finput, fguard, c);
 	  break;
 
 	case '/':
@@ -1277,38 +1287,7 @@ copy_action (symbol_list *rule, int stack_offset)
 
 	    case '\'':
 	    case '"':
-	      match = c;
-	      putc(c, faction);
-	      c = getc(finput);
-
-	      while (c != match)
-		{
-		  if (c == '\n')
-		    {
-		      warn(_("unterminated string"));
-		      ungetc(c, finput);
-		      c = match;
-		      continue;
-		    }
-		  else if (c == EOF)
-		    fatal(_("unterminated string at end of file"));
-
-		  putc(c, faction);
-
-		  if (c == '\\')
-		    {
-		      c = getc(finput);
-		      if (c == EOF)
-			fatal(_("unterminated string"));
-		      putc(c, faction);
-		      if (c == '\n')
-			lineno++;
-		    }
-
-		  c = getc(finput);
-		}
-
-	      putc(c, faction);
+	      copy_string (finput, faction, c);
 	      break;
 
 	    case '/':
