@@ -40,6 +40,7 @@
 
 bool header_flag = false;
 bool graph_flag = false;
+bool html_flag = false;
 bool xml_flag = false;
 bool no_lines_flag = false;
 bool token_table_flag = false;
@@ -432,6 +433,7 @@ Output Files:\n\
   -b, --file-prefix=PREFIX      specify a PREFIX for output files\n\
   -o, --output=FILE             leave output to FILE\n\
   -g, --graph[=FILE]            also output a graph of the automaton\n\
+      --html[=FILE]             also output an HTML report of the automaton\n\
   -x, --xml[=FILE]              also output an XML report of the automaton\n\
   -M, --file-prefix-map=OLD=NEW replace prefix OLD with NEW when writing file paths\n\
                                 in output files\n\
@@ -572,6 +574,7 @@ enum
 {
   COLOR_OPTION = CHAR_MAX + 1,
   FIXED_OUTPUT_FILES_OPTION,
+  HTML_OPTION,
   LOCATIONS_OPTION,
   PRINT_DATADIR_OPTION,
   PRINT_LOCALEDIR_OPTION,
@@ -616,6 +619,7 @@ static struct option const long_options[] =
   { "file-prefix",     required_argument,   0,   'b' },
   { "output",          required_argument,   0,   'o' },
   { "graph",           optional_argument,   0,   'g' },
+  { "html",            optional_argument,   0,   HTML_OPTION },
   { "xml",             optional_argument,   0,   'x' },
   { "file-prefix-map", required_argument,   0,   'M' },
 
@@ -839,6 +843,16 @@ getargs (int argc, char *argv[])
         /* Handled in getargs_colors. */
         break;
 
+      case HTML_OPTION:
+        html_flag = true;
+        xml_flag = true;
+        if (optarg)
+          {
+            free (spec_html_file);
+            spec_html_file = xstrdup (optarg);
+          }
+        break;
+
       case FIXED_OUTPUT_FILES_OPTION:
         complain (&loc, Wdeprecated,
                   _("deprecated option: %s, use %s"),
