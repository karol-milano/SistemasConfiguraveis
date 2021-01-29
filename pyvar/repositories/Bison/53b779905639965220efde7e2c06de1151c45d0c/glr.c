@@ -243,10 +243,6 @@ b4_syncline([@oline@], [@ofile@])
 # define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
 #endif
 
-#if ! defined (__GNUC__)
-# define inline
-#endif
-
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  ]b4_final_state_number[
 /* YYLAST -- Last index in YYTABLE.  */
