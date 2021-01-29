@@ -284,23 +284,23 @@ muscle_location_grow (char const *key, location loc)
   muscle_grow (key, "]]", "");
 }
 
-#define MUSCLE_COMMON_DECODE(Value)                                           \
-  case '$':                                                                   \
-    aver (*++(Value) == ']');                                                 \
-    aver (*++(Value) == '[');                                                 \
-    obstack_sgrow (&muscle_obstack, "$");                                     \
-    break;                                                                    \
-  case '@':                                                                   \
-    switch (*++(Value))                                                       \
-      {                                                                       \
-        case '@': obstack_sgrow (&muscle_obstack, "@" ); break;               \
-        case '{': obstack_sgrow (&muscle_obstack, "[" ); break;               \
-        case '}': obstack_sgrow (&muscle_obstack, "]" ); break;               \
-        default: aver (false); break;                                         \
-      }                                                                       \
-    break;                                                                    \
-  default:                                                                    \
-    obstack_1grow (&muscle_obstack, *(Value));                                \
+#define MUSCLE_COMMON_DECODE(Value)                             \
+  case '$':                                                     \
+    aver (*++(Value) == ']');                                   \
+    aver (*++(Value) == '[');                                   \
+    obstack_sgrow (&muscle_obstack, "$");                       \
+    break;                                                      \
+  case '@':                                                     \
+    switch (*++(Value))                                         \
+      {                                                         \
+        case '@': obstack_sgrow (&muscle_obstack, "@" ); break; \
+        case '{': obstack_sgrow (&muscle_obstack, "[" ); break; \
+        case '}': obstack_sgrow (&muscle_obstack, "]" ); break; \
+        default: aver (false); break;                           \
+      }                                                         \
+    break;                                                      \
+  default:                                                      \
+    obstack_1grow (&muscle_obstack, *(Value));                  \
     break;
 
 /* Reverse of MUSCLE_OBSTACK_SGROW.  */
