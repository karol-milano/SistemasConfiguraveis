@@ -1051,27 +1051,33 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
     }
 }
 
+
+/* The user's requested LR type.  */
+static LrType
+lr_type_get (void)
+{
+  char *type = muscle_percent_define_get ("lr.type");
+  LrType res;
+  if (STREQ (type, "lalr"))
+    res = LR_TYPE__LALR;
+  else if (STREQ (type, "ielr"))
+    res = LR_TYPE__IELR;
+  else if (STREQ (type, "canonical-lr"))
+    res = LR_TYPE__CANONICAL_LR;
+  else
+    {
+      aver (false);
+      abort ();
+    }
+  free (type);
+  return res;
+}
+
+
 void
 ielr (void)
 {
-  LrType lr_type;
-
-  /* Examine user options.  */
-  {
-    char *type = muscle_percent_define_get ("lr.type");
-    if (STREQ (type, "lalr"))
-      lr_type = LR_TYPE__LALR;
-    else if (STREQ (type, "ielr"))
-      lr_type = LR_TYPE__IELR;
-    else if (STREQ (type, "canonical-lr"))
-      lr_type = LR_TYPE__CANONICAL_LR;
-    else
-      {
-        aver (false);
-        abort ();
-      }
-    free (type);
-  }
+  LrType lr_type = lr_type_get ();
 
   /* Phase 0: LALR(1).  */
   timevar_push (tv_lalr);
