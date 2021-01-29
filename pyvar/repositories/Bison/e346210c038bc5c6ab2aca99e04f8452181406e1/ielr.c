@@ -36,7 +36,36 @@
 #include "symtab.h"
 
 /** Records the value of the \%define variable lr.type.  */
-typedef enum { LR_TYPE__LALR, LR_TYPE__IELR, LR_TYPE__CANONICAL_LR } LrType;
+typedef enum
+  {
+   LR_TYPE__LR0,
+   LR_TYPE__LALR,
+   LR_TYPE__IELR,
+   LR_TYPE__CANONICAL_LR
+  } LrType;
+
+/* The user's requested LR type.  */
+static LrType
+lr_type_get (void)
+{
+  char *type = muscle_percent_define_get ("lr.type");
+  LrType res;
+  if (STREQ (type, "lr(0)"))
+    res = LR_TYPE__LR0;
+  else if (STREQ (type, "lalr"))
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
 
 /**
  * \post:
@@ -1052,46 +1081,39 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
 }
 
 
-/* The user's requested LR type.  */
-static LrType
-lr_type_get (void)
-{
-  char *type = muscle_percent_define_get ("lr.type");
-  LrType res;
-  if (STREQ (type, "lalr"))
-    res = LR_TYPE__LALR;
-  else if (STREQ (type, "ielr"))
-    res = LR_TYPE__IELR;
-  else if (STREQ (type, "canonical-lr"))
-    res = LR_TYPE__CANONICAL_LR;
-  else
-    {
-      aver (false);
-      abort ();
-    }
-  free (type);
-  return res;
-}
-
-
 void
 ielr (void)
 {
   LrType lr_type = lr_type_get ();
 
   /* Phase 0: LALR(1).  */
-  timevar_push (tv_lalr);
-  if (lr_type == LR_TYPE__CANONICAL_LR)
-    set_goto_map ();
-  else
-    lalr ();
-  if (lr_type == LR_TYPE__LALR)
+  switch (lr_type)
     {
+    case LR_TYPE__LR0:
+      timevar_push (tv_lalr);
+      set_goto_map ();
+      timevar_pop (tv_lalr);
+      return;
+
+    case LR_TYPE__CANONICAL_LR:
+      timevar_push (tv_lalr);
+      set_goto_map ();
+      timevar_pop (tv_lalr);
+      break;
+
+    case LR_TYPE__LALR:
+      timevar_push (tv_lalr);
+      lalr ();
       bitsetv_free (goto_follows);
       timevar_pop (tv_lalr);
       return;
+
+    case LR_TYPE__IELR:
+      timevar_push (tv_lalr);
+      lalr ();
+      timevar_pop (tv_lalr);
+      break;
     }
-  timevar_pop (tv_lalr);
 
   {
     bitsetv follow_kernel_items;
