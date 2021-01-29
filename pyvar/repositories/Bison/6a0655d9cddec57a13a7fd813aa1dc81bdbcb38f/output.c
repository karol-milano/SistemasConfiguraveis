@@ -402,9 +402,16 @@ prepare_symbol_definitions (void)
       const char *key;
       const char *value;
 
-#define SET_KEY(Entry)                                                  \
-      obstack_fgrow2 (&format_obstack, "symbol(%d, %s)", i, Entry);     \
-      obstack_1grow (&format_obstack, 0);                               \
+#define SET_KEY(Entry)                                          \
+      obstack_fgrow2 (&format_obstack, "symbol(%d, %s)",        \
+                      i, Entry);                                \
+      obstack_1grow (&format_obstack, 0);                       \
+      key = obstack_finish (&format_obstack);
+
+#define SET_KEY2(Entry, Suffix)                                 \
+      obstack_fgrow3 (&format_obstack, "symbol(%d, %s_%s)",     \
+                      i, Entry, Suffix);                        \
+      obstack_1grow (&format_obstack, 0);                       \
       key = obstack_finish (&format_obstack);
 
       // Whether the symbol has an identifier.
@@ -436,28 +443,29 @@ prepare_symbol_definitions (void)
       SET_KEY("type");
       MUSCLE_INSERT_STRING (key, sym->type_name ? sym->type_name : "");
 
-#define CODE_PROP(PropName)                                             \
-      do {                                                              \
-        code_props const *p = symbol_code_props_get (sym, PropName);    \
-        SET_KEY("has_" #PropName);                                      \
-        MUSCLE_INSERT_INT (key, !!p->code);                             \
-                                                                        \
-        if (p->code)                                                    \
-          {                                                             \
-            SET_KEY(#PropName "_file");                                 \
-            MUSCLE_INSERT_STRING (key, p->location.start.file);         \
-                                                                        \
-            SET_KEY(#PropName "_line");                                 \
-            MUSCLE_INSERT_INT (key, p->location.start.line);            \
-                                                                        \
-            SET_KEY(#PropName);                                         \
-            MUSCLE_INSERT_STRING_RAW (key, p->code);                    \
-          }                                                             \
-      } while (0)
-
-      CODE_PROP(destructor);
-      CODE_PROP(printer);
-#undef CODE_PROP
+      {
+        int j;
+        for (j = 0; j < CODE_PROPS_SIZE; ++j)
+          {
+            char const *pname = code_props_type_string (j);
+            code_props const *p = symbol_code_props_get (sym, j);
+            SET_KEY2("has", pname);
+            MUSCLE_INSERT_INT (key, !!p->code);
+
+            if (p->code)
+              {
+                SET_KEY2(pname, "file");
+                MUSCLE_INSERT_STRING (key, p->location.start.file);
+
+                SET_KEY2(pname, "line");
+                MUSCLE_INSERT_INT (key, p->location.start.line);
+
+                SET_KEY(pname);
+                MUSCLE_INSERT_STRING_RAW (key, p->code);
+              }
+          }
+      }
+#undef SET_KEY2
 #undef SET_KEY
     }
 }
