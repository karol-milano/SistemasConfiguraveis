@@ -132,8 +132,8 @@ get_merge_function (const char* name, const char* type,
   if (syms->next == NULL)
     {
       syms->next = XMALLOC (merger_list, 1);
-      syms->next->name = strdup (name);
-      syms->next->type = strdup (type);
+      syms->next->name = xstrdup (name);
+      syms->next->type = xstrdup (type);
       syms->next->next = NULL;
       merge_functions = head.next;
     }
