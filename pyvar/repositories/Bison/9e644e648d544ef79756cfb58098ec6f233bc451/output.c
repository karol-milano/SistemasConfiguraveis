@@ -1074,6 +1074,8 @@ prepare (void)
   MACRO_INSERT_INT ("nstates", nstates);
   MACRO_INSERT_INT ("ntokens", ntokens);
 
+  MACRO_INSERT_INT ("locations_flag", locations_flag);
+
   if (spec_name_prefix)
     MACRO_INSERT_STRING ("prefix", spec_name_prefix);
 }
