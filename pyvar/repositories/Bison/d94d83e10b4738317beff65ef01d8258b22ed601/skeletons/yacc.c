@@ -1,4 +1,4 @@
-                                                             -*- C -*-
+#                                                            -*- C -*-
 # Yacc compatible skeleton for Bison
 
 # Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software
@@ -20,7 +20,34 @@ m4_pushdef([b4_copyright_years],
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
-# Check the value of %define api.push-pull.
+m4_include(b4_skeletonsdir/[c.m4])
+
+## ---------- ##
+## api.pure.  ##
+## ---------- ##
+
+b4_percent_define_default([[api.pure]], [[false]])
+b4_percent_define_check_values([[[[api.pure]],
+                                 [[false]], [[true]], [[]], [[full]]]])
+
+m4_define([b4_pure_flag], [[0]])
+m4_case(b4_percent_define_get([[api.pure]]),
+        [false], [m4_define([b4_pure_flag], [[0]])],
+        [true],  [m4_define([b4_pure_flag], [[1]])],
+        [],      [m4_define([b4_pure_flag], [[1]])],
+        [full],  [m4_define([b4_pure_flag], [[2]])])
+
+m4_define([b4_pure_if],
+[m4_case(b4_pure_flag,
+         [0], [$2],
+         [1], [$1],
+         [2], [$1])])
+         [m4_fatal([invalid api.pure value: ]$1)])])
+
+## --------------- ##
+## api.push-pull.  ##
+## --------------- ##
+
 b4_percent_define_default([[api.push-pull]], [[pull]])
 b4_percent_define_check_values([[[[api.push-pull]],
                                  [[pull]], [[push]], [[both]]]])
@@ -38,8 +65,10 @@ b4_use_push_for_pull_if([
   b4_push_if([m4_define([b4_use_push_for_pull_flag], [[0]])],
              [m4_define([b4_push_flag], [[1]])])])
 
-# Check the value of %define parse.lac and friends, where LAC stands for
-# lookahead correction.
+## ----------- ##
+## parse.lac.  ##
+## ----------- ##
+
 b4_percent_define_default([[parse.lac]], [[none]])
 b4_percent_define_default([[parse.lac.es-capacity-initial]], [[20]])
 b4_percent_define_default([[parse.lac.memory-trace]], [[failures]])
@@ -51,8 +80,6 @@ m4_define([b4_lac_flag],
           [m4_if(b4_percent_define_get([[parse.lac]]),
                  [none], [[0]], [[1]])])
 
-m4_include(b4_skeletonsdir/[c.m4])
-
 ## ---------------- ##
 ## Default values.  ##
 ## ---------------- ##
@@ -62,28 +89,6 @@ m4_define_default([b4_stack_depth_max], [10000])
 m4_define_default([b4_stack_depth_init],  [200])
 
 
-## ------------------------ ##
-## Pure/impure interfaces.  ##
-## ------------------------ ##
-
-b4_percent_define_default([[api.pure]], [[false]])
-b4_percent_define_check_values([[[[api.pure]],
-                                 [[false]], [[true]], [[]], [[full]]]])
-
-m4_define([b4_pure_flag], [[0]])
-m4_case(b4_percent_define_get([[api.pure]]),
-        [false], [m4_define([b4_pure_flag], [[0]])],
-        [true],  [m4_define([b4_pure_flag], [[1]])],
-        [],      [m4_define([b4_pure_flag], [[1]])],
-        [full],  [m4_define([b4_pure_flag], [[2]])])
-
-m4_define([b4_pure_if],
-[m4_case(b4_pure_flag,
-         [0], [$2],
-         [1], [$1],
-         [2], [$1])])
-         [m4_fatal([invalid api.pure value: ]$1)])])
-
 # b4_yyerror_arg_loc_if(ARG)
 # --------------------------
 # Expand ARG iff yyerror is to be given a location as argument.
