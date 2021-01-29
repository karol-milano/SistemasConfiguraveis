@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.2.189-f435.  */
+/* A Bison parser, made by GNU Bison 3.4.2.191-54c5d.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.2.189-f435"
+#define YYBISON_VERSION "3.4.2.191-54c5d"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -105,22 +105,23 @@
 /* Unqualified %code blocks.  */
 
   #include "system.h"
+
+  #include <c-ctype.h>
   #include <errno.h>
+  #include <intprops.h>
+  #include <quotearg.h>
+  #include <vasnprintf.h>
+  #include <xmemdup0.h>
 
-  #include "c-ctype.h"
   #include "complain.h"
   #include "conflicts.h"
   #include "files.h"
   #include "getargs.h"
   #include "gram.h"
-  #include "intprops.h"
   #include "named-ref.h"
-  #include "quotearg.h"
   #include "reader.h"
   #include "scan-code.h"
   #include "scan-gram.h"
-  #include "vasnprintf.h"
-  #include "xmemdup0.h"
 
   static int current_prec = 0;
   static location current_lhs_loc;
@@ -490,19 +491,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   292,   292,   301,   302,   306,   307,   313,   317,   322,
-     323,   328,   329,   330,   331,   332,   337,   342,   343,   344,
-     345,   346,   347,   347,   348,   349,   350,   351,   352,   353,
-     354,   355,   359,   360,   369,   370,   374,   385,   389,   393,
-     401,   411,   412,   422,   423,   429,   442,   442,   447,   447,
-     452,   456,   466,   467,   468,   469,   473,   474,   479,   480,
-     484,   485,   489,   490,   491,   504,   513,   517,   521,   529,
-     530,   534,   547,   548,   560,   564,   568,   576,   578,   583,
-     590,   600,   604,   608,   616,   617,   625,   626,   632,   633,
-     634,   641,   641,   649,   650,   651,   656,   659,   661,   663,
-     665,   667,   669,   671,   673,   675,   680,   681,   690,   714,
-     715,   716,   717,   729,   731,   758,   763,   764,   769,   778,
-     779,   783,   784
+       0,   293,   293,   302,   303,   307,   308,   314,   318,   323,
+     324,   329,   330,   331,   332,   333,   338,   343,   344,   345,
+     346,   347,   348,   348,   349,   350,   351,   352,   353,   354,
+     355,   356,   360,   361,   370,   371,   375,   386,   390,   394,
+     402,   412,   413,   423,   424,   430,   443,   443,   448,   448,
+     453,   457,   467,   468,   469,   470,   474,   475,   480,   481,
+     485,   486,   490,   491,   492,   505,   514,   518,   522,   530,
+     531,   535,   548,   549,   561,   565,   569,   577,   579,   584,
+     591,   601,   605,   609,   617,   618,   626,   627,   633,   634,
+     635,   642,   642,   650,   651,   652,   657,   660,   662,   664,
+     666,   668,   670,   672,   674,   676,   681,   682,   691,   715,
+     716,   717,   718,   730,   732,   759,   764,   765,   770,   779,
+     780,   784,   785
 };
 #endif
 
@@ -2979,37 +2980,53 @@ handle_pure_parser (location const *loc, char const *directive)
 }
 
 
-static void
-handle_require (location const *loc, char const *version)
+/* Convert VERSION into an int (MAJOR * 100 + MINOR).  Return -1 on
+   errors.
+
+   Changes of behavior are only on minor version changes, so "3.0.5"
+   is the same as "3.0": 300. */
+static int
+str_to_version (char const *version)
 {
-  /* Changes of behavior are only on minor version changes, so "3.0.5"
-     is the same as "3.0". */
+  int res = 0;
   errno = 0;
-  char *cp = NULL, *cp1;
+  char *cp = NULL;
   long major = strtol (version, &cp, 10);
-  if (errno || cp == version || *cp != '.' || major < 0)
-    {
-      complain (loc, complaint, _("invalid version requirement: %s"),
-                version);
-      return;
-    }
+  if (errno || cp == version || *cp != '.' || major < 0
+      || INT_MULTIPLY_WRAPV (major, 100, &res))
+    return -1;
+
   ++cp;
+  char *cp1 = NULL;
   long minor = strtol (cp, &cp1, 10);
-  if (errno || cp1 == cp || ! (0 <= minor && minor < 100)
-      || INT_MULTIPLY_WRAPV (major, 100, &required_version)
-      || INT_ADD_WRAPV (minor, required_version, &required_version))
+  if (errno || cp1 == cp || (*cp1 != '\0' && *cp1 != '.')
+      || ! (0 <= minor && minor < 100)
+      || INT_ADD_WRAPV (minor, res, &res))
+    return -1;
+
+  return res;
+}
+
+
+static void
+handle_require (location const *loc, char const *version)
+{
+  required_version = str_to_version (version);
+  if (required_version == -1)
     {
       complain (loc, complaint, _("invalid version requirement: %s"),
                 version);
+      required_version = 0;
       return;
     }
+
   /* Pretend to be at least 3.4, to check features published in 3.4
      while developping it.  */
   const char* api_version = "3.4";
   const char* package_version =
-    strverscmp (api_version, PACKAGE_VERSION) > 0
+    0 < strverscmp (api_version, PACKAGE_VERSION)
     ? api_version : PACKAGE_VERSION;
-  if (strverscmp (version, package_version) > 0)
+  if (0 < strverscmp (version, package_version))
     {
       complain (loc, complaint, _("require bison %s, but have %s"),
                 version, package_version);
