@@ -230,7 +230,9 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 
 ]b4_defines_if([[#include "@basename(]b4_spec_header_file[@)"]],
                [b4_shared_declarations])[
-]b4_declare_symbol_enum[
+
+]b4_glr_cc_if([b4_glr_cc_setup],
+              [b4_declare_symbol_enum])[
 
 /* Default (constant) value used for initialization for null
    right-hand sides.  Unlike the standard yacc.c template, here we set
@@ -2731,7 +2733,7 @@ m4_if(b4_prefix, [yy], [],
 #define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
 #define yylloc  ]b4_prefix[lloc]])])[
 
-]m4_ifdef([b4_pre_epilogue], [b4_pre_epilogue])[]dnl This is a hack for glr.cc.  To remove when we have a better glr.cc.
-b4_percent_code_get([[epilogue]])[]dnl
+]b4_glr_cc_if([b4_glr_cc_cleanup])[
+]b4_percent_code_get([[epilogue]])[]dnl
 b4_epilogue[]dnl
 b4_output_end
