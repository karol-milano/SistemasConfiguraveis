@@ -537,6 +537,8 @@ void
 actions_output (FILE *out)
 {
   int rule;
+
+  fputs ("m4_define([b4_actions], \n[[", out);
   for (rule = 1; rule < nrules + 1; ++rule)
     if (rules[rule].action)
       {
@@ -550,6 +552,7 @@ actions_output (FILE *out)
 	fprintf (out, "    %s\n    break;\n\n",
 		 rules[rule].action);
       }
+  fputs ("]])\n\n", out);
 }
 
 
@@ -562,6 +565,8 @@ token_definitions_output (FILE *out)
 {
   int i;
   int first = 1;
+
+  fputs ("m4_define([b4_tokens], \n[", out);
   for (i = 0; i < ntokens; ++i)
     {
       symbol_t *symbol = symbols[i];
@@ -597,6 +602,7 @@ token_definitions_output (FILE *out)
 
       first = 0;
     }
+  fputs ("])\n\n", out);
 }
 
 
@@ -1011,13 +1017,8 @@ output_skeleton (void)
   fputs ("m4_changecom()\n", out);
   fputs ("m4_init()\n", out);
 
-  fputs ("m4_define([b4_actions], \n[[", out);
   actions_output (out);
-  fputs ("]])\n\n", out);
-
-  fputs ("m4_define([b4_tokens], \n[", out);
   token_definitions_output (out);
-  fputs ("])\n\n", out);
 
   muscles_m4_output (out);
 
