@@ -31,8 +31,8 @@ Boston, MA 02111-1307, USA.  */
 
 char *nullable;
 
-void free_nullable PARAMS((void));
-void set_nullable PARAMS((void));
+extern void free_nullable PARAMS((void));
+extern void set_nullable PARAMS((void));
 
 void
 set_nullable (void)
