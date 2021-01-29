@@ -18,13 +18,7 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
-
-#if HAVE_LOCALE_H
-# include <locale.h>
-#endif
-#if ! HAVE_SETLOCALE
-# define setlocale(Category, Locale)
-#endif
+#include <locale.h>
 
 int yyparse (void);
 
