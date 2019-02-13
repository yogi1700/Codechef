

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{

   int t;
   cin >> t;
   while(t--)
   {
     int n;
     cin >> n;
     vector<pair<int, int>> input;
     map<int , int> hp;
     for(int i = 0; i < n ; i++)
     {
          int x;
          cin >> x;
          input.push_back(make_pair(x, i + 1));
          hp[x]++;
     }
     sort(input.begin(), input.end());
     int c = 1;
     /*for(auto it = hp.begin(); it != hp.end(); it++)
     {
         cout << it-> first << it -> second << "\n";
     }*/
     //cout << "\n";
     for(int i = 0; i < n - 1 ; i++)
     {
        if(input[i].first == input[i + 1].first)
            {
               if(hp.find(input[i].second) != hp.end() && hp.find( input[i + 1].second) != hp.end())
                {
                  //cout <<  input[i].second << " " <<  input[i + 1].second;
                  cout << "Truly Happy";
                  c = 0;
                  break;
                }
                            
           }
     }
     
     if(c == 1)
      cout << "Poor Chef";
     cout << "\n";
   }
}




