@@ -1600,8 +1600,7 @@ output_token_defines (struct obstack *oout)
 
       obstack_fgrow2 (oout, "#define\t%s\t%d\n",
 		      symbol,
-		      ((translations && !raw_flag)
-		       ? bp->user_token_number : bp->value));
+		      (translations ? bp->user_token_number : bp->value));
       if (semantic_parser)
 	obstack_fgrow2 (oout, "#define\tT%s\t%d\n", symbol, bp->value);
     }
