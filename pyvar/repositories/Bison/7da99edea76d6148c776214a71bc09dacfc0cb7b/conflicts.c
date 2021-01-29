@@ -19,6 +19,7 @@
    02111-1307, USA.  */
 
 #include "system.h"
+#include "complain.h"
 #include "getargs.h"
 #include "files.h"
 #include "gram.h"
@@ -29,7 +30,8 @@
 #include "LR0.h"
 
 errs **err_table = NULL;
-int expected_conflicts;
+/* -1 stands for not specified. */
+int expected_conflicts = -1;
 static char *conflicts = NULL;
 
 static unsigned *shiftset = NULL;
@@ -404,31 +406,23 @@ conflict_report (int src_num, int rrc_num)
   static char res[4096];
   char *cp = res;
 
-  if (src_num == 1)
+  if (src_num >= 1)
     {
-      sprintf (cp, _(" 1 shift/reduce conflict"));
-      cp += strlen (cp);
-    }
-  else if (src_num > 1)
-    {
-      sprintf (cp, _(" %d shift/reduce conflicts"), src_num);
+      sprintf (cp, ngettext ("%d shift/reduce conflict",
+			     "%d shift/reduce conflicts", src_num), src_num);
       cp += strlen (cp);
     }
 
   if (src_num > 0 && rrc_num > 0)
     {
-      sprintf (cp, _(" and"));
+      sprintf (cp, " %s ", _("and"));
       cp += strlen (cp);
     }
 
-  if (rrc_num == 1)
+  if (rrc_num >= 1)
     {
-      sprintf (cp, _(" 1 reduce/reduce conflict"));
-      cp += strlen (cp);
-    }
-  else if (rrc_num > 1)
-    {
-      sprintf (cp, _(" %d reduce/reduce conflicts"), rrc_num);
+      sprintf (cp, ngettext ("%d reduce/reduce conflict",
+			     "%d reduce/reduce conflicts", rrc_num), rrc_num);
       cp += strlen (cp);
     }
 
@@ -451,7 +445,7 @@ conflicts_output (FILE *out)
   for (i = 0; i < nstates; i++)
     if (conflicts[i])
       {
-	fprintf (out, _("State %d contains"), i);
+	fprintf (out, _("State %d contains "), i);
 	fputs (conflict_report (count_sr_conflicts (i),
 				count_rr_conflicts (i)), out);
       }
@@ -495,9 +489,19 @@ conflicts_print (void)
       }
     else
       {
-	fprintf (stderr, _("%s contains"), infile);
+	fprintf (stderr, _("%s contains "), infile);
 	fputs (conflict_report (src_total, rrc_total), stderr);
       }
+
+  if (expected_conflicts != -1
+      && src_total != expected_conflicts)
+    {
+      complain_message_count++;
+      fprintf (stderr, ngettext ("expected %d shift/reduce conflict",
+				 "expected %d shift/reduce conflicts",
+				 expected_conflicts),
+	       expected_conflicts);
+    }
 }
 
 
