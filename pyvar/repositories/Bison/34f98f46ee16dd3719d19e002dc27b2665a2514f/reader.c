@@ -44,10 +44,8 @@ static symbol_list *grammar = NULL;
 static bool start_flag = false;
 merger_list *merge_functions;
 
-/* Was %union, %before-definitions, or %after-definitions seen?  */
+/* Was %union seen?  */
 bool typed = false;
-bool before_definitions = false;
-bool after_definitions = false;
 
 /* Should rules have a default precedence?  */
 bool default_prec = true;
@@ -70,17 +68,16 @@ grammar_start_symbol_set (symbol *sym, location loc)
 }
 
 
-/*---------------------------------------------------------------------------.
-| There are two prologues: one before the first %union, %before-definitions, |
-| or %after-definitions; and one after.  Augment the current one.            |
-`---------------------------------------------------------------------------*/
+/*---------------------------------------------------------------------.
+| There are two prologues: one before the first %union and one after.  |
+|  Augment the one specified by POST.                                  |
+`---------------------------------------------------------------------*/
 
 void
-prologue_augment (const char *prologue, location loc)
+prologue_augment (const char *prologue, location loc, bool post)
 {
   struct obstack *oout =
-    !(typed || before_definitions || after_definitions)
-    ? &pre_prologue_obstack : &post_prologue_obstack;
+    !post ? &pre_prologue_obstack : &post_prologue_obstack;
 
   obstack_fgrow1 (oout, "]b4_syncline(%d, [[", loc.start.line);
   /* FIXME: Protection of M4 characters missing here.  See
