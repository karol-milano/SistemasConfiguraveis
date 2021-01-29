@@ -354,7 +354,9 @@ set_goto_map (void)
 
 
 
-/*  Map_goto maps a state/symbol pair into its numeric representation.	*/
+/*----------------------------------------------------------.
+| Map a state/symbol pair into its numeric representation.  |
+`----------------------------------------------------------*/
 
 static int
 map_goto (int state, int symbol)
@@ -379,8 +381,8 @@ map_goto (int state, int symbol)
 	high = middle - 1;
     }
 
-  berror ("map_goto");
-/* NOTREACHED */
+  assert (0);
+  /* NOTREACHED */
   return 0;
 }
 
