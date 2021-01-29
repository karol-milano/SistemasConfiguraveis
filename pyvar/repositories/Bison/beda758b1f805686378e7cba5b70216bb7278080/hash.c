@@ -1,6 +1,6 @@
-/* hash.c -- hash table maintenance
-   Copyright 1995, 2001  Free Software Foundation, Inc.
-   Written by Greg McGary <gkm@gnu.ai.mit.edu>
+/* hash - hashing table processing.
+   Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
+   Written by Jim Meyering, 1992.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -13,281 +13,997 @@
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
-*/
-
-#include <config.h>
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+
+/* A generic hash table package.  */
+
+/* Define USE_OBSTACK to 1 if you want the allocator to use obstacks instead
+   of malloc.  If you change USE_OBSTACK, you have to recompile!  */
+
+#if HAVE_CONFIG_H
+# include <config.h>
+#endif
+#if HAVE_STDLIB_H
+# include <stdlib.h>
+#endif
+#if HAVE_STDBOOL_H
+# include <stdbool.h>
+#else
+typedef enum {false = 0, true = 1} bool;
+#endif
 #include <stdio.h>
+#include <assert.h>
+
+#ifndef HAVE_DECL_FREE
+# error "this configure-time declaration test was not run"
+#endif
+#if !HAVE_DECL_FREE
+void free ();
+#endif
+
+#ifndef HAVE_DECL_MALLOC
+# error "this configure-time declaration test was not run"
+#endif
+#if !HAVE_DECL_MALLOC
+char *malloc ();
+#endif
+
+#if USE_OBSTACK
+# include "obstack.h"
+# ifndef obstack_chunk_alloc
+#  define obstack_chunk_alloc malloc
+# endif
+# ifndef obstack_chunk_free
+#  define obstack_chunk_free free
+# endif
+#endif
+
 #include "hash.h"
-#include "error.h"
-#include "system.h"
-#include "xalloc.h"
 
-static void hash_rehash PARAMS((struct hash_table* ht));
-static unsigned long round_up_2 PARAMS((unsigned long rough));
+/* A hash table contains many internal entries, each holding a pointer to
+   some user provided data (also called a user entry).  An entry indistinctly
+   refers to both the internal entry and its associated user entry.  A user
+   entry contents may be hashed by a randomization function (the hashing
+   function, or just `hasher' for short) into a number (or `slot') between 0
+   and the current table size.  At each slot position in the hash table,
+   starts a linked chain of entries for which the user data all hash to this
+   slot.  A bucket is the collection of all entries hashing to the same slot.
+
+   A good `hasher' function will distribute entries rather evenly in buckets.
+   In the ideal case, the length of each bucket is roughly the number of
+   entries divided by the table size.  Finding the slot for a data is usually
+   done in constant time by the `hasher', and the later finding of a precise
+   entry is linear in time with the size of the bucket.  Consequently, a
+   larger hash table size (that is, a larger number of buckets) is prone to
+   yielding shorter chains, *given* the `hasher' function behaves properly.
+
+   Long buckets slow down the lookup algorithm.  One might use big hash table
+   sizes in hope to reduce the average length of buckets, but this might
+   become inordinate, as unused slots in the hash table take some space.  The
+   best bet is to make sure you are using a good `hasher' function (beware
+   that those are not that easy to write! :-), and to use a table size
+   larger than the actual number of entries.  */
+
+/* If an insertion makes the ratio of nonempty buckets to table size larger
+   than the growth threshold (a number between 0.0 and 1.0), then increase
+   the table size by multiplying by the growth factor (a number greater than
+   1.0).  The growth threshold defaults to 0.8, and the growth factor
+   defaults to 1.414, meaning that the table will have doubled its size
+   every second time 80% of the buckets get used.  */
+#define DEFAULT_GROWTH_THRESHOLD 0.8
+#define DEFAULT_GROWTH_FACTOR 1.414
+
+/* If a deletion empties a bucket and causes the ratio of used buckets to
+   table size to become smaller than the shrink threshold (a number between
+   0.0 and 1.0), then shrink the table by multiplying by the shrink factor (a
+   number greater than the shrink threshold but smaller than 1.0).  The shrink
+   threshold and factor default to 0.0 and 1.0, meaning that the table never
+   shrinks.  */
+#define DEFAULT_SHRINK_THRESHOLD 0.0
+#define DEFAULT_SHRINK_FACTOR 1.0
+
+/* Use this to initialize or reset a TUNING structure to
+   some sensible values. */
+static const Hash_tuning default_tuning =
+  {
+    DEFAULT_SHRINK_THRESHOLD,
+    DEFAULT_SHRINK_FACTOR,
+    DEFAULT_GROWTH_THRESHOLD,
+    DEFAULT_GROWTH_FACTOR,
+    false
+  };
+
+/* Information and lookup.  */
+
+/* The following few functions provide information about the overall hash
+   table organization: the number of entries, number of buckets and maximum
+   length of buckets.  */
+
+/* Return the number of buckets in the hash table.  The table size, the total
+   number of buckets (used plus unused), or the maximum number of slots, are
+   the same quantity.  */
+
+unsigned
+hash_get_n_buckets (const Hash_table *table)
+{
+  return table->n_buckets;
+}
 
