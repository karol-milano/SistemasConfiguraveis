@@ -103,12 +103,6 @@ main (int argc, char *argv[])
   reader ();
   timevar_pop (tv_reader);
 
-  /* Fix input file now, even if there are errors: that's less
-     warnings in the following runs.  */
-  if (update_flag)
-    fixits_run ();
-  fixits_free ();
-
   if (complaint_status == status_complaint)
     goto finish;
 
@@ -217,7 +211,6 @@ main (int argc, char *argv[])
      contains things such as user actions, prologue, epilogue etc.  */
   gram_scanner_free ();
   muscle_free ();
-  uniqstrs_free ();
   code_scanner_free ();
   skel_scanner_free ();
   quotearg_free ();
@@ -234,5 +227,18 @@ main (int argc, char *argv[])
 
   cleanup_caret ();
 
+  /* Fix input file now, even if there are errors: that's less
+     warnings in the following runs.  */
+  if (!fixits_empty ())
+    {
+      if (update_flag)
+        fixits_run ();
+      else
+        complain (NULL, Wother,
+                  _("fix-its can be applied.  Rerun with option '--update'."));
+      fixits_free ();
+    }
+  uniqstrs_free ();
+
   return complaint_status ? EXIT_FAILURE : EXIT_SUCCESS;
 }
