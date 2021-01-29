@@ -320,28 +320,17 @@ static void
 type_names_output (FILE *out)
 {
   int i;
-  const char *isep = "";
   symbol **syms = symbols_by_type_name ();
   fputs ("m4_define([b4_type_names],\n[", out);
-  for (i = 0; i < nsyms; )
-    if (syms[i]->type_name)
-      {
-        int j;
-        const char *jsep = "";
-        fprintf (out, "%s[", isep);
-        isep = ",\n";
-        for (j = i; j < nsyms; ++j)
-          {
-            if (syms[i]->type_name != syms[j]->type_name)
-              break;
-            fprintf (out, "%s%d", jsep, syms[j]->number);
-            jsep = ", ";
-          }
-        fputs ("]", out);
-        i = j;
-      }
-    else
-      ++i;
+  for (i = 0; i < nsyms; /* nothing */)
+    {
+      // The index of the first symbol of the current type-name.
+      int i0 = i;
+      fputs (i ? ",\n[" : "[", out);
+      for (; i < nsyms && syms[i]->type_name == syms[i0]->type_name; ++i)
+        fprintf (out, "%s%d", i != i0 ? ", " : "", syms[i]->number);
+      fputs ("]", out);
+    }
   fputs ("])\n\n", out);
   free (syms);
 }
@@ -431,9 +420,16 @@ symbol_definitions_output (FILE *out)
       SET_KEY("user_number");
       MUSCLE_INSERT_INT (key, sym->user_token_number);
 
+      SET_KEY("is_token");
+      MUSCLE_INSERT_INT (key,
+                         i < ntokens && sym != errtoken && sym != undeftoken);
+
       SET_KEY("number");
       MUSCLE_INSERT_INT (key, sym->number);
 
+      SET_KEY("has_type_name");
+      MUSCLE_INSERT_INT (key, !!sym->type_name);
+
       SET_KEY("type_name");
       MUSCLE_INSERT_STRING (key, sym->type_name ? sym->type_name : "");
 
