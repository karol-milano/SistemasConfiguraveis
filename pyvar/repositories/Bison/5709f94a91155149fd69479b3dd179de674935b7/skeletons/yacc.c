@@ -468,18 +468,6 @@ typedef ]b4_int_type(0, m4_eval(b4_states_number - 1))[ yy_state_num;
 
 ]b4_attribute_define[
 
-/* Suppress bogus -Wconversion warnings from GCC.  */
-#if 4 < __GNUC__ + (7 <= __GNUC_MINOR__)
-# define YY_CONVERT_INT_BEGIN \
-    _Pragma ("GCC diagnostic push") \
-    _Pragma ("GCC diagnostic ignored \"-Wconversion\"")
-# define YY_CONVERT_INT_END \
-    _Pragma ("GCC diagnostic pop")
-#else
-# define YY_CONVERT_INT_BEGIN
-# define YY_CONVERT_INT_END
-#endif
-
 ]b4_parse_assert_if([[#ifdef NDEBUG
 # define YY_ASSERT(E) ((void) (0 && (E)))
 #else
@@ -1062,9 +1050,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
-            YY_CONVERT_INT_BEGIN
-            *yyesp = yystate;
-            YY_CONVERT_INT_END
+            *yyesp = (yy_state_num) yystate;
           }
         else
           {
@@ -1077,9 +1063,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
-            YY_CONVERT_INT_BEGIN
-            *++yyesp = yystate;
-            YY_CONVERT_INT_END
+            *++yyesp = (yy_state_num) yystate;
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1542,9 +1526,7 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-  YY_CONVERT_INT_BEGIN
-  *yyssp = yystate;
-  YY_CONVERT_INT_END
+   *yyssp = (yy_state_num) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
