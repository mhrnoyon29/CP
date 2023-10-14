#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define m_p make_pair
#define pb push_back
#define fi first
#define sc second
#define PI acos(-1.0)
#define MOD 1000000007
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define set(n, k) (n |= (1LL << k))
#define unset(n, k) (n &= ~(1LL << k))
#define check(n , k) (n & (1LL << k))
#define toggle(n, k) (n ^ (1LL << k))
#define fastio std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);
#define Check(n,pos) (n & (1<<pos))
#define Set(n,pos) (n  (1<<pos))
int popcount(ll n) {return __builtin_popcountll(n);}
int poplow(ll n) {return __builtin_ctzll(n);}
int pophigh(ll n) {return 63 - __builtin_ctzll(n);}
ll PERFECT_NUM[]={6,28,496,8128,33550336,8589869056,137438691328,2305843008139952128};
//-----------------------------------------------------------------------------------
//Sieve

const int N=1000005;
int MARK[N+1];
vector<int>PRIME;

void sieve(){
    MARK[1]=1;
    int root=sqrt(N);
    MARK[0]=MARK[1]=1;
    for(int i=4; i<N; i+=2) MARK[i]=1;
    
    for(int i=3; i<=root; i+=2){
        if(!MARK[i]){
            for(int j=i*i; j<=N; j+=(i*2)){
                MARK[j]=1;
            }
        }
    }
    PRIME.push_back(2);
    for(int i=3; i<=N; i+=2){
        if(!MARK[i]) PRIME.push_back(i);
    }
    return;
}
//-----------------------------------------------------------------------
//KMP 

int failure[N];
string txt, pat;

void failure_table(){
    int i=1, j=0, sz=pat.size();
    failure[0]=0;

    while(i<sz){
        if(pat[i]==pat[j]){
            j++;
            failure[i]=j;
            i++;
        }
        else{
            if(j==0){
                failure[i]=0;
                i++;
            }
            else j=failure[j-1];
        }
    }
    return;
}

int KMP(){
    int n=txt.size();
    int m=pat.size();
    failure_table();

    int i=0, j=0;
    while(i<n){
        if(pat[j]==txt[i]){
            i++; j++;
        }
        if(j==m) return i-j;
        else if(i<n && pat[j]!=txt[i]){
            if(j!=0) j=failure[j-1];
            else i++;
        }
    }
    return -1;
}

//-------------------------------------------------------------------
//Hashing

const ll bs=3797;
string S;
ll FH[N], RH[N], B[N];



void hash_koro(){
    B[0]=1;
    for(int i=1; i<N; i++) B[i]=(B[i-1]*bs)%MOD;

    //cin>>S;
    int sz=S.size();

    FH[0]=0;
    for(int i=1; i<=sz; i++) FH[i]=((FH[i-1]*bs)%MOD+(S[i-1]-'a'+1))%MOD;

    RH[sz+1]=0;
    for(int i=sz; i>=1; i--) RH[i]=((RH[i+1]*bs)%MOD+(S[i-1]-'a'+1))%MOD;
}

//-------------------------------------------------------------------
//Segment tree lazy propagation
vector<ll>arr;
struct{
    int prop;
    int sum;
}stree[3*N];


void init(int node, int lo, int hi){
    if(lo==hi){
        stree[node].sum=arr[lo];
        stree[node].prop=0;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(lo+hi)/2;

    init(left, lo, mid);
    init(right, mid+1, hi);

    stree[node].sum=stree[left].sum+stree[right].sum;
}

void update(int node, int lo, int hi, int l, int r, int val){
    if(lo>r || hi<l) return;
    if(lo>=l && hi<=r){
        stree[node].sum+=((hi-lo+1)*val);
        stree[node].prop+=val;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(left+right)/2;

    update(left, lo, mid, l, r, val);
    update(right, mid+1, r, l, r, val);
    stree[node].sum = stree[left].sum + stree[right].sum + (hi-lo+1)*stree[node].prop;
}

ll query(int node, int lo, int hi, int l, int r, int carry){
    if(lo>r || hi<l) return 0;
    if(lo>=l && hi<=r){
        return stree[node].sum + carry*(hi-lo+1);
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(left+right)/2;

    int res1=query(left, lo, mid, l, r, carry+stree[node].prop);
    int res2=query(right, mid+1, hi, l, r, carry+stree[node].prop);

    return res1+res2;
}

//-------------------------------------------------------------------------------


ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return ((a/gcd(a,b))*b);
}

ll BigMod(ll a, ll p, ll m){
    ll ret=1;
    while(p){
        if(p&1) ret=((ret%m)*(a%m))%m;
        a=((a%m)*(a%m))%m;
        p/=2;
    }
    return ret;
}
ll AddMul(ll a, ll p, ll m){
    ll ret=0;
    while(p){
        if(p&1) ret=((ret%m)+(a%m))%m;
        a=((a%m)+(a%m))%m;
    }
    return ret;
}
void iofile(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
}
//-------------------------------------------------------------------------
 /*TO GET SOMETHING YOU NEVER HAD YOU HAVE TO DO SOMETHING YOU NEVER DID*/
//-------------------------------------------------------------------------

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}


bool insideCircle(double Px, double Py, double Ax, double Ay, double Bx, double By, double w) {
    double dist1 = dist(0.0, 0.0, Ax, Ay);
    double dist2 = dist(0.0, 0.0, Bx, By);

    double dist3 = dist(Px, Py, Ax, Ay);
    double dist4 = dist(Px, Py, Bx, By);

    double dist5 = dist(Ax, Ay, Bx, By);
    
    if(dist1 <= w && dist3 <= w) return true;
    else if(dist2 <=w && dist4 <= w) return true;
    else if((dist1 <= w || dist2 <= w) && (dist3 <= w || dist4 <= w) && (dist5 <= w*(double)2)) return true;
    else return false;
}

void solve(){
    double px, py; cin>>px>>py;
    double ax, ay; cin>>ax>>ay;
    double bx, by; cin>>bx>>by;


    double l = 0, r = 10000, ans = 10000;
    while(r-l>1e-6){
        double m = (l+r)/2;
        if(insideCircle(px, py, ax, ay, bx, by, m)){
            ans = m;
            r = m;
        }
        else l = m;
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}


int main(){
    //sieve();
    fastio;
    iofile();
    ll t=1, tc=1;
    cin>>t;
    //cin.ignore();
    while(t--){
        //cout<<"Case "<<tc++<<": ";
        solve();
    }

    return 0;
}