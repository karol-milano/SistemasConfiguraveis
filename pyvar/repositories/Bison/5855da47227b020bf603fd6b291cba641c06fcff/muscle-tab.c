@@ -141,8 +141,7 @@ muscle_free (void)
 }
 
 /* Look for the muscle named KEY.  Return NULL if does not exist.  */
-static
-muscle_entry *
+static muscle_entry *
 muscle_lookup (char const *key)
 {
   muscle_entry probe;
