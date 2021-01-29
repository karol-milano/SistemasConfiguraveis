@@ -47,6 +47,28 @@ m4_ifdef([b4_parse_param],
 	   b4_parse_param)])
 
 
+
+## ------------ ##
+## Data Types.  ##
+## ------------ ##
+
+# b4_int_type(MIN, MAX)
+# ---------------------
+# Return the smallest int type able to handle numbers ranging from
+# MIN to MAX (included).  We overwrite the version from c.m4 which relies
+# on `signed char' which is not portable to old K&R compilers.
+m4_define([b4_int_type],
+[m4_if(b4_ints_in($@,      [0],   [255]), [1], [unsigned char],
+       b4_ints_in($@,   [-128],   [127]), [1], [yysigned_char],
+
+       b4_ints_in($@,      [0], [65535]), [1], [unsigned short],
+       b4_ints_in($@, [-32768], [32767]), [1], [short],
+
+       m4_eval([0 <= $1]),                [1], [unsigned int],
+
+ 	                                       [int])])
+
+
 ## ----------------- ##
 ## Semantic Values.  ##
 ## ----------------- ##
