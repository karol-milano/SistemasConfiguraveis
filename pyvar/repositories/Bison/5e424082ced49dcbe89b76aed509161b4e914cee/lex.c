@@ -1,5 +1,6 @@
 /* Token-reader for Bison's input parser,
-   Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -364,13 +365,8 @@ lex (void)
 	obstack_1grow (&token_obstack, '\0');
 	token_buffer = obstack_finish (&token_obstack);
 	symval = getsym (token_buffer);
-	if (symval->number == NUMBER_UNDEFINED)
-	  {
-	    symval->number = ntokens++;
-	    symval->class = token_sym;
-	    if (symval->user_token_number == USER_NUMBER_UNDEFINED)
-	      symval->user_token_number = code;
-	  }
+	symbol_class_set (symval, token_sym);
+	symbol_user_token_number_set (symval, code);
 	return tok_identifier;
       }
 
@@ -378,7 +374,7 @@ lex (void)
       /* parse the literal string token and treat as an identifier */
 
       {
-	int code;		/* ignored here */
+	int code;
 
 	obstack_1grow (&token_obstack, '\"');
 	/* Read up to and including ".  */
@@ -392,12 +388,7 @@ lex (void)
 	token_buffer = obstack_finish (&token_obstack);
 
 	symval = getsym (token_buffer);
-	if (symval->number == NUMBER_UNDEFINED)
-	  {
-	    symval->number = ntokens++;
-	    symval->class = token_sym;
-	  }
-
+	symbol_class_set (symval, token_sym);
 	return tok_identifier;
       }
 
