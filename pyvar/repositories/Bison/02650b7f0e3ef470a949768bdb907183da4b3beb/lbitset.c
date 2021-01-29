@@ -13,12 +13,11 @@
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
-*/
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
 
 #ifdef HAVE_CONFIG_H
-#include "config.h"
+# include <config.h>
 #endif
 
 #include "lbitset.h"
@@ -121,7 +120,7 @@ lbitset_elt_alloc (void)
 #define OBSTACK_CHUNK_FREE free
 #endif
 
-#if !defined(__GNUC__) || (__GNUC__ < 2)
+#if ! defined __GNUC__ || __GNUC__ < 2
 #define __alignof__(type) 0
 #endif
 
