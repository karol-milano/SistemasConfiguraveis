@@ -429,17 +429,17 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
     do									\
       if (N)								\
 	{								\
-	  (Current).first_line   = YYRHSLOC(Rhs, 1).first_line;		\
-	  (Current).first_column = YYRHSLOC(Rhs, 1).first_column;	\
-	  (Current).last_line    = YYRHSLOC(Rhs, N).last_line;		\
-	  (Current).last_column  = YYRHSLOC(Rhs, N).last_column;	\
+	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
+	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
+	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
+	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
 	}								\
       else								\
 	{								\
 	  (Current).first_line   = (Current).last_line   =		\
-	    YYRHSLOC(Rhs, 0).last_line;					\
+	    YYRHSLOC (Rhs, 0).last_line;				\
 	  (Current).first_column = (Current).last_column =		\
-	    YYRHSLOC(Rhs, 0).last_column;				\
+	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
     while (0)
 
