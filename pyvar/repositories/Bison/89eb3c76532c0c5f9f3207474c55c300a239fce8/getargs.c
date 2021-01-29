@@ -204,18 +204,18 @@ static const char * const warnings_args[] =
   /* In a series of synonyms, present the most meaningful first, so
      that argmatch_valid be more readable.  */
   "none       - no warnings",
-  "error      - warnings are errors",
   "yacc       - incompatibilities with POSIX YACC",
   "all        - all of the above",
+  "error      - warnings are errors",
   0
 };
 
 static const int warnings_types[] =
 {
   warnings_none,
-  warnings_error,
   warnings_yacc,
-  warnings_all
+  warnings_all,
+  warnings_error
 };
 
 ARGMATCH_VERIFY (warnings_args, warnings_types);
@@ -472,7 +472,10 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'W':
-	FLAGS_ARGMATCH (warnings, optarg);
+	if (optarg)
+	  FLAGS_ARGMATCH (warnings, optarg);
+	else
+	  warnings_flag |= warnings_all;
 	break;
 
       case LOCATIONS_OPTION:
