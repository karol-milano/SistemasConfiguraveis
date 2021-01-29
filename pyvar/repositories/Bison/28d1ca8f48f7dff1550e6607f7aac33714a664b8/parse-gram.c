@@ -510,11 +510,11 @@ static const yytype_int16 yyrline[] =
      453,   457,   467,   468,   469,   470,   474,   475,   480,   481,
      485,   486,   490,   491,   492,   505,   514,   518,   522,   530,
      531,   535,   548,   549,   561,   565,   569,   577,   579,   584,
-     591,   601,   605,   609,   617,   618,   626,   627,   633,   634,
-     635,   642,   642,   650,   651,   652,   657,   660,   662,   664,
-     666,   668,   670,   672,   674,   676,   681,   682,   691,   715,
-     716,   717,   718,   730,   732,   759,   764,   765,   770,   779,
-     780,   784,   785
+     591,   601,   605,   609,   617,   622,   634,   635,   641,   642,
+     643,   650,   650,   658,   659,   660,   665,   668,   670,   672,
+     674,   676,   678,   680,   682,   684,   689,   690,   699,   723,
+     724,   725,   726,   738,   740,   767,   772,   773,   778,   787,
+     788,   792,   793
 };
 #endif
 
@@ -2410,11 +2410,17 @@ yyreduce:
     break;
 
   case 84:
-                        { (yyval.yytype_86) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+    {
+      symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
+      (yyval.yytype_86) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
+    }
     break;
 
   case 85:
-                        { (yyval.yytype_86) = symbol_list_append ((yyvsp[-1].yytype_86), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+    {
+      symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
+      (yyval.yytype_86) = symbol_list_append ((yyvsp[-1].yytype_86), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
+    }
     break;
 
   case 90:
