@@ -1124,6 +1124,12 @@ b4_push_if(
 ]b4_c_function_def([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])[
 {
+#ifndef yyoverflow
+  /* If the stack was reallocated but the parse did not complete, then the
+     stack still needs to be freed.  */
+  if (!yyps->yynew && yyps->yyss != yyps->yyssa)
+    YYSTACK_FREE (yyps->yyss);
+#endif
   free (yyps);
 }
 
