@@ -97,13 +97,12 @@ Name (char const *name,                                                 \
   MUSCLE_INSERT_LONG_INT (obstack_finish0 (&format_obstack), lmax);     \
 }
 
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_int_table, int)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_base_table, base_number)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_rule_number_table, rule_number)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_symbol_number_table, symbol_number)
-GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number)
-
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_unsigned_int_table, unsigned int)
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_int_table, int)
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_base_table, base_number)
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_rule_number_table, rule_number)
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_symbol_number_table, symbol_number)
+GENERATE_MUSCLE_INSERT_TABLE (muscle_insert_state_number_table, state_number)
 
 /*----------------------------------------------------------------.
 | Print to OUT a representation of CP quoted and escaped for M4.  |
@@ -227,7 +226,7 @@ prepare_rules (void)
       /* LHS of the rule R. */
       r1[r] = rules[r].lhs->number;
       /* Length of rule R's RHS. */
-      r2[r] = rule_rhs_length(&rules[r]);
+      r2[r] = rule_rhs_length (&rules[r]);
       /* Line where rule was defined. */
       rline[r] = rules[r].location.start.line;
       /* Dynamic precedence (GLR).  */
@@ -417,31 +416,31 @@ prepare_symbol_definitions (void)
 
       /* Whether the symbol has an identifier.  */
       value = symbol_id_get (sym);
-      SET_KEY("has_id");
+      SET_KEY ("has_id");
       MUSCLE_INSERT_INT (key, !!value);
 
       /* Its identifier.  */
-      SET_KEY("id");
+      SET_KEY ("id");
       MUSCLE_INSERT_STRING (key, value ? value : "");
 
       /* Its tag.  Typically for documentation purpose.  */
-      SET_KEY("tag");
+      SET_KEY ("tag");
       MUSCLE_INSERT_STRING (key, sym->tag);
 
-      SET_KEY("user_number");
+      SET_KEY ("user_number");
       MUSCLE_INSERT_INT (key, sym->user_token_number);
 
-      SET_KEY("is_token");
+      SET_KEY ("is_token");
       MUSCLE_INSERT_INT (key,
                          i < ntokens && sym != errtoken && sym != undeftoken);
 
-      SET_KEY("number");
+      SET_KEY ("number");
       MUSCLE_INSERT_INT (key, sym->number);
 
-      SET_KEY("has_type");
+      SET_KEY ("has_type");
       MUSCLE_INSERT_INT (key, !!sym->type_name);
 
-      SET_KEY("type");
+      SET_KEY ("type");
       MUSCLE_INSERT_STRING (key, sym->type_name ? sym->type_name : "");
 
       {
@@ -451,18 +450,18 @@ prepare_symbol_definitions (void)
             /* "printer", not "%printer".  */
             char const *pname = code_props_type_string (j) + 1;
             code_props const *p = symbol_code_props_get (sym, j);
-            SET_KEY2("has", pname);
+            SET_KEY2 ("has", pname);
             MUSCLE_INSERT_INT (key, !!p->code);
 
             if (p->code)
               {
-                SET_KEY2(pname, "file");
+                SET_KEY2 (pname, "file");
                 MUSCLE_INSERT_STRING (key, p->location.start.file);
 
-                SET_KEY2(pname, "line");
+                SET_KEY2 (pname, "line");
                 MUSCLE_INSERT_INT (key, p->location.start.line);
 
-                SET_KEY(pname);
+                SET_KEY (pname);
                 MUSCLE_INSERT_STRING_RAW (key, p->code);
               }
           }
