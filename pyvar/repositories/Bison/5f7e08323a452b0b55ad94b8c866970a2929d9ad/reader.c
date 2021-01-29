@@ -741,6 +741,13 @@ parse_union_decl (void)
   int c;
   int count = 0;
   struct obstack union_obstack;
+  const char *prologue = "\
+#ifndef YYSTYPE\n\
+typedef union";
+  const char *epilogue = "\
+ yystype;\n\
+# define YYSTYPE yystype\n\
+#endif\n";
 
   if (typed)
     complain (_("multiple %s declarations"), "%union");
@@ -749,13 +756,15 @@ parse_union_decl (void)
 
   /* FIXME: I'm worried: are you sure attrs_obstack is properly
      filled?  */
+  /* I don't see any reasons to keep this line, because we should
+     create a special skeleton for this option.  */
   if (no_lines_flag)
     obstack_1grow (&attrs_obstack, '\n');
 
   obstack_init (&union_obstack);
   obstack_sgrow (&union_obstack, "union");
   if (defines_flag)
-    obstack_sgrow (&defines_obstack, "typedef union");
+    obstack_sgrow (&defines_obstack, prologue);
 
   c = getc (finput);
 
@@ -790,7 +799,7 @@ parse_union_decl (void)
 	  if (count <= 0)
 	    {
 	      if (defines_flag)
-		obstack_sgrow (&defines_obstack, " YYSTYPE;\n");
+		obstack_sgrow (&defines_obstack, epilogue);
 	      /* JF don't choke on trailing semi */
 	      c = skip_white_space ();
 	      if (c != ';')
