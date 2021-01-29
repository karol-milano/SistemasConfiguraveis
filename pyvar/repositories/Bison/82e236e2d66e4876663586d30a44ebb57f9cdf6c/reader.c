@@ -907,9 +907,6 @@ parse_macro_decl (void)
   int ch = ungetc (skip_white_space (), finput);
   char* macro_key;
   char* macro_value;
-  struct obstack macro_obstack;
-
-  obstack_init (&macro_obstack);
 
   /* Read key. */
   if (!isalpha (ch) && ch != '_')
@@ -919,6 +916,7 @@ parse_macro_decl (void)
       return;
     }
   copy_identifier (finput, &macro_obstack);
+  obstack_1grow (&macro_obstack, 0);
   macro_key = obstack_finish (&macro_obstack);
   
   /* Read value. */
@@ -935,11 +933,10 @@ parse_macro_decl (void)
       else
 	fatal (_("Premature EOF after %s"), "\"");
     }
-  copy_string (finput, &macro_obstack, '"');
+  copy_string2 (finput, &macro_obstack, '"', 0);
+  obstack_1grow (&macro_obstack, 0);
   macro_value = obstack_finish (&macro_obstack);
 
-  obstack_free (&macro_obstack, 0);
-
   /* Store the (key, value) pair in the environment. */
   macro_insert (macro_key, macro_value);
 }
@@ -1991,6 +1988,9 @@ reader (void)
   init_lex ();
   lineno = 1;
 
+  /* Initialize the macro obstack.  */
+  obstack_init (&macro_obstack);
+
   /* Initialize the symbol table.  */
   tabinit ();
 
