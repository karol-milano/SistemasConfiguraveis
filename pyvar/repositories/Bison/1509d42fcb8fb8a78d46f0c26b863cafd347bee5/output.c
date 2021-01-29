@@ -1289,6 +1289,7 @@ output_check (void)
   XFREE (check);
 }
 
+
 /*-----------------------------------------------------------------.
 | Compute and output yydefact, yydefgoto, yypact, yypgoto, yytable |
 | and yycheck.                                                     |
@@ -1378,7 +1379,9 @@ output_skeleton (void)
   fputs ("m4_divert_push(0)dnl\n", out);
   xfclose (out);
 
+  timevar_push (TV_M4);
   m4_invoke (tempfile);
+  timevar_pop (TV_M4);
 
   /* If `debugging', keep this file alive. */
   if (!(trace_flag & trace_tools))
@@ -1451,7 +1454,9 @@ output (void)
   prepare_tokens ();
   prepare_rules ();
   prepare_states ();
+  timevar_push (TV_ACTIONS);
   prepare_actions ();
+  timevar_pop (TV_ACTIONS);
 
   prepare ();
 
