@@ -1,5 +1,5 @@
 /* Output the generated parsing program for bison,
-   Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -293,7 +293,7 @@ output_token_translations (void)
 {
   obstack_sgrow (&table_obstack, "\
 \n\
-/* YYRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */\n");
+/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */\n");
 
   if (translations)
     {
@@ -304,7 +304,7 @@ output_token_translations (void)
 	       max_user_token_number, nsyms);
 
       output_short_or_char_table (&table_obstack,
-	     "YYRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX",
+	     "YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX",
 		    ntokens < 127 ? "char" : "short",
 		    "yytranslate", token_translations,
 		    0, 1, max_user_token_number + 1);
