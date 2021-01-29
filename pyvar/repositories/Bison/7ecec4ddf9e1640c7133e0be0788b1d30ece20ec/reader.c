@@ -69,27 +69,6 @@ grammar_start_symbol_set (symbol *sym, location loc)
     }
 }
 
-
-/*---------------------------------------------------------------------.
-| There are two prologues: one before the first %union and one after.  |
-| Augment the one specified by POST.                                   |
-`---------------------------------------------------------------------*/
-
-void
-prologue_augment (const char *prologue, location loc, bool post)
-{
-  struct obstack *oout =
-    !post ? &pre_prologue_obstack : &post_prologue_obstack;
-
-  obstack_fgrow1 (oout, "]b4_syncline(%d, [[", loc.start.line);
-  /* FIXME: Protection of M4 characters missing here.  See
-     output.c:escaped_output.  */
-  MUSCLE_OBSTACK_SGROW (oout,
-			quotearg_style (c_quoting_style, loc.start.file));
-  obstack_sgrow (oout, "]])[\n");
-  obstack_sgrow (oout, prologue);
-}
-
 
 
 /*------------------------------------------------------------------------.
@@ -585,10 +564,6 @@ reader (void)
   undeftoken->class = token_sym;
   undeftoken->number = ntokens++;
 
-  /* Initialize the obstacks. */
-  obstack_init (&pre_prologue_obstack);
-  obstack_init (&post_prologue_obstack);
-
   gram_in = xfopen (grammar_file, "r");
 
   gram__flex_debug = trace_flag & trace_scan;
