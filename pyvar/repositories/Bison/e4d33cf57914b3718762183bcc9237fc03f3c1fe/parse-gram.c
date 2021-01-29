@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.6.3.74-5ca2.  */
+/* A Bison parser, made by GNU Bison 3.6.3.87-3efc5-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.6.3.74-5ca2"
+#define YYBISON_VERSION "3.6.3.87-3efc5-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -257,17 +257,20 @@ typedef enum yysymbol_kind_t yysymbol_kind_t;
   static char *strip_braces (char *code);
 
   /* Convert CODE by calling code_props_plain_init if PLAIN, otherwise
-     code_props_symbol_action_init.  Call
+     code_props_symbol_action_init.  Calls
      gram_scanner_last_string_free to release the latest string from
      the scanner (should be CODE). */
   static char const *translate_code (char *code, location loc, bool plain);
 
   /* Convert CODE by calling code_props_plain_init after having
      stripped the first and last characters (expected to be '{', and
-     '}').  Call gram_scanner_last_string_free to release the latest
+     '}').  Calls gram_scanner_last_string_free to release the latest
      string from the scanner (should be CODE). */
   static char const *translate_code_braceless (char *code, location loc);
 
+  /* Handle a %defines directive.  */
+  static void handle_defines (char const *value);
+
   /* Handle a %error-verbose directive.  */
   static void handle_error_verbose (location const *loc, char const *directive);
 
@@ -276,6 +279,9 @@ typedef enum yysymbol_kind_t yysymbol_kind_t;
                                   location const *dir_loc,
                                   char const *directive, char const *value);
 
+  /* Handle a %language directive.  */
+  static void handle_language (location const *loc, char const *lang);
+
   /* Handle a %name-prefix directive.  */
   static void handle_name_prefix (location const *loc,
                                   char const *directive, char const *value);
@@ -302,6 +308,13 @@ typedef enum yysymbol_kind_t yysymbol_kind_t;
   static void tron (FILE *yyo);
   static void troff (FILE *yyo);
 
+  /* Interpret a quoted string (such as `"Hello, \"World\"\n\""`).
+     Manages the memory of the result.  */
+  static char *unquote (const char *str);
+
+  /* Discard the latest unquoted string.  */
+  static void unquote_free (char *last_string);
+
   /** Add a lex-param and/or a parse-param.
    *
    * \param type  where to push this formal argument.
@@ -621,19 +634,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   287,   287,   296,   297,   301,   302,   308,   312,   317,
-     318,   323,   324,   325,   326,   327,   332,   337,   338,   339,
-     340,   341,   342,   342,   343,   344,   345,   346,   347,   348,
-     349,   350,   354,   355,   364,   365,   369,   380,   384,   388,
-     396,   406,   407,   417,   418,   424,   437,   437,   442,   442,
-     447,   451,   461,   462,   463,   464,   468,   469,   474,   475,
-     479,   480,   484,   485,   486,   499,   508,   512,   516,   524,
-     525,   529,   542,   543,   548,   549,   550,   568,   572,   576,
-     584,   586,   591,   598,   608,   612,   616,   624,   629,   641,
-     642,   648,   649,   650,   657,   657,   665,   666,   667,   672,
-     675,   677,   679,   681,   683,   685,   687,   689,   691,   696,
-     697,   706,   730,   731,   732,   733,   745,   747,   771,   776,
-     777,   782,   790,   791
+       0,   308,   308,   317,   318,   322,   323,   329,   333,   338,
+     339,   340,   341,   342,   343,   344,   349,   354,   355,   356,
+     357,   358,   359,   359,   360,   361,   362,   363,   364,   365,
+     366,   367,   371,   372,   381,   382,   386,   397,   401,   405,
+     413,   423,   424,   434,   435,   441,   454,   454,   459,   459,
+     464,   468,   478,   479,   480,   481,   485,   486,   491,   492,
+     496,   497,   501,   502,   503,   516,   525,   529,   533,   541,
+     542,   546,   559,   560,   565,   566,   567,   585,   589,   593,
+     601,   603,   608,   615,   625,   629,   633,   641,   646,   658,
+     659,   665,   666,   667,   674,   674,   682,   683,   684,   689,
+     692,   694,   696,   698,   700,   702,   704,   706,   708,   713,
+     714,   723,   747,   748,   749,   750,   762,   764,   788,   793,
+     794,   799,   807,   808
 };
 #endif
 
@@ -2081,10 +2094,7 @@ yyreduce:
     break;
 
   case 10: /* prologue_declaration: "%defines" "string"  */
