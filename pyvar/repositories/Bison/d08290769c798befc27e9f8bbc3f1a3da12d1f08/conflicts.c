@@ -365,7 +365,7 @@ count_sr_conflicts (state *s)
 +`----------------------------------------------------------------*/
 
 static int
-count_rr_conflicts (state *s, int one_per_token)
+count_rr_conflicts (state *s, bool one_per_token)
 {
   int i;
   reductions *reds = s->reductions;
@@ -463,7 +463,7 @@ conflicts_print (void)
   /* Is the number of SR conflicts OK?  Either EXPECTED_CONFLICTS is
      not set, and then we want 0 SR, or else it is specified, in which
      case we want equality.  */
-  int src_ok = 0;
+  bool src_ok = false;
 
   int src_total = 0;
   int rrc_total = 0;
