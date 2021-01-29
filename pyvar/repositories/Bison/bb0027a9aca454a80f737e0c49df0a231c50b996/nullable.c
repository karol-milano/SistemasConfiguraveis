@@ -30,14 +30,14 @@
 #include "reduce.h"
 #include "nullable.h"
 
-/* Linked list of rule numbers.  */
+/* Linked list of rules.  */
 typedef struct rule_list_s
 {
   struct rule_list_s *next;
-  rule_number_t value;
+  rule_t *value;
 } rule_list_t;
 
-char *nullable = NULL;
+bool *nullable = NULL;
 
 static void
 nullable_print (FILE *out)
@@ -50,7 +50,7 @@ nullable_print (FILE *out)
 }
 
 void
-set_nullable (void)
+nullable_compute (void)
 {
   rule_number_t ruleno;
   symbol_number_t *s1;
@@ -66,7 +66,7 @@ set_nullable (void)
      Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
   rule_list_t *relts = XCALLOC (rule_list_t, nritems + nvars + 1);
 
-  nullable = XCALLOC (char, nvars) - ntokens;
+  nullable = XCALLOC (bool, nvars) - ntokens;
 
   s1 = s2 = squeue;
   p = relts;
@@ -91,7 +91,7 @@ set_nullable (void)
 		{
 		  rcount[ruleno]++;
 		  p->next = rsets[*r];
-		  p->value = ruleno;
+		  p->value = rule;
 		  rsets[*r] = p;
 		  p++;
 		}
@@ -111,12 +111,12 @@ set_nullable (void)
   while (s1 < s2)
     for (p = rsets[*s1++]; p; p = p->next)
       {
-	ruleno = p->value;
-	if (--rcount[ruleno] == 0)
-	  if (rules[ruleno].useful && !nullable[rules[ruleno].lhs->number])
+	rule_t *rule = p->value;
+	if (--rcount[rule->number] == 0)
+	  if (rule->useful && !nullable[rule->lhs->number])
 	    {
-	      nullable[rules[ruleno].lhs->number] = 1;
-	      *s2++ = rules[ruleno].lhs->number;
+	      nullable[rule->lhs->number] = 1;
+	      *s2++ = rule->lhs->number;
 	    }
       }
 
@@ -131,7 +131,7 @@ set_nullable (void)
 
 
 void
-free_nullable (void)
+nullable_free (void)
 {
   XFREE (nullable + ntokens);
 }
