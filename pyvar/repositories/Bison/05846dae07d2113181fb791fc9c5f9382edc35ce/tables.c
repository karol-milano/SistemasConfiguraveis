@@ -774,7 +774,7 @@ table_ninf_remap (base_t tab[], size_t size, base_t ninf)
 
   for (i = 0; i < size; i++)
     if (tab[i] < res && tab[i] != ninf)
-      res = base[i];
+      res = tab[i];
 
   --res;
 
