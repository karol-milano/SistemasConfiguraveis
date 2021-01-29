@@ -61,8 +61,6 @@ bool glr_parser = false;
 
 int report_flag = report_none;
 int trace_flag = trace_none;
-int warnings_flag = Wconflicts_sr | Wconflicts_rr
-                    | Wother;
 
 static struct bison_language const valid_languages[] = {
   { "c", "c-skel.m4", ".c", ".h", true },
