@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.6.4.130-76c4d.  */
+/* A Bison parser, made by GNU Bison 3.6.90.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.6.4.130-76c4d"
+#define YYBISON_VERSION "3.6.90"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -234,6 +234,10 @@ typedef enum yysymbol_kind_t yysymbol_kind_t;
   #include "scan-code.h"
   #include "scan-gram.h"
 
+  /* Pretend to be at least that version, to check features published
+     in that version while developping it.  */
+  static const char* api_version = "3.7";
+
   static int current_prec = 0;
   static location current_lhs_loc;
   static named_ref *current_lhs_named_ref;
@@ -634,19 +638,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   308,   308,   317,   318,   322,   323,   329,   333,   338,
-     339,   340,   341,   342,   343,   344,   349,   354,   355,   356,
-     357,   358,   359,   359,   360,   361,   362,   363,   364,   365,
-     366,   367,   371,   372,   381,   382,   386,   397,   401,   405,
-     413,   423,   424,   434,   435,   441,   454,   454,   459,   459,
-     464,   468,   478,   479,   480,   481,   485,   486,   491,   492,
-     496,   497,   501,   502,   503,   516,   525,   529,   533,   541,
-     542,   546,   559,   560,   565,   566,   567,   585,   589,   593,
-     601,   603,   608,   615,   625,   629,   633,   641,   646,   658,
-     659,   665,   666,   667,   674,   674,   682,   683,   684,   689,
-     692,   694,   696,   698,   700,   702,   704,   706,   708,   713,
-     714,   723,   747,   748,   749,   750,   762,   764,   788,   793,
-     794,   799,   807,   808
+       0,   312,   312,   321,   322,   326,   327,   333,   337,   342,
+     343,   344,   345,   346,   347,   348,   353,   358,   359,   360,
+     361,   362,   363,   363,   364,   365,   366,   367,   368,   369,
+     370,   371,   375,   376,   385,   386,   390,   401,   405,   409,
+     417,   427,   428,   438,   439,   445,   458,   458,   463,   463,
+     468,   472,   482,   483,   484,   485,   489,   490,   495,   496,
+     500,   501,   505,   506,   507,   520,   529,   533,   537,   545,
+     546,   550,   563,   564,   569,   570,   571,   589,   593,   597,
+     605,   607,   612,   619,   629,   633,   637,   645,   650,   662,
+     663,   669,   670,   671,   678,   678,   686,   687,   688,   693,
+     696,   698,   700,   702,   704,   706,   708,   710,   712,   717,
+     718,   727,   751,   752,   753,   754,   766,   768,   792,   797,
+     798,   803,   811,   812
 };
 #endif
 
@@ -3070,9 +3074,6 @@ handle_require (location const *loc, char const *version_quoted)
     }
   else
     {
-      /* Pretend to be at least that version, to check features published
-         in that version while developping it.  */
-      const char* api_version = "3.6";
       const char* package_version =
         0 < strverscmp (api_version, PACKAGE_VERSION)
         ? api_version : PACKAGE_VERSION;
