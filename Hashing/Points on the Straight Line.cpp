int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
   
   map <double, int> m;
   int ans = 1;
   
   int l = X.size();
   if(l == 0) return 0;
   
   for(int i = 0;  i < l-1; i++)
   {
       int maxPoints = 0;
       int overlapping_points = 0;
       
       for(int j = i+1; j < l; j++)
       {
           double slope;
           
           if(Y[j] - Y[i] == 0 && X[j] - X[i] == 0) //same point
           {
               overlapping_points++;
               continue;
           }
           else if(Y[j] - Y[i] == 0)
           {
               slope = 0;
           }
           else if(X[j] - X[i] == 0)
           {
               slope = INT_MAX;
           }
           else slope = (double)(Y[j] - Y[i]) / (double) (X[j] - X[i]);
           
           if(m.find(slope) == m.end())
           {
               m[slope] = 2; //the 2 points between which m is calculated forms the line
           }
           else m[slope] = m[slope]+1;
           
           if(m[slope] > maxPoints) maxPoints = m[slope];
       }
       
       if(maxPoints == 0) //all were overlapping so have to consider base too
            maxPoints++;
       if(overlapping_points > 0) maxPoints = maxPoints + overlapping_points;
       
       
       m.clear();
       
       if(maxPoints > ans) ans = maxPoints;
   }
   
   return ans;
}
