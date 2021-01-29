@@ -66,7 +66,7 @@ symbol *
 InadequacyList__getContributionToken (InadequacyList const *self,
                                       ContributionIndex i)
 {
-  aver (0 <= i && i < self->contributionCount);
+  aver (0 <= i && i < self->contributionCount); (void) i;
   return self->inadequacy.conflict.token;
 }
 
