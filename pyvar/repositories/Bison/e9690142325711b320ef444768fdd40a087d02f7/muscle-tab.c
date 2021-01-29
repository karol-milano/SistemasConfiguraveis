@@ -80,7 +80,7 @@ muscle_init (void)
   obstack_init (&muscle_obstack);
 
   muscle_table = hash_initialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
-				  hash_compare_muscles, muscle_entry_free);
+                                  hash_compare_muscles, muscle_entry_free);
 
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
@@ -179,7 +179,7 @@ muscle_syncline_grow (char const *key, location loc)
   char *extension = NULL;
   obstack_fgrow1 (&muscle_obstack, "]b4_syncline(%d, [[", loc.start.line);
   MUSCLE_OBSTACK_SGROW (&muscle_obstack,
-			quotearg_style (c_quoting_style, loc.start.file));
+                        quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (&muscle_obstack, "]])[");
   obstack_1grow (&muscle_obstack, 0);
   extension = obstack_finish (&muscle_obstack);
@@ -202,7 +202,7 @@ muscle_code_grow (const char *key, const char *val, location loc)
 
 
 void muscle_pair_list_grow (const char *muscle,
-			    const char *a1, const char *a2)
+                            const char *a1, const char *a2)
 {
   char *pair;
   obstack_sgrow (&muscle_obstack, "[[[");
