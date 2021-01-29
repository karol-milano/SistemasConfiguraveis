@@ -101,7 +101,7 @@ main (int argc, char *argv[])
      the grammar; see gram.h.  */
 
   timevar_push (tv_reader);
-  reader ();
+  reader (grammar_file);
   timevar_pop (tv_reader);
 
   if (complaint_status == status_complaint)
