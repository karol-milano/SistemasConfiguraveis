@@ -1666,21 +1666,21 @@ readgram (void)
 }
 
 /* At the end of the grammar file, some C source code must
-   be stored. It is going to be associated to the user_code
+   be stored. It is going to be associated to the epilogue
    directive.  */
 static void
 read_additionnal_code (void)
 {
   char c;
-  struct obstack uc_obstack;
+  struct obstack el_obstack;
   
-  obstack_init (&uc_obstack);
+  obstack_init (&el_obstack);
 
   while ((c = getc (finput)) != EOF)
-    obstack_1grow (&uc_obstack, c);
+    obstack_1grow (&el_obstack, c);
   
-  obstack_1grow (&uc_obstack, 0);
-  macro_insert ("user_code", obstack_finish (&uc_obstack));
+  obstack_1grow (&el_obstack, 0);
+  macro_insert ("epilogue", obstack_finish (&el_obstack));
 }
 
 
