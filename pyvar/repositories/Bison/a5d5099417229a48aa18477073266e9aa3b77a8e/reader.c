@@ -34,7 +34,6 @@
 #include "conflicts.h"
 #include "muscle_tab.h"
 
-int lineno;
 static symbol_list_t *grammar = NULL;
 static int start_flag = 0;
 merger_list *merge_functions;
@@ -113,7 +112,8 @@ epilogue_set (const char *epilogue, location_t location)
 `-------------------------------------------------------------------*/
 
 static int
-get_merge_function (const char* name, const char* type)
+get_merge_function (const char* name, const char* type,
+		    location_t loc)
 {
   merger_list *syms;
   merger_list head;
@@ -129,15 +129,17 @@ get_merge_function (const char* name, const char* type)
   for (syms = &head, n = 1; syms->next != NULL; syms = syms->next, n += 1)
     if (strcmp (name, syms->next->name) == 0)
       break;
-  if (syms->next == NULL) {
-    syms->next = XMALLOC (merger_list, 1);
-    syms->next->name = strdup (name);
-    syms->next->type = strdup (type);
-    syms->next->next = NULL;
-    merge_functions = head.next;
-  } else if (strcmp (type, syms->next->type) != 0)
-    warn (_("result type clash on merge function %s: `%s' vs. `%s'"),
-	  name, type, syms->next->type);
+  if (syms->next == NULL)
+    {
+      syms->next = XMALLOC (merger_list, 1);
+      syms->next->name = strdup (name);
+      syms->next->type = strdup (type);
+      syms->next->next = NULL;
+      merge_functions = head.next;
+    }
+  else if (strcmp (type, syms->next->type) != 0)
+    warn_at (loc, _("result type clash on merge function %s: `%s' vs. `%s'"),
+	     name, type, syms->next->type);
   return n;
 }
 
@@ -367,7 +369,7 @@ grammar_current_rule_merge_set (const char* name, location_t location)
   if (current_rule->merger != 0)
     complain_at (location, _("only one %%merge allowed per rule"));
   current_rule->merger =
-    get_merge_function (name, current_rule->sym->type_name);
+    get_merge_function (name, current_rule->sym->type_name, location);
 }
 
 /* Attach a SYMBOL to the current rule.  If needed, move the previous
@@ -469,7 +471,6 @@ void
 reader (void)
 {
   gram_control_t gram_control;
-  lineno = 1;
 
   /* Initialize the symbol table.  */
   symbols_new ();
