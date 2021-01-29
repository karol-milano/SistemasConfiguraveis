@@ -966,7 +966,7 @@ parse_muscle_decl (void)
 
 
 /*---------------------------------.
-| Parse a double quoted parameter. |       
+| Parse a double quoted parameter. |
 `---------------------------------*/
 
 static const char *
@@ -994,7 +994,7 @@ parse_dquoted_param (const char *from)
       else
 	break;
     }
-  
+
   obstack_1grow (&param_obstack, '\0');
   param = obstack_finish (&param_obstack);
 
@@ -1014,7 +1014,7 @@ parse_dquoted_param (const char *from)
 | Parse what comes after %skeleton. |
 `----------------------------------*/
 
-void
+static void
 parse_skel_decl (void)
 {
   skeleton = parse_dquoted_param ("%skeleton");
@@ -1133,7 +1133,6 @@ copy_action (symbol_list *rule, int stack_offset)
 {
   int c;
   int count;
-  char buf[4096];
 
   /* offset is always 0 if parser has already popped the stack pointer */
   if (semantic_parser)
