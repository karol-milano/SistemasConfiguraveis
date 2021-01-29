@@ -30,11 +30,6 @@
 /* Shorts options.  */
 const char *shortopts = "yvegdhrltknVo:b:p:S:";
 
-/* Long options.  */
-struct option *longopts = NULL;
-
-struct percent_table_struct *percent_table = NULL;
-
 /* A CLI option only.
    Arguments is the policy: `no', `optional', `required'.
    OptionChar is the value given to the Var if the latter is specified.  */
@@ -135,13 +130,16 @@ const struct option_table_struct option_table[] =
   {0, 0, 0, 0, 0, 0}
 };
 
+
 /*--------------------------------------------------------.
 | Create the longoptions structure from the option_table, |
 | for the getopt file.					  |
 `--------------------------------------------------------*/
-void
-create_long_option_table ()
+
+struct option *
+long_option_table_new ()
 {
+  struct option *res = NULL;
   int i = 0;
   int j = 0;
   int number_options;
@@ -151,26 +149,28 @@ create_long_option_table ()
 	|| option_table[i].access == opt_both)
       ++number_options;
 
-  longopts = XMALLOC (struct option, number_options + 1);
+  res = XMALLOC (struct option, number_options + 1);
   for (i = 0; option_table[i].name; i++)
     if (option_table[i].access == opt_cmd_line
 	|| option_table[i].access == opt_both)
       {
 	/* Copy the struct information in the longoptions.  */
-	longopts[j].name = option_table[i].name;
-	longopts[j].has_arg = option_table[i].has_arg;
+	res[j].name = option_table[i].name;
+	res[j].has_arg = option_table[i].has_arg;
 	/* When an options is declared having 'optional_argument' and
 	   a flag is specified to be set, the option is skipped on
 	   command line. So we never use a flag when a command line
 	   option is declared 'optional_argument.  */
-	if (longopts[j].has_arg == optional_argument)
-	  longopts[j].flag = NULL;
+	if (res[j].has_arg == optional_argument)
+	  res[j].flag = NULL;
 	else
-	  longopts[j].flag = option_table[i].set_flag;
-	longopts[j++].val = option_table[i].val;
+	  res[j].flag = option_table[i].set_flag;
+	res[j++].val = option_table[i].val;
       }
-  longopts[number_options].name = NULL;
-  longopts[number_options].has_arg = 0;
-  longopts[number_options].flag = NULL;
-  longopts[number_options].val = 0;
+  res[number_options].name = NULL;
+  res[number_options].has_arg = 0;
+  res[number_options].flag = NULL;
+  res[number_options].val = 0;
+
+  return res;
 }
