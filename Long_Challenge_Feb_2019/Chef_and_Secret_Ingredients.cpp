
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
     cout << n << endl;
     bool arr[26];
     memset(arr, true, sizeof(arr));
     for(int j = 0; j < n ; j++)
     {
          string s;
          cin >> s;
          bool temp[26]={false};
          for(int i = 0; i < s.size(); i++)
          {

             int x = s[i] - 'a';
             if(arr[x] == true)
               temp[x] = true;      
          }
        memcpy(arr,temp, 26);
     }
     int count = 0;
     for(int i = 0 ; i < 26 ; i++)
     {
       if(arr[i] == true)
           count++;
     }
     cout << count << endl;     
   }
}