-/* Implement double hashing with open addressing.  The table size is
-   always a power of two.  The secondary (`increment') hash function
-   is forced to return an odd-value, in order to be relatively prime
-   to the table size.  This guarantees that the increment can
-   potentially hit every slot in the table during collision
-   resolution.  */
+/* Return the number of slots in use (non-empty buckets).  */
 
-void *hash_deleted_item = &hash_deleted_item;
+unsigned
+hash_get_n_buckets_used (const Hash_table *table)
+{
+  return table->n_buckets_used;
+}
 
-/* Force the table size to be a power of two, possibly rounding up the
-   given size.  */
+/* Return the number of active entries.  */
 
-void
-hash_init (struct hash_table* ht, unsigned long size,
-	   hash_func_t hash_1, hash_func_t hash_2, hash_cmp_func_t hash_cmp)
+unsigned
+hash_get_n_entries (const Hash_table *table)
 {
-  ht->ht_size = round_up_2 (size);
-  if (ht->ht_size > (128 * 1024)) /* prevent size from getting out of hand */
-    ht->ht_size /= 2;
-  ht->ht_vec = (void**) XCALLOC (struct token *, ht->ht_size);
-  if (ht->ht_vec == 0)
-    error (1, 0, _("can't allocate %ld bytes for hash table: memory exhausted"),
-	   ht->ht_size * sizeof(struct token *));
-  ht->ht_capacity = ht->ht_size * 15 / 16; /* 93.75% loading factor */
-  ht->ht_fill = 0;
-  ht->ht_collisions = 0;
-  ht->ht_lookups = 0;
-  ht->ht_rehashes = 0;
-  ht->ht_hash_1 = hash_1;
-  ht->ht_hash_2 = hash_2;
-  ht->ht_compare = hash_cmp;
+  return table->n_entries;
 }
 
-/* Load an array of items into `ht'.  */
+/* Return the length of the longest chain (bucket).  */
 
-void
-hash_load (struct hash_table* ht, void *item_table, unsigned long cardinality, unsigned long size)
+unsigned
+hash_get_max_bucket_length (const Hash_table *table)
 {
-  char *items = (char *) item_table;
-  while (cardinality--)
+  struct hash_entry *bucket;
+  unsigned max_bucket_length = 0;
+
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
     {
-      hash_insert (ht, items);
-      items += size;
+      if (bucket->data)
+	{
+	  struct hash_entry *cursor = bucket;
+	  unsigned bucket_length = 1;
+
+	  while (cursor = cursor->next, cursor)
+	    bucket_length++;
+
+	  if (bucket_length > max_bucket_length)
+	    max_bucket_length = bucket_length;
+	}
     }
+
+  return max_bucket_length;
 }
 
-/* Returns the address of the table slot matching `key'.  If `key' is
-   not found, return the address of an empty slot suitable for
-   inserting `key'.  The caller is responsible for incrementing
-   ht_fill on insertion.  */
+/* Do a mild validation of a hash table, by traversing it and checking two
+   statistics.  */
 
-void **
-hash_find_slot (struct hash_table* ht, void const *key)
+bool
+hash_table_ok (const Hash_table *table)
 {
-  void **slot;
-  void **deleted_slot = 0;
-  unsigned int hash_2 = 0;
-  unsigned int hash_1 = (*ht->ht_hash_1) (key);
+  struct hash_entry *bucket;
+  unsigned n_buckets_used = 0;
+  unsigned n_entries = 0;
 
-  ht->ht_lookups++;
-  for (;;)
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
     {
-      hash_1 %= ht->ht_size;
-      slot = &ht->ht_vec[hash_1];
-
-      if (*slot == 0)
-	return slot;
-      if (*slot == hash_deleted_item)
-	{
-	  if (deleted_slot == 0)
-	    deleted_slot = slot;
-	}
-      else
+      if (bucket->data)
 	{
-	  if (key == *slot)
-	    return slot;
-	  if ((*ht->ht_compare) (key, *slot) == 0)
-	    return slot;
-	  ht->ht_collisions++;
+	  struct hash_entry *cursor = bucket;
+
+	  /* Count bucket head.  */
+	  n_buckets_used++;
+	  n_entries++;
+
+	  /* Count bucket overflow.  */
+	  while (cursor = cursor->next, cursor)
+	    n_entries++;
 	}
-      if (!hash_2)
-	  hash_2 = (*ht->ht_hash_2) (key) | 1;
-      hash_1 += hash_2;
     }
+
+  if (n_buckets_used == table->n_buckets_used && n_entries == table->n_entries)
+    return true;
+
+  return false;
+}
+
+void
+hash_print_statistics (const Hash_table *table, FILE *stream)
+{
+  unsigned n_entries = hash_get_n_entries (table);
+  unsigned n_buckets = hash_get_n_buckets (table);
+  unsigned n_buckets_used = hash_get_n_buckets_used (table);
+  unsigned max_bucket_length = hash_get_max_bucket_length (table);
+
+  fprintf (stream, "# entries:         %u\n", n_entries);
+  fprintf (stream, "# buckets:         %u\n", n_buckets);
+  fprintf (stream, "# buckets used:    %u (%.2f%%)\n", n_buckets_used,
+	   (100.0 * n_buckets_used) / n_buckets);
+  fprintf (stream, "max bucket length: %u\n", max_bucket_length);
 }
 
