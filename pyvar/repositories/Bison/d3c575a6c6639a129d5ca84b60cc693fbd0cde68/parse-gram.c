@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.7.14-eb26-dirty.  */
+/* A Bison parser, made by GNU Bison 3.7.3.7-d831b.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.7.14-eb26-dirty"
+#define YYBISON_VERSION "3.7.3.7-d831b"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -218,8 +218,6 @@ typedef enum yysymbol_kind_t yysymbol_kind_t;
   #include "system.h"
 
   #include <c-ctype.h>
-  #include <errno.h>
-  #include <intprops.h>
   #include <quotearg.h>
   #include <vasnprintf.h>
   #include <xmemdup0.h>
@@ -233,6 +231,7 @@ typedef enum yysymbol_kind_t yysymbol_kind_t;
   #include "reader.h"
   #include "scan-code.h"
   #include "scan-gram.h"
+  #include "strversion.h"
 
   /* Pretend to be at least that version, to check features published
      in that version while developping it.  */
@@ -639,19 +638,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   312,   312,   321,   322,   326,   327,   333,   337,   342,
-     343,   344,   345,   346,   347,   348,   353,   358,   359,   360,
-     361,   362,   363,   363,   364,   365,   366,   367,   368,   369,
-     370,   371,   375,   376,   385,   386,   390,   401,   405,   409,
-     417,   427,   428,   438,   439,   445,   458,   458,   463,   463,
-     468,   472,   482,   483,   484,   485,   489,   490,   495,   496,
-     500,   501,   505,   506,   507,   520,   529,   533,   537,   545,
-     546,   550,   563,   564,   569,   570,   571,   589,   593,   597,
-     605,   607,   612,   619,   629,   633,   637,   645,   650,   662,
-     663,   669,   670,   671,   678,   678,   686,   687,   688,   693,
-     696,   698,   700,   702,   704,   706,   708,   710,   712,   717,
-     718,   727,   751,   752,   753,   754,   766,   768,   792,   797,
-     798,   803,   811,   812
+       0,   311,   311,   320,   321,   325,   326,   332,   336,   341,
+     342,   343,   344,   345,   346,   347,   352,   357,   358,   359,
+     360,   361,   362,   362,   363,   364,   365,   366,   367,   368,
+     369,   370,   374,   375,   384,   385,   389,   400,   404,   408,
+     416,   426,   427,   437,   438,   444,   457,   457,   462,   462,
+     467,   471,   481,   482,   483,   484,   488,   489,   494,   495,
+     499,   500,   504,   505,   506,   519,   528,   532,   536,   544,
+     545,   549,   562,   563,   568,   569,   570,   588,   592,   596,
+     604,   606,   611,   618,   628,   632,   636,   644,   649,   661,
+     662,   668,   669,   670,   677,   677,   685,   686,   687,   692,
+     695,   697,   699,   701,   703,   705,   707,   709,   711,   716,
+     717,   726,   750,   751,   752,   753,   765,   767,   791,   796,
+     797,   802,   810,   811
 };
 #endif
 
@@ -3032,56 +3031,11 @@ handle_pure_parser (location const *loc, char const *directive)
 }
 
 
-/* Convert VERSION into an int (MAJOR * 10000 + MINOR * 100 + MICRO).
-   E.g., "3.7.4" => 30704, "3.8" => 30800.
-   Return -1 on errors. */
-static int
-str_to_version (char const *version)
-{
-  IGNORE_TYPE_LIMITS_BEGIN
-  int res = 0;
-  errno = 0;
-  char *cp = NULL;
-
-  {
-    long major = strtol (version, &cp, 10);
-    if (errno || cp == version || *cp != '.' || major < 0
-        || INT_MULTIPLY_WRAPV (major, 10000, &res))
-      return -1;
-  }
-
-  {
-    ++cp;
-    char *prev = cp;
-    long minor = strtol (cp, &cp, 10);
-    if (errno || cp == prev || (*cp != '\0' && *cp != '.')
-        || ! (0 <= minor && minor < 100)
-        || INT_MULTIPLY_WRAPV (minor, 100, &minor)
-        || INT_ADD_WRAPV (minor, res, &res))
-      return -1;
-  }
-
-  if (*cp == '.')
-    {
-      ++cp;
-      char *prev = cp;
-      long micro = strtol (cp, &cp, 10);
-      if (errno || cp == prev || (*cp != '\0' && *cp != '.')
-          || ! (0 <= micro && micro < 100)
-          || INT_ADD_WRAPV (micro, res, &res))
-        return -1;
-    }
-
-  IGNORE_TYPE_LIMITS_END
-  return res;
-}
-
-
 static void
 handle_require (location const *loc, char const *version_quoted)
 {
   char *version = unquote (version_quoted);
-  required_version = str_to_version (version);
+  required_version = strversion_to_int (version);
   if (required_version == -1)
     {
       complain (loc, complaint, _("invalid version requirement: %s"),
