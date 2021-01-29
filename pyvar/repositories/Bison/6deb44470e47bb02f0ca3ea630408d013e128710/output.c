@@ -223,10 +223,18 @@ register YYLTYPE *yylsp;\n\
 void
 output_headers (void)
 {
-  char *attrsfile_quoted = quotearg_style (c_quoting_style, attrsfile);
+  char *attrsfile_quoted = 0;
 
   if (semantic_parser)
-    obstack_fgrow1 (&guard_obstack, GUARDSTR, attrsfile_quoted);
+    {
+      /* FIXME: This is *buggy*.  ATTRSFILE is not computed yet, since
+	 we are waiting for the full input file to have been read to
+	 be sure of the output file name.  So basically, here, a SEGV
+	 is guaranteed.  OTOH, currently semantic parsers are not
+	 supported.  */
+      attrsfile_quoted = quotearg_style (c_quoting_style, attrsfile);
+      obstack_fgrow1 (&guard_obstack, GUARDSTR, attrsfile_quoted);
+    }
 
   if (no_parser_flag)
     return;
