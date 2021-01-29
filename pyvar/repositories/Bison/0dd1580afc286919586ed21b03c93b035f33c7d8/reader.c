@@ -591,7 +591,7 @@ copy_dollar (FILE *fin, struct obstack *oout,
 `-------------------------------------------------------------------*/
 
 static void
-copy_definition (void)
+copy_definition (struct obstack *oout)
 {
   int c;
   /* -1 while reading a character if prev char was %. */
@@ -599,7 +599,7 @@ copy_definition (void)
 
   if (!no_lines_flag)
     {
-      obstack_fgrow2 (&attrs_obstack, muscle_find ("linef"),
+      obstack_fgrow2 (oout, muscle_find ("linef"),
 		      lineno, quotearg_style (c_quoting_style,
 					      muscle_find ("filename")));
     }
@@ -613,7 +613,7 @@ copy_definition (void)
       switch (c)
 	{
 	case '\n':
-	  obstack_1grow (&attrs_obstack, c);
+	  obstack_1grow (oout, c);
 	  ++lineno;
 	  break;
 
@@ -623,18 +623,18 @@ copy_definition (void)
 
 	case '\'':
 	case '"':
-	  copy_string (finput, &attrs_obstack, c);
+	  copy_string (finput, oout, c);
 	  break;
 
 	case '/':
-	  copy_comment (finput, &attrs_obstack);
+	  copy_comment (finput, oout);
 	  break;
 
 	case EOF:
 	  fatal ("%s", _("unterminated `%{' definition"));
 
 	default:
-	  obstack_1grow (&attrs_obstack, c);
+	  obstack_1grow (oout, c);
 	}
 
       c = getc (finput);
@@ -643,7 +643,7 @@ copy_definition (void)
 	{
 	  if (c == '}')
 	    return;
-	  obstack_1grow (&attrs_obstack, '%');
+	  obstack_1grow (oout, '%');
 	}
       after_percent = 0;
     }
@@ -1154,7 +1154,7 @@ parse_skel_decl (void)
 /*----------------------------------------------------------------.
 | Read from finput until `%%' is seen.  Discard the `%%'.  Handle |
 | any `%' declarations, and copy the contents of any `%{ ... %}'  |
-| groups to ATTRS_OBSTACK.                                        |
+| groups to PRE_PROLOGUE_OBSTACK or POST_PROLOGUE_OBSTACK.        |
 `----------------------------------------------------------------*/
 
 static void
@@ -1174,7 +1174,10 @@ read_declarations (void)
 	      return;
 
 	    case tok_percent_left_curly:
-	      copy_definition ();
+              if (!typed)
+		copy_definition (&pre_prologue_obstack);
+	      else
+		copy_definition (&post_prologue_obstack);
 	      break;
 
 	    case tok_token:
@@ -1854,8 +1857,9 @@ reader (void)
 
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
-  obstack_init (&attrs_obstack);
   obstack_init (&output_obstack);
+  obstack_init (&pre_prologue_obstack);
+  obstack_init (&post_prologue_obstack);
 
   finput = xfopen (infile, "r");
 
