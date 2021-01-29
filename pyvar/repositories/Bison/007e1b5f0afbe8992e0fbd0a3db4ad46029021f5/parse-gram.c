@@ -100,7 +100,7 @@
 # endif
 
 #include "src/parse-gram.h"
-/* Symbol type.  */
+/* Symbol kind.  */
 enum yysymbol_kind_t
 {
   YYSYMBOL_YYEMPTY = -2,
@@ -169,14 +169,14 @@ enum yysymbol_kind_t
   YYSYMBOL_input = 62,                     /* input  */
   YYSYMBOL_prologue_declarations = 63,     /* prologue_declarations  */
   YYSYMBOL_prologue_declaration = 64,      /* prologue_declaration  */
-  YYSYMBOL_65____1 = 65,                   /* $@1  */
+  YYSYMBOL_65_1 = 65,                      /* $@1  */
   YYSYMBOL_params = 66,                    /* params  */
   YYSYMBOL_grammar_declaration = 67,       /* grammar_declaration  */
   YYSYMBOL_code_props_type = 68,           /* code_props_type  */
   YYSYMBOL_union_name = 69,                /* union_name  */
   YYSYMBOL_symbol_declaration = 70,        /* symbol_declaration  */
-  YYSYMBOL_71____2 = 71,                   /* $@2  */
-  YYSYMBOL_72____3 = 72,                   /* $@3  */
+  YYSYMBOL_71_2 = 71,                      /* $@2  */
+  YYSYMBOL_72_3 = 72,                      /* $@3  */
   YYSYMBOL_precedence_declarator = 73,     /* precedence_declarator  */
   YYSYMBOL_74_tag_opt = 74,                /* tag.opt  */
   YYSYMBOL_generic_symlist = 75,           /* generic_symlist  */
@@ -196,7 +196,7 @@ enum yysymbol_kind_t
   YYSYMBOL_grammar = 89,                   /* grammar  */
   YYSYMBOL_rules_or_grammar_declaration = 90, /* rules_or_grammar_declaration  */
   YYSYMBOL_rules = 91,                     /* rules  */
-  YYSYMBOL_92____4 = 92,                   /* $@4  */
+  YYSYMBOL_92_4 = 92,                      /* $@4  */
   YYSYMBOL_93_rhses_1 = 93,                /* rhses.1  */
   YYSYMBOL_rhs = 94,                       /* rhs  */
   YYSYMBOL_95_named_ref_opt = 95,          /* named_ref.opt  */
@@ -206,8 +206,7 @@ enum yysymbol_kind_t
   YYSYMBOL_id_colon = 99,                  /* id_colon  */
   YYSYMBOL_symbol = 100,                   /* symbol  */
   YYSYMBOL_string_as_id = 101,             /* string_as_id  */
-  YYSYMBOL_102_epilogue_opt = 102,         /* epilogue.opt  */
-
+  YYSYMBOL_102_epilogue_opt = 102          /* epilogue.opt  */
 };
 typedef enum yysymbol_kind_t yysymbol_kind_t;
 
