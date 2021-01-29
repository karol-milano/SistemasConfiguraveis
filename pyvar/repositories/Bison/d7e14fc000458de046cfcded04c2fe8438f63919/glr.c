@@ -536,10 +536,6 @@ int yydebug;
    SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
    evaluated with infinite-precision integer arithmetic.  */
 
-#if YYMAXDEPTH == 0
-# undef YYMAXDEPTH
-#endif
-
 #ifndef YYMAXDEPTH
 # define YYMAXDEPTH ]b4_stack_depth_max[
 #endif
