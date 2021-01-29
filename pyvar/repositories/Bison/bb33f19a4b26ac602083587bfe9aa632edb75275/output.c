@@ -306,9 +306,9 @@ prepare_states (void)
 
 
 
-/*----------------------------------.
-| Output the user actions to OOUT.  |
-`----------------------------------*/
+/*---------------------------------.
+| Output the user actions to OUT.  |
+`---------------------------------*/
 
 static void
 user_actions_output (FILE *out)
@@ -620,7 +620,7 @@ prepare (void)
     }
 
   /* Parse the skeleton file and output the needed parsers.  */
-  muscle_insert ("skeleton", skeleton);
+  muscle_insert ("skeleton", xstrdup (skeleton));
 }
 
 
