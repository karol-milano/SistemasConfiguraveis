@@ -21,7 +21,6 @@
 #include "system.h"
 #include "getargs.h"
 #include "files.h"
-#include "getopt.h"		/* for optarg */
 #include "symtab.h"
 #include "options.h"
 #include "lex.h"
@@ -31,7 +30,7 @@
 
 /* Buffer for storing the current token.  */
 static struct obstack token_obstack;
-const char *token_buffer = NULL;
+char *token_buffer = NULL;
 
 bucket *symval;
 int numval;
@@ -39,7 +38,7 @@ int numval;
 /* A token to be reread, see unlex and lex. */
 static token_t unlexed = tok_undef;
 static bucket *unlexed_symval = NULL;
-static const char *unlexed_token_buffer = NULL;
+static char *unlexed_token_buffer = NULL;
 
 void
 lex_init (void)
@@ -428,7 +427,7 @@ lex (void)
       /* parse the literal token and compute character code in  code  */
 
       {
-	int code, discode;
+	int code;
 
 	obstack_1grow (&token_obstack, '\'');
 	literalchar (&token_obstack, &code, '\'');
@@ -436,6 +435,7 @@ lex (void)
 	c = getc (finput);
 	if (c != '\'')
 	  {
+	    int discode;
 	    complain (_("use \"...\" for multi-character literal tokens"));
 	    while (1)
 	      if (!literalchar (0, &discode, '\''))
@@ -553,7 +553,10 @@ option_strcmp (const char *left, const char *right)
 token_t
 parse_percent_token (void)
 {
-  const struct option_table_struct *tx;
+  const struct option_table_struct *tx = NULL;
+  /* Where `=' was found in token_buffer. */
+  size_t equal_offset = 0;
+  char *arg = NULL;
 
   int c = getc (finput);
 
@@ -565,6 +568,8 @@ parse_percent_token (void)
     case '{':
       return tok_percent_left_curly;
 
+      /* FIXME: Who the heck are those 5 guys!?! `%<' = `%left'!!!
+	 Let's ask for there removal.  */
     case '<':
       return tok_left;
 
@@ -593,9 +598,33 @@ parse_percent_token (void)
       c = getc (finput);
     }
 
-  ungetc (c, finput);
+  if (c == '=')
+    {
+      equal_offset = obstack_object_size (&token_obstack);
+      obstack_1grow (&token_obstack, c);
+      c = getc (finput);
+      if (c = '"')
+	{
+	  int code;             /* ignored here */
+
+	  obstack_1grow (&token_obstack, '"');
+	  /* Read up to and including ".  */
+	  while (literalchar (&token_obstack, &code, '"'))
+	    /* nothing */;
+	}
+    }
+  else
+    ungetc (c, finput);
+
   obstack_1grow (&token_obstack, '\0');
   token_buffer = obstack_finish (&token_obstack);
+  if (equal_offset)
+    {
+      /* %token_buffer="arg" */
+      arg = token_buffer + equal_offset + 2;
+      arg[strlen (arg) - 1] = '\0';
+      token_buffer[equal_offset] = '\0';
+    }
 
   /* table lookup % directive */
   for (tx = option_table; tx->name; tx++)
@@ -603,27 +632,42 @@ parse_percent_token (void)
 	&& option_strcmp (token_buffer + 1, tx->name) == 0)
       break;
 
-  if (tx->set_flag)
-    {
-      *((int *) (tx->set_flag)) = 1;
-      return tok_noop;
-    }
+  if (arg && !tx->ret_val == tok_stropt)
+    fatal (_("`%s' supports no argument: %s"), token_buffer, quotearg (arg));
+
 
   switch (tx->ret_val)
     {
-    case tok_setopt:
-      *((char **) (tx->set_flag)) = optarg;
+    case tok_stropt:
+      assert (tx->set_flag);
+      if (arg)
+	{
+	  /* Keep only the first assignment: command line options have
+	     already been processed, and we want them to have
+	     precedence.  Side effect: if this %-option is used
+	     several times, only the first is honored.  Bah.  */
+	  if (!*((char **) (tx->set_flag)))
+	    *((char **) (tx->set_flag)) = arg;
+	}
+      else
+	fatal (_("`%s' requires an argument"), token_buffer);
+      return tok_noop;
+      break;
+
+    case tok_intopt:
+      assert (tx->set_flag);
+      *((int *) (tx->set_flag)) = 1;
       return tok_noop;
       break;
 
     case tok_obsolete:
       fatal (_("`%s' is no longer supported"), token_buffer);
+      return tok_noop;
       break;
 
     default:
-      /* Other cases do not apply here. */
+      return tx->ret_val;
       break;
     }
-
-  return tx->ret_val;
+  abort ();
 }
