@@ -605,10 +605,9 @@ grammar_current_rule_expect_rr (int count, location loc)
 }
 
 
-/*---------------------------------------------------------------.
-| Convert the rules into the representation using RRHS, RLHS and |
-| RITEM.                                                         |
-`---------------------------------------------------------------*/
+/*---------------------------------------------.
+| Build RULES and RITEM from what was parsed.  |
+`---------------------------------------------*/
 
 static void
 packgram (void)
