@@ -1076,7 +1076,9 @@ b4_push_if(
 {
   return yypull_parse (0]m4_ifset([b4_parse_param],
                                   [[, ]b4_c_args(b4_parse_param)])[);
-}
+}]b4_pure_if([], [[
+
+static char yypstate_allocated = 0;]])[
 
 ]b4_c_function_def([[yypull_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
@@ -1092,8 +1094,10 @@ b4_push_if(
     {
       yyps_local = yypstate_new ();
       if (!yyps_local)
-        {
-          yyerror (]b4_yyerror_args[YY_("memory exhausted"));
+        {]b4_pure_if([[
+          yyerror (]b4_yyerror_args[YY_("memory exhausted"));]], [[
+          if (!yypstate_allocated)
+            yyerror (]b4_yyerror_args[YY_("memory exhausted"));]])[
           return 2;
         }
     }
@@ -1112,10 +1116,17 @@ b4_push_if(
 /* Initialize the parser data structure.  */
 ]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
 {
-  yypstate *yyps = (yypstate *) malloc (sizeof *yyps);
+  yypstate *yyps;]b4_pure_if([], [[
+  if (yypstate_allocated)
+    {
+      yyerror (]b4_yyerror_args[YY_("cannot allocate multiple impure push-parser instances"));
+      return 0;
+    }]])[
+  yyps = (yypstate *) malloc (sizeof *yyps);
   if (!yyps)
     return 0;
-  yyps->yynew = 1;
+  yyps->yynew = 1;]b4_pure_if([], [[
+  yypstate_allocated = 1;]])[
   return yyps;
 }
 
@@ -1128,7 +1139,8 @@ b4_push_if(
   if (!yyps->yynew && yyps->yyss != yyps->yyssa)
     YYSTACK_FREE (yyps->yyss);
 #endif
-  free (yyps);
+  free (yyps);]b4_pure_if([], [[
+  yypstate_allocated = 0;]])[
 }
 
 ]b4_pure_if([[#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs
