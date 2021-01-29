@@ -124,7 +124,7 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   aver (merge_function != NULL && merger_find == merger);
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
-      unsigned indent = 0;
+      int indent = 0;
       complain_indent (&declaration_loc, complaint, &indent,
                        _("result type clash on merge function %s: "
                          "<%s> != <%s>"),
@@ -611,7 +611,7 @@ grammar_current_rule_expect_rr (int count, location loc)
 static void
 packgram (void)
 {
-  unsigned itemno = 0;
+  int itemno = 0;
   ritem = xnmalloc (nritems + 1, sizeof *ritem);
   /* This sentinel is used by build_relations in gram.c.  */
   *ritem++ = 0;
