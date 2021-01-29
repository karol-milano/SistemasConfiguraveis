@@ -78,29 +78,6 @@ prologue_augment (const char *prologue, location loc)
   obstack_sgrow (oout, prologue);
 }
 
-
-
-
-/*----------------------.
-| Handle the epilogue.  |
-`----------------------*/
-
-void
-epilogue_augment (const char *epilogue, location loc)
-{
-  char *extension = NULL;
-  obstack_fgrow1 (&muscle_obstack, "]b4_syncline([[%d]], [[", loc.start.line);
-  MUSCLE_OBSTACK_SGROW (&muscle_obstack,
-			quotearg_style (c_quoting_style, loc.start.file));
-  obstack_sgrow (&muscle_obstack, "]])[\n");
-  obstack_sgrow (&muscle_obstack, epilogue);
-  obstack_1grow (&muscle_obstack, 0);
-  extension = obstack_finish (&muscle_obstack);
-  muscle_grow ("epilogue", extension, "");
-  obstack_free (&muscle_obstack, extension);
-}
-
-
 
 
 /*-------------------------------------------------------------------.
