
#include<bits/stdc++.h>
#include<iostream>

using namespace std;


int gcd(int x, int y)
{

    if(y == 0)
         return x;

    else
       return gcd(y, x % y);       

}

int main()
{

   int t;
   cin >> t;
   while(t--)
   {
       long long int N, A, B, K, count = 0, g, l, s1, s2, s3;
       cin >> N >> A >> B >> K;
       if(A >= B)
          g = gcd(A,B);
       else
          g = gcd(B,A);
       l = A * B / g;
       cout << g << " " << l  << endl;
       /*for(int i =1; i <= N; i++)
       {
         if((i % A == 0 && i % B != 0) || (i % B == 0 && i % A != 0))
             {
               cout << i << endl; 
               count++;
             }
       }*/
       s1 = N / A;
       s2 = N / B;
       s3 = N / l;
       count = s1 + s2 - 2 * s3;
       cout << count << endl;
       if(count >= K)
        cout << "Win" << endl;
       else
        cout << "Lose" << endl;
   
   }
}
