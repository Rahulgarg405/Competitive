#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

void solve(){
	int n;
	cin>>n;
	set<int> st;
	for(int i = 0 ; i<n ; i++){
		int x;
		cin>>x;
		st.insert(x);
	}
	cout<<st.size()<<"\n";
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