@@ -353,7 +353,7 @@ get_state (int symbol)
       state_table[key] = sp = new_state(symbol);
     }
 
-  return (sp->number);
+  return sp->number;
 }
 
 
@@ -394,7 +394,7 @@ new_state (int symbol)
 
   nstates++;
 
-  return (p);
+  return p;
 }
 
 
