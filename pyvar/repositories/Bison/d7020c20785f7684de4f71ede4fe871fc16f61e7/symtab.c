@@ -101,7 +101,7 @@ getsym (const char *key)
       bp->link = symtab[hashval];
       bp->next = NULL;
       bp->tag = copys(key);
-      bp->class = SUNKNOWN;
+      bp->class = unknown_sym;
 
       if (firstsymbol == NULL)
 	{
