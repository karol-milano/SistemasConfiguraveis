@@ -438,10 +438,10 @@ symbol_definitions_output (FILE *out)
       SET_KEY("number");
       MUSCLE_INSERT_INT (key, sym->number);
 
-      SET_KEY("has_type_name");
+      SET_KEY("has_type");
       MUSCLE_INSERT_INT (key, !!sym->type_name);
 
-      SET_KEY("type_name");
+      SET_KEY("type");
       MUSCLE_INSERT_STRING (key, sym->type_name ? sym->type_name : "");
 
 #undef SET_KEY
