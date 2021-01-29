@@ -367,9 +367,9 @@ token_definitions_output (FILE *out)
 
       /* Don't #define nonliteral tokens whose names contain periods,
          dashes or '$' (as does the default value of the EOF token).  */
-      if (strchr (sym->tag, '.')
-          || strchr (sym->tag, '-')
-          || strchr (sym->tag, '$'))
+      if (mbschr (sym->tag, '.')
+          || mbschr (sym->tag, '-')
+          || mbschr (sym->tag, '$'))
 	continue;
 
       fprintf (out, "%s[[[%s]], %d]",
@@ -518,7 +518,7 @@ output_skeleton (void)
   full_m4sugar = xstrdup (full_skeleton);
   strcpy (full_skeleton + pkgdatadirlen + 1, m4bison);
   full_m4bison = xstrdup (full_skeleton);
-  if (strchr (skeleton, '/'))
+  if (mbschr (skeleton, '/'))
     strcpy (full_skeleton, skeleton);
   else
     strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
