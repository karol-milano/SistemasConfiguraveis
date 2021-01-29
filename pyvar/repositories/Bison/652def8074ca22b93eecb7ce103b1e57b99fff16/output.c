@@ -947,26 +947,20 @@ output_actions (void)
   output_check ();
 }
 
-/*------------------------------------------.
-| Copy the parser code into TABLE_OBSTACK.  |
-`------------------------------------------*/
+
+/*------------------------------------------------------------.
+| Copy the parser code from SKEL_FILENAME into OOUT obstack.  |
+| and do the muscle substitution.                             |
+`------------------------------------------------------------*/
 
 static void
-output_parser (void)
+output_parser (const char *skel_filename, struct obstack *oout)
 {
   int c;
   FILE *fskel;
   size_t line;
 
-  /* Loop over lines in the standard parser file.  */
-  if (!skeleton)
-    {
-      if (semantic_parser)
-	skeleton = skeleton_find ("BISON_HAIRY", BISON_HAIRY);
-      else
-	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
-    }
-  fskel = xfopen (skeleton, "r");
+  fskel = xfopen (skel_filename, "r");
 
   /* New output code.  */
   line = 1;
@@ -977,7 +971,7 @@ output_parser (void)
 	{
 	  if (c == '\n')
 	    ++line;
-	  obstack_1grow (&table_obstack, c);
+	  obstack_1grow (oout, c);
 	  c = getc (fskel);
 	}
       else if ((c = getc (fskel)) == '%')
@@ -985,6 +979,7 @@ output_parser (void)
 	  /* Read the muscle.  */
 	  const char *muscle_key = 0;
 	  const char *muscle_value = 0;
+
 	  while (isalnum (c = getc (fskel)) || c == '_')
 	    obstack_1grow (&muscle_obstack, c);
 	  obstack_1grow (&muscle_obstack, 0);
@@ -993,29 +988,49 @@ output_parser (void)
 	  muscle_key = obstack_finish (&muscle_obstack);
 	  muscle_value = muscle_find (muscle_key);
 	  if (muscle_value)
-	    obstack_sgrow (&table_obstack, muscle_value);
+	    obstack_sgrow (oout, muscle_value);
 	  else if (!strcmp (muscle_key, "line"))
-	    obstack_fgrow1 (&table_obstack, "%d", line + 1);
+	    obstack_fgrow1 (oout, "%d", line + 1);
 	  else if (!strcmp (muscle_key, "action"))
 	    {
 	      size_t size = obstack_object_size (&action_obstack);
-	      obstack_grow (&table_obstack, 
-			    obstack_finish (&action_obstack), size);
+	      obstack_grow (oout, obstack_base (&action_obstack), size);
 	    }
+	  /* FIXME: Insert the code to recognize %%sub-skeleton for exemple.  */
 	  else
 	    {
-	      obstack_sgrow (&table_obstack, "%%");
-	      obstack_sgrow (&table_obstack, muscle_key);
+	      obstack_sgrow (oout, "%%");
+	      obstack_sgrow (oout, muscle_key);
 	    }
 	}
       else
-	obstack_1grow (&table_obstack, '%');
+	obstack_1grow (oout, '%');
     }
 
   /* End.  */
   xfclose (fskel);
 }
 
+/*----------------------------------------.
+| Prepare the master parser to be output  |
+`----------------------------------------*/
+
+static void
+output_master_parser (void)
+{
+  if (!skeleton)
+    {
+      if (semantic_parser)
+	skeleton = skeleton_find ("BISON_HAIRY", BISON_HAIRY);
+      else
+	skeleton = skeleton_find ("BISON_SIMPLE", BISON_SIMPLE);
+    }
+  
+  obstack_finish (&action_obstack);
+  output_parser (skeleton, &table_obstack);
+}
+
+
 static void
 free_itemsets (void)
 {
@@ -1103,7 +1118,8 @@ output (void)
   prepare ();
   /* Copy definitions in directive.  */
   muscle_insert ("prologue", obstack_finish (&attrs_obstack));
-  output_parser ();
+
+  output_master_parser ();
 
   obstack_free (&muscle_obstack, 0);
   obstack_free (&output_obstack, 0);
