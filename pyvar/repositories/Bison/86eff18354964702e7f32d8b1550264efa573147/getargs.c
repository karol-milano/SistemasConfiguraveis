@@ -137,7 +137,10 @@ Output:\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
   -o, --output=FILE          leave output to FILE\n\
   -g, --graph                also produce a VCG description of the automaton\n\
-\n\
+"), stream);
+  putc ('\n', stream);
+
+  fputs (_("\
 THINGS is a list of comma separated words that can include:\n\
   `state'        describe the states\n\
   `itemset'      complete the core item sets with their closure\n\
