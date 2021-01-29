@@ -1095,11 +1095,11 @@ ielr (void)
   /* Examine user options.  */
   {
     char *type = muscle_percent_define_get ("lr.type");
-    if (0 == strcmp (type, "LALR"))
+    if (0 == strcmp (type, "lalr"))
       lr_type = LR_TYPE__LALR;
-    else if (0 == strcmp (type, "IELR"))
+    else if (0 == strcmp (type, "ielr"))
       lr_type = LR_TYPE__IELR;
-    else if (0 == strcmp (type, "canonical LR"))
+    else if (0 == strcmp (type, "canonical-lr"))
       lr_type = LR_TYPE__CANONICAL_LR;
     else
       aver (false);
