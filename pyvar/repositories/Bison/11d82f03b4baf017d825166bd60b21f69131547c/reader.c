@@ -34,7 +34,7 @@
 #include "output.h"
 #include "reader.h"
 #include "conflicts.h"
-#include "macrotab.h"
+#include "muscle_tab.h"
 
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 static int rline_allocated;
@@ -750,7 +750,7 @@ parse_union_decl (void)
   if (!no_lines_flag)
     obstack_fgrow2 (&attrs_obstack, "\n#line %d %s\n",
 		    lineno, quotearg_style (c_quoting_style, 
-					    macro_find("filename")));
+					    muscle_find("filename")));
   else
     obstack_1grow (&attrs_obstack, '\n');
 
@@ -903,11 +903,11 @@ parse_thong_decl (void)
 /* FIXME. */
 
 static void
-parse_macro_decl (void)
+parse_muscle_decl (void)
 {
   int ch = ungetc (skip_white_space (), finput);
-  char* macro_key;
-  char* macro_value;
+  char* muscle_key;
+  char* muscle_value;
 
   /* Read key. */
   if (!isalpha (ch) && ch != '_')
@@ -916,9 +916,9 @@ parse_macro_decl (void)
       skip_to_char ('%');
       return;
     }
-  copy_identifier (finput, &macro_obstack);
-  obstack_1grow (&macro_obstack, 0);
-  macro_key = obstack_finish (&macro_obstack);
+  copy_identifier (finput, &muscle_obstack);
+  obstack_1grow (&muscle_obstack, 0);
+  muscle_key = obstack_finish (&muscle_obstack);
   
   /* Read value. */
   ch = skip_white_space ();
@@ -934,12 +934,12 @@ parse_macro_decl (void)
       else
 	fatal (_("Premature EOF after %s"), "\"");
     }
-  copy_string2 (finput, &macro_obstack, '"', 0);
-  obstack_1grow (&macro_obstack, 0);
-  macro_value = obstack_finish (&macro_obstack);
+  copy_string2 (finput, &muscle_obstack, '"', 0);
+  obstack_1grow (&muscle_obstack, 0);
+  muscle_value = obstack_finish (&muscle_obstack);
 
   /* Store the (key, value) pair in the environment. */
-  macro_insert (macro_key, macro_value);
+  muscle_insert (muscle_key, muscle_value);
 }
 
 
@@ -1061,7 +1061,7 @@ read_declarations (void)
 	      break;
 
 	    case tok_define:
-	      parse_macro_decl ();
+	      parse_muscle_decl ();
 	      break;
 	      
 	    case tok_skel:
@@ -1113,7 +1113,7 @@ copy_action (symbol_list *rule, int stack_offset)
     {
       sprintf (buf, "#line %d %s\n",
 	       lineno, quotearg_style (c_quoting_style, 
-				       macro_find ("filename")));
+				       muscle_find ("filename")));
       obstack_grow (&action_obstack, buf, strlen (buf));
     }
   obstack_1grow (&action_obstack, '{');
@@ -1202,7 +1202,7 @@ copy_guard (symbol_list *rule, int stack_offset)
   if (!no_lines_flag)
     obstack_fgrow2 (&guard_obstack, "#line %d %s\n",
 		    lineno, quotearg_style (c_quoting_style,
-					    macro_find ("filename")));
+					    muscle_find ("filename")));
   obstack_1grow (&guard_obstack, '{');
 
   count = 0;
@@ -1683,7 +1683,7 @@ read_additionnal_code (void)
     obstack_1grow (&el_obstack, c);
   
   obstack_1grow (&el_obstack, 0);
-  macro_insert ("epilogue", obstack_finish (&el_obstack));
+  muscle_insert ("epilogue", obstack_finish (&el_obstack));
 }
 
 
@@ -1853,7 +1853,7 @@ packsymbols (void)
 
   output_token_defines (&output_obstack);
   obstack_1grow (&output_obstack, 0);
-  macro_insert ("tokendef", obstack_finish (&output_obstack));
+  muscle_insert ("tokendef", obstack_finish (&output_obstack));
 
 #if 0
   if (!no_parser_flag)
@@ -2005,8 +2005,8 @@ reader (void)
   init_lex ();
   lineno = 1;
 
-  /* Initialize the macro obstack.  */
-  obstack_init (&macro_obstack);
+  /* Initialize the muscle obstack.  */
+  obstack_init (&muscle_obstack);
 
   /* Initialize the symbol table.  */
   tabinit ();
