@@ -91,15 +91,15 @@ flags_argmatch (const char *option,
   if (args)
     {
       args = strtok (args, ",");
-      do
+      while (args)
 	{
 	  int value = XARGMATCH (option, args, keys, values);
 	  if (value == 0)
 	    *flags = 0;
 	  else
 	    *flags |= value;
+          args = strtok (NULL, ",");
 	}
-      while ((args = strtok (NULL, ",")));
     }
   else
     *flags = ~0;
