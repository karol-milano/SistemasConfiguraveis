@@ -166,7 +166,7 @@ enum color
     color_auto
   };
 
-ARGMATCH_DEFINE_GROUP(color, enum color)
+ARGMATCH_DEFINE_GROUP (color, enum color)
 
 static const argmatch_color_doc argmatch_color_docs[] =
 {
@@ -202,7 +202,7 @@ const argmatch_color_group_type argmatch_color_group =
 | --report's handling.  |
 `----------------------*/
 
-ARGMATCH_DEFINE_GROUP(report, enum report)
+ARGMATCH_DEFINE_GROUP (report, enum report)
 
 static const argmatch_report_doc argmatch_report_docs[] =
 {
@@ -240,7 +240,7 @@ const argmatch_report_group_type argmatch_report_group =
 | --trace's handling.  |
 `---------------------*/
 
-ARGMATCH_DEFINE_GROUP(trace, enum trace)
+ARGMATCH_DEFINE_GROUP (trace, enum trace)
 
 static const argmatch_trace_doc argmatch_trace_docs[] =
 {
@@ -299,7 +299,7 @@ const argmatch_trace_group_type argmatch_trace_group =
 | --feature's handling.  |
 `-----------------------*/
 
-ARGMATCH_DEFINE_GROUP(feature, enum feature)
+ARGMATCH_DEFINE_GROUP (feature, enum feature)
 
 static const argmatch_feature_doc argmatch_feature_docs[] =
 {
