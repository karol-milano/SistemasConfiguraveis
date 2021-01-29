@@ -35,8 +35,6 @@ static char *conflicts = NULL;
 
 static unsigned *shiftset = NULL;
 static unsigned *lookaheadset = NULL;
-static int src_total;
-static int rrc_total;
 static int src_count;
 static int rrc_count;
 
@@ -460,6 +458,8 @@ void
 print_conflicts (FILE *out)
 {
   int i;
+  int src_total;
+  int rrc_total;
 
   src_total = 0;
   rrc_total = 0;
