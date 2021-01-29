@@ -536,7 +536,7 @@ print_reductions (int state)
   register int m;
   register int n;
   register int default_LA;
-  register int default_rule;
+  register int default_rule = 0;
   register int cmax;
   register int count;
   register shifts *shiftp;
