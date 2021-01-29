@@ -45,6 +45,7 @@ bool no_lines_flag = false;
 bool token_table_flag = false;
 location yacc_loc = EMPTY_LOCATION_INIT;
 bool update_flag = false; /* for -u */
+bool style_debug = false; /* --style=debug. */
 
 bool nondeterministic_parser = false;
 bool glr_parser = false;
@@ -595,7 +596,13 @@ getargs_colors (int argc, char *argv[])
       if (STRPREFIX_LIT ("--color=", arg))
         handle_color_option (arg + strlen ("--color="));
       else if (STRPREFIX_LIT ("--style=", arg))
-        handle_style_option (arg + strlen ("--style="));
+        {
+          const char *style = arg + strlen ("--style=");
+          if (STREQ (style, "debug"))
+            style_debug = true;
+          else
+            handle_style_option (style);
+        }
     }
   complain_init_color ();
 }
