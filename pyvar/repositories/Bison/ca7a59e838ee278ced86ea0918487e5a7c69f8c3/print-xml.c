@@ -48,7 +48,7 @@ struct escape_buf
   char *ptr;
   size_t size;
 };
-static struct escape_buf escape_bufs[2];
+static struct escape_buf escape_bufs[3];
 
 
 /*--------------------------------.
@@ -505,8 +505,12 @@ print_xml (void)
   FILE *out = xfopen (spec_xml_file, "w");
 
   fputs ("<?xml version=\"1.0\"?>\n\n", out);
-  xml_printf (out, level, "<bison-xml-report version=\"%s\">",
-	      xml_escape (VERSION));
+  xml_printf (out, level,
+              "<bison-xml-report version=\"%s\" bug-report=\"%s\""
+              " url=\"%s\">",
+              xml_escape_n (0, VERSION),
+              xml_escape_n (1, PACKAGE_BUGREPORT),
+              xml_escape_n (2, PACKAGE_URL));
 
   fputc ('\n', out);
   xml_printf (out, level + 1, "<filename>%s</filename>",
