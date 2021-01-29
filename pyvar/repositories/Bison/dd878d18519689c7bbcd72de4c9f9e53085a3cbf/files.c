@@ -25,6 +25,8 @@
 #include <dirname.h>
 #include <error.h>
 #include <get-errno.h>
+#include <gl_array_list.h>
+#include <gl_xlist.h>
 #include <quote.h>
 #include <quotearg.h>
 #include <relocatable.h> /* relocate2 */
@@ -55,6 +57,7 @@ char *spec_verbose_file = NULL;  /* for --verbose. */
 char *spec_graph_file = NULL;    /* for -g. */
 char *spec_xml_file = NULL;      /* for -x. */
 char *spec_header_file = NULL;  /* for --defines. */
+char *spec_mapped_header_file = NULL;
 char *parser_file_name;
 
 /* All computed output file names.  */
@@ -91,11 +94,20 @@ uniqstr grammar_file = NULL;
 char *all_but_ext;
 static char *all_but_tab_ext;
 char *dir_prefix;
+char *mapped_dir_prefix;
 
 /* C source file extension (the parser source).  */
 static char *src_extension = NULL;
 /* Header file extension (if option '`-d'' is specified).  */
 static char *header_extension = NULL;
+
+struct prefix_map
+{
+  char *oldprefix;
+  char *newprefix;
+};
+
+static gl_list_t prefix_maps = NULL;
 
 /*-----------------------------------------------------------------.
 | Return a newly allocated string composed of the concatenation of |
@@ -159,6 +171,70 @@ xfdopen (int fd, char const *mode)
   return res;
 }
 
+/*  Given an input file path, returns a dynamically allocated string that
+    contains the path with the file prefix mapping rules applied, or NULL if
+    the input was NULL. */
+char *
+map_file_name (char const *filename)
+{
+  if (!filename)
+    return NULL;
+
+  struct prefix_map const *p = NULL;
+  if (prefix_maps)
+    {
+      void const *ptr;
+      gl_list_iterator_t iter = gl_list_iterator (prefix_maps);
+      while (gl_list_iterator_next (&iter, &ptr, NULL))
+        {
+          p = ptr;
+          if (strncmp (p->oldprefix, filename, strlen (p->oldprefix)) == 0)
+            break;
+          p = NULL;
+        }
+      gl_list_iterator_free (&iter);
+    }
+
+  if (!p)
+    return xstrdup (filename);
+
+  size_t oldprefix_len = strlen (p->oldprefix);
+  size_t newprefix_len = strlen (p->newprefix);
+  char *s = xmalloc (newprefix_len + strlen (filename) - oldprefix_len + 1);
+
+  char *end = stpcpy (s, p->newprefix);
+  stpcpy (end, filename + oldprefix_len);
+
+  return s;
+}
+
+static void
+prefix_map_free (struct prefix_map *p)
+{
+  free (p->oldprefix);
+  free (p->newprefix);
+  free (p);
+}
+
+/*  Adds a new file prefix mapping. If a file path starts with oldprefix, it
+    will be replaced with newprefix */
+void
+add_prefix_map(char const* oldprefix, char const* newprefix)
+{
+  if (!prefix_maps)
+    prefix_maps = gl_list_create_empty (GL_ARRAY_LIST,
+                                        /* equals */ NULL,
+                                        /* hashcode */ NULL,
+                                        (gl_listelement_dispose_fn) prefix_map_free,
+                                        true);
+
+  struct prefix_map *p = xmalloc (sizeof (*p));
+  p->oldprefix = xstrdup (oldprefix);
+  p->newprefix = xstrdup (newprefix);
+
+  gl_list_add_last (prefix_maps, p);
+}
+
 /*------------------------------------------------------------------.
 | Compute ALL_BUT_EXT, ALL_BUT_TAB_EXT and output files extensions. |
 `------------------------------------------------------------------*/
@@ -363,6 +439,9 @@ compute_output_file_names (void)
       output_file_name_check (&spec_verbose_file, false);
     }
 
+  spec_mapped_header_file = map_file_name (spec_header_file);
+  mapped_dir_prefix = map_file_name (dir_prefix);
+
   free (all_but_tab_ext);
   free (src_extension);
   free (header_extension);
@@ -449,10 +528,15 @@ output_file_names_free (void)
   free (spec_graph_file);
   free (spec_xml_file);
   free (spec_header_file);
+  free (spec_mapped_header_file);
   free (parser_file_name);
   free (dir_prefix);
+  free (mapped_dir_prefix);
   for (int i = 0; i < generated_files_size; i++)
     free (generated_files[i].name);
   free (generated_files);
   free (relocate_buffer);
+
+  if (prefix_maps)
+    gl_list_free (prefix_maps);
 }
