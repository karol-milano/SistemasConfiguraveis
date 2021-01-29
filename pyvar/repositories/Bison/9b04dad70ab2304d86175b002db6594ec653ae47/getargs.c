@@ -385,11 +385,7 @@ skeleton_arg (char const *arg, int prio, location loc)
       skeleton = arg;
     }
   else if (prio == skeleton_prio)
-    {
-      char const *msg =
-	_("multiple skeleton declarations are invalid");
-      complain_at (loc, msg);
-    }
+    complain_at (loc, _("multiple skeleton declarations are invalid"));
 }
 
 void
