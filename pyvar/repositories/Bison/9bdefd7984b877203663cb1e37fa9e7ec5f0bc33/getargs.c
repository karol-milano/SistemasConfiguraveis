@@ -110,6 +110,7 @@ typedef void (usage_fn) (FILE *out);
  *
  *  \param opt        option being decoded (e.g., --report).
  *  \param xargmatch  matching function.
+ *  \param usage      function that implement --help for this option.
  *  \param all        the value of the argument 'all'.
  *  \param flags      the flags to update
  *  \param args       comma separated list of effective subarguments to decode.