-    {
-      defines_flag = true;
-      spec_header_file = xstrdup ((yyvsp[0].STRING));
-    }
+                                   { handle_defines ((yyvsp[0].STRING)); }
     break;
 
   case 11: /* prologue_declaration: "%error-verbose"  */
@@ -2118,7 +2128,7 @@ yyreduce:
     break;
 
   case 17: /* prologue_declaration: "%language" "string"  */
-                                { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
+                                { handle_language (&(yylsp[-1]), (yyvsp[0].STRING)); }
     break;
 
   case 18: /* prologue_declaration: "%name-prefix" "string"  */
@@ -2134,7 +2144,7 @@ yyreduce:
     break;
 
   case 21: /* prologue_declaration: "%output" "string"  */
-                                { spec_outfile = (yyvsp[0].STRING); }
+                                { spec_outfile = unquote ((yyvsp[0].STRING)); gram_scanner_last_string_free (); }
     break;
 
   case 22: /* $@1: %empty  */
@@ -2387,7 +2397,7 @@ yyreduce:
 
   case 76: /* alias: "translatable string"  */
     {
-      (yyval.alias) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].TSTRING)), (yylsp[0]));
+      (yyval.alias) = symbol_get ((yyvsp[0].TSTRING), (yylsp[0]));
       symbol_class_set ((yyval.alias), token_sym, (yylsp[0]), false);
       (yyval.alias)->translatable = true;
     }
@@ -2543,11 +2553,11 @@ yyreduce:
     break;
 
   case 114: /* value: "string"  */
