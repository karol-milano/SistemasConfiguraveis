@@ -150,7 +150,7 @@ output_short_or_char_table (struct obstack *oout,
 
       if (j >= 10)
 	{
-	  obstack_grow_string (oout, "\n  ");
+	  obstack_sgrow (oout, "\n  ");
 	  j = 1;
 	}
       else
@@ -161,7 +161,7 @@ output_short_or_char_table (struct obstack *oout,
       obstack_fgrow1 (oout, "%6d", short_table[i]);
     }
 
-  obstack_grow_string (oout, "\n};\n");
+  obstack_sgrow (oout, "\n};\n");
 }
 
 
@@ -234,7 +234,7 @@ output_headers (void)
   if (semantic_parser)
     obstack_fgrow1 (&action_obstack, ACTSTR, attrsfile_quoted);
   else
-    obstack_grow_string (&action_obstack, ACTSTR_SIMPLE);
+    obstack_sgrow (&action_obstack, ACTSTR_SIMPLE);
 
   /* Rename certain symbols if -p was specified.  */
   if (spec_name_prefix)
@@ -265,7 +265,7 @@ void
 output_trailers (void)
 {
   if (semantic_parser)
-    obstack_grow_string (&guard_obstack, "\n    }\n}\n");
+    obstack_sgrow (&guard_obstack, "\n    }\n}\n");
 
   obstack_1grow (&action_obstack, '\n');
 
@@ -273,9 +273,9 @@ output_trailers (void)
     return;
 
   if (semantic_parser)
-    obstack_grow_string (&action_obstack, "    }\n");
+    obstack_sgrow (&action_obstack, "    }\n");
 
-  obstack_grow_string (&action_obstack, "}\n");
+  obstack_sgrow (&action_obstack, "}\n");
 }
 
 
@@ -283,7 +283,7 @@ output_trailers (void)
 static void
 output_token_translations (void)
 {
-  obstack_grow_string (&table_obstack, "\
+  obstack_sgrow (&table_obstack, "\
 \n\
 /* YYRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */\n");
 
@@ -303,7 +303,7 @@ output_token_translations (void)
     }
   else
     {
-      obstack_grow_string (&table_obstack,
+      obstack_sgrow (&table_obstack,
 			   "\n#define YYTRANSLATE(x) (x)\n");
     }
 }
@@ -316,7 +316,7 @@ output_gram (void)
      yyprhs and yyrhs are needed only for yydebug. */
   /* With the no_parser option, all tables are generated */
   if (!semantic_parser && !no_parser_flag)
-    obstack_grow_string (&table_obstack, "\n#if YYDEBUG != 0\n");
+    obstack_sgrow (&table_obstack, "\n#if YYDEBUG != 0\n");
 
   output_short_table (&table_obstack, NULL, "yyprhs", rrhs,
 		      0, 1, nrules + 1);
@@ -339,7 +339,7 @@ output_gram (void)
   }
 
   if (!semantic_parser && !no_parser_flag)
-    obstack_grow_string (&table_obstack, "\n#endif\n");
+    obstack_sgrow (&table_obstack, "\n#endif\n");
 }
 
 
@@ -358,7 +358,7 @@ output_rule_data (void)
   int j;
   short *short_tab = NULL;
 
