@@ -233,25 +233,22 @@ copy_identifier (FILE *fin, struct obstack *oout)
   ungetc (c, fin);
 }
 
-/*-----------------------------------------------------------------.
-| Dump the wannabee comment from IN to OUT1 and OUT2 (which can be |
-| NULL).  In fact we just saw a `/', which might or might not be a |
-| comment.  In any case, copy what we saw.                         |
-|                                                                  |
-| OUT2 might be NULL.                                              |
-`-----------------------------------------------------------------*/
+
+/*------------------------------------------------------------------.
+| Dump the wannabee comment from IN to OOUT.  In fact we just saw a |
+| `/', which might or might not be a comment.  In any case, copy    |
+| what we saw.                                                      |
+`------------------------------------------------------------------*/
 
 static inline void
-copy_comment2 (FILE *fin, struct obstack *oout1, struct obstack *oout2)
+copy_comment (FILE *fin, struct obstack *oout)
 {
   int cplus_comment;
   int ended;
   int c;
 
   /* We read a `/', output it. */
-  obstack_1grow (oout1, '/');
-  if (oout2)
-    obstack_1grow (oout2, '/');
+  obstack_1grow (oout, '/');
 
   switch ((c = getc (fin)))
     {
@@ -266,9 +263,7 @@ copy_comment2 (FILE *fin, struct obstack *oout1, struct obstack *oout2)
       return;
     }
 
-  obstack_1grow (oout1, c);
-  if (oout2)
-    obstack_1grow (oout2, c);
+  obstack_1grow (oout, c);
   c = getc (fin);
 
   ended = 0;
@@ -278,26 +273,20 @@ copy_comment2 (FILE *fin, struct obstack *oout1, struct obstack *oout2)
 	{
 	  while (c == '*')
 	    {
-	      obstack_1grow (oout1, c);
-	      if (oout2)
-		obstack_1grow (oout2, c);
+	      obstack_1grow (oout, c);
 	      c = getc (fin);
 	    }
 
 	  if (c == '/')
 	    {
-	      obstack_1grow (oout1, c);
-	      if (oout2)
-		obstack_1grow (oout2, c);
+	      obstack_1grow (oout, c);
 	      ended = 1;
 	    }
 	}
       else if (c == '\n')
 	{
 	  lineno++;
-	  obstack_1grow (oout1, c);
-	  if (oout2)
-	    obstack_1grow (oout2, c);
+	  obstack_1grow (oout, c);
 	  if (cplus_comment)
 	    ended = 1;
 	  else
@@ -307,27 +296,13 @@ copy_comment2 (FILE *fin, struct obstack *oout1, struct obstack *oout2)
 	fatal (_("unterminated comment"));
       else
 	{
-	  obstack_1grow (oout1, c);
-	  if (oout2)
-	    obstack_1grow (oout2, c);
+	  obstack_1grow (oout, c);
 	  c = getc (fin);
 	}
     }
 }
 
 
-/*-------------------------------------------------------------------.
-| Dump the comment (actually the current string starting with a `/') |
-| from FIN to OOUT.                                                  |
-`-------------------------------------------------------------------*/
-
-static inline void
-copy_comment (FILE *fin, struct obstack *oout)
-{
-  copy_comment2 (fin, oout, NULL);
-}
-
-
 /*-----------------------------------------------------------------.
 | FIN is pointing to a location (i.e., a `@').  Output to OOUT a   |
 | reference to this location. STACK_OFFSET is the number of values |
@@ -755,30 +730,13 @@ parse_union_decl (void)
   int count = 0;
   bool done = FALSE;
   struct obstack union_obstack;
-  const char *prologue = "\
-#ifndef YYSTYPE\n\
-typedef union";
-  const char *epilogue = "\
- yystype;\n\
-# define YYSTYPE yystype\n\
-#endif\n";
-
   if (typed)
     complain (_("multiple %s declarations"), "%union");
 
   typed = 1;
 
-  /* FIXME: I'm worried: are you sure attrs_obstack is properly
-     filled?  */
-  /* I don't see any reasons to keep this line, because we should
-     create a special skeleton for this option.  */
-  if (no_lines_flag)
-    obstack_1grow (&attrs_obstack, '\n');
-
   obstack_init (&union_obstack);
   obstack_sgrow (&union_obstack, "union");
-  if (defines_flag)
-    obstack_sgrow (&defines_obstack, prologue);
 
   while (!done)
     {
@@ -786,11 +744,7 @@ typedef union";
 
       /* If C contains '/', it is output by copy_comment ().  */
       if (c != '/')
-	{
-	  obstack_1grow (&union_obstack, c);
-	  if (defines_flag)
-	    obstack_1grow (&defines_obstack, c);
-	}
+	obstack_1grow (&union_obstack, c);
 
       switch (c)
 	{
@@ -799,7 +753,7 @@ typedef union";
 	  break;
 
 	case '/':
-	  copy_comment2 (finput, &defines_obstack, &union_obstack);
+	  copy_comment (finput, &union_obstack);
 	  break;
 
 	case '{':
@@ -817,14 +771,21 @@ typedef union";
 	}
     }
 
-  if (defines_flag)
-    obstack_sgrow (&defines_obstack, epilogue);
   /* JF don't choke on trailing semi */
   c = skip_white_space ();
   if (c != ';')
     ungetc (c, finput);
   obstack_1grow (&union_obstack, 0);
   muscle_insert ("stype", obstack_finish (&union_obstack));
+
+  if (defines_flag)
+    obstack_fgrow1 (&defines_obstack, "\
+#ifndef YYSTYPE\n\
+typedef %s
+yystype;\n\
+# define YYSTYPE yystype\n\
+#endif\n",
+		    muscle_find ("stype"));
 }
 
 
