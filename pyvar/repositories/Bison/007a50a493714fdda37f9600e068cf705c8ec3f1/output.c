@@ -417,7 +417,7 @@ action_row (state_t *state)
 
       /* Do not use any default reduction if there is a shift for
 	 error */
-      if (symbol == error_token_number)
+      if (symbol == errtoken->number)
 	nodefault = 1;
     }
 
@@ -614,7 +614,7 @@ token_definitions_output (FILE *out)
       if (number == SALIAS)
 	continue;
       /* Skip error token.  */
-      if (symbol->number == error_token_number)
+      if (symbol == errtoken)
 	continue;
       if (symbol->tag[0] == '\'')
 	continue;               /* skip literal character */
@@ -1078,7 +1078,8 @@ prepare (void)
   MUSCLE_INSERT_INT ("nsym", nsyms);
   MUSCLE_INSERT_INT ("debug", debug_flag);
   MUSCLE_INSERT_INT ("final", final_state);
-  MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
+  MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
+  MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
   MUSCLE_INSERT_INT ("error_verbose", error_verbose);
   MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
 
