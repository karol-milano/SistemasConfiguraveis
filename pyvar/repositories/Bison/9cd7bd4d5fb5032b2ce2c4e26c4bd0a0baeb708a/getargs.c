@@ -231,6 +231,7 @@ static const char * const feature_args[] =
   "none",
   "caret", "diagnostics-show-caret",
   "fixit", "diagnostics-parseable-fixits",
+  "syntax-only",
   "all",
   0
 };
@@ -240,6 +241,7 @@ static const int feature_types[] =
   feature_none,
   feature_caret, feature_caret,
   feature_fixit_parsable, feature_fixit_parsable,
+  feature_syntax_only,
   feature_all
 };
 
@@ -362,6 +364,8 @@ FEATURES is a list of comma separated words that can include:\n\
     show errors with carets\n\
   'fixit', 'diagnostics-parseable-fixits'\n\
     show machine-readable fixes\n\
+  'syntax-only'\n\
+    do not generate any file\n\
   'all'\n\
     all of the above\n\
   'none'\n\
@@ -698,6 +702,7 @@ getargs (int argc, char *argv[])
 
       case 'u':
         update_flag = true;
+        feature_flag |= feature_syntax_only;
         break;
 
       case 'v':
