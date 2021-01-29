@@ -71,6 +71,19 @@ symbol_new (uniqstr tag, location loc)
 }
 
 
+/*------------------------------------------------------------------.
+| Complain that S's WHAT is redeclared at SECOND, and was first set |
+| at FIRST.                                                         |
+`------------------------------------------------------------------*/
+
+static void
+redeclaration (symbol* s, const char *what, location first, location second)
+{
+  complain_at (second, _("%s redeclaration for %s"), what, s->tag);
+  complain_at (first, _("first declaration"));
+}
+
+
 /*-----------------------------------------------------------------.
 | Set the TYPE_NAME associated with SYM.  Does nothing if passed 0 |
 | as TYPE_NAME.                                                    |
@@ -82,9 +95,10 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
   if (type_name)
     {
       if (sym->type_name)
-	complain_at (loc, _("type redeclaration for %s"), sym->tag);
+	redeclaration (sym, "%type", sym->type_location, loc);
       uniqstr_assert (type_name);
       sym->type_name = type_name;
+      sym->type_location = loc;
     }
 }
 
@@ -99,8 +113,7 @@ symbol_destructor_set (symbol *sym, char *destructor, location loc)
   if (destructor)
     {
       if (sym->destructor)
-	complain_at (loc, _("%s redeclaration for %s"),
-		     "%destructor", sym->tag);
+	redeclaration (sym, "%destructor", sym->destructor_location, loc);
       sym->destructor = destructor;
       sym->destructor_location = loc;
     }
@@ -117,8 +130,7 @@ symbol_printer_set (symbol *sym, char *printer, location loc)
   if (printer)
     {
       if (sym->printer)
-	complain_at (loc, _("%s redeclaration for %s"),
-		     "%printer", sym->tag);
+	redeclaration (sym, "%printer", sym->destructor_location, loc);
       sym->printer = printer;
       sym->printer_location = loc;
     }
@@ -136,9 +148,10 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
   if (a != undef_assoc)
     {
       if (sym->prec != 0)
-	complain_at (loc, _("redefining precedence of %s"), sym->tag);
+	redeclaration (sym, assoc_to_string (a), sym->prec_location, loc);
       sym->prec = prec;
       sym->assoc = a;
+      sym->prec_location = loc;
     }
 
   /* Only terminals have a precedence. */
@@ -230,10 +243,10 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
 {
   if (symval->alias)
     warn_at (loc, _("symbol `%s' used more than once as a literal string"),
-	  symval->tag);
+	     symval->tag);
   else if (sym->alias)
     warn_at (loc, _("symbol `%s' given more than one literal string"),
-	  sym->tag);
+	     sym->tag);
   else
     {
       symval->class = token_sym;
@@ -248,7 +261,6 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
 	abort ();
       sym->number = symval->number =
 	(symval->number < sym->number) ? symval->number : sym->number;
-      symbol_type_set (symval, sym->type_name, loc);
     }
 }
 
@@ -258,45 +270,60 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
 | associativity.                                           |
 `---------------------------------------------------------*/
 
-static inline bool
+static inline void
 symbol_check_alias_consistency (symbol *this)
 {
-  /* Check only those who _are_ the aliases. */
-  if (this->alias && this->user_token_number == USER_NUMBER_ALIAS)
+  symbol *alias = this;
+  symbol *orig  = this->alias;
+
+  /* Check only those that _are_ the aliases.  */
+  if (!(this->alias && this->user_token_number == USER_NUMBER_ALIAS))
+    return;
+
+  if (orig->type_name || alias->type_name)
     {
-      if (this->prec != this->alias->prec)
-	{
-	  if (this->prec != 0 && this->alias->prec != 0)
-	    complain_at (this->alias->location,
-			 _("conflicting precedences for %s and %s"),
-			 this->tag, this->alias->tag);
-	  if (this->prec != 0)
-	    this->alias->prec = this->prec;
-	  else
-	    this->prec = this->alias->prec;
-	}
+      if (orig->type_name)
+	symbol_type_set (alias, orig->type_name, orig->type_location);
+      else
+	symbol_type_set (orig, alias->type_name, alias->type_location);
+    }
 
-      if (this->assoc != this->alias->assoc)
-	{
-	  if (this->assoc != undef_assoc && this->alias->assoc != undef_assoc)
-	    complain_at (this->alias->location,
-			 _("conflicting associativities for %s (%s) and %s (%s)"),
-			 this->tag, assoc_to_string (this->assoc),
-			 this->alias->tag, assoc_to_string (this->alias->assoc));
-	  if (this->assoc != undef_assoc)
-	    this->alias->assoc = this->assoc;
-	  else
-	    this->assoc = this->alias->assoc;
-	}
+
+  if (orig->destructor || alias->destructor)
+    {
+      if (orig->destructor)
+	symbol_destructor_set (alias, orig->destructor,
+			       orig->destructor_location);
+      else
+	symbol_destructor_set (orig, alias->destructor,
+			       alias->destructor_location);
+    }
+
+  if (orig->printer || alias->printer)
+    {
+      if (orig->printer)
+	symbol_printer_set (alias, orig->printer, orig->printer_location);
+      else
+	symbol_printer_set (orig, alias->printer, alias->printer_location);
+    }
+
+  if (alias->prec || orig->prec)
+    {
+      if (orig->prec)
+	symbol_precedence_set (alias, orig->prec, orig->assoc,
+			       orig->prec_location);
+      else
+	symbol_precedence_set (orig, alias->prec, alias->assoc,
+			       alias->prec_location);
     }
-  return true;
 }
 
 static bool
 symbol_check_alias_consistency_processor (void *this,
 					  void *null ATTRIBUTE_UNUSED)
 {
-  return symbol_check_alias_consistency (this);
+  symbol_check_alias_consistency (this);
+  return true;
 }
 
 
