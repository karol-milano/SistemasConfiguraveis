@@ -30,7 +30,7 @@
 #include "options.h"
 
 /* Shorts options.  */
-const char *shortopts = "yvgdhrltknVo:b:p:S:";
+const char *shortopts = "yvegdhrltknVo:b:p:S:";
 
 /* Long options.  */
 struct option *longopts = NULL;
@@ -102,8 +102,9 @@ const struct option_table_struct option_table[] =
      the same, the char `-'.  */
 
   /* Output.  */
-  {opt_both, "defines",	 optional_argument,   &defines_flag, tok_intopt,   'd'},
-  {opt_both, "verbose",	       no_argument,   &verbose_flag, tok_intopt,   'v'},
+  {opt_both, "defines",	 optional_argument,	 &defines_flag, tok_intopt,   'd'},
+  {opt_both, "verbose",	       no_argument,	 &verbose_flag, tok_intopt,   'v'},
+  {opt_both, "error-verbose",  no_argument,&error_verbose_flag, tok_intopt,   'e'},
 
   /* Operation modes.  */
   {opt_both, "fixed-output-files", no_argument,  &yacc_flag, tok_intopt,   'y'},
