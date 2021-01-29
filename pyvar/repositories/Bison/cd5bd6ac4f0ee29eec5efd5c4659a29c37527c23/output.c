@@ -1154,17 +1154,19 @@ output_parser (void)
   int c;
   FILE *fskel;
   size_t line;
-  const char *skeleton = NULL;
   int actions_dumped = 0;
 
   if (pure_parser)
     obstack_sgrow (&table_obstack, "#define YYPURE 1\n\n");
 
   /* Loop over lines in the standard parser file.  */
-  if (semantic_parser)
-    skeleton = skeleton_find ("BISON_HAIRY", BISON_HAIRY);
-  else
-    skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
+  if (!skeleton)
+    {
+      if (semantic_parser)
+	skeleton = skeleton_find ("BISON_HAIRY", BISON_HAIRY);
+      else
+	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
+    }
   fskel = xfopen (skeleton, "r");
 
   /* Set LINE to 2, not 1: `#line LINENUM' -- Here LINENUM is a
