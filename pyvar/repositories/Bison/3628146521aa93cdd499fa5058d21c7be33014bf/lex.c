@@ -158,7 +158,7 @@ skip_white_space (void)
 	  break;
 
 	default:
-	  return (c);
+	  return c;
 	}
     }
 }
@@ -314,7 +314,7 @@ lex (void)
       symval = unlexed_symval;
       c = unlexed;
       unlexed = -1;
-      return (c);
+      return c;
     }
 
   c = skip_white_space();
@@ -325,7 +325,7 @@ lex (void)
     {
     case EOF:
       strcpy(token_buffer, "EOF");
-      return (ENDFILE);
+      return ENDFILE;
 
     case 'A':  case 'B':  case 'C':  case 'D':  case 'E':
     case 'F':  case 'G':  case 'H':  case 'I':  case 'J':
@@ -353,7 +353,7 @@ lex (void)
       *p = 0;
       ungetc(c, finput);
       symval = getsym(token_buffer);
-      return (IDENTIFIER);
+      return IDENTIFIER;
 
     case '0':  case '1':  case '2':  case '3':  case '4':
     case '5':  case '6':  case '7':  case '8':  case '9':
@@ -372,7 +372,7 @@ lex (void)
 	  }
 	*p = 0;
 	ungetc(c, finput);
-	return (NUMBER);
+	return NUMBER;
       }
 
     case '\'':
@@ -405,7 +405,7 @@ lex (void)
 	symval->class = STOKEN;
 	if (! symval->user_token_number)
 	  symval->user_token_number = code;
-	return (IDENTIFIER);
+	return IDENTIFIER;
       }
 
     case '\"':
@@ -427,23 +427,23 @@ lex (void)
 	symval = getsym(token_buffer);
 	symval->class = STOKEN;
 
-	return (IDENTIFIER);
+	return IDENTIFIER;
       }
 
     case ',':
-      return (COMMA);
+      return COMMA;
 
     case ':':
-      return (COLON);
+      return COLON;
 
     case ';':
-      return (SEMICOLON);
+      return SEMICOLON;
 
     case '|':
-      return (BAR);
+      return BAR;
 
     case '{':
-      return (LEFT_CURLY);
+      return LEFT_CURLY;
 
     case '=':
       do
@@ -456,12 +456,12 @@ lex (void)
       if (c == '{')
 	{
 	  strcpy(token_buffer, "={");
-	  return(LEFT_CURLY);
+	  return LEFT_CURLY;
 	}
       else
 	{
 	  ungetc(c, finput);
-	  return(ILLEGAL);
+	  return ILLEGAL;
 	}
 
     case '<':
@@ -485,14 +485,14 @@ lex (void)
 	  c = getc(finput);
 	}
       *p = 0;
-      return (TYPENAME);
+      return TYPENAME;
 
 
     case '%':
-      return (parse_percent_token());
+      return parse_percent_token();
 
     default:
-      return (ILLEGAL);
+      return ILLEGAL;
     }
 }
 
@@ -570,28 +570,28 @@ parse_percent_token (void)
   switch (c)
     {
     case '%':
-      return (TWO_PERCENTS);
+      return TWO_PERCENTS;
 
     case '{':
-      return (PERCENT_LEFT_CURLY);
+      return PERCENT_LEFT_CURLY;
 
     case '<':
-      return (LEFT);
+      return LEFT;
 
     case '>':
-      return (RIGHT);
+      return RIGHT;
 
     case '2':
-      return (NONASSOC);
+      return NONASSOC;
 
     case '0':
-      return (TOKEN);
+      return TOKEN;
 
     case '=':
-      return (PREC);
+      return PREC;
     }
   if (!isalpha(c))
-    return (ILLEGAL);
+    return ILLEGAL;
 
   p = token_buffer;
   *p++ = '%';
