@@ -478,6 +478,9 @@ prepare_symbol_definitions (void)
               SET_KEY2 (pname, "line");
               MUSCLE_INSERT_INT (key, p->location.start.line);
 
+              SET_KEY2 (pname, "loc");
+              muscle_location_grow (key, p->location);
+
               SET_KEY (pname);
               MUSCLE_INSERT_STRING_RAW (key, p->code);
             }
