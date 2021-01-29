@@ -352,7 +352,7 @@ map_goto (int state, int symbol)
       middle = (low + high) / 2;
       s = from_state[middle];
       if (s == state)
-	return (middle);
+	return middle;
       else if (s < state)
 	low = middle + 1;
       else
@@ -617,7 +617,7 @@ transpose (short **R_arg, int n)
 
   FREE(temp_R);
 
-  return (new_R);
+  return new_R;
 }
 
 
