@@ -45,7 +45,10 @@ static bool start_flag = false;
 merger_list *merge_functions;
 
 /* Was %union seen?  */
-bool typed = false;
+bool union_seen = false;
+
+/* Was a tag seen?  */
+bool tag_seen = false;
 
 /* Should rules have a default precedence?  */
 bool default_prec = true;
