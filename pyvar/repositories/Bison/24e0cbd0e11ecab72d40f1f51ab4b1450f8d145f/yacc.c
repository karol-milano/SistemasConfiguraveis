@@ -510,22 +510,25 @@ while (0)
    If N is 0, then set CURRENT to the empty location which ends
    the previous symbol: RHS[0] (always defined).  */
 
+#define YYRHSLOC(Rhs, K) ((Rhs)[K])
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)				     \
-do {									     \
-  if (N)								     \
-    {									     \
-      (Current).first_line   = (Rhs)[1].first_line;			     \
-      (Current).first_column = (Rhs)[1].first_column;			     \
-      (Current).last_line    = (Rhs)[N].last_line;			     \
-      (Current).last_column  = (Rhs)[N].last_column;			     \
-    }									     \
-  else									     \
-    {									     \
-      (Current).first_line   = (Current).last_line   = (Rhs)[0].last_line;   \
-      (Current).first_column = (Current).last_column = (Rhs)[0].last_column; \
-    }									     \
-} while(0)
+# define YYLLOC_DEFAULT(Current, Rhs, N)				\
+    do									\
+      if (N)								\
+	{								\
+	  (Current).first_line   = YYRHSLOC(Rhs, 1).first_line;		\
+	  (Current).first_column = YYRHSLOC(Rhs, 1).first_column;	\
+	  (Current).last_line    = YYRHSLOC(Rhs, N).last_line;		\
+	  (Current).last_column  = YYRHSLOC(Rhs, N).last_column;	\
+	}								\
+      else								\
+	{								\
+	  (Current).first_line   = (Current).last_line   =		\
+	    YYRHSLOC(Rhs, 0).last_line;					\
+	  (Current).first_column = (Current).last_column =		\
+	    YYRHSLOC(Rhs, 0).last_column;				\
+	}								\
+    while (0)
 #endif
 
 