+/* If ENTRY matches an entry already in the hash table, return the
+   entry from the table.  Otherwise, return NULL.  */
+
 void *
-hash_find_item (struct hash_table* ht, void const *key)
+hash_lookup (const Hash_table *table, const void *entry)
 {
-  void **slot = hash_find_slot (ht, key);
-  return ((HASH_VACANT (*slot)) ? 0 : *slot);
+  struct hash_entry *bucket
+    = table->bucket + table->hasher (entry, table->n_buckets);
+  struct hash_entry *cursor;
+
+  assert (bucket < table->bucket_limit);
+
+  if (bucket->data == NULL)
+    return NULL;
+
+  for (cursor = bucket; cursor; cursor = cursor->next)
+    if (table->comparator (entry, cursor->data))
+      return cursor->data;
+
+  return NULL;
 }
 
-const void *
-hash_insert (struct hash_table* ht, void *item)
+/* Walking.  */
+
+/* The functions in this page traverse the hash table and process the
+   contained entries.  For the traversal to work properly, the hash table
+   should not be resized nor modified while any particular entry is being
+   processed.  In particular, entries should not be added or removed.  */
+
+/* Return the first data in the table, or NULL if the table is empty.  */
+
+void *
+hash_get_first (const Hash_table *table)
 {
-  void **slot = hash_find_slot (ht, item);
-  return hash_insert_at (ht, item, slot);
+  struct hash_entry *bucket;
+
+  if (table->n_entries == 0)
+    return NULL;
+
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
+    if (bucket->data)
+      return bucket->data;
+
+  assert (0);
+  return NULL;
 }
 
-const void *
-hash_insert_at (struct hash_table* ht, void *item, void const *slot)
+/* Return the user data for the entry following ENTRY, where ENTRY has been
+   returned by a previous call to either `hash_get_first' or `hash_get_next'.
+   Return NULL if there are no more entries.  */
+
+void *
+hash_get_next (const Hash_table *table, const void *entry)
+{
+  struct hash_entry *bucket
+    = table->bucket + table->hasher (entry, table->n_buckets);
+  struct hash_entry *cursor;
+
+  assert (bucket < table->bucket_limit);
+
+  /* Find next entry in the same bucket.  */
+  for (cursor = bucket; cursor; cursor = cursor->next)
+    if (cursor->data == entry && cursor->next)
+      return cursor->next->data;
+
+  /* Find first entry in any subsequent bucket.  */
+  while (++bucket < table->bucket_limit)
+    if (bucket->data)
+      return bucket->data;
+
+  /* None found.  */
+  return NULL;
+}
+
+/* Fill BUFFER with pointers to active user entries in the hash table, then
+   return the number of pointers copied.  Do not copy more than BUFFER_SIZE
+   pointers.  */
+
+unsigned
+hash_get_entries (const Hash_table *table, void **buffer,
+		  unsigned buffer_size)
 {
-  const void *old_item = *(const void **) slot;
-  if (HASH_VACANT (old_item))
+  unsigned counter = 0;
+  struct hash_entry *bucket;
+  struct hash_entry *cursor;
+
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
     {
-      ht->ht_fill++;
-      old_item = item;
+      if (bucket->data)
+	{
+	  for (cursor = bucket; cursor; cursor = cursor->next)
+	    {
+	      if (counter >= buffer_size)
+		return counter;
+	      buffer[counter++] = cursor->data;
+	    }
+	}
     }
-  *(void const **) slot = item;
-  if (ht->ht_fill >= ht->ht_capacity)
-    hash_rehash (ht);
-  return old_item;
+
+  return counter;
 }
 
-const void *
-hash_delete (struct hash_table* ht, void const *item)
+/* Call a PROCESSOR function for each entry of a hash table, and return the
+   number of entries for which the processor function returned success.  A
+   pointer to some PROCESSOR_DATA which will be made available to each call to
+   the processor function.  The PROCESSOR accepts two arguments: the first is
+   the user entry being walked into, the second is the value of PROCESSOR_DATA
+   as received.  The walking continue for as long as the PROCESSOR function
+   returns nonzero.  When it returns zero, the walking is interrupted.  */
+
+unsigned
+hash_do_for_each (const Hash_table *table, Hash_processor processor,
+		  void *processor_data)
 {
-  void **slot = hash_find_slot (ht, item);
-  return hash_delete_at (ht, slot);
+  unsigned counter = 0;
+  struct hash_entry *bucket;
+  struct hash_entry *cursor;
+
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
+    {
+      if (bucket->data)
+	{
+	  for (cursor = bucket; cursor; cursor = cursor->next)
+	    {
+	      if (!(*processor) (cursor->data, processor_data))
+		return counter;
+	      counter++;
+	    }
+	}
+    }
+
+  return counter;
 }
 
