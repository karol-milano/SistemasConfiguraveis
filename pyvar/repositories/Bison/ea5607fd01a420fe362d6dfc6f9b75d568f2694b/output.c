@@ -226,7 +226,7 @@ output_headers (void)
   char *attrsfile_quoted = quotearg_style (c_quoting_style, attrsfile);
 
   if (semantic_parser)
-    fprintf (fguard, GUARDSTR, attrsfile_quoted);
+    obstack_fgrow1 (&guard_obstack, GUARDSTR, attrsfile_quoted);
 
   if (no_parser_flag)
     return;
@@ -236,11 +236,6 @@ output_headers (void)
   else
     obstack_grow_string (&action_obstack, ACTSTR_SIMPLE);
 
-/*  if (semantic_parser)	JF moved this below
-    fprintf(ftable, "#include \"%s\"\n", attrsfile);
-  fprintf(ftable, "#include <stdio.h>\n\n");
-*/
-
   /* Rename certain symbols if -p was specified.  */
   if (spec_name_prefix)
     {
@@ -270,7 +265,7 @@ void
 output_trailers (void)
 {
   if (semantic_parser)
-    fprintf (fguard, "\n    }\n}\n");
+    obstack_grow_string (&guard_obstack, "\n    }\n}\n");
 
   obstack_1grow (&action_obstack, '\n');
 
