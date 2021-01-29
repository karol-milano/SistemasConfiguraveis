@@ -61,7 +61,7 @@ errs *
 errs_dup (errs *src)
 {
   errs *res = errs_new (src->nerrs);
-  memcpy (res->errs, src->errs, src->nerrs);
+  memcpy (res->errs, src->errs, src->nerrs * sizeof (src->errs[0]));
   return res;
 }
 
