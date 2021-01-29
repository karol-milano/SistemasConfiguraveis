@@ -52,7 +52,6 @@ typedef struct symbol_list
 } symbol_list;
 
 int lineno;
-char **tags;
 short *user_toknums;
 static symbol_list *grammar;
 static int start_flag;
@@ -1549,7 +1548,7 @@ token_translations_init (void)
       /* A token which translation has already been set? */
       if (token_translations[bp->user_token_number] != 2)
 	complain (_("tokens %s and %s both assigned number %d"),
-		  tags[token_translations[bp->user_token_number]],
+		  symbols[token_translations[bp->user_token_number]]->tag,
 		  bp->tag, bp->user_token_number);
       token_translations[bp->user_token_number] = bp->value;
     }
@@ -1568,7 +1567,6 @@ packsymbols (void)
   int tokno = 1;
   int last_user_token_number;
 
-  tags = XCALLOC (char *, nsyms + 1);
   user_toknums = XCALLOC (short, nsyms + 1);
   symbols = XCALLOC (bucket *, nsyms);
 
@@ -1644,7 +1642,6 @@ packsymbols (void)
 	}
 
       symbols[bp->value] = bp;
-      tags[bp->value] = bp->tag;
       user_toknums[bp->value] = bp->user_token_number;
       sassoc[bp->value] = bp->assoc;
     }
