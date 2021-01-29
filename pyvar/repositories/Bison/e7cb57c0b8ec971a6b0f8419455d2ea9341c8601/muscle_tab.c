@@ -139,7 +139,6 @@ muscle_grow (const char *key, const char *val, const char *separator)
     {
       /* Grow the current value. */
       char *new_val;
-      fprintf (stderr, "<= %s + %s\n", entry->value, val);
       obstack_sgrow (&muscle_obstack, entry->value);
       free (entry->value);
       obstack_sgrow (&muscle_obstack, separator);
@@ -147,7 +146,6 @@ muscle_grow (const char *key, const char *val, const char *separator)
       obstack_1grow (&muscle_obstack, 0);
       new_val = obstack_finish (&muscle_obstack);
       entry->value = xstrdup (new_val);
-      fprintf (stderr, "=> %s\n", new_val);
       obstack_free (&muscle_obstack, new_val);
     }
 }
