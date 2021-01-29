@@ -107,23 +107,16 @@ set_nullable (void)
     }
 
   while (s1 < s2)
-    {
-      p = rsets[*s1++];
-      while (p)
-	{
-	  int ruleno = p->value;
-	  p = p->next;
-	  if (--rcount[ruleno] == 0)
+    for (p = rsets[*s1++]; p; p = p->next)
+      {
+	int ruleno = p->value;
+	if (--rcount[ruleno] == 0)
+	  if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
 	    {
-	      int symbol = rule_table[ruleno].lhs;
-	      if (symbol >= 0 && !nullable[symbol])
-		{
-		  nullable[symbol] = 1;
-		  *s2++ = symbol;
-		}
+	      nullable[rule_table[ruleno].lhs] = 1;
+	      *s2++ = rule_table[ruleno].lhs;
 	    }
-	}
-    }
+      }
 
   XFREE (squeue);
   XFREE (rcount);
