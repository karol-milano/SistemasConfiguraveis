@@ -15,7 +15,7 @@
 #define yyrestart gram_restart
 #define yytext gram_text
 
-#line 19 "lex.yy.c"
+#line 19 "scan-gram.c"
 /* A lexical scanner generated by flex */
 
 /* Scanner skeleton version:
@@ -400,46 +400,46 @@ static yyconst int yy_meta[51] =
 static yyconst short int yy_base[406] =
     {   0,
         0,    0,   48,   51,   58,   61,   83,   86,   73,   94,
-      108,  110,  131,  179,  227,  249,  116,  142,  839,  840,
-      836,   55,   64,  840,  267,  840,    0,   44,   79,  840,
-      840,    0,  840,  840,  840,    0,   97,   99,  825,  840,
-      840,    0,  119,  122,  840,  840,    0,  840,    0,  126,
-      138,  840,    0,    0,  145,  153,  840,  311,  840,  155,
-      157,  840,    0,  159,  164,  840,  159,  840,   62,  164,
-      840,  840,  840,  840,    0,  185,  189,  840,  786,  840,
-      185,  192,  201,  203,  205,  207,  209,  833,  211,  213,
-      216,  219,  840,  800,   39,   86,  799,  796,   65,  801,
-
-      198,  786,  184,  795,  109,  203,  790,  797,  800,  840,
-        0,  840,    0,  230,  806,    0,  242,  244,  255,  259,
-      840,    0,  261,  263,  265,  272,  840,    0,  274,  276,
-      278,  280,  840,    0,  282,  284,  286,  288,  840,  840,
-      811,  840,  840,  840,  840,  840,  840,  840,    0,  297,
-      314,  316,  318,    0,  322,  324,  326,  328,  840,  322,
-      326,    0,  840,    0,  840,  330,  332,    0,  344,  347,
-      355,  357,  840,  359,  361,  363,  365,  367,  369,  371,
-      785,  144,  781,  780,  780,  144,  778,  787,  789,  775,
-      778,  366,  784,  770,  168,  771,  779,  780,  783,  767,
-
-      772,  766,  771,  763,  775,    0,  840,  789,    0,  782,
-        0,  374,  377,  774,  755,  764,  754,  766,  756,  764,
-      763,  762,  230,  748,  764,  757,  758,  751,  760,  744,
-      744,  755,  744,  751,  747,  743,  737,  740,  746,  745,
-      735,  746,  744,  840,  840,  373,  730,  738,  731,  727,
-      739,  725,  737,  754,  734,  722,  840,  718,  730,  372,
-      725,  716,  720,  712,  840,  712,  375,  711,  723,  709,
-      840,  713,  840,  712,  710,  840,  701,  840,  717,  702,
-      840,  378,  702,  704,  380,  717,  708,  840,  701,  702,
-      697,  840,  695,  707,  696,  840,  692,  840,  382,  840,
-
-      692,  840,  691,  704,  686,  840,  689,  690,  687,  688,
-      659,  666,  633,  840,  628,  629,  613,  606,  618,  840,
-      603,  615,  614,  597,  596,  597,  603,  590,  603,  840,
-      589,  567,  578,  840,  564,  541,  547,  534,  523,  510,
-      520,  840,  840,  506,  840,  516,  497,  510,  499,  368,
-      365,  840,  368,  359,  348,  840,  316,  307,  297,  840,
-      287,  282,  283,  260,  840,  252,  840,  840,  840,  263,
-      384,  840,  241,  236,  224,  196,  158,  840,  840,  409,
+      108,  110,  131,  179,  227,  249,  116,  142,  840,  841,
+      837,   55,   64,  841,  267,  841,    0,   44,   79,  841,
+      841,    0,  841,  841,  841,    0,   97,   99,  826,  841,
+      841,    0,  119,  122,  841,  841,    0,  841,    0,  126,
+      138,  841,    0,    0,  145,  153,  841,  311,  841,  155,
+      157,  841,    0,  159,  164,  841,  159,  841,   62,  164,
+      841,  841,  841,  841,    0,  185,  189,  841,  787,  841,
+      185,  192,  201,  203,  205,  207,  209,  834,  211,  213,
+      216,  219,  841,  801,   39,   86,  800,  797,   65,  802,
+
+      198,  787,  184,  796,  109,  203,  791,  798,  801,  841,
+        0,  841,    0,  230,  807,    0,  242,  244,  255,  259,
+      841,    0,  261,  263,  265,  272,  841,    0,  274,  276,
+      278,  280,  841,    0,  282,  284,  286,  288,  841,  841,
+      812,  841,  841,  841,  841,  841,  841,  841,    0,  297,
+      314,  317,  319,    0,  322,  324,  326,  328,  841,  322,
+      326,    0,  841,    0,  841,  330,  332,    0,  344,  347,
+      355,  357,  841,  359,  361,  363,  365,  367,  369,  371,
+      786,  144,  782,  781,  781,  144,  779,  788,  790,  776,
+      779,  366,  785,  771,  168,  772,  780,  781,  784,  768,
+
+      773,  767,  772,  764,  776,    0,  841,  790,    0,  783,
+        0,  374,  377,  775,  756,  765,  755,  767,  757,  765,
+      764,  763,  230,  749,  765,  758,  759,  752,  761,  745,
+      745,  756,  745,  752,  748,  744,  738,  741,  747,  746,
+      736,  747,  745,  841,  841,  373,  731,  739,  732,  728,
+      740,  726,  738,  755,  735,  723,  841,  719,  731,  372,
+      726,  717,  721,  713,  841,  713,  375,  712,  724,  710,
+      841,  714,  841,  713,  711,  841,  702,  841,  718,  703,
+      841,  378,  703,  705,  380,  718,  709,  841,  702,  703,
+      698,  841,  696,  708,  697,  841,  693,  841,  382,  841,
+
+      693,  841,  692,  705,  687,  841,  690,  691,  688,  689,
+      686,  670,  657,  841,  631,  643,  616,  609,  619,  841,
+      605,  616,  615,  600,  599,  600,  605,  591,  604,  841,
+      590,  592,  579,  841,  565,  562,  551,  535,  547,  511,
+      521,  841,  841,  509,  841,  521,  502,  511,  503,  493,
+      367,  841,  372,  372,  353,  841,  345,  309,  309,  841,
+      295,  292,  283,  260,  841,  252,  841,  841,  841,  263,
+      384,  841,  241,  236,  224,  196,  158,  841,  841,  409,
       423,  437,  451,  465,  479,  493,  507,  227,  521,  535,
       549,  561,  575,  587,  601,  614,  628,  642,  656,  670,
 
@@ -495,7 +495,7 @@ static yyconst short int yy_def[406] =
       379,  379,  379,  379,  379
     } ;
 
-static yyconst short int yy_nxt[891] =
+static yyconst short int yy_nxt[892] =
     {   0,
        20,   21,   22,   23,   24,   20,   25,   26,   20,   20,
        27,   28,   29,   29,   30,   31,   32,   33,   20,   20,
@@ -531,17 +531,17 @@ static yyconst short int yy_nxt[891] =
       137,  138,  372,   94,  371,   95,   96,   97,   98,  150,
 
       151,  370,   99,  100,  101,  102,  103,  104,  105,  106,
-      107,  108,  369,  109,  110,  140,  152,  153,  150,  151,
-      152,  153,  368,  141,  155,  156,  157,  158,  155,  156,
-      157,  158,  367,  140,  161,  161,  142,  143,  161,  161,
-      366,  144,  167,  167,  167,  167,  169,  170,  145,  171,
-      172,  146,  365,  147,  364,  148,  149,  169,  170,  171,
+      107,  108,  369,  109,  110,  140,  152,  153,  140,  150,
+      151,  152,  153,  141,  155,  156,  157,  158,  155,  156,
+      157,  158,  368,  140,  161,  161,  142,  143,  161,  161,
+      367,  144,  167,  167,  167,  167,  169,  170,  145,  171,
+      172,  146,  366,  147,  365,  148,  149,  169,  170,  171,
       172,  175,  176,  175,  177,  178,  176,  178,  176,  175,
       177,  175,  176,  175,  213,  228,  175,  213,  159,  178,
-      213,  289,  160,  363,  295,  161,  161,  305,  362,  308,
+      213,  289,  160,  364,  295,  161,  161,  305,  363,  308,
       228,  318,  211,  373,  211,  211,  289,  211,  211,  295,
 
-      211,  361,  305,  229,  308,  360,  318,  359,  373,   36,
+      211,  362,  305,  229,  308,  361,  318,  360,  373,   36,
        36,   36,   36,   36,   36,   36,   36,   36,   36,   36,
        36,   36,   36,   42,   42,   42,   42,   42,   42,   42,
        42,   42,   42,   42,   42,   42,   42,   49,   49,   49,
@@ -555,48 +555,50 @@ static yyconst short int yy_nxt[891] =
        75,   75,   75,   75,   75,   75,   75,   82,   82,   82,
        82,   82,   82,   82,   82,   82,   82,   82,   82,   82,
        82,  115,  115,  115,  115,  115,  115,  115,  115,  115,
-      115,  115,  358,  115,  115,  116,  357,  356,  116,  116,
-      116,  116,  355,  116,  116,  116,  116,  354,  116,  122,
-      353,  352,  351,  122,  122,  122,  122,  122,  122,  122,
+      115,  115,  359,  115,  115,  116,  358,  357,  116,  116,
+      116,  116,  356,  116,  116,  116,  116,  355,  116,  122,
+      354,  353,  352,  122,  122,  122,  122,  122,  122,  122,
       122,  127,  127,  127,  127,  127,  127,  127,  127,  127,
-      127,  127,  127,  127,  127,  128,  350,  349,  128,  128,
-      128,  348,  128,  128,  128,  128,  128,  133,  133,  133,
+      127,  127,  127,  127,  127,  128,  351,  350,  128,  128,
+      128,  349,  128,  128,  128,  128,  128,  133,  133,  133,
       133,  133,  133,  133,  133,  133,  133,  133,  133,  133,
 
-      133,  134,  347,  346,  345,  134,  134,  134,  134,  134,
+      133,  134,  348,  347,  346,  134,  134,  134,  134,  134,
       134,  134,  134,  134,  139,  139,  139,  139,  139,  139,
-      139,  139,  139,  139,  139,  139,  139,  139,  154,  344,
-      343,  342,  341,  154,  340,  154,  154,  339,  154,  154,
-      338,  154,  168,  337,  336,  335,  168,  334,  333,  168,
-      168,  332,  168,  168,  331,  168,  174,  174,  174,  174,
-      174,  174,  174,  174,  174,  174,  174,  174,  330,  174,
-      206,  329,  206,  206,  206,  206,  206,  206,  206,  206,
+      139,  139,  139,  139,  139,  139,  139,  139,  154,  345,
+      344,  343,  342,  154,  341,  154,  154,  340,  154,  154,
+      339,  154,  168,  338,  337,  336,  168,  335,  334,  168,
+      168,  333,  168,  168,  332,  168,  174,  174,  174,  174,
+      174,  174,  174,  174,  174,  174,  174,  174,  331,  174,
+      206,  330,  206,  206,  206,  206,  206,  206,  206,  206,
       206,  206,  206,  206,  210,  210,  210,  210,  210,  210,
-      210,  210,  210,  210,  210,  328,  210,  210,  211,  327,
+      210,  210,  210,  210,  210,  329,  210,  210,  211,  328,
 
       211,  211,  211,  211,  211,  211,  211,  211,  211,  211,
       211,  211,  212,  212,  212,  212,  212,  212,  212,  212,
-      212,  212,  212,  212,  212,  212,  326,  325,  324,  323,
-      322,  321,  320,  319,  317,  316,  315,  314,  313,  312,
-      311,  310,  309,  307,  306,  304,  303,  302,  301,  300,
-      299,  298,  297,  296,  294,  293,  292,  291,  290,  288,
-      287,  286,  285,  284,  283,  282,  281,  280,  279,  278,
-      277,  276,  275,  274,  273,  272,  271,  270,  269,  268,
-      267,  266,  265,  264,  263,  262,  261,  260,  259,  258,
-      257,  255,  254,  253,  252,  251,  250,  249,  248,  247,
-
-      246,  244,  243,  242,  241,  240,  239,  238,  237,  236,
-      235,  234,  231,  230,  227,  226,  225,  224,  223,  220,
-      219,  218,  214,  208,  207,  205,  204,  203,  197,  194,
-      190,  187,  186,  181,   88,  173,  121,   88,  379,   19,
+      212,  212,  212,  212,  212,  212,  327,  326,  325,  324,
+      323,  322,  321,  320,  319,  317,  316,  315,  314,  313,
+      312,  311,  310,  309,  307,  306,  304,  303,  302,  301,
+      300,  299,  298,  297,  296,  294,  293,  292,  291,  290,
+      288,  287,  286,  285,  284,  283,  282,  281,  280,  279,
+      278,  277,  276,  275,  274,  273,  272,  271,  270,  269,
+      268,  267,  266,  265,  264,  263,  262,  261,  260,  259,
+      258,  257,  255,  254,  253,  252,  251,  250,  249,  248,
+
+      247,  246,  244,  243,  242,  241,  240,  239,  238,  237,
+      236,  235,  234,  231,  230,  227,  226,  225,  224,  223,
+      220,  219,  218,  214,  208,  207,  205,  204,  203,  197,
+      194,  190,  187,  186,  181,   88,  173,  121,   88,  379,
+       19,  379,  379,  379,  379,  379,  379,  379,  379,  379,
       379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
       379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
       379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
       379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
-      379,  379,  379,  379,  379,  379,  379,  379,  379,  379
+      379
+
     } ;
 
-static yyconst short int yy_chk[891] =
+static yyconst short int yy_chk[892] =
     {   0,
         1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
         1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
@@ -632,17 +634,17 @@ static yyconst short int yy_chk[891] =
       138,  138,  370,   25,  366,   25,   25,   25,   25,  150,
 
       150,  364,   25,   25,   25,   25,   25,   25,   25,   25,
-       25,   25,  363,   25,   25,   58,  151,  151,  152,  152,
-      153,  153,  362,   58,  155,  155,  156,  156,  157,  157,
-      158,  158,  361,   58,  160,  160,   58,   58,  161,  161,
-      359,   58,  166,  166,  167,  167,  169,  169,   58,  170,
-      170,   58,  358,   58,  357,   58,   58,  171,  171,  172,
+       25,   25,  363,   25,   25,   58,  151,  151,   58,  152,
+      152,  153,  153,   58,  155,  155,  156,  156,  157,  157,
+      158,  158,  362,   58,  160,  160,   58,   58,  161,  161,
+      361,   58,  166,  166,  167,  167,  169,  169,   58,  170,
+      170,   58,  359,   58,  358,   58,   58,  171,  171,  172,
       172,  174,  174,  175,  175,  176,  176,  177,  177,  178,
       178,  179,  179,  180,  180,  192,  212,  212,  246,  213,
-      213,  260,  246,  355,  267,  246,  246,  282,  354,  285,
+      213,  260,  246,  357,  267,  246,  246,  282,  355,  285,
       192,  299,  180,  371,  180,  212,  260,  212,  213,  267,
 
-      213,  353,  282,  192,  285,  351,  299,  350,  371,  380,
+      213,  354,  282,  192,  285,  353,  299,  351,  371,  380,
       380,  380,  380,  380,  380,  380,  380,  380,  380,  380,
       380,  380,  380,  381,  381,  381,  381,  381,  381,  381,
       381,  381,  381,  381,  381,  381,  381,  382,  382,  382,
@@ -656,45 +658,47 @@ static yyconst short int yy_chk[891] =
       386,  386,  386,  386,  386,  386,  386,  387,  387,  387,
       387,  387,  387,  387,  387,  387,  387,  387,  387,  387,
       387,  389,  389,  389,  389,  389,  389,  389,  389,  389,
-      389,  389,  349,  389,  389,  390,  348,  347,  390,  390,
-      390,  390,  346,  390,  390,  390,  390,  344,  390,  391,
-      341,  340,  339,  391,  391,  391,  391,  391,  391,  391,
+      389,  389,  350,  389,  389,  390,  349,  348,  390,  390,
+      390,  390,  347,  390,  390,  390,  390,  346,  390,  391,
+      344,  341,  340,  391,  391,  391,  391,  391,  391,  391,
       391,  392,  392,  392,  392,  392,  392,  392,  392,  392,
-      392,  392,  392,  392,  392,  393,  338,  337,  393,  393,
-      393,  336,  393,  393,  393,  393,  393,  394,  394,  394,
+      392,  392,  392,  392,  392,  393,  339,  338,  393,  393,
+      393,  337,  393,  393,  393,  393,  393,  394,  394,  394,
       394,  394,  394,  394,  394,  394,  394,  394,  394,  394,
 
-      394,  395,  335,  333,  332,  395,  395,  395,  395,  395,
+      394,  395,  336,  335,  333,  395,  395,  395,  395,  395,
       395,  395,  395,  395,  396,  396,  396,  396,  396,  396,
-      396,  396,  396,  396,  396,  396,  396,  396,  397,  331,
-      329,  328,  327,  397,  326,  397,  397,  325,  397,  397,
-      324,  397,  398,  323,  322,  321,  398,  319,  318,  398,
-      398,  317,  398,  398,  316,  398,  399,  399,  399,  399,
-      399,  399,  399,  399,  399,  399,  399,  399,  315,  399,
-      400,  313,  400,  400,  400,  400,  400,  400,  400,  400,
+      396,  396,  396,  396,  396,  396,  396,  396,  397,  332,
+      331,  329,  328,  397,  327,  397,  397,  326,  397,  397,
+      325,  397,  398,  324,  323,  322,  398,  321,  319,  398,
+      398,  318,  398,  398,  317,  398,  399,  399,  399,  399,
+      399,  399,  399,  399,  399,  399,  399,  399,  316,  399,
+      400,  315,  400,  400,  400,  400,  400,  400,  400,  400,
       400,  400,  400,  400,  402,  402,  402,  402,  402,  402,
-      402,  402,  402,  402,  402,  312,  402,  402,  403,  311,
+      402,  402,  402,  402,  402,  313,  402,  402,  403,  312,
 
       403,  403,  403,  403,  403,  403,  403,  403,  403,  403,
       403,  403,  404,  404,  404,  404,  404,  404,  404,  404,
-      404,  404,  404,  404,  404,  404,  310,  309,  308,  307,
-      305,  304,  303,  301,  297,  295,  294,  293,  291,  290,
-      289,  287,  286,  284,  283,  280,  279,  277,  275,  274,
-      272,  270,  269,  268,  266,  264,  263,  262,  261,  259,
-      258,  256,  255,  254,  253,  252,  251,  250,  249,  248,
-      247,  243,  242,  241,  240,  239,  238,  237,  236,  235,
-      234,  233,  232,  231,  230,  229,  228,  227,  226,  225,
-      224,  222,  221,  220,  219,  218,  217,  216,  215,  214,
-
-      210,  208,  205,  204,  203,  202,  201,  200,  199,  198,
-      197,  196,  194,  193,  191,  190,  189,  188,  187,  185,
-      184,  183,  181,  141,  115,  109,  108,  107,  104,  102,
-      100,   98,   97,   94,   88,   79,   39,   21,   19,  379,
+      404,  404,  404,  404,  404,  404,  311,  310,  309,  308,
+      307,  305,  304,  303,  301,  297,  295,  294,  293,  291,
+      290,  289,  287,  286,  284,  283,  280,  279,  277,  275,
+      274,  272,  270,  269,  268,  266,  264,  263,  262,  261,
+      259,  258,  256,  255,  254,  253,  252,  251,  250,  249,
+      248,  247,  243,  242,  241,  240,  239,  238,  237,  236,
+      235,  234,  233,  232,  231,  230,  229,  228,  227,  226,
+      225,  224,  222,  221,  220,  219,  218,  217,  216,  215,
+
+      214,  210,  208,  205,  204,  203,  202,  201,  200,  199,
+      198,  197,  196,  194,  193,  191,  190,  189,  188,  187,
+      185,  184,  183,  181,  141,  115,  109,  108,  107,  104,
+      102,  100,   98,   97,   94,   88,   79,   39,   21,   19,
+      379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
       379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
       379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
       379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
       379,  379,  379,  379,  379,  379,  379,  379,  379,  379,
-      379,  379,  379,  379,  379,  379,  379,  379,  379,  379
+      379
+
     } ;
 
 static yy_state_type yy_last_accepting_state;
@@ -825,7 +829,7 @@ static void handle_at PARAMS ((braced_code_t code_kind,
 #define SC_PROLOGUE 7
 #define SC_EPILOGUE 8
 
-#line 829 "lex.yy.c"
+#line 833 "scan-gram.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -1010,7 +1014,7 @@ YY_DECL
   /*----------------------------.
   | Scanning Bison directives.  |
   `----------------------------*/
-#line 1014 "lex.yy.c"
+#line 1018 "scan-gram.c"
 
 	if ( yy_init )
 		{
@@ -1067,7 +1071,7 @@ yy_match:
 			yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
 			++yy_cp;
 			}
-		while ( yy_base[yy_current_state] != 840 );
+		while ( yy_base[yy_current_state] != 841 );
 
 yy_find_action:
 		yy_act = yy_accept[yy_current_state];
@@ -1871,7 +1875,7 @@ YY_RULE_SETUP
 #line 529 "scan-gram.l"
 YY_FATAL_ERROR( "flex scanner jammed" );
 	YY_BREAK
-#line 1875 "lex.yy.c"
+#line 1879 "scan-gram.c"
 case YY_STATE_EOF(INITIAL):
 	yyterminate();
 
