@@ -154,6 +154,26 @@ muscle_grow (const char *key, const char *val, const char *separator)
 }
 
 
+/*------------------------------------------------------------------.
+| Append VALUE to the current value of KEY, using muscle_grow.  But |
+| in addition, issue a synchronization line for the location LOC.   |
+`------------------------------------------------------------------*/
+
+void
+muscle_code_grow (const char *key, const char *val, location loc)
+{
+  char *extension = NULL;
+  obstack_fgrow1 (&muscle_obstack, "]b4_syncline([[%d]], [[", loc.start.line);
+  MUSCLE_OBSTACK_SGROW (&muscle_obstack,
+			quotearg_style (c_quoting_style, loc.start.file));
+  obstack_sgrow (&muscle_obstack, "]])[\n");
+  obstack_sgrow (&muscle_obstack, val);
+  obstack_1grow (&muscle_obstack, 0);
+  extension = obstack_finish (&muscle_obstack);
+  muscle_grow (key, extension, "");
+}
+
+
 /*-------------------------------------------------------------------.
 | MUSCLE is an M4 list of pairs.  Create or extend it with the pair  |
 | (A1, A2).  Note that because the muscle values are output *double* |
