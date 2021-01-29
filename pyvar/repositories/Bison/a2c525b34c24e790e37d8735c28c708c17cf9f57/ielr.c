@@ -1102,7 +1102,10 @@ ielr (void)
     else if (STREQ (type, "canonical-lr"))
       lr_type = LR_TYPE__CANONICAL_LR;
     else
-      aver (false);
+      {
+        aver (false);
+        abort ();
+      }
     free (type);
   }
 
