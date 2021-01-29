@@ -335,7 +335,7 @@ m4_define([b4_header_include_if],
                                    [$2])],
           [$2])])
 
-m4_if(b4_spec_header_file, [[y.tab.h]],
+m4_if(b4_spec_header_file, [y.tab.h], [],
       [b4_percent_define_default([[api.header.include]],
                                  [["@basename(]b4_spec_header_file[@)"]])])
 
