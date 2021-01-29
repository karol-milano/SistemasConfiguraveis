@@ -27,7 +27,7 @@
 
 /* comments for these variables are in gram.h  */
 
-short *ritem = NULL;
+item_number_t *ritem = NULL;
 int nritems = 0;
 
 rule_t *rules = NULL;
@@ -59,7 +59,7 @@ int
 rule_rhs_length (rule_t *rule)
 {
   int res = 0;
-  short *rhsp;
+  item_number_t *rhsp;
   for (rhsp = rule->rhs; *rhsp >= 0; ++rhsp)
     ++res;
   return res;
