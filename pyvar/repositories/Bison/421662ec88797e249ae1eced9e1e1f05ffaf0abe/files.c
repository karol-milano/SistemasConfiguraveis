@@ -76,7 +76,7 @@ static int generated_files_size = 0;
 uniqstr grammar_file = NULL;
 
 /* If --output=dir/foo.c was specified,
-   DIR_PREFIX is 'dir/' and ALL_BUT_EXT and ALL_BUT_TAB_EXT are 'dir/foo'.
+   DIR_PREFIX gis 'dir/' and ALL_BUT_EXT and ALL_BUT_TAB_EXT are 'dir/foo'.
 
    If --output=dir/foo.tab.c was specified, DIR_PREFIX is 'dir/',
    ALL_BUT_EXT is 'dir/foo.tab', and ALL_BUT_TAB_EXT is 'dir/foo'.
@@ -219,7 +219,7 @@ prefix_map_free (struct prefix_map *p)
 /*  Adds a new file prefix mapping. If a file path starts with oldprefix, it
     will be replaced with newprefix */
 void
-add_prefix_map(char const* oldprefix, char const* newprefix)
+add_prefix_map (char const *oldprefix, char const *newprefix)
 {
   if (!prefix_maps)
     prefix_maps = gl_list_create_empty (GL_ARRAY_LIST,
