#include<iostream>
#define sqrt(x) __builtin_sqrt(x)
#define memcpy(dest, src, n) __builtin_memcpy(dest, src, n)
#define memset(st, val, n) __builtin_memset(st, val, n)
#define memmove(dest, src, n) __builtin_memmove(dest, src, n)
#define closeios() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fropen(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout)
#define ep emplace
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int, int>
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define stci static_cast<int>
#define stcb static_cast<bool>
#define gt greater
#define vc vector
#define uid uniform_int_distribution
#define fillinf(x) memset((x), 0x3f, sizeof(x))
#define fillninf(x) memset((x), 0xc0, sizeof(x))
#define fillzero(x) memset((x), 0, sizeof(x))
template<typename t> t sqr(t x){return (x*x);}
template<typename t> t abs(t x){return (x>0?x:-x);}
template<typename t> t inrange(t n, t l, t r){return (l<=n&&n<=r);}
template<typename... args>
#ifdef USE_STDERR_STREAM
void errorf(const char* format, args... v){fprintf(stderr, format, v...);}
#else
void errorf(const char* format, args... v){}
#endif
int log2(int x){return (31-__builtin_clz(x));}
long long log2(long long x){return (63-__builtin_clzll(x));}
long long min(int x, long long y){return std::min((long long)x, y);}
long long min(long long x, int y){return std::min(x, (long long)y);}
long long max(int x, long long y){return std::max((long long)x, y);}
long long max(long long x, int y){return std::max(x, (long long)y);}
int ceildiv(int x, int y){return (x%y?x/y+1:x/y);}
#define int2ll 0
#if int2ll
#define intEx signed
#define int long long
#else
#define intEx int
#define ll long long
#endif
using namespace std;

const int maxn=114514;


intEx main(){
//	fropen("");
//	closeios();
	// code
	return 0;
}