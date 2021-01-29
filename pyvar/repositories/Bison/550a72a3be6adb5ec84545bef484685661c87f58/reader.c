@@ -195,23 +195,43 @@ copy_string (FILE *fin, FILE *fout, int match)
 }
 
 
-/*---------------------------------------------------------------.
-| Dump the comment from IN to OUT1 and OUT2.  C is either `*' or |
-| `/', depending upon the type of comments used.  OUT2 might be  |
-| NULL.                                                          |
-`---------------------------------------------------------------*/
+/*----------------------------------------------------------------.
+| Dump the wannabee comment from IN to OUT1 and OUT2.  In fact we |
+| just saw a `/', which might or might not be a comment.  In any  |
+| case, copy what we saw.                                         |
+|                                                                 |
+| OUT2 might be NULL.                                             |
+`----------------------------------------------------------------*/
 
 static inline void
-copy_comment2 (FILE *in, FILE *out1, FILE *out2, int c)
+copy_comment2 (FILE *fin, FILE *out1, FILE *out2)
 {
   int cplus_comment;
   int ended;
+  int c;
+
+  /* We read a `/', output it. */
+  putc ('/', out1);
+  if (out2)
+    putc ('/', out2);
+
+  switch ((c = getc (fin)))
+    {
+    case '/':
+      cplus_comment = 1;
+      break;
+    case '*':
+      cplus_comment = 0;
+      break;
+    default:
+      ungetc (c, fin);
+      return;
+    }
 
-  cplus_comment = (c == '/');
   putc (c, out1);
   if (out2)
     putc (c, out2);
-  c = getc (in);
+  c = getc (fin);
 
   ended = 0;
   while (!ended)
@@ -223,7 +243,7 @@ copy_comment2 (FILE *in, FILE *out1, FILE *out2, int c)
 	      putc (c, out1);
 	      if (out2)
 		putc (c, out2);
-	      c = getc (in);
+	      c = getc (fin);
 	    }
 
 	  if (c == '/')
@@ -243,7 +263,7 @@ copy_comment2 (FILE *in, FILE *out1, FILE *out2, int c)
 	  if (cplus_comment)
 	    ended = 1;
 	  else
-	    c = getc (in);
+	    c = getc (fin);
 	}
       else if (c == EOF)
 	fatal (_("unterminated comment"));
@@ -252,21 +272,21 @@ copy_comment2 (FILE *in, FILE *out1, FILE *out2, int c)
 	  putc (c, out1);
 	  if (out2)
 	    putc (c, out2);
-	  c = getc (in);
+	  c = getc (fin);
 	}
     }
 }
 
 
-/*------------------------------------------------------------.
-| Dump the comment from FIN to FOUT.  C is either `*' or `/', |
-| depending upon the type of comments used.                   |
-`------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| Dump the comment (actually the current string starting with a `/') |
+| from FIN to FOUT.                                                  |
+`-------------------------------------------------------------------*/
 
 static inline void
-copy_comment (FILE *fin, FILE *fout, int c)
+copy_comment (FILE *fin, FILE *fout)
 {
-  copy_comment2 (fin, fout, NULL, c);
+  copy_comment2 (fin, fout, NULL);
 }
 
 
@@ -416,11 +436,7 @@ copy_definition (void)
 	  break;
 
 	case '/':
-	  putc (c, fattrs);
-	  c = getc (finput);
-	  if (c != '*' && c != '/')
-	    continue;
-	  copy_comment (finput, fattrs, c);
+	  copy_comment (finput, fattrs);
 	  break;
 
 	case EOF:
@@ -732,13 +748,9 @@ parse_union_decl (void)
 	  break;
 
 	case '/':
-	  c = getc (finput);
-	  if (c != '*' && c != '/')
-	    continue;
-	  copy_comment2 (finput, fattrs, fdefines, c);
+	  copy_comment2 (finput, fattrs, fdefines);
 	  break;
 
-
 	case '{':
 	  count++;
 	  break;
@@ -1011,11 +1023,7 @@ copy_action (symbol_list *rule, int stack_offset)
 	      break;
 
 	    case '/':
-	      putc (c, faction);
-	      c = getc (finput);
-	      if (c != '*' && c != '/')
-		continue;
-	      copy_comment (finput, faction, c);
+	      copy_comment (finput, faction);
 	      break;
 
 	    case '$':
@@ -1108,11 +1116,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 	  break;
 
 	case '/':
-	  putc (c, fguard);
-	  c = getc (finput);
-	  if (c != '*' && c != '/')
-	    continue;
-	  copy_comment (finput, fguard, c);
+	  copy_comment (finput, fguard);
 	  break;
 
 	case '$':
