@@ -178,11 +178,10 @@ typedef union b4_stype yystype;
 #ifndef YYLTYPE
 typedef struct yyltype
 {
-]b4_location_if([
   int first_line;
   int first_column;
   int last_line;
-  int last_column;])[
+  int last_column;
 } yyltype;
 # define YYLTYPE ]b4_location_type[
 # define YYLTYPE_IS_TRIVIAL 1
