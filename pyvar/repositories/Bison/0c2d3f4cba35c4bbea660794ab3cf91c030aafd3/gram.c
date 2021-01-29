@@ -29,7 +29,7 @@
 /* comments for these variables are in gram.h  */
 
 item_number_t *ritem = NULL;
-int nritems = 0;
+unsigned int nritems = 0;
 
 rule_t *rules = NULL;
 int nrules = 0;
@@ -70,7 +70,7 @@ rule_rhs_length (rule_t *rule)
 void
 ritem_print (FILE *out)
 {
-  int i;
+  unsigned int i;
   fputs ("RITEM\n", out);
   for (i = 0; i < nritems; ++i)
     if (ritem[i] >= 0)
