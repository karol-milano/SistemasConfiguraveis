@@ -104,7 +104,7 @@
 enum yysymbol_kind_t
 {
   YYSYMBOL_YYEMPTY = -2,
-  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
+  YYSYMBOL_YYEOF = 0,                      /* $end  */
   YYSYMBOL_YYERROR = 1,                    /* error  */
   YYSYMBOL_YYUNDEF = 2,                    /* $undefined  */
   YYSYMBOL_STRING = 3,                     /* "string"  */
@@ -614,19 +614,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   288,   288,   297,   298,   302,   303,   309,   313,   318,
-     319,   324,   325,   326,   327,   328,   333,   338,   339,   340,
-     341,   342,   343,   343,   344,   345,   346,   347,   348,   349,
-     350,   351,   355,   356,   365,   366,   370,   381,   385,   389,
-     397,   407,   408,   418,   419,   425,   438,   438,   443,   443,
-     448,   452,   462,   463,   464,   465,   469,   470,   475,   476,
-     480,   481,   485,   486,   487,   500,   509,   513,   517,   525,
-     526,   530,   543,   544,   549,   550,   551,   569,   573,   577,
-     585,   587,   592,   599,   609,   613,   617,   625,   630,   642,
-     643,   649,   650,   651,   658,   658,   666,   667,   668,   673,
-     676,   678,   680,   682,   684,   686,   688,   690,   692,   697,
-     698,   707,   731,   732,   733,   734,   746,   748,   772,   777,
-     778,   783,   791,   792
+       0,   287,   287,   296,   297,   301,   302,   308,   312,   317,
+     318,   323,   324,   325,   326,   327,   332,   337,   338,   339,
+     340,   341,   342,   342,   343,   344,   345,   346,   347,   348,
+     349,   350,   354,   355,   364,   365,   369,   380,   384,   388,
+     396,   406,   407,   417,   418,   424,   437,   437,   442,   442,
+     447,   451,   461,   462,   463,   464,   468,   469,   474,   475,
+     479,   480,   484,   485,   486,   499,   508,   512,   516,   524,
+     525,   529,   542,   543,   548,   549,   550,   568,   572,   576,
+     584,   586,   591,   598,   608,   612,   616,   624,   629,   641,
+     642,   648,   649,   650,   657,   657,   665,   666,   667,   672,
+     675,   677,   679,   681,   683,   685,   687,   689,   691,   696,
+     697,   706,   730,   731,   732,   733,   745,   747,   771,   776,
+     777,   782,   790,   791
 };
 #endif
 
@@ -670,7 +670,7 @@ yysymbol_name (yysymbol_kind_t yysymbol)
      internationalizable.  */
   static yytype_int8 yytranslatable[] =
   {
-       1,     0,     0,     1,     1,     0,     0,     0,     0,     0,
+       0,     0,     0,     1,     1,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
