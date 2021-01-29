@@ -69,9 +69,10 @@ prologue_augment (const char *prologue, location_t location)
   struct obstack *oout =
     !typed ? &pre_prologue_obstack : &post_prologue_obstack;
 
-  obstack_fgrow2 (oout, "]b4_syncline([[%d]], [[%s]])[\n",
-	   location.first_line,
-	   quotearg_style (escape_quoting_style, location.file));
+  obstack_fgrow1 (oout, "]b4_syncline([[%d]], [[",
+		  location.first_line);
+  MUSCLE_OBSTACK_SGROW (oout, quotearg_style (c_quoting_style, location.file));
+  obstack_sgrow (oout, "]])[\n");
   obstack_sgrow (oout, prologue);
 }
 
@@ -85,9 +86,11 @@ prologue_augment (const char *prologue, location_t location)
 void
 epilogue_set (const char *epilogue, location_t location)
 {
-  obstack_fgrow2 (&muscle_obstack, "]b4_syncline([[%d]], [[%s]])[\n",
-		  location.first_line,
-		  quotearg_style (escape_quoting_style, location.file));
+  obstack_fgrow1 (&muscle_obstack, "]b4_syncline([[%d]], [[",
+		  location.first_line);
+  MUSCLE_OBSTACK_SGROW (&muscle_obstack,
+			quotearg_style (c_quoting_style, location.file));
+  obstack_sgrow (&muscle_obstack, "]])[\n");
   obstack_sgrow (&muscle_obstack, epilogue);
   obstack_1grow (&muscle_obstack, 0);
   muscle_insert ("epilogue", obstack_finish (&muscle_obstack));
