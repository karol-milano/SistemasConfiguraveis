@@ -288,7 +288,7 @@ set_goto_map()
 	  if (ISTOKEN(symbol)) break;
 
 	  if (ngotos == MAXSHORT)
-	    toomany("gotos");
+	    toomany(_("gotos"));
 
 	  ngotos++;
 	  goto_map[symbol]++;
