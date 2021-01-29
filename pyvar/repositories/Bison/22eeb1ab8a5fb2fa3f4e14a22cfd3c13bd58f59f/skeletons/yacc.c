@@ -767,13 +767,13 @@ do {                                            \
 
 ]b4_yy_location_print_define[
 
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
+# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
 do {                                                                      \
   if (yydebug)                                                            \
     {                                                                     \
       YYFPRINTF (stderr, "%s ", Title);                                   \
       yy_symbol_print (stderr,                                            \
-                  Type, Value]b4_locations_if([, Location])[]b4_user_args[); \
+                  Kind, Value]b4_locations_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");                                           \
     }                                                                     \
 } while (0)
@@ -841,7 +841,7 @@ do {                                    \
 int yydebug;
 #else /* !]b4_api_PREFIX[DEBUG */
 # define YYDPRINTF(Args) ((void) 0)
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
+# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
 #endif /* !]b4_api_PREFIX[DEBUG */
