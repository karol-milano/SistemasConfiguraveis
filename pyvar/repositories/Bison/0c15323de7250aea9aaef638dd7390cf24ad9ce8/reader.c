@@ -113,7 +113,7 @@ grammar_start_symbol_set (symbol_t *s)
 `----------------------------------------------------------------*/
 
 void
-prologue_augment (const char *prologue, int location)
+prologue_augment (const char *prologue, location_t location)
 {
   struct obstack *oout =
     !typed ? &pre_prologue_obstack : &post_prologue_obstack;
@@ -121,8 +121,9 @@ prologue_augment (const char *prologue, int location)
   if (!no_lines_flag)
     {
       obstack_fgrow2 (oout, muscle_find ("linef"),
-		      location, quotearg_style (c_quoting_style,
-						muscle_find ("filename")));
+		      location.first_line,
+		      quotearg_style (c_quoting_style,
+				      muscle_find ("filename")));
     }
   obstack_sgrow (oout, prologue);
 }
@@ -135,7 +136,7 @@ prologue_augment (const char *prologue, int location)
 `----------------------*/
 
 void
-epilogue_set (const char *epilogue, int location)
+epilogue_set (const char *epilogue, location_t location)
 {
   struct obstack el_obstack;
   obstack_init (&el_obstack);
@@ -143,8 +144,9 @@ epilogue_set (const char *epilogue, int location)
   if (!no_lines_flag)
     {
       obstack_fgrow2 (&el_obstack, muscle_find ("linef"),
-		      location, quotearg_style (c_quoting_style,
-						muscle_find ("filename")));
+		      location.first_line,
+		      quotearg_style (c_quoting_style,
+				      muscle_find ("filename")));
     }
   obstack_sgrow (&el_obstack, epilogue);
   obstack_1grow (&el_obstack, 0);
