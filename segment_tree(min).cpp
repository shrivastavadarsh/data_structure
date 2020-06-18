#include <bits/stdc++.h>
#include<numeric>
#include<cstdlib>
#define ll long long int
#define all(x) x.begin(),x.end()

 #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define v vector<long long int> 
#define vv vector< int> 
#define gcd(m,n) __gcd(m,n)
#define vp vector<pair<long long int ,long long int>>
#define pb push_back
#define mp make_pair
#define pp pop_back
#define iter vector<int>::iterator
#define pa pair<long long int ,long long int> 
#define f(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,n) for (ll i=a ; i<n ;i+=1)
#define fe(d,e) for(auto d:e)
#define mod 1000000007
#define F first
#define S second
#define sett set<long long int>
#define um unordered_map<ll,ll>
# define N 100005LL





using namespace std;
//  for min-max type queries



int ar[100001] , st[400004];

void build(int si , int ss , int se)
{
	if(ss == se)
	{
		st[si] = ar[ss];
		return ;
	}
 
	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1 ,mid+1 , se);
 
	st[si] = min(st[2*si] , st[2*si+1]);
}
int query(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return INT_MAX;
 
	if(ss >= qs && se <= qe) return st[si];
 
	int mid = (ss + se) / 2;
 
	return min(query(2*si , ss , mid , qs , qe) , query(2*si+1 , mid+1 , se , qs , qe));
}
// in upadte si means the index u are changing
void update(int si,int ss,int se,int qi){
    if (ss==se){
        st[si]=ar[ss];
        return;
    }
    int mid = (ss+se)/2;
    if (qi<=mid)update(2*si,ss,mid,qi);
    else update(2*si+1,mid+1,se,qi);
    st[si] = min(st[2*si],st[2*si+1]);

}
int main(){
    int n;
    cin>>n;
    
    loop(i,1,n+1){
        cin>>ar[i];
    }
    
    
    build(1,1,n);
    // loop(i,1,4*n)cout<<st[i]<<" ";

    // cout<<endl;
    
    int q;
    cin>>q;
    int l,r,z;
    f(i,q){
    cin>>l>>r;
    // 1-indexed array and 1-indexed query
    

    int ans = query(1,1,n,l,r);


    

    return 0;
}


