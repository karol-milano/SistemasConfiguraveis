@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.0.2.13-975bb-dirty.  */
+/* A Bison parser, made by GNU Bison 3.0.2.29-9a91e.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.0.2.13-975bb-dirty"
+#define YYBISON_VERSION "3.0.2.29-9a91e"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -3118,6 +3118,8 @@ current_lhs (symbol *sym, location loc, named_ref *ref)
 {
   current_lhs_symbol = sym;
   current_lhs_location = loc;
+  if (sym)
+    symbol_location_as_lhs_set (sym, loc);
   /* In order to simplify memory management, named references for lhs
      are always assigned by deep copy into the current symbol_list
      node.  This is because a single named-ref in the grammar may
