@@ -2705,15 +2705,6 @@ handle_dollar (char *cp, location_t location)
 {
   const char *type_name = NULL;
 
-  /* RULE_LENGTH is the number of values in the current rule so far,
-     which says where to find `$0' with respect to the top of the
-     stack.  It is not the same as the rule->length in the case of mid
-     rule actions.  */
-  int rule_length = 0;
-  symbol_list_t *rhs;
-  for (rhs = current_rule->next; rhs; rhs = rhs->next)
-    ++rule_length;
-
   ++cp;
 
   /* Get the type name if explicit. */
@@ -2740,6 +2731,11 @@ handle_dollar (char *cp, location_t location)
     }
   else if (isdigit (*cp) || *cp == '-')
     {
+      /* RULE_LENGTH is the number of values in the current rule so
+	 far, which says where to find `$0' with respect to the top of
+	 the stack.  It is not the same as the rule->length in the
+	 case of mid rule actions.  */
+      int rule_length = symbol_list_length (current_rule->next);
       int n = strtol (cp, &cp, 10);
 
       if (n > rule_length)
@@ -2775,15 +2771,6 @@ handle_dollar (char *cp, location_t location)
 static void
 handle_at (char *cp)
 {
-  /* RULE_LENGTH is the number of values in the current rule so far,
-     which says where to find `$0' with respect to the top of the
-     stack.  It is not the same as the rule->length in the case of mid
-     rule actions.  */
-  int rule_length = 0;
-  symbol_list_t *rhs;
-  for (rhs = current_rule->next; rhs; rhs = rhs->next)
-    ++rule_length;
-
   locations_flag = 1;
   ++cp;
 
@@ -2793,7 +2780,13 @@ handle_at (char *cp)
     }
   else if (isdigit (*cp) || *cp == '-')
     {
+      /* RULE_LENGTH is the number of values in the current rule so
+	 far, which says where to find `$0' with respect to the top of
+	 the stack.  It is not the same as the rule->length in the
+	 case of mid rule actions.  */
+      int rule_length = symbol_list_length (current_rule->next);
       int n = strtol (cp, &cp, 10);
+
       if (n > rule_length)
 	complain (_("invalid value: %s%d"), "@", n);
       else
