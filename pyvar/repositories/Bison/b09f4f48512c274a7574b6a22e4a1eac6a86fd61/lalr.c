@@ -56,7 +56,7 @@ typedef struct goto_list
 } goto_list;
 
 
-/* LA is a LR by NTOKENS matrix of bits.  LA[l, i] is 1 if the rule
+/* LA is an NLA by NTOKENS matrix of bits.  LA[l, i] is 1 if the rule
    LArule[l] is applicable in the appropriate state when the next
    token is symbol i.  If LA[l, i] and LA[l, j] are both 1 for i != j,
    it is a conflict.  */
