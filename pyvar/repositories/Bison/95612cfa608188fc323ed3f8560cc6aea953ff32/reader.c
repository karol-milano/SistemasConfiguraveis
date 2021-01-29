@@ -102,12 +102,11 @@ epilogue_set (const char *epilogue, location_t location)
 /*-------------------------------------------------------------------.
 | Return the merger index for a merging function named NAME, whose   |
 | arguments have type TYPE.  Records the function, if new, in        |
-| merger_list.							     |
+| MERGER_LIST.							     |
 `-------------------------------------------------------------------*/
 
 static int
-get_merge_function (const char* name, const char* type,
-		    location_t loc)
+get_merge_function (struniq_t name, struniq_t type, location_t loc)
 {
   merger_list *syms;
   merger_list head;
@@ -117,21 +116,21 @@ get_merge_function (const char* name, const char* type,
     return 0;
 
   if (type == NULL)
-    type = "";
+    type = struniq_new ("");
 
   head.next = merge_functions;
   for (syms = &head, n = 1; syms->next != NULL; syms = syms->next, n += 1)
-    if (strcmp (name, syms->next->name) == 0)
+    if (STRUNIQ_EQ (name, syms->next->name))
       break;
   if (syms->next == NULL)
     {
       syms->next = XMALLOC (merger_list, 1);
-      syms->next->name = xstrdup (name);
-      syms->next->type = xstrdup (type);
+      syms->next->name = struniq_new (name);
+      syms->next->type = struniq_new (type);
       syms->next->next = NULL;
       merge_functions = head.next;
     }
-  else if (strcmp (type, syms->next->type) != 0)
+  else if (!STRUNIQ_EQ (type, syms->next->type))
     warn_at (loc, _("result type clash on merge function %s: <%s> != <%s>"),
 	     name, type, syms->next->type);
   return n;
@@ -257,7 +256,7 @@ grammar_current_rule_check (void)
   if (first_rhs)
     {
       const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
-      if (strcmp (lhs_type, rhs_type))
+      if (!STRUNIQ_EQ (lhs_type, rhs_type))
 	complain_at (current_rule->location,
 		     _("type clash on default action: <%s> != <%s>"),
 		     lhs_type, rhs_type);
@@ -358,7 +357,7 @@ grammar_current_rule_dprec_set (int dprec, location_t location)
    rule. */
 
 void
-grammar_current_rule_merge_set (const char* name, location_t location)
+grammar_current_rule_merge_set (struniq_t name, location_t location)
 {
   if (! glr_parser)
     warn_at (location, _("%s affects only GLR parsers"), "%merge");
@@ -491,7 +490,7 @@ reader (void)
   obstack_init (&pre_prologue_obstack);
   obstack_init (&post_prologue_obstack);
 
-  finput = xfopen (infile, "r");
+  finput = xfopen (grammar_file, "r");
   gram_in = finput;
 
   gram__flex_debug = trace_flag & trace_scan;
