@@ -1,7 +1,7 @@
 m4_divert(-1)                                                       -*- C -*-
 
 # GLR skeleton for Bison
-# Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
+# Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -137,7 +137,8 @@ m4_define([b4_rhs_location],
 m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
-b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003, 2004])
+b4_copyright([Skeleton parser for GLR parsing with Bison],
+  [2002, 2003, 2004, 2005])
 [
 /* This is the parser code for GLR (Generalized LR) parser. */
 
@@ -587,7 +588,7 @@ struct yyGLRState {
   size_t yyposn;
   union {
     /** First in a chain of alternative reductions producing the
-     *  non-terminal corresponding to this state, threaded through 
+     *  non-terminal corresponding to this state, threaded through
      *  yynext. */
     yySemanticOption* yyfirstVal;
     /** Semantic value for this state. */
@@ -614,7 +615,7 @@ struct yySemanticOption {
   yySemanticOption* yynext;
 };
 
-/** Type of the items in the GLR stack. The yyisState field 
+/** Type of the items in the GLR stack. The yyisState field
  *  indicates which item of the union is valid. */
 union yyGLRStackItem {
   yyGLRState yystate;
@@ -1313,7 +1314,7 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
     {
       if (yys0 == yys1)
 	break;
-      else if (yys0->yyresolved) 
+      else if (yys0->yyresolved)
 	{
 	  yys1->yyresolved = yytrue;
 	  yys1->yysemantics.yysval = yys0->yysemantics.yysval;
@@ -1323,7 +1324,7 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 	  yys0->yyresolved = yytrue;
 	  yys0->yysemantics.yysval = yys1->yysemantics.yysval;
 	}
-      else 
+      else
 	{
 	  yySemanticOption** yyz0p;
 	  yySemanticOption* yyz1;
@@ -2101,7 +2102,8 @@ yypdumpstack (yyGLRStack* yystack)
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
-b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003, 2004])
+b4_copyright([Skeleton parser for GLR parsing with Bison],
+  [2002, 2003, 2004, 2005])
 
 b4_token_defines(b4_tokens)
 
