@@ -13,20 +13,18 @@
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
-*/
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
 
 /* This file is a wrapper bitset implementation for the other bitset
    implementations.  It provides bitset compatibility checking and
    statistics gathering without having to instrument the bitset
    implementations.  When statistics gathering is enabled, the bitset
    operations get vectored through here and we then call the appropriate
-   routines.
-*/
+   routines.  */
 
 #ifdef HAVE_CONFIG_H
-#include "config.h"
+# include <config.h>
 #endif
 
 #include "bbitset.h"
