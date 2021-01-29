@@ -207,6 +207,8 @@ main (int argc, char *argv[])
       timevar_pop (tv_parser);
     }
 
+ finish:
+
   timevar_push (tv_free);
   nullable_free ();
   derives_free ();
@@ -228,8 +230,6 @@ main (int argc, char *argv[])
   if (trace_flag & trace_bitsets)
     bitset_stats_dump (stderr);
 
- finish:
-
   /* Stop timing and print the times.  */
   timevar_stop (tv_total);
   timevar_print (stderr);
