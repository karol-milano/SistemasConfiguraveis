@@ -74,7 +74,7 @@ prologue_augment (const char *prologue, location_t location)
       obstack_fgrow2 (oout, muscle_find ("linef"),
 		      location.first_line,
 		      quotearg_style (c_quoting_style,
-				      muscle_find ("filename")));
+				      location.file));
     }
   obstack_sgrow (oout, prologue);
 }
@@ -94,7 +94,7 @@ epilogue_set (const char *epilogue, location_t location)
       obstack_fgrow2 (&muscle_obstack, muscle_find ("linef"),
 		      location.first_line,
 		      quotearg_style (c_quoting_style,
-				      muscle_find ("filename")));
+				      location.file));
     }
   obstack_sgrow (&muscle_obstack, epilogue);
   obstack_1grow (&muscle_obstack, 0);
