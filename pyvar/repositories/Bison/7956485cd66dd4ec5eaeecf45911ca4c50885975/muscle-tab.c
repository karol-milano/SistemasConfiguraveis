@@ -637,18 +637,19 @@ void
 muscle_percent_define_default (char const *variable, char const *value)
 {
   uniqstr name = muscle_name (variable, NULL);
-  uniqstr loc_name = muscle_name (variable, "loc");
-  uniqstr syncline_name = muscle_name (variable, "syncline");
   if (!muscle_find_const (name))
     {
-      location loc;
       MUSCLE_INSERT_STRING (name, value);
-      loc.start.file = loc.end.file = "<default value>";
-      loc.start.line = loc.end.line = -1;
-      loc.start.column = loc.end.column = -1;
-      muscle_insert (loc_name, "");
-      muscle_location_grow (loc_name, loc);
-      muscle_insert (syncline_name, "");
+      {
+        uniqstr loc_name = muscle_name (variable, "loc");
+        location loc;
+        loc.start.file = loc.end.file = "<default value>";
+        loc.start.line = loc.end.line = -1;
+        loc.start.column = loc.end.column = -1;
+        muscle_insert (loc_name, "");
+        muscle_location_grow (loc_name, loc);
+      }
+      muscle_insert (muscle_name (variable, "syncline"), "");
     }
 }
 
