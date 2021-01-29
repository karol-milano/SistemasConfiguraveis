@@ -5,20 +5,18 @@
 # Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
 # 2007 Free Software Foundation, Inc.
 
-# This program is free software; you can redistribute it and/or modify
+# This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
-# the Free Software Foundation; either version 2 of the License, or
+# the Free Software Foundation, either version 3 of the License, or
 # (at your option) any later version.
-
+#
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
-
+#
 # You should have received a copy of the GNU General Public License
-# along with this program; if not, write to the Free Software
-# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
-# 02110-1301  USA
+# along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 # Handle BISON_USE_PUSH_FOR_PULL for the test suite.
 b4_use_push_for_pull_if([m4_include(b4_pkgdatadir/[push.c])], [
