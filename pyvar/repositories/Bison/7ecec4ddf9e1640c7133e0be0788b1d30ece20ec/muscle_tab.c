@@ -191,18 +191,15 @@ muscle_code_grow (const char *key, const char *val, location loc)
 }
 
 
-/*-------------------------------------------------------------------.
-| MUSCLE is an M4 list of pairs.  Create or extend it with the pair  |
-| (A1, A2).  Note that because the muscle values are output *double* |
-| quoted, one needs to strip the first level of quotes to reach the  |
-| list itself.                                                       |
-`-------------------------------------------------------------------*/
-
 void muscle_pair_list_grow (const char *muscle,
 			    const char *a1, const char *a2)
 {
   char *pair;
-  obstack_fgrow2 (&muscle_obstack, "[[[%s]], [[%s]]]", a1, a2);
+  obstack_sgrow (&muscle_obstack, "[[[");
+  MUSCLE_OBSTACK_SGROW (&muscle_obstack, a1);
+  obstack_sgrow (&muscle_obstack, "]], [[");
+  MUSCLE_OBSTACK_SGROW (&muscle_obstack, a2);
+  obstack_sgrow (&muscle_obstack, "]]]");
   obstack_1grow (&muscle_obstack, 0);
   pair = obstack_finish (&muscle_obstack);
   muscle_grow (muscle, pair, ",\n");
