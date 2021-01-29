@@ -1326,16 +1326,19 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 ]b4_function_define([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])[
 {
+  if (yyps)
+    {
 #ifndef yyoverflow
-  /* If the stack was reallocated but the parse did not complete, then the
-     stack still needs to be freed.  */
-  if (!yyps->yynew && yyps->yyss != yyps->yyssa)
-    YYSTACK_FREE (yyps->yyss);
+      /* If the stack was reallocated but the parse did not complete, then the
+         stack still needs to be freed.  */
+      if (!yyps->yynew && yyps->yyss != yyps->yyssa)
+        YYSTACK_FREE (yyps->yyss);
 #endif]b4_lac_if([[
-  if (!yyps->yynew && yyps->yyes != yyps->yyesa)
-    YYSTACK_FREE (yyps->yyes);]])[
-  free (yyps);]b4_pure_if([], [[
-  yypstate_allocated = 0;]])[
+      if (!yyps->yynew && yyps->yyes != yyps->yyesa)
+        YYSTACK_FREE (yyps->yyes);]])[
+      free (yyps);]b4_pure_if([], [[
+      yypstate_allocated = 0;]])[
+    }
 }
 ]b4_pure_if([[
 #define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs]])[
