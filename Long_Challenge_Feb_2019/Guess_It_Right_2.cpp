

#include<bits/stdc++.h>

#define ll long long int

#define D 1000000007

using namespace std;

ll pow(ll x, ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = pow(x, y/2); 
    if (y%2 == 0) 
        return (temp % D *temp % D) % D; 
    else
        return ( x % D * temp % D* temp % D) % D; 
} 



ll modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

int main()
{
     int t;
     cin >> t;
     while(t--)
     {
        ll n, k, m;
        cin >> n >> k >> m;
        ll odd = 0, even = 0, n1, sum1;
        if(m % 2 == 0)
          even = 1;
        else
          odd = 1;
        n1 = m / 2;
        cout << pow( n , n1) << endl;
        cout << "n1 = " << n1 << endl;
        cout << pow(n - 1, n1) << endl;
        if(m > 2)
        sum1 = ((pow( n , n1) - pow( n - 1, n1)) % D * modInverse(pow(n, n1), D) % D) % D;
        if( m == 2)
        sum1 = modInverse(n,D);
        cout << "sum1 = " << sum1 << endl;  
        if(even == 1)
         {
           cout << pow(n - 1, n1) << " " << modInverse( pow(n , n1) *(n + k), D) << endl; 
           sum1 = ( sum1  % D + (pow(n - 1, n1) % D * modInverse( (pow(n , n1) % D *(n + k) % D) % D, D) % D) % D ) % D;
         }         
         else if(m > 2)
         {
           cout << pow(n - 1, n1) << " " << modInverse( pow(n , n1 + 1), D) << "  "<< (pow(n - 1, n1) * modInverse( pow(n , n1 + 1), D))<< endl; 
           sum1 = (sum1 % D + ( pow(n - 1, n1) % D * modInverse( pow(n , n1 + 1), D) % D ) % D) % D;
         }
         else
         {
           sum1 = modInverse(n,D);
         } 
       cout << sum1 << endl;
     }
}
