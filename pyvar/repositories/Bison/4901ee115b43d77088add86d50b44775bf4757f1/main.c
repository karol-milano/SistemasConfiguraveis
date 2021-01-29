@@ -223,7 +223,6 @@ main (int argc, char *argv[])
   muscle_free ();
   code_scanner_free ();
   skel_scanner_free ();
-  quotearg_free ();
   timevar_pop (tv_free);
 
   if (trace_flag & trace_bitsets)
@@ -249,6 +248,7 @@ main (int argc, char *argv[])
   uniqstrs_free ();
 
   complain_free ();
+  quotearg_free ();
 
   return complaint_status ? EXIT_FAILURE : EXIT_SUCCESS;
 }
