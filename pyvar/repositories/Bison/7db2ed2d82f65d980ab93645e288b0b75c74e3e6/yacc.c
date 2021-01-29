@@ -302,18 +302,18 @@ b4_location_if(
 #endif
 
 /* YYFINAL -- State number of the termination state. */
-#define YYFINAL  b4_final
+#define YYFINAL  b4_final_state_number
 #define YYFLAG	 b4_flag
 #define YYLAST   b4_last
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  b4_ntokens
+#define YYNTOKENS  b4_tokens_number
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  b4_nnts
+#define YYNNTS  b4_nterms_number
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  b4_nrules
+#define YYNRULES  b4_rules_number
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  b4_nstates
+#define YYNSTATES  b4_states_number
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  b4_undef_token_number
