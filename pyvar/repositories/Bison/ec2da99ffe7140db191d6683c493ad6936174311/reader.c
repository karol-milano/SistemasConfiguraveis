@@ -1647,13 +1647,11 @@ symbols_save (void)
 {
   struct obstack tokendefs;
   bucket *bp;
-  char *cp, *symbol;
-  char c;
   obstack_init (&tokendefs);
 
   for (bp = firstsymbol; bp; bp = bp->next)
     {
-      symbol = bp->tag;                /* get symbol */
+      char *symbol = bp->tag;                /* get symbol */
 
       if (bp->value >= ntokens)
 	continue;
@@ -1673,9 +1671,7 @@ symbols_save (void)
 	}
 
       /* Don't #define nonliteral tokens whose names contain periods.  */
-      cp = symbol;
-      while ((c = *cp++) && c != '.');
-      if (c != '\0')
+      if (strchr (symbol, '.'))
 	continue;
 
       obstack_fgrow2 (&tokendefs, "# define %s\t%d\n",
