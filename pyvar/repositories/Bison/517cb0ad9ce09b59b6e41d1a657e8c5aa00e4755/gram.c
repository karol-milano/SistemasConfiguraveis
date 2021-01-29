@@ -1,7 +1,7 @@
 /* Allocate input grammar variables for Bison.
 
    Copyright (C) 1984, 1986, 1989, 2001, 2002, 2003, 2005, 2006
-   2007 Free Software Foundation, Inc.
+   2007, 2008, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -224,7 +224,8 @@ grammar_rules_print_xml (FILE *out, int level)
         fprintf (out, "<rule number=\"%d\" usefulness=\"%s\"",
                  rules[r].number, usefulness);
         if (rules[r].precsym)
-          fprintf (out, " percent_prec=\"%s\"", rules[r].precsym->tag);
+          fprintf (out, " percent_prec=\"%s\"",
+                   xml_escape (rules[r].precsym->tag));
         fputs (">\n", out);
       }
       rule_lhs_print_xml (&rules[r], out, level + 3);
