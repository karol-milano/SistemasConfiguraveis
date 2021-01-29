@@ -139,7 +139,7 @@ log_resolution (rule_t *rule, int token,
 static void
 flush_shift (state_t *state, int token)
 {
-  shifts *shiftp = state->shifts;
+  shifts_t *shiftp = state->shifts;
   int i;
 
   bitset_reset (lookaheadset, token);
@@ -249,7 +249,7 @@ static void
 set_conflicts (state_t *state)
 {
   int i;
-  shifts *shiftp;
+  shifts_t *shiftp;
 
   if (state->consistent)
     return;
@@ -308,7 +308,7 @@ count_sr_conflicts (state_t *state)
 {
   int i;
   int src_count = 0;
-  shifts *shiftp = state->shifts;
+  shifts_t *shiftp = state->shifts;
 
   if (!shiftp)
     return 0;
