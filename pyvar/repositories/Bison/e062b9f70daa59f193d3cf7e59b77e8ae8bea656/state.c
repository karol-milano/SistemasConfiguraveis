@@ -218,7 +218,7 @@ state_reduction_find (state *s, rule const *r)
   for (int i = 0; i < reds->num; ++i)
     if (reds->rules[i] == r)
       return i;
-  return -1;
+  abort ();
 }
 
 
