@@ -103,7 +103,17 @@ uniqstr_print_processor (void *ustr, void *null ATTRIBUTE_UNUSED)
   return uniqstr_print (ustr);
 }
 
-
+
+int
+uniqstr_cmp(uniqstr l, uniqstr r)
+{
+  return (l == r ? 0
+          : !l ? -1
+          : !r ? +1
+          : strcmp (l, r));
+}
+
+
 /*-----------------------.
 | A uniqstr hash table.  |
 `-----------------------*/
@@ -120,6 +130,7 @@ hash_uniqstr (void const *m, size_t tablesize)
   return hash_string (m, tablesize);
 }
 
+
 /*----------------------------.
 | Create the uniqstrs table.  |
 `----------------------------*/
