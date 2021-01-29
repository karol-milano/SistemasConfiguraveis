@@ -985,13 +985,8 @@ parse_dquoted_param (const char *from)
       return NULL;
     }
 
-  for (;;)
-    {
-      if (literalchar (NULL, &c, '\"'))
-	obstack_1grow (&param_obstack, c);
-      else
-	break;
-    }
+  while ((c = literalchar ()) != '"')
+    obstack_1grow (&param_obstack, c);
 
   obstack_1grow (&param_obstack, '\0');
   param = obstack_finish (&param_obstack);
