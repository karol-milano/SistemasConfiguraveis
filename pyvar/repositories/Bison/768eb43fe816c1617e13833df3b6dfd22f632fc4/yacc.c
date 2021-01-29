@@ -307,6 +307,12 @@ b4_location_if(
 
 #endif
 
+#if defined (__STDC__) || defined (__cplusplus)
+   typedef signed char yysigned_char;
+#else
+   typedef short yysigned_char;
+#endif
+
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  b4_final_state_number
 #define YYLAST   b4_last
