@@ -428,6 +428,28 @@ prepare_symbol_definitions (void)
       SET_KEY("type");
       MUSCLE_INSERT_STRING (key, sym->type_name ? sym->type_name : "");
 
+#define CODE_PROP(PropName)                                             \
+      do {                                                              \
+        code_props const *p = symbol_ ## PropName ## _get (sym);        \
+        SET_KEY("has_" #PropName);                                      \
+        MUSCLE_INSERT_INT (key, !!p->code);                             \
+                                                                        \
+        if (p->code)                                                    \
+          {                                                             \
+            SET_KEY(#PropName "_file");                                 \
+            MUSCLE_INSERT_STRING (key, p->location.start.file);         \
+                                                                        \
+            SET_KEY(#PropName "_line");                                 \
+            MUSCLE_INSERT_INT (key, p->location.start.line);            \
+                                                                        \
+            SET_KEY(#PropName);                                         \
+            MUSCLE_INSERT_STRING_RAW (key, p->code);                    \
+          }                                                             \
+      } while (0)
+
+      CODE_PROP(destructor);
+      CODE_PROP(printer);
+#undef CODE_PROP
 #undef SET_KEY
     }
 }
