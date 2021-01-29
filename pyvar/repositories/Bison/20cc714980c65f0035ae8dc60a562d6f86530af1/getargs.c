@@ -87,10 +87,12 @@ char *program_name;
  *  \param keys     array of valid subarguments.
  *  \param values   array of corresponding (int) values.
  *  \param flags    the flags to update
- *  \param args     colon separated list of effective subarguments to decode.
+ *  \param args     comma separated list of effective subarguments to decode.
  *                  If 0, then activate all the flags.
  *
- *  The special value 0 resets the flags to 0.
+ *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
+ *  If VALUE == 0 then KEY clears all flags and no-KEY sets all flags.
+ *  Thus no-none = all and no-all = none.
  */
 static void
 flags_argmatch (const char *option,
@@ -102,11 +104,18 @@ flags_argmatch (const char *option,
       args = strtok (args, ",");
       while (args)
 	{
-	  int value = XARGMATCH (option, args, keys, values);
+	  int no = strncmp (args, "no-", 3) == 0 ? 3 : 0;
+	  int value = XARGMATCH (option, args + no, keys, values);
 	  if (value == 0)
-	    *flags = 0;
+	    if (no)
+	      *flags = ~0;
+	    else
+	      *flags = 0;
 	  else
-	    *flags |= value;
+	    if (no)
+	      *flags &= ~value;
+	    else
+	      *flags |= value;
 	  args = strtok (NULL, ",");
 	}
     }
