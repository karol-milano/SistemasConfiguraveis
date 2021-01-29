@@ -1,4 +1,5 @@
-/* Keeping a unique copy of strings.
+/* Keep a unique copy of strings.
+
    Copyright (C) 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -40,7 +41,7 @@ static struct hash_table *uniqstrs_table = NULL;
 `-------------------------------------*/
 
 uniqstr
-uniqstr_new (const char *s)
+uniqstr_new (char const *s)
 {
   uniqstr res = hash_lookup (uniqstrs_table, s);
   if (!res)
@@ -58,7 +59,7 @@ uniqstr_new (const char *s)
 `------------------------------*/
 
 void
-uniqstr_assert (const char *s)
+uniqstr_assert (char const *s)
 {
   if (!hash_lookup (uniqstrs_table, s))
     {
@@ -72,33 +73,36 @@ uniqstr_assert (const char *s)
 | Print the uniqstr.  |
 `--------------------*/
 
-static bool
-uniqstr_print (const uniqstr s)
+static inline bool
+uniqstr_print (uniqstr s)
 {
   fprintf (stderr, "%s\n", s);
   return true;
 }
 
+static bool
+uniqstr_print_processor (void *s, void *null ATTRIBUTE_UNUSED)
+{
+  return uniqstr_print (s);
+}
+
 
 /*-----------------------.
 | A uniqstr hash table.  |
 `-----------------------*/
 
 static bool
-hash_compare_uniqstr (const uniqstr m1, const uniqstr m2)
+hash_compare_uniqstr (void const *m1, void const *m2)
 {
   return strcmp (m1, m2) == 0;
 }
 
 static unsigned int
-hash_uniqstr (const uniqstr m, unsigned int tablesize)
+hash_uniqstr (void const *m, unsigned int tablesize)
 {
   return hash_string (m, tablesize);
 }
 
-/* A function to apply to each symbol. */
-typedef bool (*uniqstr_processor) (const uniqstr);
-
 /*----------------------------.
 | Create the uniqstrs table.  |
 `----------------------------*/
@@ -108,9 +112,9 @@ uniqstrs_new (void)
 {
   uniqstrs_table = hash_initialize (HT_INITIAL_CAPACITY,
 				    NULL,
-				    (Hash_hasher) hash_uniqstr,
-				    (Hash_comparator) hash_compare_uniqstr,
-				    (Hash_data_freer) free);
+				    hash_uniqstr,
+				    hash_compare_uniqstr,
+				    free);
 }
 
 
@@ -119,11 +123,9 @@ uniqstrs_new (void)
 `-------------------------------------*/
 
 static void
-uniqstrs_do (uniqstr_processor processor, void *processor_data)
+uniqstrs_do (Hash_processor processor, void *processor_data)
 {
-  hash_do_for_each (uniqstrs_table,
-		    (Hash_processor) processor,
-		    processor_data);
+  hash_do_for_each (uniqstrs_table, processor, processor_data);
 }
 
 
@@ -134,7 +136,7 @@ uniqstrs_do (uniqstr_processor processor, void *processor_data)
 void
 uniqstrs_print (void)
 {
-  uniqstrs_do (uniqstr_print, NULL);
+  uniqstrs_do (uniqstr_print_processor, NULL);
 }
 
 
