@@ -24,7 +24,7 @@ Boston, MA 02111-1307, USA.  */
 
 lalr(), the entry point, builds these data structures:
 
-goto_map, from_state and to_state 
+goto_map, from_state and to_state
  record each shift transition which accepts a variable (a nonterminal).
 ngotos is the number of such transitions.
 from_state[t] is the state number which a transition leads from
@@ -39,7 +39,7 @@ The elements of LAruleno that apply to state s are those from
  lookaheads[s] through lookaheads[s+1]-1.
 Each element of LAruleno is a rule number.
 
-If lr is the length of LAruleno, then a number from 0 to lr-1 
+If lr is the length of LAruleno, then a number from 0 to lr-1
 can specify both a rule and a state where the rule might be applied.
 
 LA is a lr by ntokens matrix of bits.
@@ -55,7 +55,7 @@ If LA[l, i] and LA[l, j] are both 1 for i != j, it is a conflict.
 #include "state.h"
 #include "alloc.h"
 #include "gram.h"
-
+#include "complain.h"
 
 extern short **derives;
 extern char *nullable;
@@ -92,7 +92,6 @@ void compute_lookaheads PARAMS((void));
 void digraph PARAMS((short **));
 void traverse PARAMS((register int));
 
-extern void toomany PARAMS((char *));
 extern void berror PARAMS((char *));
 
 static int infinity;
@@ -291,7 +290,7 @@ set_goto_map (void)
 	  if (ISTOKEN(symbol)) break;
 
 	  if (ngotos == MAXSHORT)
-	    toomany(_("gotos"));
+	    fatal (_("too many gotos (max %d)"), MAXSHORT);
 
 	  ngotos++;
 	  goto_map[symbol]++;
@@ -413,7 +412,7 @@ initialize_F (void)
 	      if (nullable[symbol])
 		edge[nedges++] = map_goto(stateno, symbol);
 	    }
-	
+
 	  if (nedges)
 	    {
 	      reads[i] = rp = NEW2(nedges + 1, short);
