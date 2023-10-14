#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define for0i(n) for(int i=0;i<n;i++)
#define for1i(n) for(int i=1;i<=n;i++)
#define for0j(n) for(int j=0;j<n;j++)
#define for1j(n) for(int j=1;j<=n;j++)
#define all(x) (x).begin(), (x).end()
#define vl vector <ll>
#define MOD 1000000007
#define INF 1e18
#define mp make_pair
#define MEM(a,x) memset(a,x,sizeof(a))
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

void speed(){
	ios::sync_with_stdio(0);
    cin.tie(0);
}
void file(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
}
bool checkPrime(ll n){
	if(n==2) return true;
	if(n==1)return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
void iff(bool t){
	if(t) cout<<"YES\n";
	else cout<<"NO\n";
}
void print(ll n, ll arr[]){
	for0i(n) cout<<arr[i]<<" "; cout<<endl;
}
ll binPow(ll a, ll b, ll m){
	if(b==0) return 1;
	if(b==1) return a % m;
	ll ans = binPow(a, b/2, m);
	ans = (ans * ans) % m;
	if(b%2==1) ans = (ans * a) % m;
	return ans ;
}
ll inv(ll a,ll m) {
	return (binPow(a, m-2, m)%m);
}
bool pairSort(pair<ll,ll> &a, pair<ll,ll> &b){
	if(a.first==b.first) return (a.second < b.second);
    return (a.first > b.first);
}
ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int limit = 1e6;
vector<ll> primeFactor[1000001];
vector<bool> isPrime(1000001,true);
void sieve() 
{ 
	isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= limit; p++) { 
        if (isPrime[p] == true) { 
        	primeFactor[p].pb(p);
            for (int i = p * 2; i <= limit; i += p) {
        		primeFactor[i].pb(p);
                isPrime[i] = false; 
            }
        } 
    } 
} 


//--------------------------###--------------------------------//
//solution here


void solve(){
	//
}
int main(){
	speed(); 
	 file();
	sieve();
	ll t=1, T=1;
	cin>>T;

	while(t<=T){
		// cout<<"Case "<<t<<": ";
		solve();
		t++;
	} 
	return 0;
}