-const void *
-hash_delete_at (struct hash_table* ht, void const *slot)
+/* Allocation and clean-up.  */
+
+/* Return a hash index for a NUL-terminated STRING between 0 and N_BUCKETS-1.
+   This is a convenience routine for constructing other hashing functions.  */
+
+#if USE_DIFF_HASH
+
+/* About hashings, Paul Eggert writes to me (FP), on 1994-01-01: "Please see
+   B. J. McKenzie, R. Harries & T. Bell, Selecting a hashing algorithm,
+   Software--practice & experience 20, 2 (Feb 1990), 209-224.  Good hash
+   algorithms tend to be domain-specific, so what's good for [diffutils'] io.c
+   may not be good for your application."  */
+
+unsigned
+hash_string (const char *string, unsigned n_buckets)
 {
-  const void *item = *(const void **) slot;
-  if (!HASH_VACANT (item))
+# ifndef CHAR_BIT
+#  define CHAR_BIT 8
+# endif
+# define ROTATE_LEFT(Value, Shift) \
+  ((Value) << (Shift) | (Value) >> ((sizeof (unsigned) * CHAR_BIT) - (Shift)))
+# define HASH_ONE_CHAR(Value, Byte) \
+  ((Byte) + ROTATE_LEFT (Value, 7))
+
+  unsigned value = 0;
+
+  for (; *string; string++)
+    value = HASH_ONE_CHAR (value, *(const unsigned char *) string);
+  return value % n_buckets;
+
+# undef ROTATE_LEFT
+# undef HASH_ONE_CHAR
+}
+
+#else /* not USE_DIFF_HASH */
+
+/* This one comes from `recode', and performs a bit better than the above as
+   per a few experiments.  It is inspired from a hashing routine found in the
+   very old Cyber `snoop', itself written in typical Greg Mansfield style.
+   (By the way, what happened to this excellent man?  Is he still alive?)  */
+
+unsigned
+hash_string (const char *string, unsigned n_buckets)
+{
+  unsigned value = 0;
+
+  while (*string)
+    value = ((value * 31 + (int) *(const unsigned char *) string++)
+	     % n_buckets);
+  return value;
+}
+
+#endif /* not USE_DIFF_HASH */
+
+/* Return true if CANDIDATE is a prime number.  CANDIDATE should be an odd
+   number at least equal to 11.  */
+
+static bool
+is_prime (unsigned long candidate)
+{
+  unsigned long divisor = 3;
+  unsigned long square = divisor * divisor;
+
+  while (square < candidate && (candidate % divisor))
     {
-      *(void const **) slot = hash_deleted_item;
-      ht->ht_fill--;
-      return item;
+      divisor++;
+      square += 4 * divisor;
+      divisor++;
     }
-  else
-    return 0;
+
+  return (candidate % divisor ? true : false);
+}
+
+/* Round a given CANDIDATE number up to the nearest prime, and return that
+   prime.  Primes lower than 10 are merely skipped.  */
+
+static unsigned long
+next_prime (unsigned long candidate)
+{
+  /* Skip small primes.  */
+  if (candidate < 10)
+    candidate = 10;
+
+  /* Make it definitely odd.  */
+  candidate |= 1;
+
+  while (!is_prime (candidate))
+    candidate += 2;
+
+  return candidate;
 }
 
 void
