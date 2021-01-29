@@ -17,7 +17,6 @@
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
-#include <config.h>
 #include <stdio.h>
 
 int yyerror (char const *);
@@ -25,5 +24,7 @@ int yyerror (char const *);
 int
 yyerror (char const *message)
 {
-  return fprintf (stderr, "%s\n", message);
+  fputs (message, stderr);
+  fputc ('\n', stderr);
+  return 0;
 }
