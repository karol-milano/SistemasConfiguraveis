@@ -99,49 +99,6 @@ stringappend (const char *string1, const char *string2)
   return res;
 }
 
-
-/*-----------------------------------------------------------------.
-| Computes the macro name used to avoid double inclusion in the    |
-| header of the parser and store it in header_macro_name.  Be sure |
-| to produce valid CPP names (don't start with digit, remain       |
-| alphanumerical + underscore).                                    |
-`-----------------------------------------------------------------*/
-
-char *
-compute_header_macro (void)
-{
-  const char *prefix = "BISON_";
-  char *macro_name, *cp;
-
-  if (spec_defines_file)
-    {
-      macro_name = XMALLOC (char,
-			    strlen (prefix) +
-			    strlen (spec_defines_file) + 1);
-      cp = stpcpy (macro_name, prefix);
-      cp = stpcpy (cp, spec_defines_file);
-    }
-  else
-    {
-      macro_name = XMALLOC (char,
-			    strlen (prefix) +
-			    strlen (full_base_name) +
-			    strlen (header_extension) + 1);
-      cp = stpcpy (macro_name, prefix);
-      cp = stpcpy (cp, full_base_name);
-      cp = stpcpy (cp, header_extension);
-    }
-
-  for (cp = macro_name; *cp; ++cp)
-    if (islower (*cp))
-      *cp = toupper (*cp);
-    else if (!isalnum (*cp))
-      *cp = '_';
-
-  return macro_name;
-}
-
-
 /*-----------------------------------------------------------------.
 | Try to open file NAME with mode MODE, and print an error message |
 | if fails.                                                        |
