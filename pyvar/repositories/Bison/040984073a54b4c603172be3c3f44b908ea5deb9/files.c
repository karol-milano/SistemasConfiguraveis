@@ -66,9 +66,9 @@ static char *full_base_name = NULL;
 char *short_base_name = NULL;
 
 /* C source file extension (the parser source).  */
-const char *src_extension = NULL;
+static char const *src_extension = NULL;
 /* Header file extension (if option ``-d'' is specified).  */
-const char *header_extension = NULL;
+static char const *header_extension = NULL;
 
 /*-----------------------------------------------------------------.
 | Return a newly allocated string composed of the concatenation of |
