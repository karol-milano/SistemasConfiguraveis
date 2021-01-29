@@ -710,9 +710,11 @@ muscle_percent_define_default (char const *variable, char const *value)
       {
         uniqstr loc_name = muscle_name (variable, "loc");
         location loc;
-        loc.start.file = loc.end.file = "<default value>";
-        loc.start.line = loc.end.line = -1;
-        loc.start.column = loc.end.column = -1;
+        loc.start.file = "<default value>";
+        loc.start.line = -1;
+        loc.start.column = -1;
+        loc.start.byte = -1;
+        loc.end = loc.start;
         muscle_insert (loc_name, "");
         muscle_location_grow (loc_name, loc);
       }
