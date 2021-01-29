@@ -41,12 +41,12 @@
 `-----------------------------------------*/
 
 static transitions *
-transitions_new (int num, state **the_states)
+transitions_new (int num, state **dst)
 {
-  size_t states_size = num * sizeof *the_states;
+  size_t states_size = num * sizeof *dst;
   transitions *res = xmalloc (offsetof (transitions, states) + states_size);
   res->num = num;
-  memcpy (res->states, the_states, states_size);
+  memcpy (res->states, dst, states_size);
   return res;
 }
 
@@ -198,10 +198,10 @@ state_free (state *s)
 `---------------------------*/
 
 void
-state_transitions_set (state *s, int num, state **trans)
+state_transitions_set (state *s, int num, state **dst)
 {
   aver (!s->transitions);
-  s->transitions = transitions_new (num, trans);
+  s->transitions = transitions_new (num, dst);
 }
 
 
