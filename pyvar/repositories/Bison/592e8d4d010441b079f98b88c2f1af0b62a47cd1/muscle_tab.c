@@ -24,6 +24,10 @@
 #include "muscle_tab.h"
 #include "getargs.h"
 
+
+/* An obstack used to create some entries.  */
+struct obstack muscle_obstack;
+
 /* Initial capacity of muscles hash table.  */
 #define HT_INITIAL_CAPACITY 257
 
@@ -44,16 +48,24 @@ hash_muscle (const void *x, unsigned int tablesize)
   return hash_string (m->key, tablesize);
 }
 
+/*-----------------------------------------------------------------.
+| Create the MUSCLE_TABLE, and initialize it with default values.  |
+| Also set up the MUSCLE_OBSTACK.                                  |
+`-----------------------------------------------------------------*/
+
 void
 muscle_init (void)
 {
   muscle_table = hash_initialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
-				  hash_compare_muscles, NULL);
+				  hash_compare_muscles, free);
 
   /* Version and input file.  */
   muscle_insert ("version", VERSION);
   muscle_insert ("filename", infile);
 
+  /* FIXME: there should probably be no default here, only in the
+     skeletons.  */
+
   /* Types.  */
   muscle_insert ("ltype", "yyltype");
 
@@ -66,8 +78,25 @@ muscle_init (void)
 
   /* C++ macros.  */
   muscle_insert ("name", "Parser");
+
+  /* Initialize the muscle obstack.  */
+  obstack_init (&muscle_obstack);
 }
 
+
+/*------------------------------------------------------------.
+| Free all the memory consumed by the muscle machinery only.  |
+`------------------------------------------------------------*/
+
+void
+muscle_free (void)
+{
+  hash_free (muscle_table);
+  obstack_free (&muscle_obstack, NULL);
+}
+
+
+
 void
 muscle_insert (const char *key, const char *value)
 {
