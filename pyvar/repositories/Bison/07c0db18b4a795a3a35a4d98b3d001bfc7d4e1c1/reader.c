@@ -36,6 +36,7 @@
 #include "scan-gram.h"
 #include "scan-code.h"
 
+static void prepare_percent_define_front_end_variables (void);
 static void check_and_convert_grammar (void);
 
 static symbol_list *grammar = NULL;
@@ -590,8 +591,18 @@ reader (void)
   gram_debug = trace_flag & trace_parse;
   gram_scanner_initialize ();
   gram_parse ();
+  prepare_percent_define_front_end_variables ();
 
-  /* Set front-end %define variable defaults.  */
+  if (! complaint_issued)
+    check_and_convert_grammar ();
+
+  xfclose (gram_in);
+}
+
+static void
+prepare_percent_define_front_end_variables (void)
+{
+  /* Set %define front-end variable defaults.  */
   muscle_percent_define_default ("lr.keep-unreachable-states", "false");
   {
     char *lr_type;
@@ -606,7 +617,7 @@ reader (void)
     free (lr_type);
   }
 
-  /* Check front-end %define variables.  */
+  /* Check %define front-end variables.  */
   {
     static char const * const values[] = {
       "lr.type", "LALR", "IELR", "canonical LR", NULL,
@@ -615,11 +626,6 @@ reader (void)
     };
     muscle_percent_define_check_values (values);
   }
-
-  if (! complaint_issued)
-    check_and_convert_grammar ();
-
-  xfclose (gram_in);
 }
 
 
