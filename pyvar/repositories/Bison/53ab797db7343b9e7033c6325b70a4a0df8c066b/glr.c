@@ -18,7 +18,10 @@
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 
-m4_include(b4_pkgdatadir/[c.m4])
+# If we are loaded by glr.cc, do not override c++.m4 definitions by
+# those of c.m4.
+m4_if(b4_skeleton, ["glr.c"],
+      [m4_include(b4_pkgdatadir/[c.m4])])
 
 ## ---------------- ##
 ## Default values.  ##
@@ -494,7 +497,6 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 # define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 #endif
 
-
 /* YYLEX -- calling `yylex' with the right arguments.  */
 #define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
 