-hash_free_items (struct hash_table* ht)
+hash_reset_tuning (Hash_tuning *tuning)
+{
+  *tuning = default_tuning;
+}
+
+/* For the given hash TABLE, check the user supplied tuning structure for
+   reasonable values, and return true if there is no gross error with it.
+   Otherwise, definitively reset the TUNING field to some acceptable default
+   in the hash table (that is, the user loses the right of further modifying
+   tuning arguments), and return false.  */
+
+static bool
+check_tuning (Hash_table *table)
 {
-  void **vec = ht->ht_vec;
-  void **end = &vec[ht->ht_size];
-  for (; vec < end; vec++)
+  const Hash_tuning *tuning = table->tuning;
+
+  if (tuning->growth_threshold > 0.0
+      && tuning->growth_threshold < 1.0
+      && tuning->growth_factor > 1.0
+      && tuning->shrink_threshold >= 0.0
+      && tuning->shrink_threshold < 1.0
+      && tuning->shrink_factor > tuning->shrink_threshold
+      && tuning->shrink_factor <= 1.0
+      && tuning->shrink_threshold < tuning->growth_threshold)
+    return true;
+
+  table->tuning = &default_tuning;
+  return false;
+}
+
+/* Allocate and return a new hash table, or NULL upon failure.  The initial
+   number of buckets is automatically selected so as to _guarantee_ that you
+   may insert at least CANDIDATE different user entries before any growth of
+   the hash table size occurs.  So, if have a reasonably tight a-priori upper
+   bound on the number of entries you intend to insert in the hash table, you
+   may save some table memory and insertion time, by specifying it here.  If
+   the IS_N_BUCKETS field of the TUNING structure is true, the CANDIDATE
+   argument has its meaning changed to the wanted number of buckets.
+
+   TUNING points to a structure of user-supplied values, in case some fine
+   tuning is wanted over the default behavior of the hasher.  If TUNING is
+   NULL, the default tuning parameters are used instead.
+
+   The user-supplied HASHER function should be provided.  It accepts two
+   arguments ENTRY and TABLE_SIZE.  It computes, by hashing ENTRY contents, a
+   slot number for that entry which should be in the range 0..TABLE_SIZE-1.
+   This slot number is then returned.
+
+   The user-supplied COMPARATOR function should be provided.  It accepts two
+   arguments pointing to user data, it then returns true for a pair of entries
+   that compare equal, or false otherwise.  This function is internally called
+   on entries which are already known to hash to the same bucket index.
+
+   The user-supplied DATA_FREER function, when not NULL, may be later called
+   with the user data as an argument, just before the entry containing the
+   data gets freed.  This happens from within `hash_free' or `hash_clear'.
+   You should specify this function only if you want these functions to free
+   all of your `data' data.  This is typically the case when your data is
+   simply an auxiliary struct that you have malloc'd to aggregate several
+   values.  */
+
+Hash_table *
+hash_initialize (unsigned candidate, const Hash_tuning *tuning,
+		 Hash_hasher hasher, Hash_comparator comparator,
+		 Hash_data_freer data_freer)
+{
+  Hash_table *table;
+  struct hash_entry *bucket;
+
+  if (hasher == NULL || comparator == NULL)
+    return NULL;
+
+  table = (Hash_table *) malloc (sizeof (Hash_table));
+  if (table == NULL)
+    return NULL;
+
+  if (!tuning)
+    tuning = &default_tuning;
+  table->tuning = tuning;
+  if (!check_tuning (table))
     {
-      void *item = *vec;
-      if (!HASH_VACANT (item))
-	free (item);
-      *vec = 0;
+      /* Fail if the tuning options are invalid.  This is the only occasion
+	 when the user gets some feedback about it.  Once the table is created,
+	 if the user provides invalid tuning options, we silently revert to
+	 using the defaults, and ignore further request to change the tuning
+	 options.  */
+      free (table);
+      return NULL;
     }
-  ht->ht_fill = 0;
+
+  table->n_buckets
+    = next_prime (tuning->is_n_buckets ? candidate
+		  : (unsigned) (candidate / tuning->growth_threshold));
+
+  table->bucket = (struct hash_entry *)
+    malloc (table->n_buckets * sizeof (struct hash_entry));
+  if (table->bucket == NULL)
+    {
+      free (table);
+      return NULL;
+    }
+  table->bucket_limit = table->bucket + table->n_buckets;
+
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
+    {
+      bucket->data = NULL;
+      bucket->next = NULL;
+    }
+  table->n_buckets_used = 0;
+  table->n_entries = 0;
+
+  table->hasher = hasher;
+  table->comparator = comparator;
+  table->data_freer = data_freer;
+
+  table->free_entry_list = NULL;
+#if USE_OBSTACK
+  obstack_init (&table->entry_stack);
+#endif
+  return table;
 }
 
+/* Make all buckets empty, placing any chained entries on the free list.
+   Apply the user-specified function data_freer (if any) to the datas of any
+   affected entries.  */
+
 void
-hash_delete_items (struct hash_table* ht)
+hash_clear (Hash_table *table)
 {
-  void **vec = ht->ht_vec;
-  void **end = &vec[ht->ht_size];
-  for (; vec < end; vec++)
-    *vec = 0;
-  ht->ht_fill = 0;
-  ht->ht_collisions = 0;
-  ht->ht_lookups = 0;
-  ht->ht_rehashes = 0;
+  struct hash_entry *bucket;
+  struct hash_entry *cursor;
+
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
+    {
+      if (bucket->data)
+	{
+	  /* Free the bucket overflow.  */
+	  for (cursor = bucket->next; cursor; cursor = cursor->next)
+	    {
+	      if (table->data_freer)
+		(*table->data_freer) (cursor->data);
+	      cursor->data = NULL;
+
+	      /* Relinking is done one entry at a time, as it is to be expected
+		 that overflows are either rare or short.  */
+	      cursor->next = table->free_entry_list;
+	      table->free_entry_list = cursor;
+	    }
+
+	  /* Free the bucket head.  */
+	  if (table->data_freer)
+	    (*table->data_freer) (bucket->data);
+	  bucket->data = NULL;
+	  bucket->next = NULL;
+	}
+    }
+
+  table->n_buckets_used = 0;
+  table->n_entries = 0;
 }
 
