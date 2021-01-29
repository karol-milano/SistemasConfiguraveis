@@ -145,7 +145,7 @@ code_props_type_string (code_props_type kind)
     case printer:
       return "%printer";
     }
-  assert (0);
+  abort ();
 }
 
 /*----------------------------------------.
