@@ -1128,6 +1128,26 @@ yystype;\n\
   if (!pure_parser)
     fprintf (out, "\nextern YYSTYPE %slval;\n",
 	     spec_name_prefix);
+
+  if (locations_flag)
+    {
+      fputs ("\n\n", out);
+      fprintf (out, "\
+#ifndef YYLTYPE\n\
+typedef struct yyltype\n\
+{\n\
+  int first_line;\n\
+  int first_column;\n\
+  int last_line;\n\
+  int last_column;\n\
+} yyltype;\n\
+# define YYLTYPE yyltype\n\
+#endif\n");
+      if (!pure_parser)
+	fprintf (out, "\nextern YYLTYPE %slloc;\n",
+		 spec_name_prefix);
+    }
+
   if (semantic_parser)
     {
       int i;