+/* Reclaim all storage associated with a hash table.  If a data_freer
+   function has been supplied by the user when the hash table was created,
+   this function applies it to the data of each entry before freeing that
+   entry.  */
+
 void
-hash_free (struct hash_table* ht, int free_items)
+hash_free (Hash_table *table)
 {
-  if (free_items)
-    hash_free_items (ht);
-  free (ht->ht_vec);
-  ht->ht_vec = 0;
-  ht->ht_fill = 0;
-  ht->ht_capacity = 0;
+  struct hash_entry *bucket;
+  struct hash_entry *cursor;
+  struct hash_entry *next;
+
+  /* Call the user data_freer function.  */
+  if (table->data_freer && table->n_entries)
+    {
+      for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
+	{
+	  if (bucket->data)
+	    {
+	      for (cursor = bucket; cursor; cursor = cursor->next)
+		{
+		  (*table->data_freer) (cursor->data);
+		}
+	    }
+	}
+    }
+
+#if USE_OBSTACK
+
+  obstack_free (&table->entry_stack, NULL);
+
+#else
+
+  /* Free all bucket overflowed entries.  */
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
+    {
+      for (cursor = bucket->next; cursor; cursor = next)
+	{
+	  next = cursor->next;
+	  free (cursor);
+	}
+    }
+
+  /* Also reclaim the internal list of previously freed entries.  */
+  for (cursor = table->free_entry_list; cursor; cursor = next)
+    {
+      next = cursor->next;
+      free (cursor);
+    }
+
+#endif
+
+  /* Free the remainder of the hash table structure.  */
+  free (table->bucket);
+  free (table);
 }
 
-void
-hash_map (struct hash_table *ht, hash_map_func_t map)
+/* Insertion and deletion.  */
+
+/* Get a new hash entry for a bucket overflow, possibly by reclying a
+   previously freed one.  If this is not possible, allocate a new one.  */
+
+static struct hash_entry *
+allocate_entry (Hash_table *table)
 {
-  void **slot;
-  void **end = &ht->ht_vec[ht->ht_size];
+  struct hash_entry *new;
 
-  for (slot = ht->ht_vec; slot < end; slot++)
+  if (table->free_entry_list)
+    {
+      new = table->free_entry_list;
+      table->free_entry_list = new->next;
+    }
+  else
     {
-      if (!HASH_VACANT (*slot))
-	(*map) (*slot);
+#if USE_OBSTACK
+      new = (struct hash_entry *)
+	obstack_alloc (&table->entry_stack, sizeof (struct hash_entry));
+#else
+      new = (struct hash_entry *) malloc (sizeof (struct hash_entry));
+#endif
     }
+
+  return new;
 }
 
-/* Double the size of the hash table in the event of overflow... */
+/* Free a hash entry which was part of some bucket overflow,
+   saving it for later recycling.  */
 
 static void
-hash_rehash (struct hash_table* ht)
+free_entry (Hash_table *table, struct hash_entry *entry)
+{
+  entry->data = NULL;
+  entry->next = table->free_entry_list;
+  table->free_entry_list = entry;
+}
+
+/* This private function is used to help with insertion and deletion.  When
+   ENTRY matches an entry in the table, return a pointer to the corresponding
+   user data and set *BUCKET_HEAD to the head of the selected bucket.
+   Otherwise, return NULL.  When DELETE is true and ENTRY matches an entry in
+   the table, unlink the matching entry.  */
+
+static void *
+hash_find_entry (Hash_table *table, const void *entry,
+		 struct hash_entry **bucket_head, bool delete)
 {
-  unsigned long old_ht_size = ht->ht_size;
-  void **old_vec = ht->ht_vec;
-  void **ovp;
-  void **slot;
+  struct hash_entry *bucket
+    = table->bucket + table->hasher (entry, table->n_buckets);
+  struct hash_entry *cursor;
+
+  assert (bucket < table->bucket_limit);
+  *bucket_head = bucket;
+
+  /* Test for empty bucket.  */
+  if (bucket->data == NULL)
+    return NULL;
+
+  /* See if the entry is the first in the bucket.  */
+  if ((*table->comparator) (entry, bucket->data))
+    {
+      void *data = bucket->data;
+
+      if (delete)
+	{
+	  if (bucket->next)
+	    {
+	      struct hash_entry *next = bucket->next;
+
+	      /* Bump the first overflow entry into the bucket head, then save
+		 the previous first overflow entry for later recycling.  */
+	      *bucket = *next;
+	      free_entry (table, next);
+	    }
+	  else
+	    {
+	      bucket->data = NULL;
+	    }
+	}
 
-  ht->ht_size *= 2;
-  ht->ht_rehashes++;
-  ht->ht_capacity = ht->ht_size - (ht->ht_size >> 4);
-  ht->ht_vec = (void **) XCALLOC (struct token *, ht->ht_size);
+      return data;
+    }
 
-  for (ovp = old_vec; ovp < &old_vec[old_ht_size]; ovp++)
+  /* Scan the bucket overflow.  */
+  for (cursor = bucket; cursor->next; cursor = cursor->next)
     {
-      if (*ovp == 0)
-	continue;
-      slot = hash_find_slot (ht, *ovp);
-      *slot = *ovp;
+      if ((*table->comparator) (entry, cursor->next->data))
+	{
+	  void *data = cursor->next->data;
+
+	  if (delete)
+	    {
+	      struct hash_entry *next = cursor->next;
+
+	      /* Unlink the entry to delete, then save the freed entry for later
+		 recycling.  */
+	      cursor->next = next->next;
+	      free_entry (table, next);
+	    }
+
+	  return data;
+	}
     }
-  free (old_vec);
+
+  /* No entry found.  */
+  return NULL;
 }
 
