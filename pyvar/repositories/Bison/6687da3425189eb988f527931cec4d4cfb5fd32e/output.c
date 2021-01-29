@@ -469,40 +469,6 @@ prepare_symbol_definitions (void)
 }
 
 
-/*--------------------------------------.
-| Output the tokens definition to OUT.  |
-`--------------------------------------*/
-
-static void
-token_definitions_output (FILE *out)
-{
-  int i;
-  char const *sep = "";
-
-  fputs ("m4_define([b4_tokens], \n[", out);
-  for (i = 0; i < ntokens; ++i)
-    {
-      symbol *sym = symbols[i];
-      int number = sym->user_token_number;
-      uniqstr id = symbol_id_get (sym);
-
-      /* At this stage, if there are literal string aliases, they are
-         part of SYMBOLS, so we should not find their aliased symbols
-         here.  */
-      aver (number != USER_NUMBER_HAS_STRING_ALIAS);
-
-      /* Skip error token and tokens without identifier.  */
-      if (sym != errtoken && id)
-        {
-          fprintf (out, "%s[[[%s]], %d]",
-                   sep, id, number);
-          sep = ",\n";
-        }
-    }
-  fputs ("])\n\n", out);
-}
-
-
 static void
 prepare_actions (void)
 {
@@ -561,7 +527,6 @@ muscles_output (FILE *out)
   fputs ("m4_init()\n", out);
   merger_output (out);
   symbol_numbers_output (out);
-  token_definitions_output (out);
   type_names_output (out);
   user_actions_output (out);
   // Must be last.
