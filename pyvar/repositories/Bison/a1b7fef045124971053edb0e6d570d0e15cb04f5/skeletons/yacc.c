@@ -1486,7 +1486,7 @@ yypstate_new (void)
   yypstate *yyps;]b4_pure_if([], [[
   if (yypstate_allocated)
     return YY_NULLPTR;]])[
-  yyps = YY_CAST (yypstate *, malloc (sizeof *yyps));
+  yyps = YY_CAST (yypstate *, YYMALLOC (sizeof *yyps));
   if (!yyps)
     return YY_NULLPTR;]b4_pure_if([], [[
   yypstate_allocated = 1;]])[
@@ -1515,7 +1515,7 @@ yypstate_delete (yypstate *yyps)
 #endif]b4_lac_if([[
       if (yyes != yyesa)
         YYSTACK_FREE (yyes);]])[
-      free (yyps);]b4_pure_if([], [[
+      YYFREE (yyps);]b4_pure_if([], [[
       yypstate_allocated = 0;]])[
     }
 }
