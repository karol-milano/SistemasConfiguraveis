@@ -48,11 +48,12 @@ m4_define([b4_Pure_if],
             [$2])])
 
 
-# b4_pure_args
-# ------------
+# b4_yyerror_args
+# ---------------
 # Arguments passed to yyerror: user args plus yylloc.
-m4_define([b4_pure_args],
-[b4_Pure_if([b4_location_if([, &yylloc])])[]b4_user_args])
+m4_define([b4_yyerror_args],
+[b4_Pure_if([b4_location_if([&yylloc, ])])dnl
+m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 
 # b4_lex_param
@@ -529,7 +530,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror ("syntax error: cannot back up"b4_pure_args);	\
+      yyerror (b4_yyerror_args"syntax error: cannot back up");	\
       YYERROR;							\
     }								\
 while (0)
@@ -1135,15 +1136,15 @@ yyerrlab:
 			yycount++;
 		      }
 		}
-	      yyerror (yymsg]b4_pure_args[);
+	      yyerror (]b4_yyerror_args[yymsg);
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror ("parse error; also virtual memory exhausted"]b4_pure_args[);
+	    yyerror (]b4_yyerror_args["parse error; also virtual memory exhausted");
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror ("parse error"]b4_pure_args[);
+	yyerror (]b4_yyerror_args["parse error");
     }
   goto yyerrlab1;
 
@@ -1258,7 +1259,7 @@ yyabortlab:
 | yyoverflowlab -- parser overflow comes here.  |
 `----------------------------------------------*/
 yyoverflowlab:
-  yyerror ("parser stack overflow"]b4_pure_args[);
+  yyerror (]b4_yyerror_args["parser stack overflow");
   yyresult = 2;
   /* Fall through.  */
 #endif
