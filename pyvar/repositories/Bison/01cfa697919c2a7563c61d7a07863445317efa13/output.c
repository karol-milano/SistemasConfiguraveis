@@ -136,7 +136,7 @@ prepare_symbols (void)
 	const char *cp =
 	  quotearg_n_style (1, c_quoting_style,
 			    symbols[i]->tag);
-	/* Width of the next token, including the two quotes, the coma
+	/* Width of the next token, including the two quotes, the comma
 	   and the space.  */
 	int strsize = strlen (cp) + 2;
 
@@ -146,7 +146,14 @@ prepare_symbols (void)
 	    j = 2;
 	  }
 
-	obstack_sgrow (&format_obstack, cp);
+	for (; *cp; cp++)
+	  switch (*cp)
+	    {
+	    case '[': obstack_sgrow (&format_obstack, "@<:@"); break;
+	    case ']': obstack_sgrow (&format_obstack, "@:>@"); break;
+	    default: obstack_1grow (&format_obstack, *cp); break;
+	    }
+
 	obstack_sgrow (&format_obstack, ", ");
 	j += strsize;
       }
