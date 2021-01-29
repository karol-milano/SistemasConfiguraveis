@@ -28,9 +28,9 @@
 #include "print-xml.h"
 
 
-			/*-------------------.
-			| Shifts and Gotos.  |
-			`-------------------*/
+                        /*-------------------.
+                        | Shifts and Gotos.  |
+                        `-------------------*/
 
 
 /*-----------------------------------------.
@@ -61,14 +61,14 @@ transitions_to (transitions *shifts, symbol_number sym)
     {
       aver (j < shifts->num);
       if (TRANSITION_SYMBOL (shifts, j) == sym)
-	return shifts->states[j];
+        return shifts->states[j];
     }
 }
 
 
-			/*--------------------.
-			| Error transitions.  |
-			`--------------------*/
+                        /*--------------------.
+                        | Error transitions.  |
+                        `--------------------*/
 
 
 /*---------------------------------.
@@ -88,9 +88,9 @@ errs_new (int num, symbol **tokens)
 
 
 
-			/*-------------.
-			| Reductions.  |
-			`-------------*/
+                        /*-------------.
+                        | Reductions.  |
+                        `-------------*/
 
 
 /*---------------------------------------.
@@ -110,9 +110,9 @@ reductions_new (int num, rule **reds)
 
 
 
-			/*---------.
-			| States.  |
-			`---------*/
+                        /*---------.
+                        | States.  |
+                        `---------*/
 
 
 state_number nstates = 0;
@@ -128,7 +128,7 @@ state *final_state = NULL;
 
 state *
 state_new (symbol_number accessing_symbol,
-	   size_t nitems, item_number *core)
+           size_t nitems, item_number *core)
 {
   state *res;
   size_t items_size = nitems * sizeof *core;
@@ -264,17 +264,17 @@ state_rule_lookahead_tokens_print (state *s, rule *r, FILE *out)
       char const *sep = "";
       fprintf (out, "  [");
       BITSET_FOR_EACH (biter, reds->lookahead_tokens[red], k, 0)
-	{
-	  fprintf (out, "%s%s", sep, symbols[k]->tag);
-	  sep = ", ";
-	}
+        {
+          fprintf (out, "%s%s", sep, symbols[k]->tag);
+          sep = ", ";
+        }
       fprintf (out, "]");
     }
 }
 
 void
 state_rule_lookahead_tokens_print_xml (state *s, rule *r,
-				       FILE *out, int level)
+                                       FILE *out, int level)
 {
   /* Find the reduction we are handling.  */
   reductions *reds = s->reductions;
@@ -287,10 +287,10 @@ state_rule_lookahead_tokens_print_xml (state *s, rule *r,
       int k;
       xml_puts (out, level, "<lookaheads>");
       BITSET_FOR_EACH (biter, reds->lookahead_tokens[red], k, 0)
-	{
-	  xml_printf (out, level + 1, "<symbol>%s</symbol>",
-		      xml_escape (symbols[k]->tag));
-	}
+        {
+          xml_printf (out, level + 1, "<symbol>%s</symbol>",
+                      xml_escape (symbols[k]->tag));
+        }
       xml_puts (out, level, "</lookaheads>");
     }
 }
@@ -353,10 +353,10 @@ void
 state_hash_new (void)
 {
   state_table = hash_initialize (HT_INITIAL_CAPACITY,
-				 NULL,
-				 state_hasher,
-				 state_comparator,
-				 NULL);
+                                 NULL,
+                                 state_hasher,
+                                 state_comparator,
+                                 NULL);
 }
 
 
