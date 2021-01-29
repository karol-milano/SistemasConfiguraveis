@@ -1279,8 +1279,16 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 }
 
 #if YYDEBUG
-/* FIXME: How can we initialize the lloc bit?  */
-static yyGLRState YYLEFTMOST_STATE = { 0, 0, -1, NULL, 0, { NULL } };
+static yyGLRState YYLEFTMOST_STATE =
+  {
+    0, 0, -1, NULL, 0, { NULL },
+    /* yyloc.  */
+    {
+#if YYLTYPE_IS_TRIVIAL
+]b4_location_if([      0, 0, 0, 0])[
+#endif
+    }
+  };
 
 static void yyreportTree (yySemanticOption* yyx, int yyindent)
 {
