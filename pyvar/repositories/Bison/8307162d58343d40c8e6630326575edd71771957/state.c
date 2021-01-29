@@ -266,13 +266,13 @@ state_compare (const state_t *s1, const state_t *s2)
   int i;
 
   if (s1->nitems != s2->nitems)
-    return FALSE;
+    return false;
 
   for (i = 0; i < s1->nitems; ++i)
     if (s1->items[i] != s2->items[i])
-      return FALSE;
+      return false;
 
-  return TRUE;
+  return true;
 }
 
 static unsigned int
