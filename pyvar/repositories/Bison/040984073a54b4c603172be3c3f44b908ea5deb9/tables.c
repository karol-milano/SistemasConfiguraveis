@@ -173,7 +173,7 @@ table_grow (int desired)
 
 /*-------------------------------------------------------------------.
 | For GLR parsers, for each conflicted token in S, as indicated      |
-| by non-zero entries in CONFLROW, create a list of possible 	     |
+| by non-zero entries in CONFLROW, create a list of possible	     |
 | reductions that are alternatives to the shift or reduction	     |
 | currently recorded for that token in S.  Store the alternative     |
 | reductions followed by a 0 in CONFLICT_LIST, updating		     |
