@@ -403,8 +403,30 @@ language_argmatch (char const *arg, int prio, location const *loc)
 | Process the options.  |
 `----------------------*/
 
-/* Shorts options.  */
-static char const short_options[] = "yvegxdhr:L:ltknVo:b:p:S:T::W";
+/* Shorts options.
+   Should be computed from long_options.  */
+static char const short_options[] =
+  "L:"
+  "S:"
+  "T::"
+  "V"
+  "W"
+  "b:"
+  "d"
+  "e"
+  "g::"
+  "h"
+  "k"
+  "l"
+  "n"
+  "o:"
+  "p:"
+  "r:"
+  "t"
+  "v"
+  "x::"
+  "y"
+  ;
 
 /* Values for long options that do not have single-letter equivalents.  */
 enum
