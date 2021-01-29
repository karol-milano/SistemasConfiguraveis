@@ -34,7 +34,7 @@
 #include "getargs.h"
 #include "gram.h"
 
-/* Initializing some values below (such SPEC_NAME_PREFIX to `yy') is
+/* Initializing some values below (such SPEC_NAME_PREFIX to 'yy') is
    tempting, but don't do that: for the time being our handling of the
    %directive vs --option leaves precedence to the options by deciding
    that if a %directive sets a variable which is really set (i.e., not
@@ -58,20 +58,20 @@ uniqstr grammar_file = NULL;
 uniqstr current_file = NULL;
 
 /* If --output=dir/foo.c was specified,
-   DIR_PREFIX is `dir/' and ALL_BUT_EXT and ALL_BUT_TAB_EXT are `dir/foo'.
+   DIR_PREFIX is 'dir/' and ALL_BUT_EXT and ALL_BUT_TAB_EXT are 'dir/foo'.
 
-   If --output=dir/foo.tab.c was specified, DIR_PREFIX is `dir/',
-   ALL_BUT_EXT is `dir/foo.tab', and ALL_BUT_TAB_EXT is `dir/foo'.
+   If --output=dir/foo.tab.c was specified, DIR_PREFIX is 'dir/',
+   ALL_BUT_EXT is 'dir/foo.tab', and ALL_BUT_TAB_EXT is 'dir/foo'.
 
    If --output was not specified but --file-prefix=dir/foo was specified,
-   ALL_BUT_EXT = `foo.tab' and ALL_BUT_TAB_EXT = `foo'.
+   ALL_BUT_EXT = 'foo.tab' and ALL_BUT_TAB_EXT = 'foo'.
 
    If neither --output nor --file was specified but the input grammar
-   is name dir/foo.y, ALL_BUT_EXT and ALL_BUT_TAB_EXT are `foo'.
+   is name dir/foo.y, ALL_BUT_EXT and ALL_BUT_TAB_EXT are 'foo'.
 
    If neither --output nor --file was specified, DIR_PREFIX is the
    empty string (meaning the current directory); otherwise it is
-   `dir/'.  */
+   'dir/'.  */
 
 char *all_but_ext;
 static char *all_but_tab_ext;
@@ -79,7 +79,7 @@ char *dir_prefix;
 
 /* C source file extension (the parser source).  */
 static char *src_extension = NULL;
-/* Header file extension (if option ``-d'' is specified).  */
+/* Header file extension (if option '`-d'' is specified).  */
 static char *header_extension = NULL;
 
 /*-----------------------------------------------------------------.
@@ -191,7 +191,7 @@ compute_exts_from_src (const char *ext)
    *EXT points to the last period in the basename, or NULL if none.
 
    If there is no *EXT, *TAB is NULL.  Otherwise, *TAB points to
-   `.tab' or `_tab' if present right before *EXT, or is NULL. *TAB
+   '.tab' or '_tab' if present right before *EXT, or is NULL. *TAB
    cannot be equal to *BASE.
 
    None are allocated, they are simply pointers to parts of FILE_NAME.
@@ -222,7 +222,7 @@ file_name_split (const char *file_name,
   *ext = strrchr (*base, '.');
   *tab = NULL;
 
-  /* If there is an extension, check if there is a `.tab' part right
+  /* If there is an extension, check if there is a '.tab' part right
      before.  */
   if (*ext)
     {
@@ -270,7 +270,7 @@ compute_file_name_parts (void)
 
       if (spec_file_prefix)
         {
-          /* If --file-prefix=foo was specified, ALL_BUT_TAB_EXT = `foo'.  */
+          /* If --file-prefix=foo was specified, ALL_BUT_TAB_EXT = 'foo'.  */
           dir_prefix =
             xstrndup (spec_file_prefix,
                       last_component (spec_file_prefix) - spec_file_prefix);
@@ -278,14 +278,14 @@ compute_file_name_parts (void)
         }
       else if (yacc_flag)
         {
-          /* If --yacc, then the output is `y.tab.c'.  */
+          /* If --yacc, then the output is 'y.tab.c'.  */
           dir_prefix = xstrdup ("");
           all_but_tab_ext = xstrdup ("y");
         }
       else
         {
           /* Otherwise, ALL_BUT_TAB_EXT is computed from the input
-             grammar: `foo/bar.yy' => `bar'.  */
+             grammar: 'foo/bar.yy' => 'bar'.  */
           dir_prefix = xstrdup ("");
           all_but_tab_ext =
             xstrndup (base, (strlen (base) - (ext ? strlen (ext) : 0)));
