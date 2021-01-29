@@ -882,16 +882,11 @@ static void
 parse_header_extension_decl (void)
 {
   char buff[32];
-  int len;
-  
+
   if (header_extension)
     complain (_("multiple %%header_extension declarations"));
   fscanf (finput, "%s", buff);
-  printf("-> %s\n", buff);
-  len = strlen (buff);
-  buff[len] = '\0';
-  src_extension = XMALLOC (char, len + 1);
-  stpcpy (header_extension, buff);
+  header_extension = xstrdup (buff);
 }
 
 /*------------------------------------------.
@@ -902,16 +897,11 @@ static void
 parse_source_extension_decl (void)
 {
   char buff[32];
-  int len;
-  
+
   if (src_extension)
     complain (_("multiple %%source_extension declarations"));
   fscanf (finput, "%s", buff);
-  printf("-> %s\n", buff);
-  len = strlen (buff);
-  buff[len] = '\0';
-  src_extension = XMALLOC (char, len + 1);
-  stpcpy (src_extension, buff);
+  src_extension = xstrdup (buff);
 }
 
 /*----------------------------------------------------------------.
