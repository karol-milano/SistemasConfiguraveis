@@ -1,5 +1,5 @@
 /* hash.c -- hash table maintenance
-   Copyright (C) 1995 Free Software Foundation, Inc.
+   Copyright 1995, 2001  Free Software Foundation, Inc.
    Written by Greg McGary <gkm@gnu.ai.mit.edu>
 
    This program is free software; you can redistribute it and/or modify
@@ -120,17 +120,17 @@ hash_find_item (struct hash_table* ht, void const *key)
   return ((HASH_VACANT (*slot)) ? 0 : *slot);
 }
 
-void *
+const void *
 hash_insert (struct hash_table* ht, void *item)
 {
   void **slot = hash_find_slot (ht, item);
   return hash_insert_at (ht, item, slot);
 }
 
-void *
+const void *
 hash_insert_at (struct hash_table* ht, void *item, void const *slot)
 {
-  void *old_item = *(void **) slot;
+  const void *old_item = *(const void **) slot;
   if (HASH_VACANT (old_item))
     {
       ht->ht_fill++;
@@ -142,17 +142,17 @@ hash_insert_at (struct hash_table* ht, void *item, void const *slot)
   return old_item;
 }
 
-void *
+const void *
 hash_delete (struct hash_table* ht, void const *item)
 {
   void **slot = hash_find_slot (ht, item);
   return hash_delete_at (ht, slot);
 }
 
-void *
+const void *
 hash_delete_at (struct hash_table* ht, void const *slot)
 {
-  void *item = *(void **) slot;
+  const void *item = *(const void **) slot;
   if (!HASH_VACANT (item))
     {
       *(void const **) slot = hash_deleted_item;
