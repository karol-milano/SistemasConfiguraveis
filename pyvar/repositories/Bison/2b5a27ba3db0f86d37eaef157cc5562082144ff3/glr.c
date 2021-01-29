@@ -2086,6 +2086,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       case N:                           \
         yyformat = S;                   \
       break
+    default: /* Avoid compiler warnings. */
       YYCASE_(0, YY_("syntax error"));
       YYCASE_(1, YY_("syntax error, unexpected %s"));
       YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
