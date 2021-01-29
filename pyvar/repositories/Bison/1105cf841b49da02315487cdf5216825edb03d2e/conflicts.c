@@ -431,7 +431,7 @@ conflicts_update_state_numbers (state_number old_to_new[],
 `---------------------------------------------*/
 
 static size_t
-count_state_sr_conflicts (state *s)
+count_state_sr_conflicts (const state *s)
 {
   transitions *trans = s->transitions;
   reductions *reds = s->reductions;
@@ -479,7 +479,7 @@ count_sr_conflicts (void)
 `-----------------------------------------------------------------*/
 
 static size_t
-count_state_rr_conflicts (state *s)
+count_state_rr_conflicts (const state *s)
 {
   reductions *reds = s->reductions;
   size_t res = 0;
@@ -591,24 +591,22 @@ conflicts_output (FILE *out)
 {
   bool printed_sth = false;
   for (state_number i = 0; i < nstates; ++i)
-    {
-      state *s = states[i];
-      if (conflicts[i])
-        {
-          int src = count_state_sr_conflicts (s);
-          int rrc = count_state_rr_conflicts (s);
-          fprintf (out, _("State %d "), i);
-          if (src && rrc)
-            fprintf (out,
-                     _("conflicts: %d shift/reduce, %d reduce/reduce\n"),
-                     src, rrc);
-          else if (src)
-            fprintf (out, _("conflicts: %d shift/reduce\n"), src);
-          else if (rrc)
-            fprintf (out, _("conflicts: %d reduce/reduce\n"), rrc);
-          printed_sth = true;
-        }
-    }
+    if (conflicts[i])
+      {
+        const state *s = states[i];
+        int src = count_state_sr_conflicts (s);
+        int rrc = count_state_rr_conflicts (s);
+        fprintf (out, _("State %d "), i);
+        if (src && rrc)
+          fprintf (out,
+                   _("conflicts: %d shift/reduce, %d reduce/reduce\n"),
+                   src, rrc);
+        else if (src)
+          fprintf (out, _("conflicts: %d shift/reduce\n"), src);
+        else if (rrc)
+          fprintf (out, _("conflicts: %d reduce/reduce\n"), rrc);
+        printed_sth = true;
+      }
   if (printed_sth)
     fputs ("\n\n", out);
 }
