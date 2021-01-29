@@ -45,7 +45,7 @@ bool no_lines_flag = false;
 bool token_table_flag = false;
 location yacc_loc = EMPTY_LOCATION_INIT;
 bool update_flag = false; /* for -u */
-bool style_debug = false; /* --style=debug. */
+bool color_debug = false; /* --style=debug. */
 
 bool nondeterministic_parser = false;
 bool glr_parser = false;
@@ -596,14 +596,17 @@ getargs_colors (int argc, char *argv[])
     {
       const char *arg = argv[i];
       if (STRPREFIX_LIT ("--color=", arg))
-        handle_color_option (arg + strlen ("--color="));
+        {
+          const char *color = arg + strlen ("--color=");
+          if (STREQ (color, "debug"))
+            color_debug = true;
+          else
+            handle_color_option (color);
+        }
       else if (STRPREFIX_LIT ("--style=", arg))
         {
           const char *style = arg + strlen ("--style=");
-          if (STREQ (style, "debug"))
-            style_debug = true;
-          else
-            handle_style_option (style);
+          handle_style_option (style);
         }
     }
   complain_init_color ();
