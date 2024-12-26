#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;


ll mod(ll a, ll m = MOD) { 
    return a % m;
}
template <class T> class Math { 
    public: 
    vector<T> fact, invfact;
    Math() {} 
    Math(ll n) {
        fact.resize(n); 
        invfact.resize(n); 
        fact[0] = invfact[0] = 1; 
        for (ll i = 1; i < n; i++) { 
            fact[i] = mod(i * fact[i - 1]); 
            invfact[i] = modinv(fact[i]); 
        } 
    } 
    T modinv(T x, T m = MOD) { 
        return expo(x, m - 2, m); 
    } 
    T expo(T base, T exp, T m = MOD) { 
        T res = 1; 
        while (exp) { 
            if (exp & 1) res = mod(res * base, m); 
            base = mod(base * base, m); 
            exp >>= 1; 
        } 
        return res;         
    } 
    T choose(T n, T k) { 
        if (k < 0 || k > n) return 0; 
        T ans = fact[n]; 
        ans = mod(ans * invfact[n - k]); 
        ans = mod(ans * invfact[k]); 
        return ans;         
    }
};

// Arranging similar elements :
//  =  (n) ! / ((a1!) * (a2!) * .... * (an!));

void solve(){
	string s;
	cin>>s;
	int hash[26] = {0};
	for(auto x : s){
		hash[x-'a']++;
	}
	Math<ll> m(1e6+10);
	ll n = s.size();
	ll ans = m.fact[n];
	for(int i = 0 ; i<26 ; i++){
		if(hash[i] != 0){
			ans = (ans*m.invfact[hash[i]])%MOD;
		}
	}
	cout<<ans<<endl;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}