-void
-hash_print_stats (struct hash_table *ht, FILE *out_FILE)
+/* For an already existing hash table, change the number of buckets through
+   specifying CANDIDATE.  The contents of the hash table are preserved.  The
+   new number of buckets is automatically selected so as to _guarantee_ that
+   the table may receive at least CANDIDATE different user entries, including
+   those already in the table, before any other growth of the hash table size
+   occurs.  If TUNING->IS_N_BUCKETS is true, then CANDIDATE specifies the
+   exact number of buckets desired.  */
+
+bool
+hash_rehash (Hash_table *table, unsigned candidate)
 {
-  fprintf (out_FILE, _("Load=%ld/%ld=%.0f%%, "), ht->ht_fill, ht->ht_size,
-	   100.0 * (double) ht->ht_fill / (double) ht->ht_size);
-  fprintf (out_FILE, _("Rehash=%d, "), ht->ht_rehashes);
-  fprintf (out_FILE, _("Collisions=%ld/%ld=%.0f%%"), ht->ht_collisions, ht->ht_lookups,
-	   (ht->ht_lookups
-	    ? (100.0 * (double) ht->ht_collisions / (double) ht->ht_lookups)
-	    : 0));
+  Hash_table *new_table;
+  struct hash_entry *bucket;
+  struct hash_entry *cursor;
+  struct hash_entry *next;
+
+  new_table = hash_initialize (candidate, table->tuning, table->hasher,
+			       table->comparator, table->data_freer);
+  if (new_table == NULL)
+    return false;
+
+  /* Merely reuse the extra old space into the new table.  */
+#if USE_OBSTACK
+  obstack_free (&new_table->entry_stack, NULL);
+  new_table->entry_stack = table->entry_stack;
+#endif
+  new_table->free_entry_list = table->free_entry_list;
+
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
+    if (bucket->data)
+      for (cursor = bucket; cursor; cursor = next)
+	{
+	  void *data = cursor->data;
+	  struct hash_entry *new_bucket
+	    = (new_table->bucket
+	       + new_table->hasher (data, new_table->n_buckets));
+
+	  assert (new_bucket < new_table->bucket_limit);
+	  next = cursor->next;
+
+	  if (new_bucket->data)
+	    {
+	      if (cursor == bucket)
+		{
+		  /* Allocate or recycle an entry, when moving from a bucket
+		     header into a bucket overflow.  */
+		  struct hash_entry *new_entry = allocate_entry (new_table);
+
+		  if (new_entry == NULL)
+		    return false;
+
+		  new_entry->data = data;
+		  new_entry->next = new_bucket->next;
+		  new_bucket->next = new_entry;
+		}
+	      else
+		{
+		  /* Merely relink an existing entry, when moving from a
+		     bucket overflow into a bucket overflow.  */
+		  cursor->next = new_bucket->next;
+		  new_bucket->next = cursor;
+		}
+	    }
+	  else
+	    {
+	      /* Free an existing entry, when moving from a bucket
+		 overflow into a bucket header.  Also take care of the
+		 simple case of moving from a bucket header into a bucket
+		 header.  */
+	      new_bucket->data = data;
+	      new_table->n_buckets_used++;
+	      if (cursor != bucket)
+		free_entry (new_table, cursor);
+	    }
+	}
+
+  free (table->bucket);
+  table->bucket = new_table->bucket;
+  table->bucket_limit = new_table->bucket_limit;
+  table->n_buckets = new_table->n_buckets;
+  table->n_buckets_used = new_table->n_buckets_used;
+  table->free_entry_list = new_table->free_entry_list;
+  /* table->n_entries already holds its value.  */
+#if USE_OBSTACK
+  table->entry_stack = new_table->entry_stack;
+#endif
+  free (new_table);
+
+  return true;
 }
 
-/* Dump all items into a NULL-terminated vector.  Use the
-   user-supplied vector, or malloc one.  */
+/* If ENTRY matches an entry already in the hash table, return the pointer
+   to the entry from the table.  Otherwise, insert ENTRY and return ENTRY.
+   Return NULL if the storage required for insertion cannot be allocated.  */
 
