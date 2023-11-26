#include <bits/stdc++.h>
using namespace std;
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
typedef complex<double> cpx;
typedef __int128 ll;

void fft(vector<cpx>& a) {
    int n=sz(a),L=31-__builtin_clz(n);
    static vector<complex<long double>> R(2,1);
    static vector<cpx> rt(2,1);
    for(int k=2;k<n;k<<=1){
        R.resize(n);rt.resize(n);
        auto x=polar(1.0L,acos(-1.0L)/k);
        for(int i=k;i<k+k;i++)rt[i]=R[i]=i&1?R[i/2]*x:R[i/2];
    }
    vector<int> rev(n);
    for(int i=0;i<n;i++)rev[i]=(rev[i>>1]|(i&1)<<L)>>1;
    for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k<<1)for(int j=0;j<k;j++){
                //cpx z=rt[j+k]*a[i+j+k];
                auto x=(double*)&rt[j+k],y=(double*)&a[i+j+k];
                cpx z(x[0]*y[0]-x[1]*y[1],x[0]*y[1]+x[1]*y[0]);
                a[i+j+k]=a[i+j]-z,a[i+j]+=z;
            }
    }
}

template <typename T>
vector<T> multiply(const vector<T>& a,const vector<T>& b){
    if(a.empty()||b.empty()) return {};
    vector<T> res(sz(a)+sz(b)-1);
    int n=1<<(32-__builtin_clz(sz(res)-1));
    vector<cpx> in(n),out(n);
    copy(all(a),in.begin());
    for(int i=0;i<sz(b);i++)in[i].imag(b[i]);
    fft(in);
    for(cpx& x:in)x*=x;
    for(int i=0;i<n;i++)out[i]=in[-i&(n-1)]-conj(in[i]);
    fft(out);
    for(int i=0;i<sz(res);i++)
        res[i]=static_cast<T>(imag(out[i])/(n<<2)+(is_integral_v<T>?(imag(out[i])>0?0.5:-0.5):0));
    return res;
}

int main(){
    string a,b;cin>>a>>b;
    vector<ll> x,y;
    ll z=0,base=100000,power=log10(base);
    for(int i=0;i<sz(a);i++){
        z=z*10+(a[i]-'0');
        if((i+1)%power==sz(a)%power)x.push_back(z),z=0;
    }
    for(int i=0;i<sz(b);i++){
        z=z*10+(b[i]-'0');
        if((i+1)%power==sz(b)%power)y.push_back(z),z=0;
    }
    vector<ll> ans=multiply(x,y);
    reverse(all(ans));
    ans.resize(sz(ans)+2+ceil(log10(300000)/power));
    for(int i=0;i<sz(ans)-1;i++)ans[i+1]+=ans[i]/base,ans[i]%=base;
    int idx=sz(ans)-1;
    while(idx>=0&&!ans[idx])idx--;
    if(idx<0) printf("0");
    else{
        printf("%lld",ans[idx]);
        while(idx--)printf("%0*lld",(int)power,ans[idx]);
    }
    return 0;
}
