@@ -260,14 +260,14 @@ grammar_current_rule_check (void)
     {
       const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
       if (!STRUNIQ_EQ (lhs_type, rhs_type))
-	complain_at (current_rule->location,
-		     _("type clash on default action: <%s> != <%s>"),
-		     lhs_type, rhs_type);
+	warn_at (current_rule->location,
+		 _("type clash on default action: <%s> != <%s>"),
+		 lhs_type, rhs_type);
     }
   /* Warn if there is no default for $$ but we need one.  */
   else
-    complain_at (current_rule->location,
-		 _("empty rule for typed nonterminal, and no action"));
+    warn_at (current_rule->location,
+	     _("empty rule for typed nonterminal, and no action"));
 }
 
 