-          { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
+          { (yyval.value).kind = muscle_string;  (yyval.value).chars = unquote ((yyvsp[0].STRING)); gram_scanner_last_string_free ();}
     break;
 
   case 115: /* value: "{...}"  */
-          { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
+          { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); gram_scanner_last_string_free (); }
     break;
 
   case 116: /* id: "identifier"  */
@@ -2583,7 +2593,7 @@ yyreduce:
 
   case 121: /* string_as_id: "string"  */
     {
-      (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
+      (yyval.string_as_id) = symbol_get ((yyvsp[0].STRING), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
     break;
@@ -2940,6 +2950,17 @@ add_param (param_type type, char *decl, location loc)
 }
 
 
+static void
+handle_defines (char const *value)
+{
+  defines_flag = true;
+  char *file = unquote (value);
+  spec_header_file = xstrdup (file);
+  gram_scanner_last_string_free ();
+  unquote_free (file);
+}
+
+
 static void
 handle_error_verbose (location const *loc, char const *directive)
 {
@@ -2952,8 +2973,9 @@ handle_error_verbose (location const *loc, char const *directive)
 static void
 handle_file_prefix (location const *loc,
                     location const *dir_loc,
-                    char const *directive, char const *value)
+                    char const *directive, char const *value_quoted)
 {
+  char *value = unquote (value_quoted);
   bison_directive (loc, directive);
   bool warned = false;
 
@@ -2973,11 +2995,18 @@ handle_file_prefix (location const *loc,
     deprecated_directive (dir_loc, directive, "%file-prefix");
 }
 
+static void
+handle_language (location const *loc, char const *lang)
+{
+  language_argmatch (unquote (lang), grammar_prio, *loc);
+}
+
 
 static void
 handle_name_prefix (location const *loc,
-                    char const *directive, char const *value)
+                    char const *directive, char const *value_quoted)
 {
+  char *value = unquote (value_quoted);
   bison_directive (loc, directive);
 
   char buf1[1024];
@@ -3049,34 +3078,39 @@ str_to_version (char const *version)
 
 
 static void
-handle_require (location const *loc, char const *version)
+handle_require (location const *loc, char const *version_quoted)
 {
+  char *version = unquote (version_quoted);
   required_version = str_to_version (version);
   if (required_version == -1)
     {
       complain (loc, complaint, _("invalid version requirement: %s"),
                 version);
       required_version = 0;
-      return;
     }
-
-  /* Pretend to be at least that version, to check features published
-     in that version while developping it.  */
-  const char* api_version = "3.6";
-  const char* package_version =
-    0 < strverscmp (api_version, PACKAGE_VERSION)
-    ? api_version : PACKAGE_VERSION;
-  if (0 < strverscmp (version, package_version))
+  else
     {
-      complain (loc, complaint, _("require bison %s, but have %s"),
-                version, package_version);
-      exit (EX_MISMATCH);
+      /* Pretend to be at least that version, to check features published
+         in that version while developping it.  */
+      const char* api_version = "3.6";
+      const char* package_version =
+        0 < strverscmp (api_version, PACKAGE_VERSION)
+        ? api_version : PACKAGE_VERSION;
+      if (0 < strverscmp (version, package_version))
+        {
+          complain (loc, complaint, _("require bison %s, but have %s"),
+                    version, package_version);
+          exit (EX_MISMATCH);
+        }
     }
+  unquote_free (version);
+  gram_scanner_last_string_free ();
 }
 
 static void
-handle_skeleton (location const *loc, char const *skel)
+handle_skeleton (location const *loc, char const *skel_quoted)
 {
+  char *skel = unquote (skel_quoted);
   char const *skeleton_user = skel;
   if (strchr (skeleton_user, '/'))
     {
@@ -3157,3 +3191,95 @@ static void troff (FILE *yyo)
 {
   end_use_class ("value", yyo);
 }
+
+
+/*----------.
+| Unquote.  |
+`----------*/
+
+struct obstack obstack_for_unquote;
+
+void
+parser_init (void)
+{
+  obstack_init (&obstack_for_unquote);
+}
+
+void
+parser_free (void)
+{
+  obstack_free (&obstack_for_unquote, 0);
+}
+
+static void
+unquote_free (char *last_string)
+{
+  obstack_free (&obstack_for_unquote, last_string);
+}
+
+static char *
+unquote (const char *cp)
+{
+#define GROW(Char)                              \
+  obstack_1grow (&obstack_for_unquote, Char);
+  for (++cp; *cp && *cp != '"'; ++cp)
+    switch (*cp)
+      {
+      case '"':
+        break;
+      case '\\':
+        ++cp;
+        switch (*cp)
+          {
+          case '0': case '1': case '2': case '3': case '4':
+          case '5': case '6': case '7': case '8': case '9':
+            {
+              int c = cp[0] - '0';
+              if (c_isdigit (cp[1]))
+                {
+                  ++cp;
+                  c = c * 8 + cp[0] - '0';
+                }
+              if (c_isdigit (cp[1]))
+                {
+                  ++cp;
+                  c = c * 8 + cp[0] - '0';
+                }
+              GROW (c);
+            }
+            break;
+
+          case 'a': GROW ('\a'); break;
+          case 'b': GROW ('\b'); break;
+          case 'f': GROW ('\f'); break;
+          case 'n': GROW ('\n'); break;
+          case 'r': GROW ('\r'); break;
+          case 't': GROW ('\t'); break;
+          case 'v': GROW ('\v'); break;
+
+          case 'x':
+            {
+              int c = 0;
+              while (c_isxdigit (cp[1]))
+                {
+                  ++cp;
+                  c = (c * 16 + (c_isdigit (cp[0]) ? cp[0] - '0'
+                                 : c_isupper (cp[0]) ? cp[0] - 'A'
+                                 : cp[0] - '0'));
+                }
+              GROW (c);
+              break;
+            }
+          }
+        break;
+
+      default:
+        GROW (*cp);
+        break;
+      }
+  assert (*cp == '"');
+  ++cp;
+  assert (*cp == '\0');
+#undef GROW
+  return obstack_finish0 (&obstack_for_unquote);
+}
