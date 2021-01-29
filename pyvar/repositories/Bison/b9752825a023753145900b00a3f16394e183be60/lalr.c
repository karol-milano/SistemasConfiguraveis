@@ -103,7 +103,7 @@ traverse (int i)
 	  break;
 
 	for (k = 0; k < size; ++k)
-	  F (i)[k] = F (j)[k];
+	  F (j)[k] = F (i)[k];
       }
 }
 
