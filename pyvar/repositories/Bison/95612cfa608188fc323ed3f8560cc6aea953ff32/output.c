@@ -198,7 +198,7 @@ prepare_symbols (void)
 
 /*-------------------------------------------------------------.
 | Prepare the muscles related to the rules: rhs, prhs, r1, r2, |
-| rline, dprec, merger                                         |
+| rline, dprec, merger.                                        |
 `-------------------------------------------------------------*/
 
 static void
@@ -230,9 +230,9 @@ prepare_rules (void)
       rhs[i++] = -1;
       /* Line where rule was defined. */
       rline[r] = rules[r].location.first_line;
-      /* Dynamic precedence (GLR) */
+      /* Dynamic precedence (GLR).  */
       dprec[r] = rules[r].dprec;
-      /* Merger-function index (GLR) */
+      /* Merger-function index (GLR).  */
       merger[r] = rules[r].merger;
     }
   assert (i == nritems);
