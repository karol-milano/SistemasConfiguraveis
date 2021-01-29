@@ -1,4 +1,4 @@
-/* Macro table manager for Bison,
+/* Muscle table manager for Bison,
    Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -56,31 +56,31 @@ hash_muscle (const void *x, unsigned int tablesize)
 void
 muscle_init (void)
 {
+  /* Initialize the muscle obstack.  */
+  obstack_init (&muscle_obstack);
+
   muscle_table = hash_initialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
 				  hash_compare_muscles, free);
 
   /* Version and input file.  */
-  muscle_insert ("version", VERSION);
-  muscle_insert ("filename", infile);
+  MUSCLE_INSERT_STRING ("version", VERSION);
+  MUSCLE_INSERT_STRING ("filename", infile);
 
   /* FIXME: there should probably be no default here, only in the
      skeletons.  */
 
   /* Types.  */
-  muscle_insert ("ltype", "yyltype");
+  MUSCLE_INSERT_STRING ("ltype", "yyltype");
 
   /* Default #line formatting.  */
-  muscle_insert ("linef", "#line %d %s\n");
+  MUSCLE_INSERT_STRING ("linef", "#line %d %s\n");
 
   /* Stack parameters.  */
-  muscle_insert ("maxdepth", "10000");
-  muscle_insert ("initdepth", "200");
+  MUSCLE_INSERT_STRING ("maxdepth", "10000");
+  MUSCLE_INSERT_STRING ("initdepth", "200");
 
   /* C++ macros.  */
-  muscle_insert ("name", "Parser");
-
-  /* Initialize the muscle obstack.  */
-  obstack_init (&muscle_obstack);
+  MUSCLE_INSERT_STRING ("name", "Parser");
 }
 
 
@@ -97,14 +97,19 @@ muscle_free (void)
 
 
 
+/*------------------------------------------------------------.
+| Insert (KEY, VALUE).  If KEY already existed, overwrite the |
+| previous value.                                             |
+`------------------------------------------------------------*/
+
 void
-muscle_insert (const char *key, const char *value)
+muscle_insert (const char *key, char *value)
 {
-  muscle_entry_t pair;
+  muscle_entry_t probe;
   muscle_entry_t *entry = NULL;
 
-  pair.key = key;
-  entry = hash_lookup (muscle_table, &pair);
+  probe.key = key;
+  entry = hash_lookup (muscle_table, &probe);
 
   if (!entry)
     {
@@ -116,32 +121,99 @@ muscle_insert (const char *key, const char *value)
   entry->value = value;
 }
 
-const char*
+
+/*-------------------------------------------------------------------.
+| Insert (KEY, VALUE).  If KEY already existed, overwrite the        |
+| previous value.  Uses MUSCLE_OBSTACK.  De-allocates the previously |
+| associated value.  VALUE and SEPARATOR are copied.                 |
+`-------------------------------------------------------------------*/
+
+void
+muscle_grow (const char *key, const char *val, const char *separator)
+{
+  muscle_entry_t probe;
+  muscle_entry_t *entry = NULL;
+
+  probe.key = key;
+  entry = hash_lookup (muscle_table, &probe);
+
+  if (!entry)
+    {
+      /* First insertion in the hash. */
+      entry = XMALLOC (muscle_entry_t, 1);
+      entry->key = key;
+      hash_insert (muscle_table, entry);
+      entry->value = xstrdup (val);
+    }
+  else
+    {
+      /* Grow the current value. */
+      char *new_val;
+      fprintf (stderr, "<= %s + %s\n", entry->value, val);
+      obstack_sgrow (&muscle_obstack, entry->value);
+      free (entry->value);
+      obstack_sgrow (&muscle_obstack, separator);
+      obstack_sgrow (&muscle_obstack, val);
+      obstack_1grow (&muscle_obstack, 0);
+      new_val = obstack_finish (&muscle_obstack);
+      entry->value = xstrdup (new_val);
+      fprintf (stderr, "=> %s\n", new_val);
+      obstack_free (&muscle_obstack, new_val);
+    }
+}
+
+
+/*-------------------------------------------------------------------.
+| MUSCLE is an M4 list of pairs.  Create or extend it with the pair  |
+| (A1, A2).  Note that because the muscle values are output *double* |
+| quoted, one needs to strip the first level of quotes to reach the  |
+| list itself.                                                       |
+`-------------------------------------------------------------------*/
+
+void muscle_pair_list_grow (const char *muscle,
+			    const char *a1, const char *a2)
+{
+  char *value;
+  obstack_fgrow2 (&muscle_obstack, "[[[%s]], [[%s]]]", a1, a2);
+  obstack_1grow (&muscle_obstack, 0);
+  value = obstack_finish (&muscle_obstack);
+  muscle_grow (muscle, value, ",\n");
+  obstack_free (&muscle_obstack, value);
+}
+
+/*-------------------------------.
+| Find the value of muscle KEY.  |
+`-------------------------------*/
+
+char*
 muscle_find (const char *key)
 {
-  muscle_entry_t pair;
+  muscle_entry_t probe;
   muscle_entry_t *result = NULL;
 
-  pair.key = key;
-  result = hash_lookup (muscle_table, &pair);
+  probe.key = key;
+  result = hash_lookup (muscle_table, &probe);
   return result ? result->value : NULL;
 }
 
 
-/* Output the definition of all the current muscles into a list of
-   m4_defines.  */
+/*------------------------------------------------.
+| Output the definition of ENTRY as a m4_define.  |
+`------------------------------------------------*/
 
 static int
 muscle_m4_output (muscle_entry_t *entry, FILE *out)
 {
   fprintf (out, "m4_define([b4_%s],\n", entry->key);
-  fprintf (out, "          [[%s]])\n\n\n", entry->value);
+  fprintf (out, "[[%s]])\n\n\n", entry->value);
   return 1;
 }
 
 
-/* Output the definition of all the current muscles into a list of
-   m4_defines.  */
+/*----------------------------------------------------------------.
+| Output the definition of all the current muscles into a list of |
+| m4_defines.                                                     |
+`----------------------------------------------------------------*/
 
 void
 muscles_m4_output (FILE *out)
