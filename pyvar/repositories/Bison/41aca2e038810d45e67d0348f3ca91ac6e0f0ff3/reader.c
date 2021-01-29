@@ -1,30 +1,31 @@
 /* Input parser for bison
-   Copyright (C) 1984, 1986, 1989, 1992, 1998 Free Software Foundation, Inc.
+   Copyright (C) 1984, 86, 89, 92, 98, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to
+   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
 
 
-/* read in the grammar specification and record it in the format described in gram.h.
-  All guards are copied into the fguard file and all actions into faction,
-  in each case forming the body of a C function (yyguard or yyaction)
-  which contains a switch statement to decide which guard or action to execute.
+/* Read in the grammar specification and record it in the format
+   described in gram.h.  All guards are copied into the fguard file
+   and all actions into faction, in each case forming the body of a C
+   function (yyguard or yyaction) which contains a switch statement to
+   decide which guard or action to execute.
 
-The entry point is reader().  */
+   The entry point is reader ().  */
 
 #include <stdio.h>
 #include "system.h"
@@ -239,9 +240,9 @@ reader_output_yylsp (FILE *f)
     fprintf(f, LTYPESTR);
 }
 
-/* read from finput until %% is seen.  Discard the %%.
-Handle any % declarations,
-and copy the contents of any %{ ... %} groups to fattrs.  */
+/* Read from finput until `%%' is seen.  Discard the `%%'.  Handle any
+   `%' declarations, and copy the contents of any `%{ ... %}' groups
+   to fattrs.  */
 
 void
 read_declarations (void)
@@ -973,12 +974,12 @@ get_type_name (int n, symbol_list *rule)
 }
 
 
-/* after %guard is seen in the input file,
-copy the actual guard into the guards file.
-If the guard is followed by an action, copy that into the actions file.
-stack_offset is the number of values in the current rule so far,
-which says where to find $0 with respect to the top of the stack,
-for the simple parser in which the stack is not popped until after the guard is run.  */
+/* After `%guard' is seen in the input file, copy the actual guard
+   into the guards file.  If the guard is followed by an action, copy
+   that into the actions file.  STACK_OFFSET is the number of values
+   in the current rule so far, which says where to find `$0' with
+   respect to the top of the stack, for the simple parser in which the
+   stack is not popped until after the guard is run.  */
 
 void
 copy_guard (symbol_list *rule, int stack_offset)
@@ -997,7 +998,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 
   fprintf(fguard, "\ncase %d:\n", nrules);
   if (!nolinesflag)
-    fprintf(fguard, "#line %d \"%s\"\n", lineno, infile);
+    fprintf (fguard, "#line %d \"%s\"\n", lineno, infile);
   putc('{', fguard);
 
   count = 0;
@@ -1136,18 +1137,18 @@ copy_guard (symbol_list *rule, int stack_offset)
 	  if (c == '$')
 	    {
 	      fprintf(fguard, "yyval");
-	      if (!type_name) type_name = rule->sym->type_name;
+	      if (!type_name)
+		type_name = rule->sym->type_name;
 	      if (type_name)
 		fprintf(fguard, ".%s", type_name);
 	      if(!type_name && typed)
 		warns(_("$$ of `%s' has no declared type"), rule->sym->tag);
 	    }
-
 	  else if (isdigit(c) || c == '-')
 	    {
 	      ungetc (c, finput);
-	      n = read_signed_integer(finput);
-	      c = getc(finput);
+	      n = read_signed_integer (finput);
+	      c = getc (finput);
 
 	      if (!type_name && n > 0)
 		type_name = get_type_name(n, rule);
@@ -1211,10 +1212,10 @@ copy_guard (symbol_list *rule, int stack_offset)
 
 
 
-/* Assuming that a { has just been seen, copy everything up to the matching }
-into the actions file.
-stack_offset is the number of values in the current rule so far,
-which says where to find $0 with respect to the top of the stack.  */
+/* Assuming that a `{' has just been seen, copy everything up to the
+   matching `}' into the actions file.  STACK_OFFSET is the number of
+   values in the current rule so far, which says where to find `$0'
+   with respect to the top of the stack.  */
 
 void
 copy_action (symbol_list *rule, int stack_offset)
@@ -1228,12 +1229,13 @@ copy_action (symbol_list *rule, int stack_offset)
   int cplus_comment;
 
   /* offset is always 0 if parser has already popped the stack pointer */
-  if (semantic_parser) stack_offset = 0;
+  if (semantic_parser)
+    stack_offset = 0;
 
-  fprintf(faction, "\ncase %d:\n", nrules);
+  fprintf (faction, "\ncase %d:\n", nrules);
   if (!nolinesflag)
-    fprintf(faction, "#line %d \"%s\"\n", lineno, infile);
-  putc('{', faction);
+    fprintf (faction, "#line %d \"%s\"\n", lineno, infile);
+  putc ('{', faction);
 
   count = 1;
   c = getc(finput);
@@ -1361,11 +1363,13 @@ copy_action (symbol_list *rule, int stack_offset)
 	      if (c == '$')
 		{
 		  fprintf(faction, "yyval");
-		  if (!type_name) type_name = get_type_name(0, rule);
+		  if (!type_name)
+		    type_name = get_type_name(0, rule);
 		  if (type_name)
 		    fprintf(faction, ".%s", type_name);
 		  if(!type_name && typed)
-		    warns(_("$$ of `%s' has no declared type"), rule->sym->tag);
+		    warns(_("$$ of `%s' has no declared type"),
+			  rule->sym->tag);
 		}
 	      else if (isdigit(c) || c == '-')
 		{
