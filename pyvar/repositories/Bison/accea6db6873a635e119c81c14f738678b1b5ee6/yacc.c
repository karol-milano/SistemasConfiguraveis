@@ -1044,8 +1044,8 @@ yyreduce:
   /* If YYLEN is nonzero, implement the default value of the action:
      `$$ = $1'.
 
-     Otherwise, the following line sets YYVAL to the semantic value of
-     the lookahead token.  This behavior is undocumented and Bison
+     Otherwise, the following line sets YYVAL to garbage.
+     This behavior is undocumented and Bison
      users should not rely upon it.  Assigning to YYVAL
      unconditionally makes the parser a bit smaller, and it avoids a
      GCC warning that YYVAL may be used uninitialized.  */
