@@ -1,5 +1,6 @@
 /* Output the generated parsing program for bison,
-   Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000, 2001
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,76 +20,73 @@
    02111-1307, USA.  */
 
 
-/* The parser tables consist of these tables.
-   Starred ones needed only for the semantic parser.
-   Double starred are output only if switches are set.
+/* The parser tables consist of these tables.  Marked ones needed only
+   for the semantic parser.  Double marked are output only if switches
+   are set.
 
-   yytranslate = vector mapping yylex's token numbers into bison's token
-   numbers.
+   YYTRANSLATE = vector mapping yylex's token numbers into bison's
+   token numbers.
 
-   ** yytname = vector of string-names indexed by bison token number
+   ++ YYTNAME = vector of string-names indexed by bison token number.
 
-   ** yytoknum = vector of yylex token numbers corresponding to entries
-   in yytname
+   ++ YYTOKNUM = vector of yylex token numbers corresponding to
+   entries in YYTNAME.
 
-   yyrline = vector of line-numbers of all rules.  For yydebug printouts.
+   YYRLINE = vector of line-numbers of all rules.  For yydebug
+   printouts.
 
-   yyrhs = vector of items of all rules.
-   This is exactly what ritems contains.  For yydebug and for semantic
-   parser.
+   YYRHS = vector of items of all rules.  This is exactly what RITEMS
+   contains.  For yydebug and for semantic parser.
 
-   yyprhs[r] = index in yyrhs of first item for rule r.
+   YYPRHS[R] = index in YYRHS of first item for rule R.
 
-   yyr1[r] = symbol number of symbol that rule r derives.
+   YYR1[R] = symbol number of symbol that rule R derives.
 
-   yyr2[r] = number of symbols composing right hand side of rule r.
+   YYR2[R] = number of symbols composing right hand side of rule R.
 
-   * yystos[s] = the symbol number of the symbol that leads to state s.
+   + YYSTOS[S] = the symbol number of the symbol that leads to state
+   S.
 
-   yydefact[s] = default rule to reduce with in state s,
-   when yytable doesn't specify something else to do.
-   Zero means the default is an error.
+   YYDEFACT[S] = default rule to reduce with in state s, when YYTABLE
+   doesn't specify something else to do.  Zero means the default is an
+   error.
 
-   yydefgoto[i] = default state to go to after a reduction of a rule that
-   generates variable ntokens + i, except when yytable
-   specifies something else to do.
+   YYDEFGOTO[I] = default state to go to after a reduction of a rule
+   that generates variable NTOKENS + I, except when YYTABLE specifies
+   something else to do.
 
-   yypact[s] = index in yytable of the portion describing state s.
-   The lookahead token's type is used to index that portion
-   to find out what to do.
+   YYPACT[S] = index in YYTABLE of the portion describing state S.
+   The lookahead token's type is used to index that portion to find
+   out what to do.
 
-   If the value in yytable is positive,
-   we shift the token and go to that state.
+   If the value in YYTABLE is positive, we shift the token and go to
+   that state.
 
    If the value is negative, it is minus a rule number to reduce by.
 
-   If the value is zero, the default action from yydefact[s] is used.
-
-   yypgoto[i] = the index in yytable of the portion describing
-   what to do after reducing a rule that derives variable i + ntokens.
-   This portion is indexed by the parser state number, s,
-   as of before the text for this nonterminal was read.
-   The value from yytable is the state to go to if
-   the corresponding value in yycheck is s.
-
-   yytable = a vector filled with portions for different uses,
-   found via yypact and yypgoto.
-
-   yycheck = a vector indexed in parallel with yytable.
-   It indicates, in a roundabout way, the bounds of the
-   portion you are trying to examine.
-
-   Suppose that the portion of yytable starts at index p
-   and the index to be examined within the portion is i.
-   Then if yycheck[p+i] != i, i is outside the bounds
-   of what is actually allocated, and the default
-   (from yydefact or yydefgoto) should be used.
-   Otherwise, yytable[p+i] should be used.
-
-   YYFINAL = the state number of the termination state.
-   YYFLAG = most negative short int.  Used to flag ??
-   YYNTBASE = ntokens.
-*/
+   If the value is zero, the default action from YYDEFACT[S] is used.
+
+   YYPGOTO[I] = the index in YYTABLE of the portion describing what to
+   do after reducing a rule that derives variable I + NTOKENS.  This
+   portion is indexed by the parser state number, S, as of before the
+   text for this nonterminal was read.  The value from YYTABLE is the
+   state to go to if the corresponding value in YYCHECK is S.
+
+   YYTABLE = a vector filled with portions for different uses, found
+   via YYPACT and YYPGOTO.
+
+   YYCHECK = a vector indexed in parallel with YYTABLE.  It indicates,
+   in a roundabout way, the bounds of the portion you are trying to
+   examine.
+
+   Suppose that the portion of yytable starts at index P and the index
+   to be examined within the portion is I.  Then if YYCHECK[P+I] != I,
+   I is outside the bounds of what is actually allocated, and the
+   default (from YYDEFACT or YYDEFGOTO) should be used.  Otherwise,
+   YYTABLE[P+I] should be used.
+
+   YYFINAL = the state number of the termination state.  YYFLAG = most
+   negative short int.  Used to flag ??  */
 
 #include "system.h"
 #include "quotearg.h"
