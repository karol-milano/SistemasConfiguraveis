@@ -60,8 +60,6 @@ symbol *errtoken = NULL;
 symbol *undeftoken = NULL;
 symbol *eoftoken = NULL;
 symbol *acceptsymbol = NULL;
-symbol *startsymbol = NULL;
-location startsymbol_loc;
 
 /* Precedence relation graph. */
 static symgraph **prec_nodes;
@@ -1146,15 +1144,6 @@ symbols_pack (void)
 
   symbols_token_translations_init ();
 
-  if (startsymbol->content->class == unknown_sym)
-    complain (&startsymbol_loc, fatal,
-              _("the start symbol %s is undefined"),
-              startsymbol->tag);
-  else if (startsymbol->content->class == token_sym)
-    complain (&startsymbol_loc, fatal,
-              _("the start symbol %s is a token"),
-              startsymbol->tag);
-
   // If some user tokens are internationalized, the internal ones
   // should be too.
   if (has_translations ())
