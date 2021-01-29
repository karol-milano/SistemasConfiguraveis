@@ -19,6 +19,7 @@
    02111-1307, USA.  */
 
 #include "system.h"
+#include "getargs.h"
 #include "gram.h"
 #include "reader.h"
 #include "closure.h"
@@ -39,7 +40,6 @@ static int rulesetsize;
 /* number of words required to hold a bit for each variable */
 static int varsetsize;
 
-#if TRACE
 
 /*-----------------.
 | Debugging code.  |
@@ -97,7 +97,6 @@ print_fderives (void)
 	  fprintf (stderr, "   %d\n", j);
     }
 }
-#endif
 
 /*-------------------------------------------------------------------.
 | Set FIRSTS to be an NVARS by NVARS bit matrix indicating which     |
@@ -142,9 +141,8 @@ set_firsts (void)
 
   RTC (firsts, nvars);
 
-#ifdef TRACE
-  print_firsts ();
-#endif
+  if (trace_flag)
+    print_firsts ();
 }
 
 /*-------------------------------------------------------------------.
@@ -203,9 +201,8 @@ set_fderives (void)
       rrow += rulesetsize;
     }
 
-#ifdef TRACE
-  print_fderives ();
-#endif
+  if (trace_flag)
+    print_fderives ();
 
   XFREE (firsts);
 }
@@ -300,9 +297,8 @@ closure (short *core, int n)
   while (csp < csend)
     *itemsetend++ = *csp++;
 
-#if TRACE
-  print_closure (n);
-#endif
+  if (trace_flag)
+    print_closure (n);
 }
 
 
