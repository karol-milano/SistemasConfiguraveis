@@ -1,5 +1,5 @@
 /* Compute look-ahead criteria for bison,
-   Copyright 1984, 1986, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 2000, 2001  Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -48,7 +48,6 @@ short *to_state;
 extern void berror PARAMS ((const char *));
 
 static int infinity;
-static int maxrhs;
 static int ngotos;
 
 /* And for the famous F variable, which named is so descriptive that a
@@ -213,8 +212,9 @@ set_state_table (void)
 }
 
 
-static void
-set_maxrhs (void)
+/* Return the size of the longest ride hand side of the rules. */
+static size_t
+maxrhs (void)
 {
   short *itemp;
   int length;
@@ -236,7 +236,7 @@ set_maxrhs (void)
 	}
     }
 
-  maxrhs = max;
+  return max;
 }
 
 
@@ -547,7 +547,7 @@ build_relations (void)
 
   includes = XCALLOC (short *, ngotos);
   edge = XCALLOC (short, ngotos + 1);
-  states = XCALLOC (short, maxrhs + 1);
+  states = XCALLOC (short, maxrhs () + 1);
 
   for (i = 0; i < ngotos; i++)
     {
@@ -673,7 +673,6 @@ lalr (void)
   tokensetsize = WORDSIZE (ntokens);
 
   set_state_table ();
-  set_maxrhs ();
   initialize_LA ();
   set_goto_map ();
   initialize_F ();
