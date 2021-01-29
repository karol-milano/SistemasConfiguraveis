@@ -498,7 +498,8 @@ typedef struct yySemanticOption yySemanticOption;
 typedef union yyGLRStackItem yyGLRStackItem;
 typedef struct yyGLRStack yyGLRStack;
 
-struct yyGLRState {
+struct yyGLRState
+{
   /** Type tag: always true.  */
   yybool yyisState;
   /** Type tag for yysemantics.  If true, yysval applies, otherwise
@@ -522,7 +523,8 @@ struct yyGLRState {
   YYLTYPE yyloc;]])[
 };
 
-struct yyGLRStateSet {
+struct yyGLRStateSet
+{
   yyGLRState** yystates;
   /** During nondeterministic operation, yylookaheadNeeds tracks which
    *  stacks have actually needed the current lookahead.  During deterministic
@@ -533,7 +535,8 @@ struct yyGLRStateSet {
   YYPTRDIFF_T yycapacity;
 };
 
-struct yySemanticOption {
+struct yySemanticOption
+{
   /** Type tag: always false.  */
   yybool yyisState;
   /** Rule number for this reduction */
