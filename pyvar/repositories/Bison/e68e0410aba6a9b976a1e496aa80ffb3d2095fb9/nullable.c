@@ -1,5 +1,5 @@
 /* Part of the bison parser generator,
-   Copyright 1984, 1989, 2000, 2001 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -26,11 +26,17 @@
 #include "system.h"
 #include "getargs.h"
 #include "symtab.h"
-#include "types.h"
 #include "gram.h"
 #include "reduce.h"
 #include "nullable.h"
 
+/* Linked list of rule numbers.  */
+typedef struct rule_list_s
+{
+  struct rule_list_s *next;
+  rule_number_t value;
+} rule_list_t;
+
 char *nullable = NULL;
 
 static void
@@ -49,16 +55,16 @@ set_nullable (void)
   rule_number_t ruleno;
   symbol_number_t *s1;
   symbol_number_t *s2;
-  shorts *p;
+  rule_list_t *p;
 
   symbol_number_t *squeue = XCALLOC (symbol_number_t, nvars);
   short *rcount = XCALLOC (short, nrules + 1);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
-  shorts **rsets = XCALLOC (shorts *, nvars) - ntokens;
+  rule_list_t **rsets = XCALLOC (rule_list_t *, nvars) - ntokens;
   /* This is said to be more elements than we actually use.
      Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
-  shorts *relts = XCALLOC (shorts, nritems + nvars + 1);
+  rule_list_t *relts = XCALLOC (rule_list_t, nritems + nvars + 1);
 
   if (trace_flag)
     fprintf (stderr, "Entering set_nullable\n");
