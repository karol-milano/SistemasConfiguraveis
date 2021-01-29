@@ -42,10 +42,10 @@
 #include "relation.h"
 #include "symtab.h"
 
-goto_number *goto_map = NULL;
-static goto_number ngotos = 0;
-state_number *from_state = NULL;
-state_number *to_state = NULL;
+goto_number *goto_map;
+static goto_number ngotos;
+state_number *from_state;
+state_number *to_state;
 
 /* Linked list of goto numbers.  */
 typedef struct goto_list
@@ -90,9 +90,9 @@ set_goto_map (void)
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
-	  if (ngotos >= GOTO_NUMBER_MAXIMUM)
-	    abort ();
 	  ngotos++;
+	  if (! ngotos)
+	    abort ();
 	  goto_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
 	}
     }
