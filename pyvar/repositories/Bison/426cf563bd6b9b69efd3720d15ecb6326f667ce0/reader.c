@@ -964,6 +964,52 @@ parse_muscle_decl (void)
 }
 
 
+
+/*---------------------------------.
+| Parse a double quoted parameter. |       
+`---------------------------------*/
+
+static const char *
+parse_dquoted_param (const char *from)
+{
+  struct obstack param_obstack;
+  const char *param = NULL;
+  int c;
+
+  obstack_init (&param_obstack);
+  c = skip_white_space ();
+
+  if (c != '"')
+    {
+      complain (_("invalid %s declaration"), from);
+      ungetc (c, finput);
+      skip_to_char ('%');
+      return NULL;
+    }
+
+  for (;;)
+    {
+      if (literalchar (NULL, &c, '\"'))
+	obstack_1grow (&param_obstack, c);
+      else
+	break;
+    }
+  
+  obstack_1grow (&param_obstack, '\0');
+  param = obstack_finish (&param_obstack);
+
+  if (c != '"' || strlen (param) == 0)
+    {
+      complain (_("invalid %s declaration"), from);
+      if (c != '"')
+	ungetc (c, finput);
+      skip_to_char ('%');
+      return NULL;
+    }
+
+  return param;
+}
+
 /*----------------------------------.
 | Parse what comes after %skeleton. |
 `----------------------------------*/
@@ -971,7 +1017,7 @@ parse_muscle_decl (void)
 void
 parse_skel_decl (void)
 {
-  /* Complete with parse_dquoted_param () on the CVS branch 1.29.  */
+  skeleton = parse_dquoted_param ("%skeleton");
 }
 
 /*----------------------------------------------------------------.
