@@ -26,6 +26,7 @@
 #include "bitset.h"
 #include "quotearg.h"
 #include "symtab.h"
+#include "gram.h"
 #include "getargs.h"
 #include "reader.h"
 #include "gram.h"
@@ -51,7 +52,7 @@ static state_t *this_state = NULL;
 static state_t *last_state = NULL;
 
 static int nshifts;
-static short *shift_symbol = NULL;
+static token_number_t *shift_symbol = NULL;
 
 static short *redset = NULL;
 static short *shiftset = NULL;
@@ -116,7 +117,7 @@ allocate_storage (void)
   shiftset = XCALLOC (short, nsyms);
   redset = XCALLOC (short, nrules + 1);
   state_hash = XCALLOC (state_t *, STATE_HASH_SIZE);
-  shift_symbol = XCALLOC (short, nsyms);
+  shift_symbol = XCALLOC (token_number_t, nsyms);
 }
 
 
@@ -161,20 +162,19 @@ new_itemsets (void)
   nshifts = 0;
 
   for (i = 0; i < nritemset; ++i)
-    {
-      int symbol = ritem[itemset[i]];
-      if (symbol >= 0)
-	{
-	  if (!kernel_size[symbol])
-	    {
-	      shift_symbol[nshifts] = symbol;
-	      nshifts++;
-	    }
-
-	  kernel_base[symbol][kernel_size[symbol]] = itemset[i] + 1;
-	  kernel_size[symbol]++;
-	}
-    }
+    if (ritem[itemset[i]] >= 0)
+      {
+	token_number_t symbol
+	  = item_number_as_token_number (ritem[itemset[i]]);
+	if (!kernel_size[symbol])
+	  {
+	    shift_symbol[nshifts] = symbol;
+	    nshifts++;
+	  }
+
+	kernel_base[symbol][kernel_size[symbol]] = itemset[i] + 1;
+	kernel_size[symbol]++;
+      }
 }
 
 
@@ -185,7 +185,7 @@ new_itemsets (void)
 `-----------------------------------------------------------------*/
 
 static state_t *
-new_state (int symbol)
+new_state (token_number_t symbol)
 {
   state_t *p;
 
@@ -229,7 +229,7 @@ new_state (int symbol)
 `--------------------------------------------------------------*/
 
 static int
-get_state (int symbol)
+get_state (token_number_t symbol)
 {
   int key;
   int i;
@@ -298,7 +298,7 @@ append_states (void)
 {
   int i;
   int j;
-  int symbol;
+  token_number_t symbol;
 
   if (trace_flag)
     fprintf (stderr, "Entering append_states, state = %d\n",
