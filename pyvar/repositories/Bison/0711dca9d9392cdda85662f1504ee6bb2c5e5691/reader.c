@@ -735,6 +735,7 @@ prepare_percent_define_front_end_variables (void)
       muscle_percent_define_default ("lr.default-reduction", "accepting");
     free (lr_type);
   }
+  muscle_percent_define_default ("tool.xsltproc", "xsltproc");
 
   /* Check %define front-end variables.  */
   {