-  obstack_grow_string (&table_obstack, "\n\
+  obstack_sgrow (&table_obstack, "\n\
 #if YYDEBUG != 0\n");
 
   output_short_table (&table_obstack,
@@ -366,7 +366,7 @@ output_rule_data (void)
 		      "yyrline", rline,
 		      0, 1, nrules + 1);
 
-  obstack_grow_string (&table_obstack, "#endif\n\n");
+  obstack_sgrow (&table_obstack, "#endif\n\n");
 
   if (token_table_flag || no_parser_flag)
     {
@@ -380,11 +380,11 @@ output_rule_data (void)
 
   /* Output the table of symbol names.  */
   if (!token_table_flag && !no_parser_flag)
-    obstack_grow_string (&table_obstack,
+    obstack_sgrow (&table_obstack,
 			 "\n#if YYDEBUG != 0 || defined YYERROR_VERBOSE\n\n");
-  obstack_grow_string (&table_obstack, "\
+  obstack_sgrow (&table_obstack, "\
 /* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */\n");
-  obstack_grow_string (&table_obstack,
+  obstack_sgrow (&table_obstack,
 	   "static const char *const yytname[] =\n{\n  ");
 
   j = 0;
@@ -408,7 +408,7 @@ output_rule_data (void)
 
       if (j + strsize > 75)
 	{
-	  obstack_grow_string (&table_obstack, "\n  ");
+	  obstack_sgrow (&table_obstack, "\n  ");
 	  j = 2;
 	}
 
@@ -418,25 +418,25 @@ output_rule_data (void)
 	  if (*p == '"' || *p == '\\')
 	    obstack_fgrow1 (&table_obstack, "\\%c", *p);
 	  else if (*p == '\n')
-	    obstack_grow_string (&table_obstack, "\\n");
+	    obstack_sgrow (&table_obstack, "\\n");
 	  else if (*p == '\t')
-	    obstack_grow_string (&table_obstack, "\\t");
+	    obstack_sgrow (&table_obstack, "\\t");
 	  else if (*p == '\b')
-	    obstack_grow_string (&table_obstack, "\\b");
+	    obstack_sgrow (&table_obstack, "\\b");
 	  else if (*p < 040 || *p >= 0177)
 	    obstack_fgrow1 (&table_obstack, "\\%03o", *p);
 	  else
 	    obstack_1grow (&table_obstack, *p);
 	}
 
-      obstack_grow_string (&table_obstack, "\", ");
+      obstack_sgrow (&table_obstack, "\", ");
       j += strsize;
     }
   /* add a NULL entry to list of tokens */
-  obstack_grow_string (&table_obstack, "NULL\n};\n");
+  obstack_sgrow (&table_obstack, "NULL\n};\n");
 
   if (!token_table_flag && !no_parser_flag)
-    obstack_grow_string (&table_obstack, "#endif\n\n");
+    obstack_sgrow (&table_obstack, "#endif\n\n");
 
   /* Output YYTOKNUM. */
   if (token_table_flag)
@@ -1150,7 +1150,7 @@ output_parser (void)
   int actions_dumped = 0;
 
   if (pure_parser)
-    obstack_grow_string (&table_obstack, "#define YYPURE 1\n\n");
+    obstack_sgrow (&table_obstack, "#define YYPURE 1\n\n");
 
   /* Loop over lines in the standard parser file.  */
   if (semantic_parser)
@@ -1187,13 +1187,13 @@ output_parser (void)
 		if ((c = getc (fskel)) == 'e')
 		  line_type = sync_line;
 		else
-		  obstack_grow_string (&table_obstack, "#lin");
+		  obstack_sgrow (&table_obstack, "#lin");
 	      else
-		obstack_grow_string (&table_obstack, "#li");
+		obstack_sgrow (&table_obstack, "#li");
 	    else
-	      obstack_grow_string (&table_obstack, "#l");
+	      obstack_sgrow (&table_obstack, "#l");
 	  else
-	    obstack_grow_string (&table_obstack, "#");
+	    obstack_sgrow (&table_obstack, "#");
 	}
       else if (c == '%')
 	{
@@ -1209,23 +1209,23 @@ output_parser (void)
 			  if ((c = getc (fskel)) == 's')
 			    line_type = actions_line;
 			  else
-			    obstack_grow_string (&table_obstack, "%% action");
+			    obstack_sgrow (&table_obstack, "%% action");
 			else
-			  obstack_grow_string (&table_obstack, "%% actio");
+			  obstack_sgrow (&table_obstack, "%% actio");
 		      else
-			obstack_grow_string (&table_obstack, "%% acti");
+			obstack_sgrow (&table_obstack, "%% acti");
 		    else
-		      obstack_grow_string (&table_obstack, "%% act");
+		      obstack_sgrow (&table_obstack, "%% act");
 		  else
-		    obstack_grow_string (&table_obstack, "%% ac");
+		    obstack_sgrow (&table_obstack, "%% ac");
 		else
-		  obstack_grow_string (&table_obstack, "%% a");
+		  obstack_sgrow (&table_obstack, "%% a");
 	      else
-		obstack_grow_string (&table_obstack, "%% ");
+		obstack_sgrow (&table_obstack, "%% ");
 	    else
-	      obstack_grow_string (&table_obstack, "%%");
+	      obstack_sgrow (&table_obstack, "%%");
 	  else
-	    obstack_grow_string (&table_obstack, "%");
+	    obstack_sgrow (&table_obstack, "%");
 	}
 
       switch (line_type)
@@ -1317,7 +1317,7 @@ output (void)
     }
   reader_output_yylsp (&table_obstack);
   if (debug_flag)
-    obstack_grow_string (&table_obstack, "\
+    obstack_sgrow (&table_obstack, "\
 #ifndef YYDEBUG\n\
 # define YYDEBUG 1\n\
 #endif\n\
@@ -1328,10 +1328,10 @@ output (void)
 		    quotearg_style (c_quoting_style, attrsfile));
 
   if (!no_parser_flag)
-    obstack_grow_string (&table_obstack, "#include <stdio.h>\n\n");
+    obstack_sgrow (&table_obstack, "#include <stdio.h>\n\n");
 
   /* Make "const" do nothing if not in ANSI C.  */
-  obstack_grow_string (&table_obstack, "\
+  obstack_sgrow (&table_obstack, "\
 #ifndef __cplusplus\n\
 # ifndef __STDC__\n\
 #  define const\n\
