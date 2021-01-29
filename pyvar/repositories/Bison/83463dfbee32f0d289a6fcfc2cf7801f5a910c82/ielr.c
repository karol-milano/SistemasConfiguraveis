@@ -540,7 +540,7 @@ typedef struct state_list
   /**
    * nextIsocore is the next state in a circularly linked-list of all states
    * with the same core.  The one originally computed by generate_states in
-   * LR0.c is lr0Isocore.
+   * lr0.c is lr0Isocore.
    */
   struct state_list *lr0Isocore;
   struct state_list *nextIsocore;
