@@ -1190,7 +1190,7 @@ int vector;
 	{
 	  loc = j + from[k];
 	  if (loc > MAXTABLE)
-	    fatals("maximum table size (%s) exceeded", int_to_string(MAXTABLE));
+	    fatals(_("maximum table size (%s) exceeded"), int_to_string(MAXTABLE));
 
 	  if (table[loc] != 0)
 	    ok = 0;
