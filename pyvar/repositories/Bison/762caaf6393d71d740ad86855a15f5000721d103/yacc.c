@@ -535,19 +535,19 @@ union yyalloc
 #endif
 
 #if defined YYCOPY_NEEDED && YYCOPY_NEEDED
-/* Copy COUNT objects from FROM to TO.  The source and destination do
+/* Copy COUNT objects from SRC to DST.  The source and destination do
    not overlap.  */
 # ifndef YYCOPY
 #  if defined __GNUC__ && 1 < __GNUC__
-#   define YYCOPY(To, From, Count) \
-      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
+#   define YYCOPY(Dst, Src, Count) \
+      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
 #  else
-#   define YYCOPY(To, From, Count)              \
+#   define YYCOPY(Dst, Src, Count)              \
       do                                        \
         {                                       \
           YYSIZE_T yyi;                         \
           for (yyi = 0; yyi < (Count); yyi++)   \
-            (To)[yyi] = (From)[yyi];            \
+            (Dst)[yyi] = (Src)[yyi];            \
         }                                       \
       while (YYID (0))
 #  endif
