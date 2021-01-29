@@ -36,7 +36,7 @@ Software Foundation, 59 Temple Place - Suite 330, Boston, MA
 # if HAVE_SYS_TIME_H
 #  include <sys/time.h>
 # endif
-int time_report = 0;
+int timevar_report = 0;
 
 #endif
 
@@ -134,7 +134,7 @@ static float clocks_to_msec;
 /* See timevar.h for an explanation of timing variables.  */
 
 /* This macro evaluates to nonzero if timing variables are enabled.  */
-#define TIMEVAR_ENABLE (time_report)
+#define TIMEVAR_ENABLE (timevar_report)
 
 /* A timing variable.  */
 
