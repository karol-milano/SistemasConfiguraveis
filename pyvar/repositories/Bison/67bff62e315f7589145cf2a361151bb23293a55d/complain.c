@@ -308,6 +308,8 @@ complain_init_color (void)
 void
 complain_init (void)
 {
+  caret_init ();
+
   warnings warnings_default =
     Wconflicts_sr | Wconflicts_rr | Wdeprecated | Wother;
 
