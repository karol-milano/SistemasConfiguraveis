@@ -137,8 +137,8 @@ get_merge_function (const char* name, const char* type,
       merge_functions = head.next;
     }
   else if (strcmp (type, syms->next->type) != 0)
-    warn_at (loc, _("result type clash (`%s' `%s') on merge function %s"),
-	     type, syms->next->type, name);
+    warn_at (loc, _("result type clash on merge function %s: <%s> != <%s>"),
+	     name, type, syms->next->type);
   return n;
 }
 
@@ -264,7 +264,7 @@ grammar_current_rule_check (void)
       const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
       if (strcmp (lhs_type, rhs_type))
 	complain_at (current_rule->location,
-		     _("type clash (`%s' `%s') on default action"),
+		     _("type clash on default action: <%s> != <%s>"),
 		     lhs_type, rhs_type);
     }
   /* Warn if there is no default for $$ but we need one.  */
