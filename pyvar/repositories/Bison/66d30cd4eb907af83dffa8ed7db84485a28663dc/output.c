@@ -661,7 +661,7 @@ prepare (void)
     }
 
   /* Parse the skeleton file and output the needed parsers.  */
-  muscle_insert ("skeleton", xstrdup (skeleton));
+  MUSCLE_INSERT_STRING ("skeleton", skeleton);
 }
 
 
