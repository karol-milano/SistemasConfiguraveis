@@ -332,6 +332,28 @@ get_type_name (int n, symbol_list *rule)
   return rp->sym->type_name;
 }
 
+/*------------------------------------------------------------------.
+| Copy the character C to OOUT, and insert quadigraphs when needed. |
+`------------------------------------------------------------------*/
+
+static inline void
+copy_character (struct obstack *oout, int c)
+{
+  switch (c)
+    {
+    case '[':
+      obstack_sgrow (oout, "@<:@");
+      break;
+
+    case ']':
+      obstack_sgrow (oout, "@:>@");
+      break;
+
+    default:
+      obstack_1grow (oout, c);
+    }
+}
+
 /*------------------------------------------------------------.
 | Dump the string from FIN to OOUT if non null.  MATCH is the |
 | delimiter of the string (either ' or ").                    |
@@ -359,14 +381,14 @@ copy_string2 (FILE *fin, struct obstack *oout, int match, int store)
 	  continue;
 	}
 
-      obstack_1grow (oout, c);
+      copy_character (oout, c);
 
       if (c == '\\')
 	{
 	  c = getc (fin);
 	  if (c == EOF)
 	    fatal (_("unterminated string at end of file"));
-	  obstack_1grow (oout, c);
+	  copy_character (oout, c);
 
 	  if (c == '\n')
 	    ++lineno;
@@ -463,7 +485,7 @@ copy_comment (FILE *fin, struct obstack *oout)
 	fatal (_("unterminated comment"));
       else
 	{
-	  obstack_1grow (oout, c);
+	  copy_character (oout, c);
 	  c = getc (fin);
 	}
     }
@@ -634,7 +656,7 @@ copy_definition (struct obstack *oout)
 	  fatal ("%s", _("unterminated `%{' definition"));
 
 	default:
-	  obstack_1grow (oout, c);
+	  copy_character (oout, c);
 	}
 
       c = getc (finput);
@@ -1666,7 +1688,7 @@ read_additionnal_code (void)
     }
 
   while ((c = getc (finput)) != EOF)
-    obstack_1grow (&el_obstack, c);
+    copy_character (&el_obstack, c);
 
   obstack_1grow (&el_obstack, 0);
   muscle_insert ("epilogue", obstack_finish (&el_obstack));
