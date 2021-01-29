@@ -234,22 +234,14 @@ output_rule_data (void)
 
   j = 0;
   for (i = 0; i < nsyms; i++)
-    /* this used to be i<=nsyms, but that output a final "" symbol
-       almost by accident */
     {
+      /* Be sure not to use twice the same quotearg slot. */
+      const char *cp =
+	quotearg_n_style (1, c_quoting_style,
+			  quotearg_style (escape_quoting_style, tags[i]));
       /* Width of the next token, including the two quotes, the coma
 	 and the space.  */
-      int strsize = 4;
-      char *p;
-
-      for (p = tags[i]; p && *p; p++)
-	if (*p == '"' || *p == '\\' || *p == '\n' || *p == '\t'
-	    || *p == '\b')
-	  strsize += 2;
-	else if (*p < 040 || *p >= 0177)
-	  strsize += 4;
-	else
-	  strsize++;
+      int strsize = strlen (cp) + 2;
 
       if (j + strsize > 75)
 	{
@@ -257,24 +249,8 @@ output_rule_data (void)
 	  j = 2;
 	}
 
-      obstack_1grow (&output_obstack, '\"');
-      for (p = tags[i]; p && *p; p++)
-	{
-	  if (*p == '"' || *p == '\\')
-	    obstack_fgrow1 (&output_obstack, "\\%c", *p);
-	  else if (*p == '\n')
-	    obstack_sgrow (&output_obstack, "\\n");
-	  else if (*p == '\t')
-	    obstack_sgrow (&output_obstack, "\\t");
-	  else if (*p == '\b')
-	    obstack_sgrow (&output_obstack, "\\b");
-	  else if (*p < 040 || *p >= 0177)
-	    obstack_fgrow1 (&output_obstack, "\\%03o", *p);
-	  else
-	    obstack_1grow (&output_obstack, *p);
-	}
-
-      obstack_sgrow (&output_obstack, "\", ");
+      obstack_sgrow (&output_obstack, cp);
+      obstack_sgrow (&output_obstack, ", ");
       j += strsize;
     }
   /* add a NULL entry to list of tokens */
