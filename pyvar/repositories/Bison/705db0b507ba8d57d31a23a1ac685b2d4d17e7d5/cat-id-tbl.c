@@ -0,0 +1,187 @@
+/* Automatically generated by po2tbl.sed from bison.pot.  */
+
+#if HAVE_CONFIG_H
+# include <config.h>
+#endif
+
+#include "libgettext.h"
+
+const struct _msg_ent _msg_tbl[] = {
+  {"", 1},
+  {"too many states (max %d)", 2},
+  {"Conflict in state %d between rule %d and token %s resolved as %s.\n", 3},
+  {"reduce", 4},
+  {"shift", 5},
+  {"an error", 6},
+  {" 1 shift/reduce conflict", 7},
+  {" %d shift/reduce conflicts", 8},
+  {" and", 9},
+  {" 1 reduce/reduce conflict", 10},
+  {" %d reduce/reduce conflicts", 11},
+  {"State %d contains", 12},
+  {"conflicts: ", 13},
+  {" %d shift/reduce", 14},
+  {" %d reduce/reduce", 15},
+  {"%s contains", 16},
+  {"    %-4s\t[reduce using rule %d (%s)]\n", 17},
+  {"\
+    $default\treduce using rule %d (%s)\n\
+\n", 18},
+  {"    %-4s\treduce using rule %d (%s)\n", 19},
+  {"    $default\treduce using rule %d (%s)\n", 20},
+  {"DERIVES", 21},
+  {"%s derives", 22},
+  {"GNU bison generates parsers for LALR(1) grammars.\n", 23},
+  {"Usage: %s [OPTION]... FILE\n", 24},
+  {"\
+If a long option shows an argument as mandatory, then it is mandatory\n\
+for the equivalent short option also.  Similarly for optional arguments.\n", 25},
+  {"\
+Operation modes:\n\
+  -h, --help      display this help and exit\n\
+  -V, --version   output version information and exit\n\
+  -y, --yacc      emulate POSIX yacc\n", 26},
+  {"\
+Parser:\n\
+  -t, --debug                instrument the parser for debugging\n\
+      --locations            enable locations computation\n\
+  -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
+  -l, --no-lines             don't generate `#line' directives\n\
+  -n, --no-parser            generate the tables only\n\
+  -r, --raw                  number the tokens from 3\n\
+  -k, --token-table          include a table of token names\n", 27},
+  {"\
+Output:\n\
+  -d, --defines              also produce a header file\n\
+  -v, --verbose              also produce an explanation of the automaton\n\
+  -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
+  -o, --output-file=FILE     leave output to FILE\n", 28},
+  {"Report bugs to <bug-bison@gnu.org>.\n", 29},
+  {"bison (GNU Bison) %s", 30},
+  {"Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.\n", 31},
+  {"\
+This is free software; see the source for copying conditions.  There is NO\n\
+warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n", 32},
+  {"Try `%s --help' for more information.\n", 33},
+  {"%s: no grammar file given\n", 34},
+  {"%s: extra arguments ignored after `%s'\n", 35},
+  {"too many gotos (max %d)", 36},
+  {"unexpected `/' found and ignored", 37},
+  {"unterminated comment", 38},
+  {"unexpected end of file", 39},
+  {"unescaped newline in constant", 40},
+  {"octal value outside range 0...255: `\\%o'", 41},
+  {"hexadecimal value above 255: `\\x%x'", 42},
+  {"unknown escape sequence: `\\' followed by `%s'", 43},
+  {"unterminated type name at end of file", 44},
+  {"unterminated type name", 45},
+  {"use \"...\" for multi-character literal tokens", 46},
+  {"%s: internal error: %s\n", 47},
+  {"Entering set_nullable", 48},
+  {"maximum table size (%d) exceeded", 49},
+  {" type %d is %s\n", 50},
+  {"   (rule %d)", 51},
+  {"    $default\taccept\n", 52},
+  {"    NO ACTIONS\n", 53},
+  {"    $   \tgo to state %d\n", 54},
+  {"    %-4s\tshift, and go to state %d\n", 55},
+  {"    %-4s\terror (nonassociative)\n", 56},
+  {"    %-4s\tgo to state %d\n", 57},
+  {"state %d", 58},
+  {"Grammar", 59},
+  {"rule %-4d %s ->", 60},
+  {"\t\t/* empty */", 61},
+  {"Terminals, with rules where they appear", 62},
+  {"Nonterminals, with rules where they appear", 63},
+  {" on left:", 64},
+  {" on right:", 65},
+  {"   Skipping to next \\n", 66},
+  {"   Skipping to next %c", 67},
+  {"invalid $ value", 68},
+  {"unterminated string at end of file", 69},
+  {"unterminated string", 70},
+  {"%s is invalid", 71},
+  {"$$ of `%s' has no declared type", 72},
+  {"$%d of `%s' has no declared type", 73},
+  {"unterminated `%{' definition", 74},
+  {"Premature EOF after %s", 75},
+  {"symbol `%s' used more than once as a literal string", 76},
+  {"symbol `%s' given more than one literal string", 77},
+  {"symbol %s redefined", 78},
+  {"type redeclaration for %s", 79},
+  {"`%s' is invalid in %s", 80},
+  {"multiple %s declarations", 81},
+  {"invalid %s declaration", 82},
+  {"%type declaration has no <typename>", 83},
+  {"invalid %%type declaration due to item: %s", 84},
+  {"redefining precedence of %s", 85},
+  {"invalid text (%s) - number should be after identifier", 86},
+  {"unexpected item: %s", 87},
+  {"unmatched %s", 88},
+  {"argument of %%expect is not an integer", 89},
+  {"unrecognized item %s, expected an identifier", 90},
+  {"expected string constant instead of %s", 91},
+  {"unrecognized: %s", 92},
+  {"no input grammar", 93},
+  {"unknown character: %s", 94},
+  {"unterminated %guard clause", 95},
+  {"ill-formed rule: initial symbol not followed by colon", 96},
+  {"grammar starts with vertical bar", 97},
+  {"rule given for %s, which is a token", 98},
+  {"two @prec's in a row", 99},
+  {"%%guard present but %%semantic_parser not specified", 100},
+  {"two actions at end of one rule", 101},
+  {"type clash (`%s' `%s') on default action", 102},
+  {"empty rule for typed nonterminal, and no action", 103},
+  {"invalid input: %s", 104},
+  {"too many symbols (tokens plus nonterminals); maximum %d", 105},
+  {"no rules in the input grammar", 106},
+  {"symbol %s is used, but is not defined as a token and has no rules", 107},
+  {"conflicting precedences for %s and %s", 108},
+  {"conflicting assoc values for %s and %s", 109},
+  {"tokens %s and %s both assigned number %d", 110},
+  {"the start symbol %s is undefined", 111},
+  {"the start symbol %s is a token", 112},
+  {"Useless nonterminals:", 113},
+  {"Terminals which are not used:", 114},
+  {"Useless rules:", 115},
+  {"\
+Variables\n\
+---------\n\
+\n", 116},
+  {"Value  Sprec    Sassoc    Tag\n", 117},
+  {"\
+Rules\n\
+-----\n\
+\n", 118},
+  {"\
+Rules interpreted\n\
+-----------------\n\
+\n", 119},
+  {"%d rules never reduced\n", 120},
+  {"%s contains ", 121},
+  {"%d useless nonterminal%s", 122},
+  {" and ", 123},
+  {"%d useless rule%s", 124},
+  {"Start symbol %s does not derive any sentence", 125},
+  {"\
+reduced %s defines %d terminal%s, %d nonterminal%s, and %d production%s.\n", 126},
+  {"Unknown system error", 127},
+  {"%s: option `%s' is ambiguous\n", 128},
+  {"%s: option `--%s' doesn't allow an argument\n", 129},
+  {"%s: option `%c%s' doesn't allow an argument\n", 130},
+  {"%s: option `%s' requires an argument\n", 131},
+  {"%s: unrecognized option `--%s'\n", 132},
+  {"%s: unrecognized option `%c%s'\n", 133},
+  {"%s: illegal option -- %c\n", 134},
+  {"%s: invalid option -- %c\n", 135},
+  {"%s: option requires an argument -- %c\n", 136},
+  {"%s: option `-W %s' is ambiguous\n", 137},
+  {"%s: option `-W %s' doesn't allow an argument\n", 138},
+  {"memory exhausted", 139},
+  {"`", 140},
+  {"'", 141},
+  {"Memory exhausted", 142},
+};
+
+int _msg_tbl_length = 142;
