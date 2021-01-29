@@ -401,7 +401,8 @@ skeleton_arg (char const *arg, int prio, location loc)
       skeleton = arg;
     }
   else if (prio == skeleton_prio)
-    complain_at (loc, _("multiple skeleton declarations are invalid"));
+    complain_at (loc, complaint,
+                 _("multiple skeleton declarations are invalid"));
 }
 
 void
@@ -426,7 +427,7 @@ language_argmatch (char const *arg, int prio, location loc)
   else
     return;
 
-  complain_at (loc, msg, quotearg_colon (arg));
+  complain_at (loc, complaint, msg, quotearg_colon (arg));
 }
 
 /*----------------------.
