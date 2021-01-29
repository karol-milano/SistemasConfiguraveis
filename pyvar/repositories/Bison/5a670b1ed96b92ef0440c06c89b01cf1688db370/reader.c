@@ -1570,8 +1570,6 @@ packsymbols (void)
   user_toknums = XCALLOC (short, nsyms + 1);
   symbols = XCALLOC (bucket *, nsyms);
 
-  sassoc = XCALLOC (short, nsyms);
-
   max_user_token_number = 256;
   last_user_token_number = 256;
 
@@ -1643,7 +1641,6 @@ packsymbols (void)
 
       symbols[bp->value] = bp;
       user_toknums[bp->value] = bp->user_token_number;
-      sassoc[bp->value] = bp->assoc;
     }
 
   token_translations_init ();
