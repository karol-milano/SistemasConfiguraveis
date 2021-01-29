@@ -122,7 +122,7 @@ set_goto_map (void)
 
 
 goto_number
-map_goto (state_number s0, symbol_number sym)
+map_goto (state_number src, symbol_number sym)
 {
   goto_number low = goto_map[sym - ntokens];
   goto_number high = goto_map[sym - ntokens + 1] - 1;
@@ -132,9 +132,9 @@ map_goto (state_number s0, symbol_number sym)
       aver (low <= high);
       goto_number middle = (low + high) / 2;
       state_number s = from_state[middle];
-      if (s == s0)
+      if (s == src)
         return middle;
-      else if (s < s0)
+      else if (s < src)
         low = middle + 1;
       else
         high = middle - 1;
