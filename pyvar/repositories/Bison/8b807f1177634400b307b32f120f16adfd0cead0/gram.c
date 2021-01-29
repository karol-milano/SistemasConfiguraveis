@@ -93,16 +93,14 @@ rule_rhs_length (rule const *r)
 void
 rule_rhs_print (rule const *r, FILE *out)
 {
-  if (*r->rhs >= 0)
+  if (0 <= *r->rhs)
     {
       item_number *rp;
       for (rp = r->rhs; *rp >= 0; rp++)
         fprintf (out, " %s", symbols[*rp]->tag);
     }
   else
-    {
-      fprintf (out, " /* %s */", _("empty"));
-    }
+    fputs (" %empty", out);
 }
 
 static void
