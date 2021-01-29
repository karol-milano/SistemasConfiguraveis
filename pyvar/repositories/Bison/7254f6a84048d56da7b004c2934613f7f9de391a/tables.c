@@ -1,7 +1,7 @@
 /* Output the generated parsing program for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006 Free Software Foundation, Inc.
+   2005, 2006, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -30,6 +30,7 @@
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
+#include "muscle-tab.h"
 #include "reader.h"
 #include "symtab.h"
 #include "tables.h"
@@ -303,6 +304,16 @@ action_row (state *s)
       actrow[sym->number] = ACTION_NUMBER_MINIMUM;
     }
 
+  /* Turn off default rules where requested by the user.  See
+     state_lookahead_tokens_count in lalr.c to understand when states are
+     labeled as consistent.  */
+  {
+    char *default_rules = muscle_percent_define_get ("lr.default_rules");
+    if (0 != strcmp (default_rules, "all") && !s->consistent)
+      nodefault = true;
+    free (default_rules);
+  }
+
   /* Now find the most common reduction and make it the default action
      for this state.  */
 
