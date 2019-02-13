
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int t;
   cin >> t;
   while(t--)
   { 
     int n;
     cin >> n;
     vector<int>a;
     vector<int>d;

     for(int i = 0; i < n ; i++)
     {
         int x;
         cin >> x;
         a.push_back(x);
     }

     for(int i = 0; i < n ; i++)
     {
         int x;
         cin >> x;
         d.push_back(x);
     }

     vector<int>s;
     if((d[0] - a[n - 1] - a[1]) > 0)
       s.push_back(d[0]); 

     for(int i = 1; i < n - 1; i++)
     {
       if((d[i] - a[i - 1] - a[ i + 1]) > 0)
         s.push_back(d[i]);
     }

     if(d[n - 1] - a[0] - a[n - 2] > 0)
       s.push_back(d[n - 1]);
    
     int count = -1;
     if(s.size())
       count = s[0];

     for(int i = 1; i < s.size(); i++)
     {
       if(s[i] > count)
       {
         count = s[i];
       }
     }
      cout << count << endl;     
    }
    return 0;
}  
