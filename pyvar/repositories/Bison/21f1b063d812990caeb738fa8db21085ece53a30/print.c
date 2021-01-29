@@ -401,7 +401,7 @@ print_grammar (FILE *out)
 	buffer[0] = 0;
 	column = strlen (tag);
 	fputs (tag, out);
-	END_TEST (50);
+	END_TEST (65);
 	sprintf (buffer, " (%d)", i);
 
 	for (r = 0; r < nrules; r++)
@@ -445,14 +445,16 @@ print_grammar (FILE *out)
 
       if (left_count > 0)
 	{
-	  END_TEST (50);
+	  END_TEST (65);
 	  sprintf (buffer + strlen (buffer), _(" on left:"));
 
 	  for (r = 0; r < nrules; r++)
 	    {
-	      END_TEST (65);
 	      if (rules[r].lhs->number == i)
-		sprintf (buffer + strlen (buffer), " %d", r);
+		{
+		  END_TEST (65);
+		  sprintf (buffer + strlen (buffer), " %d", r);
+		}
 	    }
 	}
 
@@ -460,7 +462,7 @@ print_grammar (FILE *out)
 	{
 	  if (left_count > 0)
 	    sprintf (buffer + strlen (buffer), ",");
-	  END_TEST (50);
+	  END_TEST (65);
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
 	  for (r = 0; r < nrules; r++)
 	    {
