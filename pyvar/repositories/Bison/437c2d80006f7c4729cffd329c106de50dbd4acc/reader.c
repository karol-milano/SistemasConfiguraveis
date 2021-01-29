@@ -69,13 +69,9 @@ prologue_augment (const char *prologue, location_t location)
   struct obstack *oout =
     !typed ? &pre_prologue_obstack : &post_prologue_obstack;
 
-  if (!no_lines_flag)
-    {
-      obstack_fgrow2 (oout, muscle_find ("linef"),
-		      location.first_line,
-		      quotearg_style (c_quoting_style,
-				      location.file));
-    }
+  obstack_fgrow2 (oout, "]b4_syncline([[%d]], [[%s]])[\n",
+	   location.first_line,
+	   quotearg_style (escape_quoting_style, location.file));
   obstack_sgrow (oout, prologue);
 }
 
@@ -89,13 +85,9 @@ prologue_augment (const char *prologue, location_t location)
 void
 epilogue_set (const char *epilogue, location_t location)
 {
-  if (!no_lines_flag)
-    {
-      obstack_fgrow2 (&muscle_obstack, muscle_find ("linef"),
-		      location.first_line,
-		      quotearg_style (c_quoting_style,
-				      location.file));
-    }
+  obstack_fgrow2 (&muscle_obstack, "]b4_syncline([[%d]], [[%s]])[\n",
+		  location.first_line,
+		  quotearg_style (escape_quoting_style, location.file));
   obstack_sgrow (&muscle_obstack, epilogue);
   obstack_1grow (&muscle_obstack, 0);
   muscle_insert ("epilogue", obstack_finish (&muscle_obstack));
