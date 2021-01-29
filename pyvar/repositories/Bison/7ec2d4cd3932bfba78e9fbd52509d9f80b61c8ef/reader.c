@@ -84,8 +84,9 @@ prologue_augment (const char *prologue, location_t location)
 `----------------------*/
 
 void
-epilogue_set (const char *epilogue, location_t location)
+epilogue_augment (const char *epilogue, location_t location)
 {
+  char *extension = NULL;
   obstack_fgrow1 (&muscle_obstack, "]b4_syncline([[%d]], [[",
 		  location.first_line);
   MUSCLE_OBSTACK_SGROW (&muscle_obstack,
@@ -93,7 +94,9 @@ epilogue_set (const char *epilogue, location_t location)
   obstack_sgrow (&muscle_obstack, "]])[\n");
   obstack_sgrow (&muscle_obstack, epilogue);
   obstack_1grow (&muscle_obstack, 0);
-  muscle_insert ("epilogue", obstack_finish (&muscle_obstack));
+  extension = obstack_finish (&muscle_obstack);
+  muscle_grow ("epilogue", extension, "");
+  obstack_free (&muscle_obstack, extension);
 }
 
 
