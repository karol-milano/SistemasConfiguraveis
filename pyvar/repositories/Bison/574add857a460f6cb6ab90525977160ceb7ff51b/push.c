@@ -1091,7 +1091,14 @@ b4_push_if(
 ]b4_locations_if([[  YYLTYPE yylloc;
 ]])])[
   if (yyps == 0)
-    yyps_local = yypstate_new ();
+    {
+      yyps_local = yypstate_new ();
+      if (!yyps_local)
+        {
+          yyerror (]b4_yyerror_args[YY_("memory exhausted"));
+          return 2;
+        }
+    }
   else
     yyps_local = yyps;
   do {
@@ -1108,6 +1115,8 @@ b4_push_if(
 ]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
 {
   yypstate *yyps = (yypstate *) malloc (sizeof *yyps);
+  if (!yyps)
+    return 0;
   yyps->yynew = 1;
   return yyps;
 }
