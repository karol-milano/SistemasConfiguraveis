@@ -18,17 +18,22 @@
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
+# Check the value of %define push_pull.
+b4_percent_define_default([[push_pull]], [[pull]])
+b4_percent_define_check_values([[[[push_pull]], [[pull]], [[push]], [[both]]]])
+b4_define_flag_if([pull]) m4_define([b4_pull_flag], [[1]])
+b4_define_flag_if([push]) m4_define([b4_push_flag], [[1]])
+m4_case(b4_percent_define_get([[push_pull]]),
+        [pull], [m4_define([b4_push_flag], [[0]])],
+        [push], [m4_define([b4_pull_flag], [[0]])])
+
 # Handle BISON_USE_PUSH_FOR_PULL for the test suite.  So that push parsing
 # tests function as written, don't let BISON_USE_PUSH_FOR_PULL modify Bison's
 # behavior at all when push parsing is already requested.
+b4_define_flag_if([use_push_for_pull])
 b4_use_push_for_pull_if([
-  b4_push_if([
-    m4_define([b4_use_push_for_pull_flag], [[0]])
-    b4_define_flag_if([use_push_for_pull])
-  ], [
-    m4_define([b4_push_flag], [[1]])
-    b4_define_flag_if([push])
-  ])])
+  b4_push_if([m4_define([b4_use_push_for_pull_flag], [[0]])],
+             [m4_define([b4_push_flag], [[1]])])])
 
 m4_include(b4_pkgdatadir/[c.m4])
 
@@ -157,8 +162,14 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
    define necessary library symbols; they are noted "INFRINGES ON
    USER NAME SPACE" below.  */
 
-]b4_identification
-b4_percent_code_get([[top]])[]dnl
+]b4_identification[
+/* Push parsers.  */
+#define YYPUSH ]b4_push_flag[
+
+/* Pull parsers.  */
+#define YYPULL ]b4_pull_flag[
+
+]b4_percent_code_get([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */
 ]b4_pull_if([[#define yyparse         ]b4_prefix[parse
