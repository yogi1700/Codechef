#include<bits/stdc++.h>

using namespace std;

/*void factor(vector<long long int>&res, long long int len) 
{ 
    long long int n = len;
    for (long long int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                res.push_back(i); 
  
            else 
            {
               res.push_back(i);
               res.push_back(n / i);
            }     
        } 
    }
}*/ 

bool comp(pair<char, long long int> data1, pair<char, long long int> data2)
{
   if(data1.second >= data2.second)
          return true;
   else
          return false;
}

int main()
{
   long long int t;
   cin >> t;
   while(t--)
   {
      string s;
      cin >> s;
      long long int len = s.length(), pl = 0, mi =0, limit1 = 0, limit2 = 0, t, k,count = 0, c1 = 0, n = len, i, j;          
      //cout << "len = " << len << endl;
      vector<pair<char,long long int>> data;
      map<char, long long int> mp;
      vector<long long int> res;
      //factor(res,len);
      for (i=1; i<=sqrt(n); i++) 
       { 
            if (n%i == 0) 
            { 
                if (n/i == i) 
                   res.push_back(i); 
                else 
                 {
                   res.push_back(i);
                   res.push_back(n / i);
                 }     
           }  
       }
      for(i = 0; i < len ; i++)
       {
         mp[s[i]] ++;         
       }
      //cout << "factors" << endl;
      /*for(long long int i = 0 ; i < res.size(); i++)
        {
           cout << res[i] << endl; 
        }*/
      for(auto it = mp.begin(); it != mp.end(); it++)
      {
         data.push_back(make_pair(it-> first,it->second));                    
      }
      sort(data.begin(), data.end(), comp);
      for(i = 0; i < res.size(); i++)
       {
           pl = 0, mi =0, limit1 = 0, limit2 = 0;
           k = len / res[i];
           //cout << " k = " << k << endl;
           if(k > 26 )
             continue;
           if(res[i] < len / 26)
              continue;
           vector<long long int>temp(data.size(), res[i]);
           for(j = 0; j < data.size(); j++)
             {
                    //cout << " temp" << j << " = " << temp[j] << " and data =" << data[j].second<< "\t";
                    long long int t = data[j].second - temp[j];
                    //cout << " t=" << t << "\t";
                    temp[j] = t;
                    //cout << " temp" << j << " = " << temp[j] << "\t";  
 		    //cout << "\n" ;                     
             }  
          //cout << "\n" ;
          for(j = 0; j < data.size(); j++)
            {
              if(temp[j] > 0 && limit1 < len)
                pl += temp[j];
              else if(temp[j] < 0 && limit2 < len)
                mi += temp[j];
              limit1 += res[i];
              limit2 += res[i];
              //cout << " res[j] ="  << res[i] << " limit1 = " << limit1 << " limit2 = " << limit2 << " pl ="<<pl << " mi =" << mi << "\n";
            }
           //cout << "pl = "<< pl << " mi = " << mi << endl;
           
           if( c1 == 0)
            {
               count = max(pl, abs(mi));
               c1 = 1;
            }
           else
           {
              t =  max(pl, abs(mi));           
              if(t < count)
                count = t;
           }
        }
          cout << count << endl;  
     }

   return 0;
}
