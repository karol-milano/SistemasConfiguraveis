@@ -790,7 +790,7 @@ scanner_last_string_free (void)
 static int braces_level = 0;
 static int percent_percent_count = 0;
 
-static void handle_dollar PARAMS ((char *cp));
+static void handle_dollar PARAMS ((char *cp, location_t location));
 static void handle_at PARAMS ((char *cp));
 
 #define SC_COMMENT 1
@@ -1696,7 +1696,7 @@ YY_OBS_GROW; braces_level++;
 case 82:
 YY_RULE_SETUP
 #line 444 "scan-gram.l"
-{ handle_dollar (yytext); }
+{ handle_dollar (yytext, *yylloc); }
 	YY_BREAK
 case 83:
 YY_RULE_SETUP
@@ -2701,7 +2701,7 @@ int main()
 `------------------------------------------------------------------*/
 
 static void
-handle_dollar (char *cp)
+handle_dollar (char *cp, location_t location)
 {
   const char *type_name = NULL;
 
@@ -2710,7 +2710,7 @@ handle_dollar (char *cp)
      stack.  It is not the same as the rule->length in the case of mid
      rule actions.  */
   int rule_length = 0;
-  symbol_list *rhs;
+  symbol_list_t *rhs;
   for (rhs = current_rule->next; rhs; rhs = rhs->next)
     ++rule_length;
 
@@ -2729,10 +2729,10 @@ handle_dollar (char *cp)
   if (*cp == '$')
     {
       if (!type_name)
-	type_name = get_type_name (0, current_rule);
+	type_name = symbol_list_n_type_name_get (current_rule, location, 0);
       if (!type_name && typed)
-	complain (_("$$ of `%s' has no declared type"),
-		  current_rule->sym->tag);
+	complain_at (location, _("$$ of `%s' has no declared type"),
+		     current_rule->sym->tag);
       if (!type_name)
 	type_name = "";
       obstack_fgrow1 (&string_obstack,
@@ -2743,13 +2743,14 @@ handle_dollar (char *cp)
       int n = strtol (cp, &cp, 10);
 
       if (n > rule_length)
-	complain (_("invalid value: %s%d"), "$", n);
+	complain_at (location, _("invalid value: %s%d"), "$", n);
       else
 	{
 	  if (!type_name && n > 0)
-	    type_name = get_type_name (n, current_rule);
+	    type_name = symbol_list_n_type_name_get (current_rule, location,
+						     n);
 	  if (!type_name && typed)
-	    complain (_("$%d of `%s' has no declared type"),
+	    complain_at (location, _("$%d of `%s' has no declared type"),
 		      n, current_rule->sym->tag);
 	  if (!type_name)
 	    type_name = "";
@@ -2779,7 +2780,7 @@ handle_at (char *cp)
      stack.  It is not the same as the rule->length in the case of mid
      rule actions.  */
   int rule_length = 0;
-  symbol_list *rhs;
+  symbol_list_t *rhs;
   for (rhs = current_rule->next; rhs; rhs = rhs->next)
     ++rule_length;
 
