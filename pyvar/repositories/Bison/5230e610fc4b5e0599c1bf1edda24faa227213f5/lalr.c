@@ -40,6 +40,7 @@
 #include "relation.h"
 #include "symtab.h"
 
+/* goto_map[nterm - NTOKENS] -> number of gotos.  */
 goto_number *goto_map = NULL;
 goto_number ngotos = 0;
 state_number *from_state = NULL;
@@ -70,8 +71,7 @@ static goto_list **lookback;
 void
 set_goto_map (void)
 {
-  goto_number *temp_map = xnmalloc (nvars + 1, sizeof *temp_map);
-
+  /* Count the number of gotos (ngotos) per nterm (goto_map). */
   goto_map = xcalloc (nvars + 1, sizeof *goto_map);
   ngotos = 0;
   for (state_number s = 0; s < nstates; ++s)
@@ -80,14 +80,13 @@ set_goto_map (void)
       for (int i = sp->num - 1; 0 <= i && TRANSITION_IS_GOTO (sp, i); --i)
         {
           ngotos++;
-
           /* Abort if (ngotos + 1) would overflow.  */
           aver (ngotos != GOTO_NUMBER_MAXIMUM);
-
           goto_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
         }
     }
 
+  goto_number *temp_map = xnmalloc (nvars + 1, sizeof *temp_map);
   {
     goto_number k = 0;
     for (symbol_number i = ntokens; i < nsyms; ++i)
