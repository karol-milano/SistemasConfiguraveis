@@ -458,14 +458,14 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   169,   169,   182,   184,   187,   189,   190,   191,   192,
+       0,   170,   170,   182,   184,   187,   189,   190,   191,   192,
      193,   194,   195,   196,   197,   199,   200,   201,   202,   203,
      205,   206,   207,   208,   209,   212,   214,   215,   219,   226,
      225,   236,   235,   248,   247,   253,   253,   258,   267,   282,
      284,   285,   288,   290,   295,   297,   301,   306,   311,   317,
      323,   333,   336,   345,   347,   353,   355,   360,   367,   366,
      371,   373,   376,   379,   381,   383,   385,   387,   391,   393,
-     396,   402,   411,   419,   424,   430,   432
+     396,   402,   411,   419,   421,   428,   430
 };
 #endif
 
@@ -1216,10 +1216,9 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 171 "parse-gram.y"
+#line 172 "parse-gram.y"
     {
       yycontrol->errcode = 0;
-      epilogue_set (yyvsp[0].string, yylsp[0]);
     }
     break;
 
@@ -1601,17 +1600,11 @@ yyreduce:
     }
     break;
 
-  case 73:
-#line 421 "parse-gram.y"
-    {
-      yyval.string = xstrdup ("");
-    }
-    break;
-
   case 74:
-#line 425 "parse-gram.y"
+#line 422 "parse-gram.y"
     {
-      yyval.string = yyvsp[0].string;
+      epilogue_augment (yyvsp[0].string, yylsp[0]);
+      scanner_last_string_free ();
     }
     break;
 
@@ -1619,7 +1612,7 @@ yyreduce:
     }
 
 /* Line 1056 of /usr/local/share/bison/yacc.c.  */
-#line 1623 "parse-gram.c"
+#line 1616 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1838,7 +1831,7 @@ yyreturn:
 }
 
 
-#line 434 "parse-gram.y"
+#line 432 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
@@ -1872,6 +1865,10 @@ yyprint (FILE *file,
     case EPILOGUE:
       fprintf (file, " = {{ %s }}", value->string);
       break;
+
+    default:
+      fprintf (file, "unknown token type");
+      break;
     }
 }
 
