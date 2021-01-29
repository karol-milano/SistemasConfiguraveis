@@ -299,8 +299,9 @@ muscle_location_grow (char const *key, location loc)
 
 #define COMMON_DECODE(Value)                                    \
   case '$':                                                     \
-    aver (*++(Value) == ']');                                   \
-    aver (*++(Value) == '[');                                   \
+    ++(Value); aver (*(Value) == '[');                          \
+    ++(Value); aver (*(Value) == ']');                          \
+    ++(Value); aver (*(Value) == '[');                          \
     obstack_sgrow (&muscle_obstack, "$");                       \
     break;                                                      \
   case '@':                                                     \
@@ -349,7 +350,7 @@ location_decode (char const *value)
   location loc;
   aver (value);
   aver (*value == '[');
-  aver (*++value == '[');
+  ++value; aver (*value == '[');
   while (*++value)
     switch (*value)
       {
@@ -360,16 +361,16 @@ location_decode (char const *value)
         case ']':
           {
             char *boundary_str;
-            aver (*++value == ']');
+            ++value; aver (*value == ']');
             boundary_str = obstack_finish0 (&muscle_obstack);
             switch (*++value)
               {
                 case ',':
                   boundary_set_from_string (&loc.start, boundary_str);
                   obstack_free (&muscle_obstack, boundary_str);
-                  aver (*++value == ' ');
-                  aver (*++value == '[');
-                  aver (*++value == '[');
+                  ++value; aver (*value == ' ');
+                  ++value; aver (*value == '[');
+                  ++value; aver (*value == '[');
                   break;
                 case '\0':
                   boundary_set_from_string (&loc.end, boundary_str);
