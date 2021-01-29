@@ -36,6 +36,8 @@
 #include "symlist.h"
 #include "symtab.h"
 
+static void check_and_convert_grammar (void);
+
 static symbol_list *grammar = NULL;
 static bool start_flag = false;
 merger_list *merge_functions;
@@ -515,12 +517,22 @@ reader (void)
   scanner_initialize ();
   gram_parse ();
 
-  /* If something went wrong during the parsing, don't try to
-     continue.  */
-  if (complaint_issued)
-    return;
+  if (! complaint_issued)
+    check_and_convert_grammar ();
+
+  xfclose (gram_in);
+}
+
 
-  /* Grammar has been read.  Do some checking */
+/*-------------------------------------------------------------.
+| Check the grammar that has just been read, and convert it to |
+| internal form.					       |
+`-------------------------------------------------------------*/
+
+static void
+check_and_convert_grammar (void)
+{
+  /* Grammar has been read.  Do some checking.  */
   if (nrules == 0)
     fatal (_("no rules in the input grammar"));
 
@@ -537,7 +549,7 @@ reader (void)
       endtoken->user_token_number = 0;
     }
 
-  /* Insert the initial rule, which line is that of the first rule
+  /* Insert the initial rule, whose line is that of the first rule
      (not that of the start symbol):
 
      accept: %start EOF.  */
@@ -555,8 +567,6 @@ reader (void)
 
   assert (nsyms <= SYMBOL_NUMBER_MAXIMUM && nsyms == ntokens + nvars);
 
-  xfclose (gram_in);
-
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   symbols_pack ();
