@@ -35,9 +35,9 @@
 | Create a new array of N shifts/gotos.  |
 `---------------------------------------*/
 
-#define TRANSITIONS_ALLOC(Nshifts)						\
-  (transitions_t *) xcalloc ((unsigned) (sizeof (transitions_t) 			\
-                                  + (Nshifts - 1) * sizeof (state_number_t)), 1)
+#define TRANSITIONS_ALLOC(Num)					\
+  (transitions_t *) xcalloc ((sizeof (transitions_t) 			\
+                                  + (Num - 1) * sizeof (state_number_t)), 1)
 
 static transitions_t *
 transitions_new (int num, state_number_t *the_states)
