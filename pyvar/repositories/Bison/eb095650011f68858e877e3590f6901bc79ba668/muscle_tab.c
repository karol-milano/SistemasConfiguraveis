@@ -1,6 +1,6 @@
 /* Muscle table manager for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software
+   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Free Software
    Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -30,10 +30,13 @@
 #include "muscle_tab.h"
 #include "getargs.h"
 
+/* A key-value pair, along with storage that can be reclaimed when
+   this pair is no longer needed.  */
 typedef struct
 {
-  const char *key;
-  char *value;
+  char const *key;
+  char const *value;
+  char *storage;
 } muscle_entry;
 
 /* An obstack used to create some entries.  */
@@ -64,6 +67,14 @@ hash_muscle (const void *x, size_t tablesize)
 | Also set up the MUSCLE_OBSTACK.                                  |
 `-----------------------------------------------------------------*/
 
+static void
+muscle_entry_free (void *entry)
+{
+  muscle_entry *mentry = entry;
+  free (mentry->storage);
+  free (mentry);
+}
+
 void
 muscle_init (void)
 {
@@ -71,7 +82,7 @@ muscle_init (void)
   obstack_init (&muscle_obstack);
 
   muscle_table = hash_initialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
-				  hash_compare_muscles, free);
+				  hash_compare_muscles, muscle_entry_free);
 
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
@@ -98,7 +109,7 @@ muscle_free (void)
 `------------------------------------------------------------*/
 
 void
-muscle_insert (const char *key, char *value)
+muscle_insert (char const *key, char const *value)
 {
   muscle_entry probe;
   muscle_entry *entry;
@@ -112,6 +123,7 @@ muscle_insert (const char *key, char *value)
       entry = xmalloc (sizeof *entry);
       entry->key = key;
       hash_insert (muscle_table, entry);
+      entry->storage = NULL;
     }
   entry->value = value;
 }
@@ -138,19 +150,19 @@ muscle_grow (const char *key, const char *val, const char *separator)
       entry = xmalloc (sizeof *entry);
       entry->key = key;
       hash_insert (muscle_table, entry);
-      entry->value = xstrdup (val);
+      entry->value = entry->storage = xstrdup (val);
     }
   else
     {
       /* Grow the current value. */
       char *new_val;
       obstack_sgrow (&muscle_obstack, entry->value);
-      free (entry->value);
+      free (entry->storage);
       obstack_sgrow (&muscle_obstack, separator);
       obstack_sgrow (&muscle_obstack, val);
       obstack_1grow (&muscle_obstack, 0);
       new_val = obstack_finish (&muscle_obstack);
-      entry->value = xstrdup (new_val);
+      entry->value = entry->storage = xstrdup (new_val);
       obstack_free (&muscle_obstack, new_val);
     }
 }
@@ -173,6 +185,7 @@ muscle_code_grow (const char *key, const char *val, location loc)
   obstack_1grow (&muscle_obstack, 0);
   extension = obstack_finish (&muscle_obstack);
   muscle_grow (key, extension, "");
+  obstack_free (&muscle_obstack, extension);
 }
 
 
