@@ -54,9 +54,25 @@ m4_define([b4_user_formals],
 [m4_ifset([b4_parse_param], [, b4_c_ansi_formals(b4_parse_param)])])
 
 
+# b4_yyerror_args
+# ---------------
+# Arguments passed to yyerror: user args plus yylloc.
+m4_define([b4_yyerror_args],
+[b4_pure_if([b4_location_if([yylocp, ])])dnl
+m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
+
+
+# b4_lyyerror_args
+# ----------------
+# Same as above, but on the lookahead, hence yyllocp instead of yylocp.
+m4_define([b4_lyyerror_args],
+[b4_pure_if([b4_location_if([yyllocp, ])])dnl
+m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
+
+
 # b4_pure_args
 # ------------
-# Arguments passed to yyerror: user args plus yylloc.
+# Arguments needed by yyerror: user args plus yylloc.
 m4_define([b4_pure_args],
 [b4_pure_if([b4_location_if([, yylocp])])[]b4_user_args])
 
@@ -581,7 +597,7 @@ yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yyformat, ...)
       va_start (yyap, yyformat);
       yystack->yyerrflag = 1;
       vsprintf (yymsg, yyformat, yyap);
-      yyerror (yymsg]b4_pure_args[);
+      yyerror (]b4_yyerror_args[yymsg);
     }
   longjmp (yystack->yyexception_buffer, 1);
 }
@@ -636,7 +652,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYBACKUP
 # define YYBACKUP(Token, Value)						     \
   do {									     \
-    yyerror ("syntax error: cannot back up"]b4_pure_args[);		     \
+    yyerror (]b4_yyerror_args["syntax error: cannot back up");		     \
     YYERROR;								     \
   } while (0)
 
@@ -1591,12 +1607,12 @@ yyreportParseError (yyGLRStack* yystack,
 		    yyprefix = " or ";
 		  }
 	    }
-	  yyerror (yymsg]b4_lpure_args[);
+	  yyerror (]b4_lyyerror_args[yymsg);
 	  free (yymsg);
 	}
       else
 #endif
-	yyerror ("parse error"]b4_lpure_args[);
+	yyerror (]b4_lyyerror_args["parse error");
       yynerrs += 1;
     }
 }
