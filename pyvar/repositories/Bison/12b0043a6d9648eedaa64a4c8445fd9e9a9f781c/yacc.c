@@ -2,7 +2,8 @@ m4_divert(-1)                                                       -*- C -*-
 m4_include([c.m4])
 
 # Yacc compatible skeleton for Bison
-# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
+# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002
+# Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -303,7 +304,6 @@ b4_location_if(
 
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  b4_final_state_number
-#define YYFLAG	 b4_flag
 #define YYLAST   b4_last
 
 /* YYNTOKENS -- Number of terminals. */
@@ -385,7 +385,7 @@ static const short yydefact[[]] =
   b4_defact
 };
 
-/* YYPGOTO[[NTERM-NUM]]. */
+/* YYDEFGOTO[[NTERM-NUM]]. */
 static const short yydefgoto[[]] =
 {
   b4_defgoto
@@ -393,7 +393,8 @@ static const short yydefgoto[[]] =
 
 /* YYPACT[[STATE-NUM]] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-static const short yypact[[]] =
+#define YYPACT_NINF b4_pact_ninf
+static const b4_sint_type(b4_pact_max) yypact[[]] =
 {
   b4_pact
 };
@@ -407,7 +408,8 @@ static const short yypgoto[[]] =
 /* YYTABLE[[YYPACT[STATE-NUM]]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.  */
-static const short yytable[[]] =
+#define YYTABLE_NINF b4_table_ninf
+static const b4_sint_type(b4_table_max) yytable[[]] =
 {
   b4_table
 };
@@ -820,7 +822,7 @@ yybackup:
   /* First try to decide what to do without reference to lookahead token.  */
 
   yyn = yypact[yystate];
-  if (yyn == YYFLAG)
+  if (yyn == YYPACT_NINF)
     goto yydefault;
 
   /* Not known => get a lookahead token if don't already have one.  */
@@ -855,7 +857,7 @@ yybackup:
     }
 
   yyn += yychar1;
-  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
+  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
     goto yydefault;
 
   yyn = yytable[yyn];
@@ -869,7 +871,7 @@ yybackup:
 
   if (yyn < 0)
     {
-      if (yyn == YYFLAG)
+      if (yyn == YYTABLE_NINF)
 	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
@@ -980,7 +982,7 @@ yyreduce:
   yyn = yyr1[yyn];
 
   yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
-  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
+  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
     yystate = yytable[yystate];
   else
     yystate = yydefgoto[yyn - YYNTOKENS];
@@ -1000,7 +1002,7 @@ yyerrlab:
 #if YYERROR_VERBOSE
       yyn = yypact[yystate];
 
-      if (yyn > YYFLAG && yyn < YYLAST)
+      if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
 	  YYSIZE_T yysize = 0;
 	  char *yymsg;
@@ -1090,7 +1092,7 @@ yyerrlab1:
   for (;;)
     {
       yyn = yypact[yystate];
-      if (yyn != YYFLAG)
+      if (yyn != YYPACT_NINF)
 	{
 	  yyn += YYTERROR;
 	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
