@@ -228,6 +228,7 @@ static const char * const feature_args[] =
 {
   "none",
   "caret", "diagnostics-show-caret",
+  "fixit", "diagnostics-parseable-fixits",
   "all",
   0
 };
@@ -236,6 +237,7 @@ static const int feature_types[] =
 {
   feature_none,
   feature_caret, feature_caret,
+  feature_fixit_parsable, feature_fixit_parsable,
   feature_all
 };
 
