@@ -60,11 +60,6 @@ hash_muscle (const void *x, size_t tablesize)
   return hash_string (m->key, tablesize);
 }
 
-/*-----------------------------------------------------------------.
-| Create the MUSCLE_TABLE, and initialize it with default values.  |
-| Also set up the MUSCLE_OBSTACK.                                  |
-`-----------------------------------------------------------------*/
-
 static void
 muscle_entry_free (void *entry)
 {
@@ -87,10 +82,6 @@ muscle_init (void)
 }
 
 
-/*------------------------------------------------------------.
-| Free all the memory consumed by the muscle machinery only.  |
-`------------------------------------------------------------*/
-
 void
 muscle_free (void)
 {
@@ -99,12 +90,6 @@ muscle_free (void)
 }
 
 
-
-/*------------------------------------------------------------.
-| Insert (KEY, VALUE).  If KEY already existed, overwrite the |
-| previous value.                                             |
-`------------------------------------------------------------*/
-
 void
 muscle_insert (char const *key, char const *value)
 {
@@ -212,11 +197,6 @@ void muscle_pair_list_grow (const char *muscle,
 }
 
 
-/*----------------------------------------------------------------------------.
-| Find the value of muscle KEY.  Unlike MUSCLE_FIND, this is always reliable  |
-| to determine whether KEY has a value.                                       |
-`----------------------------------------------------------------------------*/
-
 char const *
 muscle_find_const (char const *key)
 {
@@ -231,12 +211,6 @@ muscle_find_const (char const *key)
 }
 
 
-/*----------------------------------------------------------------------------.
-| Find the value of muscle KEY.  Abort if muscle_insert was invoked more      |
-| recently than muscle_grow for KEY since muscle_find can't return a          |
-| char const *.                                                               |
-`----------------------------------------------------------------------------*/
-
 char *
 muscle_find (char const *key)
 {
@@ -711,11 +685,6 @@ muscle_m4_output_processor (void *entry, void *out)
 }
 
 
-/*----------------------------------------------------------------.
-| Output the definition of all the current muscles into a list of |
-| m4_defines.                                                     |
-`----------------------------------------------------------------*/
-
 void
 muscles_m4_output (FILE *out)
 {
