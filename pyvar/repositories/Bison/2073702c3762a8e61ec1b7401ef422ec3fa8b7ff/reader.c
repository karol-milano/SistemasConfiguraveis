@@ -70,8 +70,9 @@ prologue_augment (const char *prologue, location_t location)
     !typed ? &pre_prologue_obstack : &post_prologue_obstack;
 
   obstack_fgrow1 (oout, "]b4_syncline([[%d]], [[",
-		  location.first_line);
-  MUSCLE_OBSTACK_SGROW (oout, quotearg_style (c_quoting_style, location.file));
+		  location.start.line);
+  MUSCLE_OBSTACK_SGROW (oout, quotearg_style (c_quoting_style,
+					      location.start.file));
   obstack_sgrow (oout, "]])[\n");
   obstack_sgrow (oout, prologue);
 }
@@ -88,9 +89,9 @@ epilogue_augment (const char *epilogue, location_t location)
 {
   char *extension = NULL;
   obstack_fgrow1 (&muscle_obstack, "]b4_syncline([[%d]], [[",
-		  location.first_line);
+		  location.start.line);
   MUSCLE_OBSTACK_SGROW (&muscle_obstack,
-			quotearg_style (c_quoting_style, location.file));
+			quotearg_style (c_quoting_style, location.start.file));
   obstack_sgrow (&muscle_obstack, "]])[\n");
   obstack_sgrow (&muscle_obstack, epilogue);
   obstack_1grow (&muscle_obstack, 0);
