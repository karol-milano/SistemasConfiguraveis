@@ -1,7 +1,7 @@
 /* Generate the nondeterministic finite state machine for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2004, 2005 Free
-   Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2004, 2005, 2006
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -282,7 +282,7 @@ save_reductions (state *s)
 	  if (r == 0)
 	    {
 	      /* This is "reduce 0", i.e., accept. */
-	      assert (!final_state);
+	      aver (!final_state);
 	      final_state = s;
 	    }
 	}
