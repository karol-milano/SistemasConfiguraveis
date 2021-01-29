@@ -25,7 +25,6 @@
 #include "symtab.h"
 #include "options.h"
 #include "lex.h"
-#include "xalloc.h"
 #include "complain.h"
 #include "gram.h"
 #include "quote.h"
@@ -37,15 +36,24 @@ const char *token_buffer = NULL;
 bucket *symval;
 int numval;
 
-static int unlexed;		/* these two describe a token to be reread */
-static bucket *unlexed_symval;	/* by the next call to lex */
+/* these two describe a token to be reread */
+static token_t unlexed = tok_undef;
+/* by the next call to lex */
+static bucket *unlexed_symval = NULL;
 
 
 void
-init_lex (void)
+lex_init (void)
 {
   obstack_init (&token_obstack);
-  unlexed = -1;
+  unlexed = tok_undef;
+}
+
+
+void
+lex_free (void)
+{
+  obstack_free (&token_obstack, NULL);
 }
 
 
@@ -314,7 +322,7 @@ literalchar (struct obstack *out, int *pcode, char term)
 
 
 void
-unlex (int token)
+unlex (token_t token)
 {
   unlexed = token;
   unlexed_symval = symval;
@@ -357,12 +365,12 @@ lex (void)
   /* Just to make sure. */
   token_buffer = NULL;
 
-  if (unlexed >= 0)
+  if (unlexed != tok_undef)
     {
+      token_t res = unlexed;
       symval = unlexed_symval;
-      c = unlexed;
-      unlexed = -1;
-      return c;
+      unlexed = tok_undef;
+      return res;
     }
 
   c = skip_white_space ();
@@ -418,7 +426,6 @@ lex (void)
     case '\'':
       /* parse the literal token and compute character code in  code  */
 
-      translations = -1;
       {
 	int code, discode;
 
@@ -446,7 +453,6 @@ lex (void)
     case '\"':
       /* parse the literal string token and treat as an identifier */
 
-      translations = -1;
       {
 	int code;		/* ignored here */
 
@@ -464,32 +470,40 @@ lex (void)
       }
 
     case ',':
+      token_buffer = ",";
       return tok_comma;
 
     case ':':
+      token_buffer = ":";
       return tok_colon;
 
     case ';':
+      token_buffer = ";";
       return tok_semicolon;
 
     case '|':
+      token_buffer = "|";
       return tok_bar;
 
     case '{':
+      token_buffer = "{";
       return tok_left_curly;
 
     case '=':
+      obstack_1grow (&token_obstack, c);
       do
 	{
 	  c = getc (finput);
+	  obstack_1grow (&token_obstack, c);
 	  if (c == '\n')
 	    lineno++;
 	}
       while (c == ' ' || c == '\n' || c == '\t');
+      obstack_1grow (&token_obstack, '\0');
+      token_buffer = obstack_finish (&token_obstack);
 
       if (c == '{')
 	{
-	  token_buffer = "={";
 	  return tok_left_curly;
 	}
       else
@@ -506,6 +520,9 @@ lex (void)
       return parse_percent_token ();
 
     default:
+      obstack_1grow (&token_obstack, c);
+      obstack_1grow (&token_obstack, '\0');
+      token_buffer = obstack_finish (&token_obstack);
       return tok_illegal;
     }
 }
@@ -516,28 +533,28 @@ lex (void)
 static int
 option_strcmp (const char *left, const char *right)
 {
-    const unsigned char *l, *r;
-    int c;
-
-    assert(left != NULL && right != NULL);     
-    l = (const unsigned char *)left;
-    r = (const unsigned char *)right;
-    while (((c = *l - *r++) == 0 && *l != '\0')
-	   || ((*l == '-' || *l == '_') && (*r == '_' || *r == '-')))
-        l++;
-    return c;
+  const unsigned char *l, *r;
+  int c;
+
+  assert (left);
+  assert (right);
+  l = (const unsigned char *)left;
+  r = (const unsigned char *)right;
+  while (((c = *l - *r++) == 0 && *l != '\0')
+	 || ((*l == '-' || *l == '_') && (*r == '_' || *r == '-')))
+    l++;
+  return c;
 }
 
 /* Parse a token which starts with %.
    Assumes the % has already been read and discarded.  */
 
-int
+token_t
 parse_percent_token (void)
 {
-  int c;
   const struct option_table_struct *tx;
 
-  c = getc (finput);
+  int c = getc (finput);
 
   switch (c)
     {
@@ -601,6 +618,10 @@ parse_percent_token (void)
     case tok_obsolete:
       fatal (_("`%s' is no longer supported"), token_buffer);
       break;
+
+    default:
+      /* Other cases do not apply here. */
+      break;
     }
 
   return tx->ret_val;
