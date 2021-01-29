@@ -51,21 +51,17 @@ struniq_new (const char *s)
 }
 
 
-/*---------------------------------.
-| Return TRUE iff S is a struniq.  |
-`---------------------------------*/
+/*------------------------------.
+| Abort if S is not a struniq.  |
+`------------------------------*/
 
-bool
-struniq_assert_p (const char *s)
+void
+struniq_assert (const char *s)
 {
   if (!hash_lookup (struniqs_table, s))
     {
       error (0, 0, "not a struniq: %s", quotearg (s));
-      return false;
-    }
-  else
-    {
-      return true;
+      abort ();
     }
 }
 
