@@ -234,8 +234,6 @@ main (int argc, char *argv[])
   timevar_stop (tv_total);
   timevar_print (stderr);
 
-  caret_free ();
-
   /* Fix input file now, even if there are errors: that's less
      warnings in the following runs.  */
   if (!fixits_empty ())
@@ -249,5 +247,7 @@ main (int argc, char *argv[])
     }
   uniqstrs_free ();
 
+  complain_free ();
+
   return complaint_status ? EXIT_FAILURE : EXIT_SUCCESS;
 }
