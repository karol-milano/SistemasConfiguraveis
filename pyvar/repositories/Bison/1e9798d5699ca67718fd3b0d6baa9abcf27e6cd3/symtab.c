@@ -43,6 +43,31 @@ hash (const char *key)
   return k % TABSIZE;
 }
 
+/*--------------------------------------------------------------.
+| Create a new symbol, named TAG, which hash value is HASHVAL.  |
+`--------------------------------------------------------------*/
+
+static bucket *
+bucket_new (const char *tag, int hashval)
+{
+  bucket *res = XMALLOC (bucket, 1);
+
+  res->link = symtab[hashval];
+  res->next = NULL;
+  res->tag = xstrdup (tag);
+  res->type_name = NULL;
+  res->value = 0;
+  res->prec = 0;
+  res->assoc = right_assoc;
+  res->user_token_number = 0;
+  res->alias = NULL;
+  res->class = unknown_sym;
+
+  nsyms++;
+
+  return res;
+}
+
 
 void
 tabinit (void)
@@ -54,6 +79,11 @@ tabinit (void)
 }
 
 
+/*----------------------------------------------------------------.
+| Find the symbol named KEY, and return it.  If it does not exist |
+| yet, create it.                                                 |
+`----------------------------------------------------------------*/
+
 bucket *
 getsym (const char *key)
 {
@@ -75,13 +105,7 @@ getsym (const char *key)
 
   if (found == 0)
     {
-      nsyms++;
-
-      bp = XCALLOC (bucket, 1);
-      bp->link = symtab[hashval];
-      bp->next = NULL;
-      bp->tag = xstrdup (key);
-      bp->class = unknown_sym;
+      bp = bucket_new (key, hashval);
 
       if (firstsymbol == NULL)
 	{
