@@ -249,7 +249,7 @@ prepare_symbol_names (char const *muscle_name)
       if (i)
         obstack_1grow (&format_obstack, ' ');
       if (translatable)
-        obstack_sgrow (&format_obstack, "]b4_symbol_translate([");
+        obstack_sgrow (&format_obstack, "]b4_symbol_translate""([");
       obstack_escape (&format_obstack, cp);
       if (translatable)
         obstack_sgrow (&format_obstack, "])[");
@@ -554,7 +554,7 @@ prepare_symbol_definitions (void)
   /* Map "orig NUM" to new numbers.  See data/README.  */
   for (symbol_number i = ntokens; i < nsyms + nuseless_nonterminals; ++i)
     {
-      obstack_printf (&format_obstack, "symbol(orig %d, number)", i);
+      obstack_printf (&format_obstack, "symbol""(orig %d, number)", i);
       const char *key = obstack_finish0 (&format_obstack);
       MUSCLE_INSERT_INT (key, nterm_map ? nterm_map[i - ntokens] : i);
     }
@@ -565,12 +565,12 @@ prepare_symbol_definitions (void)
       const char *key;
 
 #define SET_KEY(Entry)                                          \
-      obstack_printf (&format_obstack, "symbol(%d, %s)",        \
+      obstack_printf (&format_obstack, "symbol""(%d, %s)",        \
                       i, Entry);                                \
       key = obstack_finish0 (&format_obstack);
 
 #define SET_KEY2(Entry, Suffix)                                 \
-      obstack_printf (&format_obstack, "symbol(%d, %s_%s)",     \
+      obstack_printf (&format_obstack, "symbol""(%d, %s_%s)",     \
                       i, Entry, Suffix);                        \
       key = obstack_finish0 (&format_obstack);
 
