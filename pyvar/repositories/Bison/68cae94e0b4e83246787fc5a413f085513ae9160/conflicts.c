@@ -1,6 +1,6 @@
 /* Find and resolve or report look-ahead conflicts for bison,
 
-   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005
+   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005, 2006
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -216,6 +216,9 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 
 	  switch (symbols[i]->assoc)
 	    {
+	    default:
+	      abort ();
+
 	    case right_assoc:
 	      log_resolution (redrule, i, right_resolution);
 	      flush_reduce (look_ahead_tokens, i);
@@ -233,9 +236,6 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 	      /* Record an explicit error for this token.  */
 	      errors[nerrs++] = symbols[i];
 	      break;
-
-	    case undef_assoc:
-	      abort ();
 	    }
       }
 
