@@ -32,9 +32,16 @@ struct obstack action_obstack;
 struct obstack attrs_obstack;
 struct obstack output_obstack;
 
+/* Initializing some values below (such SPEC_NAME_PREFIX to `yy') is
+   tempting, but don't do that: for the time being our handling of the
+   %directive vs --option leaves precedence to the options by deciding
+   that if a %directive sets a variable which is really set (i.e., not
+   NULL), then the %directive is ignored.  As a result, %name-prefix,
+   for instance, will not be honored.  */
+
 char *spec_outfile = NULL;	/* for -o. */
 char *spec_file_prefix = NULL;	/* for -b. */
-const char *spec_name_prefix = "yy";	/* for -p. */
+const char *spec_name_prefix = NULL;	/* for -p. */
 char *spec_verbose_file = NULL;   /* for --verbose. */
 char *spec_graph_file = NULL;   /* for -g. */
 char *spec_defines_file = NULL; /* for --defines. */
