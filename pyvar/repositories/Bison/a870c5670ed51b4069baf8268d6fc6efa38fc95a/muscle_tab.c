@@ -1,5 +1,5 @@
 /* Macro table manager for Bison,
-   Copyright 1984, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -32,19 +32,20 @@ struct hash_table muscle_table;
 static unsigned long
 mhash1 (const void *item)
 {
-  return_STRING_HASH_1 (((muscle_entry_t *) item)->key);
+  return_STRING_HASH_1 (((const muscle_entry_t *) item)->key);
 }
 
 static unsigned long
 mhash2 (const void *item)
 {
-  return_STRING_HASH_2 (((muscle_entry_t *) item)->key);
+  return_STRING_HASH_2 (((const muscle_entry_t *) item)->key);
 }
 
 static int
 mcmp (const void *x, const void *y)
 {
-  return strcmp (((muscle_entry_t*) x)->key, ((muscle_entry_t *) y)->key);
+  return strcmp (((const muscle_entry_t*) x)->key,
+		 ((const muscle_entry_t *) y)->key);
 }
 
 void
@@ -105,7 +106,7 @@ muscle_init (void)
   muscle_insert ("name", "Parser");
 }
 
-void 
+void
 muscle_insert (const char *key, const char *value)
 {
   muscle_entry_t *pair = XMALLOC (muscle_entry_t, 1);
