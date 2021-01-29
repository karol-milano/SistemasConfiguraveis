@@ -99,7 +99,7 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
 /* Output to OUT the location LOC.
    Warning: it uses quotearg's slot 3.  */
 unsigned
-location_print (FILE *out, location loc)
+location_print (location loc, FILE *out)
 {
   unsigned res = 0;
   int end_col = 0 != loc.end.column ? loc.end.column - 1 : 0;
@@ -161,7 +161,7 @@ cleanup_caret ()
 }
 
 void
-location_caret (FILE *out, location loc)
+location_caret (location loc, FILE *out)
 {
   /* FIXME: find a way to support multifile locations, and only open once each
      file. That would make the procedure future-proof.  */
