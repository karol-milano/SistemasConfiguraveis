@@ -45,7 +45,7 @@ hash (char *key)
   while (*cp)
     k = ((k << 1) ^ (*cp++)) & 0x3fff;
 
-  return (k % TABSIZE);
+  return k % TABSIZE;
 }
 
 
@@ -63,7 +63,7 @@ copys (char *s)
 
   result = xmalloc((unsigned int)i);
   strcpy(result, s);
-  return (result);
+  return result;
 }
 
 
@@ -122,7 +122,7 @@ getsym (char *key)
       symtab[hashval] = bp;
     }
 
-  return (bp);
+  return bp;
 }
 
 
