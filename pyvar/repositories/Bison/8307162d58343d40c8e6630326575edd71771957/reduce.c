@@ -71,8 +71,8 @@ useful_production (rule_number_t r, bitset N0)
 
   for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
     if (ISVAR (*rhsp) && !bitset_test (N0, *rhsp - ntokens))
-      return FALSE;
-  return TRUE;
+      return false;
+  return true;
 }
 
 
@@ -353,14 +353,14 @@ reduce_output (FILE *out)
     }
 
   {
-    bool b = FALSE;
+    bool b = false;
     int i;
     for (i = 0; i < ntokens; i++)
       if (!bitset_test (V, i) && !bitset_test (V1, i))
 	{
 	  if (!b)
 	    fprintf (out, "%s\n\n", _("Terminals which are not used"));
-	  b = TRUE;
+	  b = true;
 	  fprintf (out, "   %s\n", symbols[i]->tag);
 	}
     if (b)
