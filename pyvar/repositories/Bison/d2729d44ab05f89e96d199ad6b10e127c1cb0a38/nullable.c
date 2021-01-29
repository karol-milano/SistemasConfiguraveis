@@ -30,9 +30,11 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 char *nullable;
 
+void free_nullable PARAMS((void));
+void set_nullable PARAMS((void));
 
 void
-set_nullable()
+set_nullable (void)
 {
   register short *r;
   register short *s1;
@@ -130,7 +132,7 @@ set_nullable()
 
 
 void
-free_nullable()
+free_nullable (void)
 {
   FREE(nullable + ntokens);
 }
