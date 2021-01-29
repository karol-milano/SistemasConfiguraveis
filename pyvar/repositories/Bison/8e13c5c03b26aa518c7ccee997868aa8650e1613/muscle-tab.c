@@ -557,6 +557,7 @@ muscle_percent_define_use (char const *variable)
 /* The value of %define variable VARIABLE (corresponding to FIELD, if
    defined).  Do not register as used, but diagnose unset variables.  */
 
+static
 char const *
 muscle_percent_define_get_raw (char const *variable, char const *field)
 {
