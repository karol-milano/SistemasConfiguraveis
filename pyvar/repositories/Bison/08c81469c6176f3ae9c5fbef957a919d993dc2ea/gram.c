@@ -1,7 +1,7 @@
 /* Allocate input grammar variables for Bison.
 
    Copyright (C) 1984, 1986, 1989, 2001, 2002, 2003, 2005, 2006
-   2007 Free Software Foundation, Inc.
+   2007, 2008 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -87,10 +87,10 @@ rule_lhs_print_xml (rule *r, FILE *out, int level)
   xml_printf (out, level, "<lhs>%s</lhs>", r->lhs->tag);
 }
 
-int
+size_t
 rule_rhs_length (rule *r)
 {
-  int res = 0;
+  size_t res = 0;
   item_number *rhsp;
   for (rhsp = r->rhs; *rhsp >= 0; ++rhsp)
     ++res;
