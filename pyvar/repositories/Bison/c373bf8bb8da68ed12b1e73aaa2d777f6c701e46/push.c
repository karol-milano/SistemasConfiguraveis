@@ -18,12 +18,13 @@
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
-# Check the value of %define push_pull.
-b4_percent_define_default([[push_pull]], [[pull]])
-b4_percent_define_check_values([[[[push_pull]], [[pull]], [[push]], [[both]]]])
+# Check the value of %define api.push_pull.
+b4_percent_define_default([[api.push_pull]], [[pull]])
+b4_percent_define_check_values([[[[api.push_pull]],
+                               [[pull]], [[push]], [[both]]]])
 b4_define_flag_if([pull]) m4_define([b4_pull_flag], [[1]])
 b4_define_flag_if([push]) m4_define([b4_push_flag], [[1]])
-m4_case(b4_percent_define_get([[push_pull]]),
+m4_case(b4_percent_define_get([[api.push_pull]]),
         [pull], [m4_define([b4_push_flag], [[0]])],
         [push], [m4_define([b4_pull_flag], [[0]])])
 
