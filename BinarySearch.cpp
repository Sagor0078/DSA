#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
const int mxN = 1e6+8;
vector<ll> a(mxN);
void precompute(){
     ll i = 0;
     while(i*i<=mxN){
        a.push_back(i*i);
        i++;
     }
}
ll binary_search(ll x){
   ll low = 0 ;
   ll high = a.size() - 1;
   ll ans = 0;
   while(low<=high){
       ll mid = low+(high - low)/2;
       if(a[mid]>=x){
          ans = a[mid];
          high = mid - 1;
       }else{
          low = mid+1;
       }
   }
   return ans;
}
void solve(){
    precompute();
    ll N;
    cin>>N;
    map<ll,ll> mp;
    for(ll i=0;i<N;i++) mp[i] = -1;
    ll i = N-1;
    while(i>=0){
        if(mp[i] == -1){
            ll current_val = binary_search(i);
            ll x = current_val - i;
            ll y = x;
            while(x<=i){
                mp[x] = i;
                mp[i] = x;
                x++;
                i--;
            }
            i = y - 1;
        }
    }
    for(ll i=0;i<N;i++){
        cout<<mp[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int T;
    cin>>T;
    while(T--){
       solve();
    }
}