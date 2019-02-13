

#include<bits/stdc++.h>

#define ll long long int

#define D 1000000007

using namespace std;

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 

void lowest(ll &den3, ll &num3) 
{ 
    ll common_factor = gcd(num3,den3);
    if(common_factor != 0)
    { 
    den3 = den3/common_factor; 
    num3 = num3/common_factor; 
    }
} 
  
void addFraction(ll num1, ll den1, ll num2, ll den2, ll &num3, ll &den3) 
{ 
    den3 = gcd(den1,den2); 
    den3 = (den1*den2) / den3;
    if(den1 != 0)
    num3 = (num1)*(den3/den1); 
    if(den2 != 0)
     num3 += (num2)*(den3/den2); 
    lowest(den3,num3); 
} 


void multiplyFraction(ll num1, ll den1, ll num2, ll den2, ll &num3, ll &den3) 
{ 
    den3 = (den1*den2); 
    num3 = (num1)*(num2); 
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

/*ll modInverse(ll a, ll m) 
{ 
    a = a%m; 
    for (ll x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
}*/ 


int main()
{
     int t;
     cin >> t;
     while(t--)
     {
        ll n, k, m;
        cin >> n >> k >> m;
        ll odd = 0, even = 0, n1, d1, n2, d2, temp1, temp2, temp3 = 1, temp4 = n, sum1, sum2 , sum3 = 1, sum4 = n;
        if(m % 2 == 0)
          even = 1;
        else
          odd = 1;
        sum1 = 1, sum2 = n;
        for(ll i = 1; i < (m / 2); i++)
          {
           n1 = 1;
           d1 = n;
           temp1 = sum2 - sum1;
           temp2 = sum2;
           multiplyFraction(n1, d1, temp1, temp2 , n2, d2);
           //cout << " n2 = "<< n2 << " d2 = " << d2 << endl;
           addFraction(sum1, sum2, n2, d2, sum3, sum4);
           //cout << " n3 = "<< temp3 << " d3 = " << temp4 << endl;
           sum1 = sum3; 
           sum2 = sum4;
           //cout << " sum1 = "<< sum1 << " sum2 = " << sum2 << endl;
         }
        if(even == 1)
         {
           n1 = 1;
           d1 = n + k;
           temp1 = sum2 - sum1;
           temp2 = sum2;
           multiplyFraction(n1, d1, temp1, temp2 , n2, d2);
           //cout << " n3 = "<< temp3 << " d3 = " << temp4 << endl;
           addFraction(sum1, sum2, n2, d2, sum3, sum4);
           //cout << " n3 = "<< temp3 << " d3 = " << temp4 << endl;
           sum1 = sum3; 
           sum2 = sum4;
           //cout << " sum1 = "<< sum1 << " sum2 = " << sum2 << endl;
             
         }         
         else if(m > 2)
         {
           n1 = 1;
           d1 = n;
           temp1 = sum2 - sum1;
           temp2 = sum2;
           multiplyFraction(n1, d1, temp1, temp2 , n2, d2);
           temp3 = n2;
           temp4 = d2;
           addFraction(sum1, sum2, n2, d2, sum3, sum4);
         } 
         else
         {
            sum3 = sum1;
            sum4 = sum2;
         }
       //cout << " temp3 = "<< temp3 << " temp4 =" << temp4 << endl;
       //cout << " sum3 = "<< sum3 << " sum4 =" << sum4 << endl;
       cout << sum3 * 1ll * modInverse(sum4, D) << endl;
     }
}
