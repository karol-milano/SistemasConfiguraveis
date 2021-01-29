@@ -28,6 +28,31 @@
 #include "muscle-tab.h"
 #include "quote.h"
 
+muscle_kind
+muscle_kind_new (char const *k)
+{
+  if (STREQ (k, "code"))
+    return muscle_code;
+  else if (STREQ (k, "keyword"))
+    return muscle_keyword;
+  else if (STREQ (k, "string"))
+    return muscle_string;
+  aver (0);
+}
+
+char const *
+muscle_kind_string (muscle_kind k)
+{
+  switch (k)
+    {
+    case muscle_code:    return "code";
+    case muscle_keyword: return "keyword";
+    case muscle_string:  return "string";
+    }
+  aver (0);
+}
+
+
 /* A key-value pair, along with storage that can be reclaimed when
    this pair is no longer needed.  */
 typedef struct
@@ -35,6 +60,7 @@ typedef struct
   char const *key;
   char const *value;
   char *storage;
+  muscle_kind kind;
 } muscle_entry;
 
 /* An obstack used to create some entries.  */
@@ -446,6 +472,7 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
 
 void
 muscle_percent_define_insert (char const *var, location variable_loc,
+                              muscle_kind kind,
                               char const *value,
                               muscle_percent_define_how how)
 {
@@ -456,6 +483,8 @@ muscle_percent_define_insert (char const *var, location variable_loc,
   char const *syncline_name =
     UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
   char const *how_name = UNIQSTR_CONCAT ("percent_define_how(", variable, ")");
+  char const *kind_name =
+    UNIQSTR_CONCAT ("percent_define_kind(", variable, ")");
 
   /* Command-line options are processed before the grammar file.  */
   if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
@@ -481,6 +510,7 @@ muscle_percent_define_insert (char const *var, location variable_loc,
   muscle_user_name_list_grow ("percent_define_user_variables", variable,
                               variable_loc);
   MUSCLE_INSERT_INT (how_name, how);
+  MUSCLE_INSERT_STRING (kind_name, muscle_kind_string (kind));
  end:
   free (variable);
 }
@@ -497,10 +527,10 @@ muscle_percent_define_ensure (char const *variable, location loc,
   /* Don't complain is VARIABLE is already defined, but be sure to set
      its value to VAL.  */
   if (!muscle_find_const (name))
-    muscle_percent_define_insert (variable, loc, val,
+    muscle_percent_define_insert (variable, loc, muscle_keyword, val,
                                   MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
   if (muscle_percent_define_flag_if (variable) != value)
-    muscle_percent_define_insert (variable, loc, val,
+    muscle_percent_define_insert (variable, loc, muscle_keyword, val,
                                   MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
 }
 
