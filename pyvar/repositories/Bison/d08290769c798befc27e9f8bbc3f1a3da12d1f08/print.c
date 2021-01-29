@@ -327,16 +327,16 @@ print_reductions (FILE *out, state *s)
   if (reds->lookaheads)
     for (i = 0; i < ntokens; i++)
       {
-	int count = bitset_test (shiftset, i);
+	bool count = bitset_test (shiftset, i);
 
 	for (j = 0; j < reds->num; ++j)
 	  if (bitset_test (reds->lookaheads[j], i))
 	    {
-	      if (count == 0)
+	      if (! count)
 		{
 		  if (reds->rules[j] != default_rule)
 		    max_length (&width, symbols[i]->tag);
-		  count++;
+		  count = true;
 		}
 	      else
 		{
@@ -356,21 +356,21 @@ print_reductions (FILE *out, state *s)
   if (reds->lookaheads)
     for (i = 0; i < ntokens; i++)
       {
-	int defaulted = 0;
-	int count = bitset_test (shiftset, i);
+	bool defaulted = false;
+	bool count = bitset_test (shiftset, i);
 
 	for (j = 0; j < reds->num; ++j)
 	  if (bitset_test (reds->lookaheads[j], i))
 	    {
-	      if (count == 0)
+	      if (! count)
 		{
 		  if (reds->rules[j] != default_rule)
 		    print_reduction (out, width,
 				     symbols[i]->tag,
 				     reds->rules[j], true);
 		  else
-		    defaulted = 1;
-		  count++;
+		    defaulted = true;
+		  count = true;
 		}
 	      else
 		{
@@ -378,7 +378,7 @@ print_reductions (FILE *out, state *s)
 		    print_reduction (out, width,
 				     symbols[i]->tag,
 				     default_rule, true);
-		  defaulted = 0;
+		  defaulted = false;
 		  print_reduction (out, width,
 				   symbols[i]->tag,
 				   reds->rules[j], false);
