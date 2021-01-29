@@ -24,6 +24,7 @@
 #include "system.h"
 
 #include <assure.h>
+#include <fstrcmp.h>
 #include <hash.h>
 
 #include "complain.h"
@@ -32,6 +33,8 @@
 #include "quote.h"
 
 
+static struct hash_table *symbol_table = NULL;
+static struct hash_table *semantic_type_table = NULL;
 
 /*----------------------------------------------------------------.
 | Symbols sorted by tag.  Allocated by table_sort, after which no |
@@ -41,6 +44,7 @@
 static symbol **symbols_sorted = NULL;
 static semantic_type **semantic_types_sorted = NULL;
 
+
 /*------------------------.
 | Distinguished symbols.  |
 `------------------------*/
@@ -321,15 +325,54 @@ complain_class_redeclared (symbol *sym, symbol_class class, location second)
     }
 }
 
+static const symbol *
+symbol_from_uniqstr_fuzzy (const uniqstr key)
+{
+  aver (symbols_sorted);
+#define FSTRCMP_THRESHOLD 0.6
+  double best_similarity = FSTRCMP_THRESHOLD;
+  const symbol *res = NULL;
+  size_t count = hash_get_n_entries (symbol_table);
+  for (int i = 0; i < count; ++i)
+    {
+      symbol *sym = symbols_sorted[i];
+      if (STRNEQ (key, sym->tag)
+          && (sym->content->status == declared
+              || sym->content->status == undeclared))
+        {
+          double similarity = fstrcmp_bounded (key, sym->tag, best_similarity);
+          if (best_similarity < similarity)
+            {
+              res = sym;
+              best_similarity = similarity;
+            }
+        }
+    }
+  return res;
+}
+
 static void
 complain_symbol_undeclared (symbol *sym)
 {
   assert (sym->content->status != declared);
-  complain (&sym->location,
-            sym->content->status == needed ? complaint : Wother,
-            _("symbol %s is used, but is not defined as a token"
-              " and has no rules"),
-            quote (sym->tag));
+  const symbol *best = symbol_from_uniqstr_fuzzy (sym->tag);
+  if (best)
+    {
+      complain (&sym->location,
+                sym->content->status == needed ? complaint : Wother,
+                _("symbol %s is used, but is not defined as a token"
+                  " and has no rules; did you mean %s?"),
+                quote_n (0, sym->tag),
+                quote_n (1, best->tag));
+      if (feature_flag & feature_caret)
+        location_caret_suggestion (sym->location, best->tag, stderr);
+    }
+  else
+    complain (&sym->location,
+              sym->content->status == needed ? complaint : Wother,
+              _("symbol %s is used, but is not defined as a token"
+                " and has no rules"),
+              quote (sym->tag));
 }
 
 void
@@ -694,9 +737,6 @@ symbol_translation (symbol *this)
 /* Initial capacity of symbol and semantic type hash table.  */
 #define HT_INITIAL_CAPACITY 257
 
-static struct hash_table *symbol_table = NULL;
-static struct hash_table *semantic_type_table = NULL;
-
 static inline bool
 hash_compare_symbol (const symbol *m1, const symbol *m2)
 {
