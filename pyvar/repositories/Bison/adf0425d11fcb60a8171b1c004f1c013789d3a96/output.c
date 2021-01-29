@@ -442,7 +442,7 @@ prepare_symbol_definitions (void)
           if (p->code)
             {
               SET_KEY2 (pname, "file");
-              MUSCLE_INSERT_STRING (key, p->location.start.file);
+              MUSCLE_INSERT_C_STRING (key, p->location.start.file);
 
               SET_KEY2 (pname, "line");
               MUSCLE_INSERT_INT (key, p->location.start.line);
