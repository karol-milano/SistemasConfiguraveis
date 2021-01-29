@@ -1,5 +1,5 @@
 /* Bitset statistics.
-   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -160,8 +160,8 @@ bitset_log_histogram_print (FILE *file, const char *name, const char *msg,
   for (; i < n_bins; i++)
     fprintf (file, "%*lu-%lu\t%8u (%5.1f%%)\n",
 	     max_width - ((unsigned int) (0.30103 * (i) + 0.9999) + 1),
-	     (unsigned long) 1 << (i - 1),
-	     ((unsigned long) 1 << i) - 1,
+	     1UL << (i - 1),
+	     (1UL << i) - 1,
 	     bins[i],
 	     (100.0 * bins[i]) / total);
 }
