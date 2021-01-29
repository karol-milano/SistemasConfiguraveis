@@ -83,19 +83,22 @@ ielr_compute_ritem_sees_lookahead_set (void)
   while (0 < i)
     {
       --i;
+      // Walk the RHS right to left, as long as it's symbol,
+      // nonterminal, nullable.
       while (!item_number_is_rule_number (ritem[i])
              && ISVAR (ritem[i])
              && nullable [item_number_as_symbol_number (ritem[i]) - ntokens])
         bitset_set (result, i--);
       if (!item_number_is_rule_number (ritem[i]) && ISVAR (ritem[i]))
         bitset_set (result, i--);
+      // Flush the remainder of the RHS.
       while (!item_number_is_rule_number (ritem[i]) && 0 < i)
         --i;
     }
   if (trace_flag & trace_ielr)
     {
-      fprintf (stderr, "ritem_sees_lookahead_set:\n");
-      debug_bitset (result);
+      fprintf (stderr, "ritem_sees_lookahead_set (indexes of ritems): ");
+      bitset_dump (stderr, result);
       fprintf (stderr, "\n");
     }
   return result;
@@ -569,6 +572,24 @@ typedef struct state_list
   struct state_list *nextIsocore;
 } state_list;
 
+MAYBE_UNUSED static void
+state_list_print_ (const state_list *s, FILE *out, const char *sep)
+{
+  if (s)
+    {
+      fprintf (out, "%s%d", sep, s->state->number);
+      state_list_print_ (s->next, out, " ");
+    }
+}
+
+MAYBE_UNUSED static void
+state_list_print (const state_list *s, FILE *out)
+{
+  fprintf (out, "{");
+  state_list_print_ (s, out, "");
+  fprintf (out, "}");
+}
+
 /**
  * \pre
  *   - \c follow_kernel_items and \c always_follows were computed by
