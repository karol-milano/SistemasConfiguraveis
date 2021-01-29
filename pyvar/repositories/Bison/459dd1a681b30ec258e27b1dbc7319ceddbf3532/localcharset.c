@@ -75,13 +75,13 @@
 /* Pointer to the contents of the charset.alias file, if it has already been
    read, else NULL.  Its format is:
    ALIAS_1 '\0' CANONICAL_1 '\0' ... ALIAS_n '\0' CANONICAL_n '\0' '\0'  */
-static char * volatile charset_aliases;
+static const char * volatile charset_aliases;
 
 /* Return a pointer to the contents of the charset.alias file.  */
 static const char *
 get_charset_aliases ()
 {
-  char *cp;
+  const char *cp;
 
   cp = charset_aliases;
   if (cp == NULL)
