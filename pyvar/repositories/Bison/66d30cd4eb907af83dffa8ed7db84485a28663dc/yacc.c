@@ -20,6 +20,27 @@ m4_include([c.m4])
 # Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 # 02111-1307  USA
 
+
+
+## ---------------- ##
+## Default values.  ##
+## ---------------- ##
+
+# Stack parameters.
+m4_define_default([b4_stack_depth_max], [10000])
+m4_define_default([b4_stack_depth_init],  [200])
+
+# Location type.
+m4_define_default([b4_location_type], [yyltype])
+
+
+
+
+## ----------------- ##
+## Semantic Values.  ##
+## ----------------- ##
+
+
 # b4_lhs_value([TYPE])
 # --------------------
 # Expansion of $<TYPE>$.
@@ -203,7 +224,7 @@ typedef struct yyltype
   int last_line;
   int last_column;
 } yyltype;
-# define YYLTYPE b4_ltype
+# define YYLTYPE b4_location_type
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
@@ -543,7 +564,7 @@ int yydebug;
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
 #ifndef	YYINITDEPTH
-# define YYINITDEPTH b4_initdepth
+# define YYINITDEPTH b4_stack_depth_init
 #endif
 
 /* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
@@ -558,7 +579,7 @@ int yydebug;
 #endif
 
 #ifndef YYMAXDEPTH
-# define YYMAXDEPTH b4_maxdepth
+# define YYMAXDEPTH b4_stack_depth_max
 #endif
 
 
