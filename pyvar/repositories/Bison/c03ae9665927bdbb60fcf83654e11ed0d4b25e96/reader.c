@@ -52,7 +52,6 @@ typedef struct symbol_list
 } symbol_list;
 
 int lineno;
-short *user_toknums;
 static symbol_list *grammar;
 static int start_flag;
 static bucket *startval;
@@ -1567,7 +1566,6 @@ packsymbols (void)
   int tokno = 1;
   int last_user_token_number;
 
-  user_toknums = XCALLOC (short, nsyms + 1);
   symbols = XCALLOC (bucket *, nsyms);
 
   max_user_token_number = 256;
@@ -1640,7 +1638,6 @@ packsymbols (void)
 	}
 
       symbols[bp->value] = bp;
-      user_toknums[bp->value] = bp->user_token_number;
     }
 
   token_translations_init ();
