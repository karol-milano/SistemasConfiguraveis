@@ -1035,7 +1035,7 @@ do {                                                                      \
 
 static void
 yy_symbol_value_print (FILE *yyo,
-                       yysymbol_kind_t yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   FILE *yyoutput = yyo;
   YYUSE (yyoutput);
@@ -1043,14 +1043,14 @@ yy_symbol_value_print (FILE *yyo,
   if (!yyvaluep)
     return;
 # ifdef YYPRINT
-  if (yytype < YYNTOKENS)
-    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
+  if (yykind < YYNTOKENS)
+    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
 # endif
 /* "%code pre-printer" blocks.  */
 tron (yyo);
 
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
-  switch (yytype)
+  switch (yykind)
     {
     case 3: /* "string"  */
          { fputs (((*yyvaluep).STRING), yyo); }
@@ -1140,7 +1140,7 @@ tron (yyo);
         break;
 
     case 74: /* tag.opt  */
-         { fputs (((*yyvaluep).yytype_74), yyo); }
+         { fputs (((*yyvaluep).yykind_74), yyo); }
         break;
 
     case 75: /* generic_symlist  */
@@ -1164,7 +1164,7 @@ tron (yyo);
         break;
 
     case 80: /* token_decl.1  */
-         { symbol_list_syms_print (((*yyvaluep).yytype_80), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).yykind_80), yyo); }
         break;
 
     case 81: /* token_decl  */
@@ -1172,7 +1172,7 @@ tron (yyo);
         break;
 
     case 82: /* int.opt  */
-         { fprintf (yyo, "%d", ((*yyvaluep).yytype_82)); }
+         { fprintf (yyo, "%d", ((*yyvaluep).yykind_82)); }
         break;
 
     case 83: /* alias  */
@@ -1184,7 +1184,7 @@ tron (yyo);
         break;
 
     case 85: /* token_decl_for_prec.1  */
-         { symbol_list_syms_print (((*yyvaluep).yytype_85), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).yykind_85), yyo); }
         break;
 
     case 86: /* token_decl_for_prec  */
@@ -1196,7 +1196,7 @@ tron (yyo);
         break;
 
     case 88: /* symbol_decl.1  */
-         { symbol_list_syms_print (((*yyvaluep).yytype_88), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).yykind_88), yyo); }
         break;
 
     case 96: /* variable  */
@@ -1246,14 +1246,14 @@ troff (yyo);
 
 static void
 yy_symbol_print (FILE *yyo,
-                 yysymbol_kind_t yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   YYFPRINTF (yyo, "%s %s (",
-             yytype < YYNTOKENS ? "token" : "nterm", yysymbol_name (yytype));
+             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));
 
   YY_LOCATION_PRINT (yyo, *yylocationp);
   YYFPRINTF (yyo, ": ");
-  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
+  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
   YYFPRINTF (yyo, ")");
 }
 
