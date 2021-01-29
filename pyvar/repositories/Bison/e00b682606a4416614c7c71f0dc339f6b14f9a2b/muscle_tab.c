@@ -1,4 +1,5 @@
-/* Muscle table manager for Bison,
+/* Muscle table manager for Bison.
+
    Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -106,7 +107,7 @@ muscle_insert (const char *key, char *value)
   if (!entry)
     {
       /* First insertion in the hash. */
-      entry = XMALLOC (muscle_entry, 1);
+      MALLOC (entry, 1);
       entry->key = key;
       hash_insert (muscle_table, entry);
     }
@@ -132,7 +133,7 @@ muscle_grow (const char *key, const char *val, const char *separator)
   if (!entry)
     {
       /* First insertion in the hash. */
-      entry = XMALLOC (muscle_entry, 1);
+      MALLOC (entry, 1);
       entry->key = key;
       hash_insert (muscle_table, entry);
       entry->value = xstrdup (val);
@@ -191,12 +192,18 @@ muscle_find (const char *key)
 | Output the definition of ENTRY as a m4_define.  |
 `------------------------------------------------*/
 
-static int
+static inline bool
 muscle_m4_output (muscle_entry *entry, FILE *out)
 {
   fprintf (out, "m4_define([b4_%s],\n", entry->key);
   fprintf (out, "[[%s]])\n\n\n", entry->value);
-  return 1;
+  return true;
+}
+
+static bool
+muscle_m4_output_processor (void *entry, void *out)
+{
+  return muscle_m4_output (entry, out);
 }
 
 
@@ -208,7 +215,5 @@ muscle_m4_output (muscle_entry *entry, FILE *out)
 void
 muscles_m4_output (FILE *out)
 {
-  hash_do_for_each (muscle_table,
-		    (Hash_processor) muscle_m4_output,
-		    out);
+  hash_do_for_each (muscle_table, muscle_m4_output_processor, out);
 }
