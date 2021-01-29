@@ -31,8 +31,8 @@ m4_case(b4_percent_define_get([[api.push-pull]]),
         [push], [m4_define([b4_pull_flag], [[0]])])
 
 # Handle BISON_USE_PUSH_FOR_PULL for the test suite.  So that push parsing
-# tests function as written, don't let BISON_USE_PUSH_FOR_PULL modify Bison's
-# behavior at all when push parsing is already requested.
+# tests function as written, do not let BISON_USE_PUSH_FOR_PULL modify the
+# behavior of Bison at all when push parsing is already requested.
 b4_define_flag_if([use_push_for_pull])
 b4_use_push_for_pull_if([
   b4_push_if([m4_define([b4_use_push_for_pull_flag], [[0]])],
@@ -1068,7 +1068,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
               }
             *++yyesp = yystate;
           }
-        YYDPRINTF ((stderr, " G%d", *yyesp));
+        YYDPRINTF ((stderr, " G%d", yystate));
       }
     }
 }]])[
@@ -2000,7 +2000,7 @@ yypushreturn:]])[
 ]b4_epilogue[]dnl
 b4_defines_if(
 [@output(b4_spec_defines_file@)@
-b4_copyright([Interface for Bison's Yacc-like parsers in C])dnl
+b4_copyright([Bison interface for Yacc-like parsers in C])dnl
 
 b4_percent_code_get([[requires]])[]dnl
 