@@ -1633,7 +1633,7 @@ yyexpected_tokens (const yypcontext_t *yyctx,
 
 
 
-/* The token type of the lookahead of this context.  */
+/* The kind of the lookahead of this context.  */
 static yysymbol_kind_t
 yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
@@ -1663,16 +1663,16 @@ yyreport_syntax_error (const yypcontext_t *yyctx);
 
 static void
 yydestruct (const char *yymsg,
-            yysymbol_kind_t yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
+            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 {
   YYUSE (yyvaluep);
   YYUSE (yylocationp);
   if (!yymsg)
     yymsg = "Deleting";
-  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);
+  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);
 
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
-  switch (yytype)
+  switch (yykind)
     {
     case 75: /* generic_symlist  */
             { symbol_list_free (((*yyvaluep).generic_symlist)); }
@@ -1691,7 +1691,7 @@ yydestruct (const char *yymsg,
         break;
 
     case 80: /* token_decl.1  */
-            { symbol_list_free (((*yyvaluep).yytype_80)); }
+            { symbol_list_free (((*yyvaluep).yykind_80)); }
         break;
 
     case 84: /* token_decls_for_prec  */
@@ -1699,7 +1699,7 @@ yydestruct (const char *yymsg,
         break;
 
     case 85: /* token_decl_for_prec.1  */
-            { symbol_list_free (((*yyvaluep).yytype_85)); }
+            { symbol_list_free (((*yyvaluep).yykind_85)); }
         break;
 
     case 87: /* symbol_decls  */
@@ -1707,7 +1707,7 @@ yydestruct (const char *yymsg,
         break;
 
     case 88: /* symbol_decl.1  */
-            { symbol_list_free (((*yyvaluep).yytype_88)); }
+            { symbol_list_free (((*yyvaluep).yykind_88)); }
         break;
 
       default:
@@ -2291,11 +2291,11 @@ yyreduce:
     break;
 
   case 56:
-         { (yyval.yytype_74) = NULL; }
+         { (yyval.yykind_74) = NULL; }
     break;
 
   case 57:
-         { (yyval.yytype_74) = (yyvsp[0].TAG); }
+         { (yyval.yykind_74) = (yyvsp[0].TAG); }
     break;
 
   case 59:
@@ -2320,43 +2320,43 @@ yyreduce:
 
   case 66:
     {
-      (yyval.token_decls) = (yyvsp[0].yytype_80);
+      (yyval.token_decls) = (yyvsp[0].yykind_80);
     }
     break;
 
   case 67:
     {
-      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 68:
     {
-      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
   case 69:
-                            { (yyval.yytype_80) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
+                            { (yyval.yykind_80) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
     break;
 
   case 70:
-                            { (yyval.yytype_80) = symbol_list_append ((yyvsp[-1].yytype_80), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+                            { (yyval.yykind_80) = symbol_list_append ((yyvsp[-1].yykind_80), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
     break;
 
   case 71:
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
-      if (0 <= (yyvsp[-1].yytype_82))
-        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_82), (yylsp[-1]));
+      if (0 <= (yyvsp[-1].yykind_82))
+        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yykind_82), (yylsp[-1]));
       if ((yyvsp[0].alias))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].alias), (yylsp[0]));
     }
     break;
 
   case 72:
-          { (yyval.yytype_82) = -1; }
+          { (yyval.yykind_82) = -1; }
     break;
 
   case 74:
@@ -2377,68 +2377,68 @@ yyreduce:
 
   case 77:
     {
-      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_85);
+      (yyval.token_decls_for_prec) = (yyvsp[0].yykind_85);
     }
     break;
 
   case 78:
     {
-      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_85), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 79:
     {
-      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_85), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
   case 80:
-    { (yyval.yytype_85) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+    { (yyval.yykind_85) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
     break;
 
   case 81:
-    { (yyval.yytype_85) = symbol_list_append ((yyvsp[-1].yytype_85), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+    { (yyval.yykind_85) = symbol_list_append ((yyvsp[-1].yykind_85), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
     break;
 
   case 82:
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
-      if (0 <= (yyvsp[0].yytype_82))
-        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_82), (yylsp[0]));
+      if (0 <= (yyvsp[0].yykind_82))
+        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yykind_82), (yylsp[0]));
     }
     break;
 
   case 84:
     {
-      (yyval.symbol_decls) = (yyvsp[0].yytype_88);
+      (yyval.symbol_decls) = (yyvsp[0].yykind_88);
     }
     break;
 
   case 85:
     {
-      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_88), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 86:
     {
-      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_88), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
   case 87:
     {
       symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
-      (yyval.yytype_88) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
+      (yyval.yykind_88) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
   case 88:
     {
       symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
-      (yyval.yytype_88) = symbol_list_append ((yyvsp[-1].yytype_88), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
+      (yyval.yykind_88) = symbol_list_append ((yyvsp[-1].yykind_88), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
     }
     break;
 
@@ -2449,7 +2449,7 @@ yyreduce:
     break;
 
   case 94:
-                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_95)); }
+                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yykind_95)); }
     break;
 
   case 95:
@@ -2473,11 +2473,11 @@ yyreduce:
     break;
 
   case 100:
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_95)); }
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yykind_95)); }
     break;
 
   case 101:
-    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_95), (yyvsp[-2].yytype_74)); }
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yykind_95), (yyvsp[-2].yykind_74)); }
     break;
 
   case 102:
@@ -2509,11 +2509,11 @@ yyreduce:
     break;
 
   case 109:
-                 { (yyval.yytype_95) = NULL; }
+                 { (yyval.yykind_95) = NULL; }
     break;
 
   case 110:
-                 { (yyval.yytype_95) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+                 { (yyval.yykind_95) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
     break;
 
   case 112:
