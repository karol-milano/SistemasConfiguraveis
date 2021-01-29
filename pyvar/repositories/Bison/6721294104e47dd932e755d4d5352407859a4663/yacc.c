@@ -20,13 +20,13 @@ m4_pushdef([b4_copyright_years],
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
-# Check the value of %define api.push_pull.
-b4_percent_define_default([[api.push_pull]], [[pull]])
-b4_percent_define_check_values([[[[api.push_pull]],
+# Check the value of %define api.push-pull.
+b4_percent_define_default([[api.push-pull]], [[pull]])
+b4_percent_define_check_values([[[[api.push-pull]],
                                [[pull]], [[push]], [[both]]]])
 b4_define_flag_if([pull]) m4_define([b4_pull_flag], [[1]])
 b4_define_flag_if([push]) m4_define([b4_push_flag], [[1]])
-m4_case(b4_percent_define_get([[api.push_pull]]),
+m4_case(b4_percent_define_get([[api.push-pull]]),
         [pull], [m4_define([b4_push_flag], [[0]])],
         [push], [m4_define([b4_pull_flag], [[0]])])
 