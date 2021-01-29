@@ -118,9 +118,9 @@ muscle_insert (const char *key, char *value)
 
 
 /*-------------------------------------------------------------------.
-| Insert (KEY, VALUE).  If KEY already existed, overwrite the        |
-| previous value.  Uses MUSCLE_OBSTACK.  De-allocates the previously |
-| associated value.  VALUE and SEPARATOR are copied.                 |
+| Append VALUE to the current value of KEY.  If KEY did not already  |
+| exist, create it.  Use MUSCLE_OBSTACK.  De-allocate the previously |
+| associated value.  Copy VALUE and SEPARATOR.                       |
 `-------------------------------------------------------------------*/
 
 void
@@ -198,7 +198,7 @@ void muscle_pair_list_grow (const char *muscle,
 | Find the value of muscle KEY.  |
 `-------------------------------*/
 
-char*
+char *
 muscle_find (const char *key)
 {
   muscle_entry probe;
