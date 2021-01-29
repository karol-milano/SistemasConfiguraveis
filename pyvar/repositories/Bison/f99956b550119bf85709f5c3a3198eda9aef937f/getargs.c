@@ -506,7 +506,7 @@ skeleton_arg (char const *arg, int prio, location loc)
 void
 language_argmatch (char const *arg, int prio, location loc)
 {
-  char const *msg;
+  char const *msg = NULL;
 
   if (prio < language_prio)
     {
@@ -521,10 +521,9 @@ language_argmatch (char const *arg, int prio, location loc)
     }
   else if (language_prio == prio)
     msg = _("multiple language declarations are invalid");
-  else
-    return;
 
-  complain (&loc, complaint, msg, quotearg_colon (arg));
+  if (msg)
+    complain (&loc, complaint, msg, quotearg_colon (arg));
 }
 
 /*----------------------.
