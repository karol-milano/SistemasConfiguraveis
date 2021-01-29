@@ -471,7 +471,7 @@ token_actions (void)
 static void
 save_column (symbol_number sym, state_number default_state)
 {
-  int i;
+  goto_number i;
   base_number *sp;
   base_number *sp1;
   base_number *sp2;
@@ -515,7 +515,7 @@ static state_number
 default_goto (symbol_number sym, short int state_count[])
 {
   state_number s;
-  int i;
+  goto_number i;
   goto_number m = goto_map[sym - ntokens];
   goto_number n = goto_map[sym - ntokens + 1];
   state_number default_state = -1;
