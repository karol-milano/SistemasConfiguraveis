@@ -427,8 +427,8 @@ skeleton_arg (char const *arg, int prio, location loc)
       skeleton = arg;
     }
   else if (prio == skeleton_prio)
-    complain_at (loc, complaint,
-                 _("multiple skeleton declarations are invalid"));
+    complain (&loc, complaint,
+              _("multiple skeleton declarations are invalid"));
 }
 
 void
@@ -453,7 +453,7 @@ language_argmatch (char const *arg, int prio, location loc)
   else
     return;
 
-  complain_at (loc, complaint, msg, quotearg_colon (arg));
+  complain (&loc, complaint, msg, quotearg_colon (arg));
 }
 
 /*----------------------.
