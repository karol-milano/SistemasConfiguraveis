@@ -742,9 +742,9 @@ int state;
 	  if (mask == 0)
 	    {
 	      mask = 1;
-	      /* This used to be fp1, but I think fp2 is right
-		 because fp2 is where the words are fetched to test with mask
-		 in this loop.  */
+	      /* We tried incrementing just fp1, and just fp2; both seem wrong.
+		 It seems necessary to increment both in sync.  */
+	      fp1++;
 	      fp2++;
 	    }
 	}
