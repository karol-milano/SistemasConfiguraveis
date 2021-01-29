@@ -30,6 +30,7 @@
 #include "complain.h"
 #include "getargs.h"
 #include "gram.h"
+#include "intprops.h"
 #include "quote.h"
 
 
@@ -549,6 +550,9 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
            && *user_token_numberp != user_token_number)
     complain (&loc, complaint, _("redefining user token number of %s"),
               sym->tag);
+  else if (user_token_number == INT_MAX)
+    complain (&loc, complaint, _("user token number of %s too large"),
+              sym->tag);
   else
     {
       *user_token_numberp = user_token_number;
@@ -1005,7 +1009,11 @@ symbols_token_translations_init (void)
     {
       sym_content *this = symbols[i]->content;
       if (this->user_token_number == USER_NUMBER_UNDEFINED)
-        this->user_token_number = ++max_user_token_number;
+        {
+          if (INT_ADD_WRAPV (max_user_token_number, 1, &max_user_token_number))
+            complain (NULL, fatal, _("token number too large"));
+          this->user_token_number = max_user_token_number;
+        }
       if (this->user_token_number > max_user_token_number)
         max_user_token_number = this->user_token_number;
     }
