@@ -86,18 +86,19 @@ char *program_name;
  *  \param option   option being decoded.
  *  \param keys     array of valid subarguments.
  *  \param values   array of corresponding (int) values.
+ *  \param all      the all value.
  *  \param flags    the flags to update
  *  \param args     comma separated list of effective subarguments to decode.
  *                  If 0, then activate all the flags.
  *
  *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
- *  If VALUE == 0 then KEY clears all flags and no-KEY sets all flags.
- *  Thus no-none = all and no-all = none.
+ *  If VALUE == 0 then KEY clears all flags from \c all and no-KEY sets all
+ *  flags from \c all.  Thus no-none = all and no-all = none.
  */
 static void
 flags_argmatch (const char *option,
 		const char * const keys[], const int values[],
-		int *flags, char *args)
+		int all, int *flags, char *args)
 {
   if (args)
     {
@@ -107,20 +108,24 @@ flags_argmatch (const char *option,
 	  int no = strncmp (args, "no-", 3) == 0 ? 3 : 0;
 	  int value = XARGMATCH (option, args + no, keys, values);
 	  if (value == 0)
-	    if (no)
-	      *flags = ~0;
-	    else
-	      *flags = 0;
+	    {
+	      if (no)
+		*flags |= all;
+	      else
+		*flags &= ~all;
+	    }
 	  else
-	    if (no)
-	      *flags &= ~value;
-	    else
-	      *flags |= value;
+	    {
+	      if (no)
+		*flags &= ~value;
+	      else
+		*flags |= value;
+	    }
 	  args = strtok (NULL, ",");
 	}
     }
   else
-    *flags = ~0;
+    *flags |= all;
 }
 
 /** Decode a set of sub arguments.
@@ -130,11 +135,12 @@ flags_argmatch (const char *option,
  *
  *  \arg FlagName_args   the list of keys.
  *  \arg FlagName_types  the list of values.
+ *  \arg FlagName_all    the all value.
  *  \arg FlagName_flag   the flag to update.
  */
 #define FLAGS_ARGMATCH(FlagName, Args)					\
   flags_argmatch ("--" #FlagName, FlagName ## _args, FlagName ## _types, \
-		  &FlagName ## _flag, Args)
+		  FlagName ## _all, &FlagName ## _flag, Args)
 
 
 /*----------------------.
@@ -579,10 +585,7 @@ getargs (int argc, char *argv[])
 	exit (EXIT_SUCCESS);
 
       case 'W':
-	if (optarg)
-	  FLAGS_ARGMATCH (warnings, optarg);
-	else
-	  warnings_flag |= warnings_all;
+	FLAGS_ARGMATCH (warnings, optarg);
 	break;
 
       case 'b':
