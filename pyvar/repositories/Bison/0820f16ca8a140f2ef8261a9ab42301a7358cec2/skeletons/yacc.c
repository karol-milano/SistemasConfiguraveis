@@ -48,6 +48,10 @@ m4_define([b4_pure_if],
 ## api.push-pull.  ##
 ## --------------- ##
 
+# b4_pull_if, b4_push_if
+# ----------------------
+# Whether the pull/push APIs are needed.  Both can be enabled.
+
 b4_percent_define_default([[api.push-pull]], [[pull]])
 b4_percent_define_check_values([[[[api.push-pull]],
                                  [[pull]], [[push]], [[both]]]])
