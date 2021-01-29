@@ -298,11 +298,11 @@ muscle_boundary_grow (char const *key, boundary bound)
 }
 
 void
-muscle_grow_used_name_list (char const *key, char const *used_name,
+muscle_grow_user_name_list (char const *key, char const *user_name,
                             location loc)
 {
   muscle_grow (key, "[[[[", ",");
-  muscle_grow (key, used_name, "");
+  muscle_grow (key, user_name, "");
   muscle_grow (key, "]], [[", "");
   muscle_boundary_grow (key, loc.start);
   muscle_grow (key, "]], [[", "");
