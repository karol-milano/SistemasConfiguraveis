@@ -37,7 +37,7 @@ muscle_kind_new (char const *k)
     return muscle_keyword;
   else if (STREQ (k, "string"))
     return muscle_string;
-  aver (0);
+  abort ();
 }
 
 char const *
@@ -49,7 +49,7 @@ muscle_kind_string (muscle_kind k)
     case muscle_keyword: return "keyword";
     case muscle_string:  return "string";
     }
-  aver (0);
+  abort ();
 }
 
 
