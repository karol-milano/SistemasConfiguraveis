@@ -196,9 +196,6 @@ new_state (int symbol)
 {
   int n;
   core *p;
-  short *isp1;
-  short *isp2;
-  short *iend;
 
 #if TRACE
   fprintf (stderr, "Entering new_state, symbol = %d, state = %d\n",
@@ -208,18 +205,14 @@ new_state (int symbol)
   if (nstates >= MAXSHORT)
     fatal (_("too many states (max %d)"), MAXSHORT);
 
-  isp1 = kernel_base[symbol];
-  iend = kernel_end[symbol];
-  n = iend - isp1;
+  n = kernel_end[symbol] - kernel_base[symbol];
 
   p = CORE_ALLOC (n);
   p->accessing_symbol = symbol;
   p->number = nstates;
   p->nitems = n;
 
-  isp2 = p->items;
-  while (isp1 < iend)
-    *isp2++ = *isp1++;
+  shortcpy (p->items, kernel_base[symbol], n);
 
   last_state->next = p;
   last_state = p;
@@ -360,21 +353,13 @@ static void
 save_shifts (void)
 {
   shifts *p;
-  short *sp1;
-  short *sp2;
-  short *send;
 
   p = SHIFTS_ALLOC (nshifts);
 
   p->number = this_state->number;
   p->nshifts = nshifts;
 
-  sp1 = shiftset;
-  sp2 = p->shifts;
-  send = shiftset + nshifts;
-
-  while (sp1 < send)
-    *sp2++ = *sp1++;
+  shortcpy (p->shifts, shiftset, nshifts);
 
   if (last_shift)
     {
@@ -603,8 +588,6 @@ static void
 save_reductions (void)
 {
   short *isp;
-  short *rp1;
-  short *rp2;
   int item;
   int count;
   reductions *p;
@@ -630,12 +613,7 @@ save_reductions (void)
       p->number = this_state->number;
       p->nreds = count;
 
-      rp1 = redset;
-      rp2 = p->rules;
-      rend = rp1 + count;
-
-      for (/* nothing */; rp1 < rend; ++rp1, ++rp2)
-	*rp2 = *rp1;
+      shortcpy (p->rules, redset, count);
 
       if (last_reduction)
 	{
