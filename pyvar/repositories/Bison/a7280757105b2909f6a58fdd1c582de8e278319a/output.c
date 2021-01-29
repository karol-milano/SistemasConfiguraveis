@@ -149,7 +149,7 @@ prepare_symbols (void)
   MUSCLE_INSERT_INT ("tokens_number", ntokens);
   MUSCLE_INSERT_INT ("nterms_number", nvars);
   MUSCLE_INSERT_INT ("symbols_number", nsyms);
-  MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
+  MUSCLE_INSERT_INT ("undef_token_number", undeftoken->content->number);
   MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
 
   muscle_insert_symbol_number_table ("translate",
@@ -197,7 +197,7 @@ prepare_symbols (void)
     int i;
     int *values = xnmalloc (ntokens, sizeof *values);
     for (i = 0; i < ntokens; ++i)
-      values[i] = symbols[i]->user_token_number;
+      values[i] = symbols[i]->content->user_token_number;
     muscle_insert_int_table ("toknum", values,
                              values[0], 1, ntokens);
     free (values);
@@ -283,9 +283,9 @@ prepare_states (void)
 static int
 symbol_type_name_cmp (const symbol **lhs, const symbol **rhs)
 {
-  int res = uniqstr_cmp ((*lhs)->type_name, (*rhs)->type_name);
+  int res = uniqstr_cmp ((*lhs)->content->type_name, (*rhs)->content->type_name);
   if (!res)
-    res = (*lhs)->number - (*rhs)->number;
+    res = (*lhs)->content->number - (*rhs)->content->number;
   return res;
 }
 
@@ -320,8 +320,9 @@ type_names_output (FILE *out)
       /* The index of the first symbol of the current type-name.  */
       int i0 = i;
       fputs (i ? ",\n[" : "[", out);
-      for (; i < nsyms && syms[i]->type_name == syms[i0]->type_name; ++i)
-        fprintf (out, "%s%d", i != i0 ? ", " : "", syms[i]->number);
+      for (; i < nsyms
+           && syms[i]->content->type_name == syms[i0]->content->type_name; ++i)
+        fprintf (out, "%s%d", i != i0 ? ", " : "", syms[i]->content->number);
       fputs ("]", out);
     }
   fputs ("])\n\n", out);
@@ -428,20 +429,21 @@ prepare_symbol_definitions (void)
       MUSCLE_INSERT_STRING (key, sym->tag);
 
       SET_KEY ("user_number");
-      MUSCLE_INSERT_INT (key, sym->user_token_number);
+      MUSCLE_INSERT_INT (key, sym->content->user_token_number);
 
       SET_KEY ("is_token");
       MUSCLE_INSERT_INT (key,
                          i < ntokens && sym != errtoken && sym != undeftoken);
 
       SET_KEY ("number");
-      MUSCLE_INSERT_INT (key, sym->number);
+      MUSCLE_INSERT_INT (key, sym->content->number);
 
       SET_KEY ("has_type");
-      MUSCLE_INSERT_INT (key, !!sym->type_name);
+      MUSCLE_INSERT_INT (key, !!sym->content->type_name);
 
       SET_KEY ("type");
-      MUSCLE_INSERT_STRING (key, sym->type_name ? sym->type_name : "");
+      MUSCLE_INSERT_STRING (key, sym->content->type_name
+                            ? sym->content->type_name : "");
 
       {
         int j;
