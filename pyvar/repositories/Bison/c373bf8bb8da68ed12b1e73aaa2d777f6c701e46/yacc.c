@@ -19,7 +19,7 @@
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 # This hack will go away when we mv push.c yacc.c.
-m4_ifndef([b4_percent_define(push_pull)],
+m4_ifndef([b4_percent_define(api.push_pull)],
 [m4_if(b4_use_push_for_pull_flag, [0], [
 
 m4_include(b4_pkgdatadir/[c.m4])
