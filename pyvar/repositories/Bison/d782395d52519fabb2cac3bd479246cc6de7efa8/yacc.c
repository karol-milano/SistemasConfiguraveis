@@ -18,8 +18,9 @@
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
-# Handle BISON_USE_PUSH_FOR_PULL for the test suite.
-b4_use_push_for_pull_if([m4_include(b4_pkgdatadir/[push.c])], [
+# This hack will go away when we mv push.c yacc.c.
+m4_ifndef([b4_percent_define(push_pull)],
+[m4_if(b4_use_push_for_pull_flag, [0], [
 
 m4_include(b4_pkgdatadir/[c.m4])
 
@@ -1532,4 +1533,6 @@ b4_percent_code_get([[provides]])
 ])dnl b4_defines_if
 m4_divert_pop(0)
 
-])dnl b4_use_push_for_pull_if
+],
+[m4_include(b4_pkgdatadir/[push.c])])],
+[m4_include(b4_pkgdatadir/[push.c])])
