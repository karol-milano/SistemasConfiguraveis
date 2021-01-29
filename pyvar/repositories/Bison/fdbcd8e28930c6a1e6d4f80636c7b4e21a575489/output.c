@@ -568,30 +568,6 @@ actions_output (FILE *out)
 }
 
 
-/*----------------------------.
-| Output the guards to OOUT.  |
-`----------------------------*/
-
-void
-guards_output (FILE *out)
-{
-  int rule;
-  for (rule = 1; rule < nrules + 1; ++rule)
-    if (rules[rule].guard)
-      {
-	fprintf (out, "  case %d:\n", rule);
-
-	if (!no_lines_flag)
-	  fprintf (out, muscle_find ("linef"),
-		   rules[rule].guard_line,
-		   quotearg_style (c_quoting_style,
-				   muscle_find ("filename")));
-	fprintf (out, "{ %s; }\n    break;\n\n",
-		 rules[rule].guard);
-      }
-}
-
-
 /*---------------------------------------.
 | Output the tokens definition to OOUT.  |
 `---------------------------------------*/
@@ -629,10 +605,6 @@ token_definitions_output (FILE *out)
 
       fprintf (out, "%s  [[[%s]], [%d]]",
 	       first ? "" : ",\n", symbol->tag, number);
-      if (semantic_parser)
-	/* FIXME: This is probably wrong, and should be just as
-	   above. --akim.  */
-	fprintf (out, "# define T%s\t%d\n", symbol->tag, symbol->number);
       first = 0;
     }
 }
@@ -1020,10 +992,6 @@ output_skeleton (void)
   actions_output (out);
   fputs ("]])\n\n", out);
 
-  fputs ("m4_define([b4_guards], \n[[", out);
-  guards_output (out);
-  fputs ("]])\n\n", out);
-
   fputs ("m4_define([b4_tokens], \n[", out);
   token_definitions_output (out);
   fputs ("])\n\n", out);
@@ -1099,12 +1067,7 @@ prepare (void)
 
   /* Find the right skeleton file.  */
   if (!skeleton)
-    {
-      if (semantic_parser)
-	skeleton = "bison.hairy";
-      else
-	skeleton = "bison.simple";
-    }
+    skeleton = "bison.simple";
 
   /* Parse the skeleton file and output the needed parsers.  */
   muscle_insert ("skeleton", skeleton);
