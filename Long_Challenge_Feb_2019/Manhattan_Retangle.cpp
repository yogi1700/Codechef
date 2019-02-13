#include<bits/stdc++.h>

using namespace std;


int main()
{
   int t;
   cin >> t;
   while(t--)
   {
      long long int  k, l , m , n, l5, l6;
      long long int x, y;
      cout << "Q" <<" "<< 0 <<" "<< 0 << endl;
      cin >> k;
      cout << "Q" <<" "<< 0 <<" "<< 1000000000 << endl;
      cin >> l;
      cout << "Q" <<" "<< 1000000000 <<" "<< 0 << endl;
      cin >> m;
      cout << "Q" <<" "<< 1000000000 <<" "<< 1000000000 << endl;
      cin >> n;
      long long int  m1 = ((k - m + 1000000000)) , m2 = ((k - l + 1000000000));
      cout << "Q" <<" "<< m1 /2  <<" "<< 0 << endl;
      cin >> l5;
      cout << "Q" <<" "<< 0 <<" "<< m2 / 2 << endl;
      cin >> l6;
      x = k - m + 1000000000 - l6;
      y = k + 1000000000 - l - l5;      
      cout << "A" <<" "<< l6 <<" "<< l5 << " "<< x << " " << y << endl;
      int f;
      cin >> f; 
   }   
}
