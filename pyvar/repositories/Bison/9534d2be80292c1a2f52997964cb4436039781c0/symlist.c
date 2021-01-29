@@ -78,42 +78,6 @@ symbol_list_type_new (uniqstr type_name, location loc)
 }
 
 
-/*----------------------------------------.
-| Create a list containing a <*> at LOC.  |
-`----------------------------------------*/
-
-symbol_list *
-symbol_list_default_tagged_new (location loc)
-{
-  symbol_list *res = xmalloc (sizeof *res);
-
-  res->content_type = SYMLIST_DEFAULT_TAGGED;
-  res->location = res->sym_loc = loc;
-  res->named_ref = NULL;
-  res->next = NULL;
-
-  return res;
-}
-
-
-/*---------------------------------------.
-| Create a list containing a <> at LOC.  |
-`---------------------------------------*/
-
-symbol_list *
-symbol_list_default_tagless_new (location loc)
-{
-  symbol_list *res = xmalloc (sizeof *res);
-
-  res->content_type = SYMLIST_DEFAULT_TAGLESS;
-  res->location = res->sym_loc = loc;
-  res->named_ref = NULL;
-  res->next = NULL;
-
-  return res;
-}
-
-
 /*-----------------------------------------------------------------------.
 | Print this list, for which every content_type must be SYMLIST_SYMBOL.  |
 `-----------------------------------------------------------------------*/
@@ -247,11 +211,5 @@ symbol_list_code_props_set (symbol_list *node, code_props_type kind,
         if (node->content.sem_type->status == undeclared)
           node->content.sem_type->status = used;
         break;
-      case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_code_props_set (kind, &cprops);
-        break;
-      case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_code_props_set (kind, &cprops);
-        break;
     }
 }
