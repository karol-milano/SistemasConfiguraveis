@@ -82,7 +82,7 @@ static base_t *width = NULL;
 /* For a given state, N = ACTROW[SYMBOL]:
 
    If N = 0, stands for `run the default action'.
-   If N = MIN, stands for `raise a parse error'.
+   If N = MIN, stands for `raise a syntax error'.
    If N > 0, stands for `shift SYMBOL and go to n'.
    If N < 0, stands for `reduce -N'.  */
 typedef short action_t;
@@ -116,7 +116,7 @@ static int conflict_list_free;
 static size_t table_size = 32768;
 base_t *table = NULL;
 base_t *check = NULL;
-/* The value used in TABLE to denote explicit parse errors
+/* The value used in TABLE to denote explicit syntax errors
    (%nonassoc), a negative infinite.  First defaults to ACTION_MIN,
    but in order to keep small tables, renumbered as TABLE_ERROR, which
    is the smallest (non error) value minus 1.  */