-void**
-hash_dump (struct hash_table *ht, void **vector_0, qsort_cmp_t compare)
+void *
+hash_insert (Hash_table *table, const void *entry)
 {
-  void **vector;
-  void **slot;
-  void **end = &ht->ht_vec[ht->ht_size];
-
-  if (vector_0 == 0)
-    vector_0 = XMALLOC (void *, ht->ht_fill + 1);
-  vector = vector_0;
-
-  for (slot = ht->ht_vec; slot < end; slot++)
-    if (!HASH_VACANT (*slot))
-      *vector++ = *slot;
-  *vector = 0;
-
-  if (compare)
-    qsort (vector_0, ht->ht_fill, sizeof (void *), compare);
-  return vector_0;
+  void *data;
+  struct hash_entry *bucket;
+
+  assert (entry);		/* cannot insert a NULL entry */
+
+  /* If there's a matching entry already in the table, return that.  */
+  if ((data = hash_find_entry (table, entry, &bucket, false)) != NULL)
+    return data;
+
+  /* ENTRY is not matched, it should be inserted.  */
+
+  if (bucket->data)
+    {
+      struct hash_entry *new_entry = allocate_entry (table);
+
+      if (new_entry == NULL)
+	return NULL;
+
+      /* Add ENTRY in the overflow of the bucket.  */
+
+      new_entry->data = (void *) entry;
+      new_entry->next = bucket->next;
+      bucket->next = new_entry;
+      table->n_entries++;
+      return (void *) entry;
+    }
+
+  /* Add ENTRY right in the bucket head.  */
+
+  bucket->data = (void *) entry;
+  table->n_entries++;
+  table->n_buckets_used++;
+
+  /* If the growth threshold of the buckets in use has been reached, increase
+     the table size and rehash.  There's no point in checking the number of
+     entries:  if the hashing function is ill-conditioned, rehashing is not
+     likely to improve it.  */
+
+  if (table->n_buckets_used
+      > table->tuning->growth_threshold * table->n_buckets)
+    {
+      /* Check more fully, before starting real work.  If tuning arguments
+	 became invalid, the second check will rely on proper defaults.  */
+      check_tuning (table);
+      if (table->n_buckets_used
+	  > table->tuning->growth_threshold * table->n_buckets)
+	{
+	  const Hash_tuning *tuning = table->tuning;
+	  unsigned candidate
+	    = (unsigned) (tuning->is_n_buckets
+			  ? (table->n_buckets * tuning->growth_factor)
+			  : (table->n_buckets * tuning->growth_factor
+			     * tuning->growth_threshold));
+
+	  /* If the rehash fails, arrange to return NULL.  */
+	  if (!hash_rehash (table, candidate))
+	    entry = NULL;
+	}
+    }
+
+  return (void *) entry;
 }
 
-/* Round a given number up to the nearest power of 2. */
+/* If ENTRY is already in the table, remove it and return the just-deleted
+   data (the user may want to deallocate its storage).  If ENTRY is not in the
+   table, don't modify the table and return NULL.  */
 
-static unsigned long
-round_up_2 (unsigned long rough)
+void *
+hash_delete (Hash_table *table, const void *entry)
+{
+  void *data;
+  struct hash_entry *bucket;
+
+  data = hash_find_entry (table, entry, &bucket, true);
+  if (!data)
+    return NULL;
+
+  table->n_entries--;
+  if (!bucket->data)
+    {
+      table->n_buckets_used--;
+
+      /* If the shrink threshold of the buckets in use has been reached,
+	 rehash into a smaller table.  */
+
+      if (table->n_buckets_used
+	  < table->tuning->shrink_threshold * table->n_buckets)
+	{
+	  /* Check more fully, before starting real work.  If tuning arguments
+	     became invalid, the second check will rely on proper defaults.  */
+	  check_tuning (table);
+	  if (table->n_buckets_used
+	      < table->tuning->shrink_threshold * table->n_buckets)
+	    {
+	      const Hash_tuning *tuning = table->tuning;
+	      unsigned candidate
+		= (unsigned) (tuning->is_n_buckets
+			      ? table->n_buckets * tuning->shrink_factor
+			      : (table->n_buckets * tuning->shrink_factor
+				 * tuning->growth_threshold));
+
+	      hash_rehash (table, candidate);
+	    }
+	}
+    }
+
+  return data;
+}
+
+/* Testing.  */
+
+#if TESTING
+
+void
+hash_print (const Hash_table *table)
 {
-  int round;
+  struct hash_entry *bucket;
 
-  round = 1;
-  while (rough)
+  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
     {
-      round <<= 1;
-      rough >>= 1;
+      struct hash_entry *cursor;
+
+      if (bucket)
+	printf ("%d:\n", slot);
+
+      for (cursor = bucket; cursor; cursor = cursor->next)
+	{
+	  char *s = (char *) cursor->data;
+	  /* FIXME */
+	  printf ("  %s\n", s);
+	}
     }
-  return round;
 }
+
+#endif /* TESTING */
