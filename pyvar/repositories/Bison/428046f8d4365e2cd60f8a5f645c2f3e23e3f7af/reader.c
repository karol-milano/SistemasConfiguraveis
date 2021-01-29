@@ -753,6 +753,7 @@ parse_union_decl (void)
 {
   int c;
   int count = 0;
+  bool done = FALSE;
   struct obstack union_obstack;
   const char *prologue = "\
 #ifndef YYSTYPE\n\
@@ -779,10 +780,10 @@ typedef union";
   if (defines_flag)
     obstack_sgrow (&defines_obstack, prologue);
 
-  c = getc (finput);
-
-  while (c != EOF)
+  while (!done)
     {
+      c = xgetc (finput);
+
       /* If C contains '/', it is output by copy_comment ().  */
       if (c != '/')
 	{
@@ -806,26 +807,24 @@ typedef union";
 	  break;
 
 	case '}':
+	  /* FIXME: Errr.  How could this happen???. --akim */
 	  if (count == 0)
 	    complain (_("unmatched %s"), "`}'");
 	  count--;
-	  if (count <= 0)
-	    {
-	      if (defines_flag)
-		obstack_sgrow (&defines_obstack, epilogue);
-	      /* JF don't choke on trailing semi */
-	      c = skip_white_space ();
-	      if (c != ';')
-		ungetc (c, finput);
-	      obstack_1grow (&union_obstack, 0);
-	      muscle_insert ("stype", obstack_finish (&union_obstack));
-	      return;
-	    }
+	  if (!count)
+	    done = TRUE;
+	  break;
 	}
-
-      c = getc (finput);
     }
 
+  if (defines_flag)
+    obstack_sgrow (&defines_obstack, epilogue);
+  /* JF don't choke on trailing semi */
+  c = skip_white_space ();
+  if (c != ';')
+    ungetc (c, finput);
+  obstack_1grow (&union_obstack, 0);
+  muscle_insert ("stype", obstack_finish (&union_obstack));
 }
 
 
