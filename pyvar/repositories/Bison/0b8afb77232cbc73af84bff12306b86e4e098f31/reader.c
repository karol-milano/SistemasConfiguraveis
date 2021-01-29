@@ -1575,9 +1575,9 @@ readgram (void)
 			   "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
       if (defines_flag)
 	obstack_sgrow (&defines_obstack, "\
-#ifndef YYSTYPE\n\
-# define YYSTYPE int\n\
-#endif\n");
+# ifndef YYSTYPE\n\
+#  define YYSTYPE int\n\
+# endif\n");
     }
 
   /* Report any undefined symbols and consider them nonterminals.  */
@@ -1634,11 +1634,11 @@ output_token_defines (struct obstack *oout)
       if (c != '\0')
 	continue;
 
-      obstack_fgrow2 (oout, "#define\t%s\t%d\n",
+      obstack_fgrow2 (oout, "# define\t%s\t%d\n",
 		      symbol,
 		      (translations ? bp->user_token_number : bp->value));
       if (semantic_parser)
-	obstack_fgrow2 (oout, "#define\tT%s\t%d\n", symbol, bp->value);
+	obstack_fgrow2 (oout, "# define\tT%s\t%d\n", symbol, bp->value);
     }
 
   obstack_1grow (oout, '\n');
@@ -1793,7 +1793,7 @@ packsymbols (void)
 	    /* don't make these for dummy nonterminals made by gensym.  */
 	    if (*tags[i] != '@')
 	       obstack_fgrow2 (&defines_obstack,
-			       "#define\tNT%s\t%d\n", tags[i], i);
+			       "# define\tNT%s\t%d\n", tags[i], i);
 	  }
 #if 0
       /* `fdefines' is now a temporary file, so we need to copy its
