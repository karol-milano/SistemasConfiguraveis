@@ -75,9 +75,9 @@ extern char *program_name;
 /** Decode an option's set of keys.
  *
  *  \param option   option being decoded.
- *  \paran keys     array of valid subarguments.
+ *  \param keys     array of valid subarguments.
  *  \param values   array of corresponding (int) values.
- *  \param flag     the flags to update
+ *  \param flags    the flags to update
  *  \param args     colon separated list of effective subarguments to decode.
  *                  If 0, then activate all the flags.
  *
@@ -108,7 +108,7 @@ flags_argmatch (const char *option,
 /** Decode a set of sub arguments.
  *
  *  \param FlagName  the flag familly to update.
- *  \param args      the effective sub arguments to decode.
+ *  \param Args      the effective sub arguments to decode.
  *
  *  \arg FlagName_args   the list of keys.
  *  \arg FlagName_types  the list of values.
