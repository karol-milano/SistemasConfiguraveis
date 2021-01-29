@@ -29,11 +29,12 @@ bucket **symtab;
 bucket *firstsymbol;
 bucket *lastsymbol;
 
+void tabinit PARAMS((void));
+void free_symtab PARAMS((void));
 
 
-int
-hash(key)
-char *key;
+static int
+hash (char *key)
 {
   register char *cp;
   register int k;
@@ -48,9 +49,8 @@ char *key;
 
 
 
-char *
-copys(s)
-char *s;
+static char *
+copys (char *s)
 {
   register int i;
   register char *cp;
@@ -67,7 +67,7 @@ char *s;
 
 
 void
-tabinit()
+tabinit (void)
 {
 /*   register int i; JF unused */
 
@@ -79,8 +79,7 @@ tabinit()
 
 
 bucket *
-getsym(key)
-char *key;
+getsym (char *key)
 {
   register int hashval;
   register bucket *bp;
@@ -127,7 +126,7 @@ char *key;
 
 
 void
-free_symtab()
+free_symtab (void)
 {
   register int i;
   register bucket *bp,*bptmp;/* JF don't use ptr after free */
