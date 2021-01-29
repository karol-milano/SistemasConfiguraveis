@@ -1556,11 +1556,10 @@ token_translations_init (void)
 }
 
 
-/*------------------------------------------------------------------.
-| Assign symbol numbers, and write definition of token names into   |
-| FDEFINES.  Set up vectors TAGS and SPREC of names and precedences |
-| of symbols.                                                       |
-`------------------------------------------------------------------*/
+/*----------------------------------------------------------------.
+| Assign symbol numbers, and write definition of token names into |
+| FDEFINES.  Set up vectors SYMBOL_TABLE, TAGS of symbols.        |
+`----------------------------------------------------------------*/
 
 static void
 packsymbols (void)
@@ -1571,8 +1570,8 @@ packsymbols (void)
 
   tags = XCALLOC (char *, nsyms + 1);
   user_toknums = XCALLOC (short, nsyms + 1);
+  symbols = XCALLOC (bucket *, nsyms);
 
-  sprec = XCALLOC (short, nsyms);
   sassoc = XCALLOC (short, nsyms);
 
   max_user_token_number = 256;
@@ -1644,9 +1643,9 @@ packsymbols (void)
 	    max_user_token_number = bp->user_token_number;
 	}
 
+      symbols[bp->value] = bp;
       tags[bp->value] = bp->tag;
       user_toknums[bp->value] = bp->user_token_number;
-      sprec[bp->value] = bp->prec;
       sassoc[bp->value] = bp->assoc;
     }
 
