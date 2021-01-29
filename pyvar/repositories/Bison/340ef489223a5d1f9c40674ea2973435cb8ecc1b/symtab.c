@@ -29,10 +29,6 @@ bucket *firstsymbol;
 static bucket *lastsymbol;
 static bucket **symtab;
 
-extern void tabinit PARAMS((void));
-extern void free_symtab PARAMS((void));
-
-
 static int
 hash (const char *key)
 {
