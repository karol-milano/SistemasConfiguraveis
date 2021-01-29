@@ -20,7 +20,6 @@
 
 #include "system.h"
 #include "getargs.h"
-#include "xalloc.h"
 #include "files.h"
 #include "gram.h"
 #include "state.h"
@@ -30,12 +29,12 @@
 #include "LR0.h"
 
 int any_conflicts = 0;
-errs **err_table;
+errs **err_table = NULL;
 int expected_conflicts;
-static char *conflicts;
+static char *conflicts = NULL;
 
-static unsigned *shiftset;
-static unsigned *lookaheadset;
+static unsigned *shiftset = NULL;
+static unsigned *lookaheadset = NULL;
 static int src_total;
 static int rrc_total;
 static int src_count;
@@ -264,7 +263,7 @@ set_conflicts (int state)
 }
 
 void
-initialize_conflicts (void)
+solve_conflicts (void)
 {
   int i;
 
@@ -458,7 +457,7 @@ conflict_report (int src_num, int rrc_num)
 `---------------------------------------------*/
 
 void
-print_conflicts (void)
+print_conflicts (FILE *out)
 {
   int i;
 
@@ -478,9 +477,8 @@ print_conflicts (void)
 
 	  if (verbose_flag)
 	    {
-	      obstack_fgrow1 (&output_obstack, _("State %d contains"), i);
-	      obstack_sgrow (&output_obstack,
-			     conflict_report (src_count, rrc_count));
+	      fprintf (out, _("State %d contains"), i);
+	      fputs (conflict_report (src_count, rrc_count), out);
 	    }
 	}
     }
@@ -738,7 +736,7 @@ print_reductions (int state)
 
 
 void
-finalize_conflicts (void)
+free_conflicts (void)
 {
   XFREE (conflicts);
   XFREE (shiftset);
