@@ -96,10 +96,10 @@ set_nullable (void)
 	  {
 	    /* This rule has an empty RHS. */
 	    assert (rules[ruleno].rhs[0] == -ruleno);
-	    if (rules[ruleno].useful && !nullable[rules[ruleno].lhs])
+	    if (rules[ruleno].useful && !nullable[rules[ruleno].lhs->number])
 	      {
-		nullable[rules[ruleno].lhs] = 1;
-		*s2++ = rules[ruleno].lhs;
+		nullable[rules[ruleno].lhs->number] = 1;
+		*s2++ = rules[ruleno].lhs->number;
 	      }
 	  }
       }
@@ -109,10 +109,10 @@ set_nullable (void)
       {
 	ruleno = p->value;
 	if (--rcount[ruleno] == 0)
-	  if (rules[ruleno].useful && !nullable[rules[ruleno].lhs])
+	  if (rules[ruleno].useful && !nullable[rules[ruleno].lhs->number])
 	    {
-	      nullable[rules[ruleno].lhs] = 1;
-	      *s2++ = rules[ruleno].lhs;
+	      nullable[rules[ruleno].lhs->number] = 1;
+	      *s2++ = rules[ruleno].lhs->number;
 	    }
       }
 
