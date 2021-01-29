@@ -1,7 +1,7 @@
 /* Find and resolve or report lookahead conflicts for bison,
 
    Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-   2007 Free Software Foundation, Inc.
+   2007, 2008 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -285,16 +285,21 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
 	    flush_reduce (lookahead_tokens, i);
 	  }
 	else
-	  /* Matching precedence levels.
-	     For left association, keep only the reduction.
-	     For right association, keep only the shift.
-	     For nonassociation, keep neither.  */
+          /* Matching precedence levels.
+             For non-defined associativity, keep both: unexpected
+             associativity conflict.
+             For left associativity, keep only the reduction.
+             For right associativity, keep only the shift.
+             For nonassociativity, keep neither.  */
 
 	  switch (symbols[i]->assoc)
 	    {
-	    default:
+            case undef_assoc:
 	      abort ();
 
+            case precedence_assoc:
+              break;
+
 	    case right_assoc:
 	      log_resolution (redrule, i, right_resolution);
 	      flush_reduce (lookahead_tokens, i);
