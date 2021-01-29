@@ -292,7 +292,6 @@ muscle_location_grow (char const *key, location loc)
 
 #define COMMON_DECODE(Value)                                    \
   case '$':                                                     \
-    ++(Value); aver (*(Value) == '[');                          \
     ++(Value); aver (*(Value) == ']');                          \
     ++(Value); aver (*(Value) == '[');                          \
     obstack_sgrow (&muscle_obstack, "$");                       \
