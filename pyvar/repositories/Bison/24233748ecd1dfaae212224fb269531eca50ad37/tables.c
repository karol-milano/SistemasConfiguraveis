@@ -512,7 +512,14 @@ default_goto (symbol_number sym, size_t state_count[])
 {
   const goto_number begin = goto_map[sym - ntokens];
   const goto_number end = goto_map[sym - ntokens + 1];
-  state_number res = -1;
+
+  /* In the case this symbol is never reduced to ($accept), use state
+     0.  We used to use -1, but as a result the yydefgoto table must
+     be signed, which (1) might trigger compiler warnings when storing
+     a value from yydefgoto into a state number (nonnegative), and (2)
+     wastes bits which might result in using a int16 where a uint8
+     suffices. */
+  state_number res = 0;
 
   if (begin != end)
     {
