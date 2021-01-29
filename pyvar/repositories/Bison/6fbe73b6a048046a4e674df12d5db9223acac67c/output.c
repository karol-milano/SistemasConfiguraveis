@@ -86,18 +86,15 @@ Name (char const *name,                                                 \
       if (max < table_data[i])                                          \
         max = table_data[i];                                            \
     }                                                                   \
-  obstack_1grow (&format_obstack, 0);                                   \
-  muscle_insert (name, obstack_finish (&format_obstack));               \
+  muscle_insert (name, obstack_finish0 (&format_obstack));              \
                                                                         \
   lmin = min;                                                           \
   lmax = max;                                                           \
   /* Build `NAME_min' and `NAME_max' in the obstack. */                 \
   obstack_printf (&format_obstack, "%s_min", name);                     \
-  obstack_1grow (&format_obstack, 0);                                   \
-  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmin);      \
+  MUSCLE_INSERT_LONG_INT (obstack_finish0 (&format_obstack), lmin);     \
   obstack_printf (&format_obstack, "%s_max", name);                     \
-  obstack_1grow (&format_obstack, 0);                                   \
-  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmax);      \
+  MUSCLE_INSERT_LONG_INT (obstack_finish0 (&format_obstack), lmax);     \
 }
 
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
@@ -193,8 +190,7 @@ prepare_symbols (void)
     obstack_sgrow (&format_obstack, " ]b4_null[");
 
     /* Finish table and store. */
-    obstack_1grow (&format_obstack, 0);
-    muscle_insert ("tname", obstack_finish (&format_obstack));
+    muscle_insert ("tname", obstack_finish0 (&format_obstack));
   }
 
   /* Output YYTOKNUM. */
@@ -412,14 +408,12 @@ prepare_symbol_definitions (void)
 #define SET_KEY(Entry)                                          \
       obstack_printf (&format_obstack, "symbol(%d, %s)",        \
                       i, Entry);                                \
-      obstack_1grow (&format_obstack, 0);                       \
-      key = obstack_finish (&format_obstack);
+      key = obstack_finish0 (&format_obstack);
 
 #define SET_KEY2(Entry, Suffix)                                 \
       obstack_printf (&format_obstack, "symbol(%d, %s_%s)",     \
                       i, Entry, Suffix);                        \
-      obstack_1grow (&format_obstack, 0);                       \
-      key = obstack_finish (&format_obstack);
+      key = obstack_finish0 (&format_obstack);
 
       // Whether the symbol has an identifier.
       value = symbol_id_get (sym);
