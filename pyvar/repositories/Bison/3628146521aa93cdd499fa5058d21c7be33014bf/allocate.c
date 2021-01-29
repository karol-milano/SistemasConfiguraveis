@@ -60,7 +60,7 @@ xmalloc (register unsigned n)
       done (1);
     }
 
-  return (block);
+  return block;
 }
 
 char *
@@ -76,5 +76,5 @@ xrealloc (register char *block, register unsigned n)
       done (1);
     }
 
-  return (block);
+  return block;
 }
