@@ -631,7 +631,7 @@ reader (void)
   gram_parse ();
   prepare_percent_define_front_end_variables ();
 
-  if (! complaint_issued)
+  if (complaint_status  < status_complaint)
     check_and_convert_grammar ();
 
   xfclose (gram_in);
