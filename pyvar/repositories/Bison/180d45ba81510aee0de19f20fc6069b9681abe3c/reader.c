@@ -735,9 +735,9 @@ token_buffer);
 
 
 /*--------------------------------------------------------------.
-| Copy the union declaration into ATTRS_OBSTACK (and fdefines), |
-| where it is made into the definition of YYSTYPE, the type of  |
-| elements of the parser value stack.                           |
+| Copy the union declaration into the stype muscle		|
+| (and fdefines),  where it is made into the definition of	|
+| YYSTYPE, the type of elements of the parser value stack.	|
 `--------------------------------------------------------------*/
 
 static void
@@ -745,23 +745,18 @@ parse_union_decl (void)
 {
   int c;
   int count = 0;
+  struct obstack union_obstack;
 
   if (typed)
     complain (_("multiple %s declarations"), "%union");
 
   typed = 1;
 
-
-  if (!no_lines_flag)
-    {
-      obstack_fgrow2 (&attrs_obstack, muscle_find ("linef"),
-		      lineno, quotearg_style (c_quoting_style, 
-					      muscle_find("filename")));
-    }
-  else
+  if (no_lines_flag)
     obstack_1grow (&attrs_obstack, '\n');
   
-  obstack_sgrow (&attrs_obstack, "typedef union");
+  obstack_init (&union_obstack);
+  obstack_sgrow (&union_obstack, "union");
   if (defines_flag)
     obstack_sgrow (&defines_obstack, "typedef union");
 
@@ -769,7 +764,7 @@ parse_union_decl (void)
 
   while (c != EOF)
     {
-      obstack_1grow (&attrs_obstack, c);
+      obstack_1grow (&union_obstack, c);
       if (defines_flag)
 	obstack_1grow (&defines_obstack, c);
 
@@ -780,7 +775,7 @@ parse_union_decl (void)
 	  break;
 
 	case '/':
-	  copy_comment2 (finput, &defines_obstack, &attrs_obstack);
+	  copy_comment2 (finput, &defines_obstack, &union_obstack);
 	  break;
 
 	case '{':
@@ -793,19 +788,21 @@ parse_union_decl (void)
 	  count--;
 	  if (count <= 0)
 	    {
-	      obstack_sgrow (&attrs_obstack, " YYSTYPE;\n");
 	      if (defines_flag)
 		obstack_sgrow (&defines_obstack, " YYSTYPE;\n");
 	      /* JF don't choke on trailing semi */
 	      c = skip_white_space ();
 	      if (c != ';')
 		ungetc (c, finput);
+	      obstack_1grow (&union_obstack, 0);
+	      muscle_insert ("stype", obstack_finish (&union_obstack));
 	      return;
 	    }
 	}
 
       c = getc (finput);
     }
+
 }
 
 
