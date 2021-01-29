@@ -18,10 +18,11 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
-#include "system.h"
 
 #include "ielr.h"
 
+#include "system.h"
+
 #include <bitset.h>
 #include <timevar.h>
 
@@ -318,7 +319,7 @@ static state ***
 ielr_compute_predecessors (void)
 {
   int *predecessor_counts = xnmalloc (nstates, sizeof *predecessor_counts);
-  state ***result = xnmalloc (nstates, sizeof *result);
+  state ***res = xnmalloc (nstates, sizeof *res);
   for (state_number i = 0; i < nstates; ++i)
     predecessor_counts[i] = 0;
   for (state_number i = 0; i < nstates; ++i)
@@ -326,18 +327,18 @@ ielr_compute_predecessors (void)
       ++predecessor_counts[states[i]->transitions->states[j]->number];
   for (state_number i = 0; i < nstates; ++i)
     {
-      result[i] = xnmalloc (predecessor_counts[i]+1, sizeof *result[i]);
-      result[i][predecessor_counts[i]] = NULL;
+      res[i] = xnmalloc (predecessor_counts[i]+1, sizeof *res[i]);
+      res[i][predecessor_counts[i]] = NULL;
       predecessor_counts[i] = 0;
     }
   for (state_number i = 0; i < nstates; ++i)
     for (int j = 0; j < states[i]->transitions->num; ++j)
       {
         state_number k = states[i]->transitions->states[j]->number;
-        result[k][predecessor_counts[k]++] = states[i];
+        res[k][predecessor_counts[k]++] = states[i];
       }
   free (predecessor_counts);
-  return result;
+  return res;
 }
 
 /**
@@ -709,15 +710,17 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
   /* Determine whether there's an isocore of t with which these lookaheads can
      be merged.  */
   {
-    AnnotationIndex ai;
-    AnnotationList *a;
     if (annotation_lists)
-      for (ai = 0, a = annotation_lists[lr0_isocore->state->number];
+      {
+        AnnotationIndex ai;
+        AnnotationList *a;
+        for (ai = 0, a = annotation_lists[lr0_isocore->state->number];
            a;
            ++ai, a = a->next)
         work1[ai] =
           AnnotationList__computeDominantContribution (
             a, lr0_isocore->state->nitems, lookaheads, false);
+      }
     for (this_isocorep = &t->state_list;
          this_isocorep == &t->state_list || *this_isocorep != t->state_list;
          this_isocorep = &(*this_isocorep)->nextIsocore)
@@ -726,6 +729,8 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
           break;
         if (annotation_lists)
           {
+            AnnotationIndex ai;
+            AnnotationList *a;
             for (ai = 0, a = annotation_lists[lr0_isocore->state->number];
                  a;
                  ++ai, a = a->next)
@@ -789,15 +794,14 @@ ielr_compute_state (bitsetv follow_kernel_items, bitsetv always_follows,
          actually new.  */
       if (has_lookaheads)
         {
-          size_t i;
           if (!(*this_isocorep)->lookaheads)
             {
               (*this_isocorep)->lookaheads =
                 xnmalloc (t->nitems, sizeof (*this_isocorep)->lookaheads);
-              for (i = 0; i < t->nitems; ++i)
+              for (size_t i = 0; i < t->nitems; ++i)
                 (*this_isocorep)->lookaheads[i] = NULL;
             }
-          for (i = 0; i < t->nitems; ++i)
+          for (size_t i = 0; i < t->nitems; ++i)
             if (!bitset_empty_p (lookaheads[i]))
               {
                 if (!(*this_isocorep)->lookaheads[i])
