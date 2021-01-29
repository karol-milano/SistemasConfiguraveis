@@ -2024,17 +2024,18 @@ add_param (char const *type, char *decl, location loc)
   char const *name_start = NULL;
   char *p;
 
-  for (p = decl; *p; p++)
+  for (p = decl; p[1]; p++)
     if ((p == decl
 	 || ! memchr (alphanum, p[-1], sizeof alphanum))
 	&& memchr (alphanum, p[0], sizeof alphanum - 10))
       name_start = p;
-
+  fprintf (stderr, "DECLI: {%s}(%c)\n", decl, *p);
   /* Strip the surrounding '{' and '}', and any blanks just inside
      the braces.  */
   while (*--p == ' ' || *p == '\t')
     continue;
-  *p = '\0';
+  p[1] = '\0';
+  fprintf (stderr, "DECLO: {%s}\n", decl);
   while (*++decl == ' ' || *decl == '\t')
     continue;
 
