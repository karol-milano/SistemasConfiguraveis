@@ -60,11 +60,8 @@ static char *relocate_buffer = NULL;
 #define GENERATE_MUSCLE_INSERT_TABLE(Name, Type)                        \
                                                                         \
 static void                                                             \
-Name (char const *name,                                                 \
-      Type *table_data,                                                 \
-      Type first,                                                       \
-      int begin,                                                        \
-      int end)                                                          \
+Name (char const *name, Type *table_data, Type first,                   \
+      int begin, int end)                                               \
 {                                                                       \
   Type min = first;                                                     \
   Type max = first;                                                     \
