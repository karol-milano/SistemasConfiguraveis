@@ -1501,7 +1501,7 @@ readgram (void)
 static void
 read_additionnal_code (void)
 {
-  char c;
+  int c;
   struct obstack el_obstack;
 
   obstack_init (&el_obstack);
