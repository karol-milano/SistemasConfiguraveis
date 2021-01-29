@@ -708,8 +708,8 @@ action_row (int state)
   register int i;
   register int j;
   register int k;
-  register int m;
-  register int n;
+  register int m = 0;
+  register int n = 0;
   register int count;
   register int default_rule;
   register int nreds;
@@ -1165,7 +1165,7 @@ pack_vector (int vector)
   register int j;
   register int k;
   register int t;
-  register int loc;
+  register int loc = 0;
   register int ok;
   register short *from;
   register short *to;
