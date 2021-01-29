@@ -755,8 +755,8 @@ pack_vector (int vector)
 	  return j;
 	}
     }
-
-  assert (!"pack_vector");
+#define pack_vector_succeeded 0
+  assert (pack_vector_succeeded);
   return 0;
 }
 
