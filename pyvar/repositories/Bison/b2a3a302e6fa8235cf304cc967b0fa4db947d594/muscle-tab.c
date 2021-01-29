@@ -175,9 +175,6 @@ muscle_grow (const char *key, const char *val,
              const char *separator, const char *terminator)
 {
   muscle_entry *entry = muscle_lookup (key);
-  size_t vals = strlen (val);
-  size_t terms = strlen (terminator);
-
   if (entry)
     {
       obstack_sgrow (&muscle_obstack, entry->value);
@@ -189,12 +186,14 @@ muscle_grow (const char *key, const char *val,
 
   obstack_sgrow (&muscle_obstack, val);
 
+  size_t vals = strlen (val);
+  size_t terms = strlen (terminator);
   if (terms <= vals
       && STRNEQ (val + vals - terms, terminator))
     obstack_sgrow (&muscle_obstack, terminator);
 
   {
-    char *new_val = obstack_finish0 (&muscle_obstack);
+    char const *new_val = obstack_finish0 (&muscle_obstack);
     entry->value = entry->storage = xstrdup (new_val);
     obstack_free (&muscle_obstack, new_val);
   }
@@ -208,12 +207,11 @@ muscle_grow (const char *key, const char *val,
 static void
 muscle_syncline_grow (char const *key, location loc)
 {
-  char *extension = NULL;
   obstack_printf (&muscle_obstack, "]b4_syncline(%d, ", loc.start.line);
   obstack_quote (&muscle_obstack,
                  quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (&muscle_obstack, ")[");
-  extension = obstack_finish0 (&muscle_obstack);
+  char const *extension = obstack_finish0 (&muscle_obstack);
   muscle_grow (key, extension, "", "");
   obstack_free (&muscle_obstack, extension);
 }
@@ -236,13 +234,12 @@ void
 muscle_pair_list_grow (const char *muscle,
                        const char *a1, const char *a2)
 {
-  char *pair;
   obstack_sgrow (&muscle_obstack, "[");
   obstack_quote (&muscle_obstack, a1);
   obstack_sgrow (&muscle_obstack, ", ");
   obstack_quote (&muscle_obstack, a2);
   obstack_sgrow (&muscle_obstack, "]");
-  pair = obstack_finish0 (&muscle_obstack);
+  char const *pair = obstack_finish0 (&muscle_obstack);
   muscle_grow (muscle, pair, ",\n", "");
   obstack_free (&muscle_obstack, pair);
 }
@@ -275,11 +272,10 @@ muscle_find (char const *key)
 static void
 muscle_boundary_grow (char const *key, boundary bound)
 {
-  char *extension;
   obstack_sgrow  (&muscle_obstack, "[[");
   obstack_escape (&muscle_obstack, bound.file);
   obstack_printf (&muscle_obstack, ":%d.%d]]", bound.line, bound.column);
-  extension = obstack_finish0 (&muscle_obstack);
+  char const *extension = obstack_finish0 (&muscle_obstack);
   muscle_grow (key, extension, "", "");
   obstack_free (&muscle_obstack, extension);
 }
@@ -322,9 +318,6 @@ static char *
 string_decode (char const *key)
 {
   char const *value = muscle_find_const (key);
-  char *value_decoded;
-  char *result;
-
   if (!value)
     return NULL;
   do {
@@ -337,20 +330,20 @@ string_decode (char const *key)
           break;
       }
   } while (*value++);
-  value_decoded = obstack_finish (&muscle_obstack);
-  result = xstrdup (value_decoded);
+  char const *value_decoded = obstack_finish (&muscle_obstack);
+  char *res = xstrdup (value_decoded);
   obstack_free (&muscle_obstack, value_decoded);
-  return result;
+  return res;
 }
 
 /* Reverse of muscle_location_grow.  */
 static location
 location_decode (char const *value)
 {
-  location loc;
   aver (value);
   aver (*value == '[');
   ++value; aver (*value == '[');
+  location loc;
   while (*++value)
     switch (*value)
       {
@@ -359,29 +352,26 @@ location_decode (char const *value)
           aver (false);
           break;
         case ']':
-          {
-            char *boundary_str;
-            ++value; aver (*value == ']');
-            boundary_str = obstack_finish0 (&muscle_obstack);
-            switch (*++value)
-              {
-                case ',':
-                  boundary_set_from_string (&loc.start, boundary_str);
-                  obstack_free (&muscle_obstack, boundary_str);
-                  ++value; aver (*value == ' ');
-                  ++value; aver (*value == '[');
-                  ++value; aver (*value == '[');
-                  break;
-                case '\0':
-                  boundary_set_from_string (&loc.end, boundary_str);
-                  obstack_free (&muscle_obstack, boundary_str);
-                  return loc;
-                  break;
-                default:
-                  aver (false);
-                  break;
-              }
-          }
+          ++value; aver (*value == ']');
+          char *boundary_str = obstack_finish0 (&muscle_obstack);
+          switch (*++value)
+            {
+            case ',':
+              boundary_set_from_string (&loc.start, boundary_str);
+              obstack_free (&muscle_obstack, boundary_str);
+              ++value; aver (*value == ' ');
+              ++value; aver (*value == '[');
+              ++value; aver (*value == '[');
+              break;
+            case '\0':
+              boundary_set_from_string (&loc.end, boundary_str);
+              obstack_free (&muscle_obstack, boundary_str);
+              return loc;
+              break;
+            default:
+              aver (false);
+              break;
+            }
           break;
       }
   aver (false);
@@ -446,21 +436,21 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
   } conversion_type;
   const conversion_type conversion[] =
     {
-      { "api.push_pull", "api.push-pull", },
-      { "api.tokens.prefix", "api.token.prefix", },
-      { "lex_symbol", "api.token.constructor", },
-      { "location_type", "api.location.type", },
-      { "lr.default-reductions", "lr.default-reduction", },
+      { "api.push_pull",              "api.push-pull", },
+      { "api.tokens.prefix",          "api.token.prefix", },
+      { "lex_symbol",                 "api.token.constructor", },
+      { "location_type",              "api.location.type", },
+      { "lr.default-reductions",      "lr.default-reduction", },
       { "lr.keep-unreachable-states", "lr.keep-unreachable-state", },
       { "lr.keep_unreachable_states", "lr.keep-unreachable-state", },
-      { "namespace", "api.namespace", },
-      { "stype", "api.value.type", },
-      { "variant=",     "api.value.type=variant", },
-      { "variant=true", "api.value.type=variant", },
+      { "namespace",                  "api.namespace", },
+      { "stype",                      "api.value.type", },
+      { "variant=",                   "api.value.type=variant", },
+      { "variant=true",               "api.value.type=variant", },
       { NULL, NULL, }
     };
-  conversion_type const *c;
-  for (c = conversion; c->obsolete; ++c)
+
+  for (conversion_type const *c = conversion; c->obsolete; ++c)
     {
       char const *eq = strchr (c->obsolete, '=');
       if (eq
@@ -474,14 +464,12 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
           free (old);
           free (upd);
           char *res = xstrdup (c->updated);
-          {
-            char *eq2 = strchr (res, '=');
-            if (eq2)
-              {
-                *eq2 = '\0';
-                *value = eq2 + 1;
-              }
-          }
+          char *eq2 = strchr (res, '=');
+          if (eq2)
+            {
+              *eq2 = '\0';
+              *value = eq2 + 1;
+            }
           return res;
         }
     }
@@ -507,9 +495,9 @@ muscle_percent_define_insert (char const *var, location variable_loc,
       && muscle_find_const (name))
     {
       muscle_percent_define_how how_old = atoi (muscle_find_const (how_name));
-      unsigned i = 0;
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
         goto end;
+      unsigned i = 0;
       complain_indent (&variable_loc, complaint, &i,
                        _("%%define variable %s redefined"),
                        quote (variable));
@@ -645,16 +633,16 @@ bool
 muscle_percent_define_flag_if (char const *variable)
 {
   uniqstr invalid_boolean_name = muscle_name (variable, "invalid_boolean");
-  bool result = false;
+  bool res = false;
 
   if (muscle_percent_define_ifdef (variable))
     {
       char *value = muscle_percent_define_get (variable);
       muscle_percent_define_check_kind (variable, muscle_keyword);
       if (value[0] == '\0' || STREQ (value, "true"))
-        result = true;
+        res = true;
       else if (STREQ (value, "false"))
-        result = false;
+        res = false;
       else if (!muscle_find_const (invalid_boolean_name))
         {
           muscle_insert (invalid_boolean_name, "");
@@ -669,7 +657,7 @@ muscle_percent_define_flag_if (char const *variable)
     complain (NULL, fatal, _("%s: undefined %%define variable %s"),
               "muscle_percent_define_flag", quote (variable));
 
-  return result;
+  return res;
 }
 
 void
@@ -705,14 +693,12 @@ muscle_percent_define_check_values (char const * const *values)
       if (value)
         {
           for (++values; *values; ++values)
-            {
-              if (STREQ (value, *values))
-                break;
-            }
+            if (STREQ (value, *values))
+              break;
           if (!*values)
             {
-              unsigned i = 0;
               location loc = muscle_percent_define_get_loc (*variablep);
+              unsigned i = 0;
               complain_indent (&loc, complaint, &i,
                                _("invalid value for %%define variable %s: %s"),
                                quote (*variablep), quote_n (1, value));
@@ -722,10 +708,8 @@ muscle_percent_define_check_values (char const * const *values)
                                  _("accepted value: %s"), quote (*values));
             }
           else
-            {
-              while (*values)
-                ++values;
-            }
+            while (*values)
+              ++values;
           free (value);
         }
       else
