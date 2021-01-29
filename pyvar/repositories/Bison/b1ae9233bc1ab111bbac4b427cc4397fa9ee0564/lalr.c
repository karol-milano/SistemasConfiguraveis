@@ -87,9 +87,7 @@ set_goto_map (void)
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
-	  if (ngotos == GOTO_NUMBER_MAX)
-	    fatal (_("too many gotos (max %d)"), GOTO_NUMBER_MAX);
-
+	  assert (ngotos < GOTO_NUMBER_MAX);
 	  ngotos++;
 	  goto_map[TRANSITION_SYMBOL (sp, i)]++;
 	}
