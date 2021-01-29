@@ -1667,6 +1667,25 @@ readgram (void)
 
   ntokens = nsyms - nvars;
 }
+
+/* At the end of the grammar file, some C source code must
+   be stored. It is going to be associated to the user_code
+   directive.  */
+static void
+read_additionnal_code (void)
+{
+  char c;
+  struct obstack uc_obstack;
+  
+  obstack_init (&uc_obstack);
+
+  while ((c = getc (finput)) != EOF)
+    obstack_1grow (&uc_obstack, c);
+  
+  obstack_1grow (&uc_obstack, 0);
+  macro_insert ("user_code", obstack_finish (&uc_obstack));
+}
+
 
 /*--------------------------------------------------------------.
 | For named tokens, but not literal ones, define the name.  The |
@@ -2016,6 +2035,8 @@ reader (void)
   /* Read in the grammar, build grammar in list form.  Write out
      guards and actions.  */
   readgram ();
+  /* Some C code is given at the end of the grammar file. */
+  read_additionnal_code ();
   /* Now we know whether we need the line-number stack.  If we do,
      write its type into the .tab.h file.  */
 #if 0
