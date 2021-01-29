@@ -32,7 +32,7 @@
 /* Comments for these variables are in gram.h.  */
 
 item_number *ritem = NULL;
-unsigned int nritems = 0;
+unsigned nritems = 0;
 
 rule *rules = NULL;
 rule_number nrules = 0;
@@ -126,7 +126,7 @@ rule_rhs_print_xml (rule const *r, FILE *out, int level)
 void
 ritem_print (FILE *out)
 {
-  unsigned int i;
+  unsigned i;
   fputs ("RITEM\n", out);
   for (i = 0; i < nritems; ++i)
     if (ritem[i] >= 0)
@@ -254,8 +254,8 @@ grammar_dump (FILE *out, const char *title)
       {
         rule const *rule_i = &rules[i];
         item_number *rp = NULL;
-        unsigned int rhs_itemno = rule_i->rhs - ritem;
-        unsigned int rhs_count = 0;
+        unsigned rhs_itemno = rule_i->rhs - ritem;
+        unsigned rhs_count = 0;
         /* Find the last RHS index in ritems. */
         for (rp = rule_i->rhs; *rp >= 0; ++rp)
           ++rhs_count;
