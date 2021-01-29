@@ -248,22 +248,14 @@ reduce_grammar_tables (void)
     free (rules + 1);
     rules = rules_sorted;
 
-    /* Also reorder ritems. */
-    {
-      short *ritems_sorted = XCALLOC (short, nitems + 1);
-      short *ritemsp = ritems_sorted;
-      for (i = 1; i < nrules + 1; ++i)
-	{
-	  short *rhsp = rules[i].rhs;
-	  rules[i].rhs = ritemsp;
-	  for (/* Nothing. */; *rhsp >= 0; ++rhsp)
-	    *ritemsp++ = *rhsp;
-	  *ritemsp++ = -i;
-	}
-      *ritemsp++ = 0;
-      free (ritem);
-      ritem = ritems_sorted;
-    }
+    /* Renumber the rules markers in RITEMS.  */
+    for (i = 1; i < nrules + 1; ++i)
+      {
+	short *rhsp = rules[i].rhs;
+	for (/* Nothing. */; *rhsp >= 0; ++rhsp)
+	  /* Nothing. */;
+	*rhsp = -i;
+      }
     nrules -= nuseless_productions;
   }
 
