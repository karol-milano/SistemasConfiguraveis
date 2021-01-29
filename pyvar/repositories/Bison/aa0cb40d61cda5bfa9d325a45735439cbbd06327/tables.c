@@ -126,7 +126,7 @@ static int table_size = 32768;
 base_number *table;
 base_number *check;
 /* The value used in TABLE to denote explicit syntax errors
-   (%nonassoc), a negative infinite.  First defaults to ACTION_NUMBER_MININUM,
+   (%nonassoc), a negative infinite.  First defaults to ACTION_NUMBER_MINIMUM,
    but in order to keep small tables, renumbered as TABLE_ERROR, which
    is the smallest (non error) value minus 1.  */
 base_number table_ninf = 0;
