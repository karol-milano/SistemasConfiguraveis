@@ -21,12 +21,12 @@
 #include "system.h"
 
 #include <hash.h>
-#include <quotearg.h>
 
 #include "complain.h"
 #include "files.h"
-#include "muscle-tab.h"
 #include "getargs.h"
+#include "muscle-tab.h"
+#include "quote.h"
 
 /* A key-value pair, along with storage that can be reclaimed when
    this pair is no longer needed.  */
@@ -425,8 +425,8 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
           free (variable_tr);
           return;
         }
-      complain_at (variable_loc, _("%%define variable '%s' redefined"),
-                   variable);
+      complain_at (variable_loc, _("%%define variable %s redefined"),
+                   quote (variable));
       complain_at (muscle_percent_define_get_loc (variable),
                    _("previous definition"));
     }
@@ -467,8 +467,8 @@ muscle_percent_define_get_loc (char const *variable)
   char const *loc_name;
   loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
   if (!muscle_find_const (loc_name))
-    fatal(_("undefined %%define variable '%s' passed to"
-            " muscle_percent_define_get_loc"), variable);
+    fatal(_("%s: undefined %%define variable %s"),
+          "muscle_percent_define_get_loc", quote (variable));
   return muscle_location_decode (loc_name);
 }
 
@@ -481,8 +481,8 @@ muscle_percent_define_get_syncline (char const *variable)
     UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
   syncline = muscle_find_const (syncline_name);
   if (!syncline)
-    fatal(_("undefined %%define variable '%s' passed to"
-            " muscle_percent_define_get_syncline"), variable);
+    fatal(_("%s: undefined %%define variable %s"),
+          "muscle_percent_define_get_syncline", quote (variable));
   return syncline;
 }
 
@@ -527,14 +527,14 @@ muscle_percent_define_flag_if (char const *variable)
         {
           muscle_insert (invalid_boolean_name, "");
           complain_at(muscle_percent_define_get_loc (variable),
-                      _("invalid value for %%define Boolean variable '%s'"),
-                      variable);
+                      _("invalid value for %%define Boolean variable %s"),
+                      quote (variable));
         }
       free (value);
     }
   else
-    fatal(_("undefined %%define variable '%s' passed to muscle_percent_define_flag_if"),
-          variable);
+    fatal(_("%s: undefined %%define variable %s"),
+          "muscle_percent_define_flag", quote (variable));
 
   return result;
 }
@@ -585,10 +585,10 @@ muscle_percent_define_check_values (char const * const *values)
             {
               location loc = muscle_percent_define_get_loc (*variablep);
               complain_at(loc,
-                          _("invalid value for %%define variable '%s': '%s'"),
-                          *variablep, value);
+                          _("invalid value for %%define variable %s: %s"),
+                          quote (*variablep), quote_n (1, value));
               for (values = variablep + 1; *values; ++values)
-                complain_at (loc, _("accepted value: '%s'"), *values);
+                complain_at (loc, _("accepted value: %s"), quote (*values));
             }
           else
             {
@@ -598,9 +598,8 @@ muscle_percent_define_check_values (char const * const *values)
           free (value);
         }
       else
-        fatal(_("undefined %%define variable '%s' passed to"
-                " muscle_percent_define_check_values"),
-              *variablep);
+        fatal (_("%s: undefined %%define variable %s"),
+               "muscle_percent_define_check_values", quote (*variablep));
     }
 }
 
