/**
 * Author: Theerada Siri
 */
//prime seive
for (ll i=2; i<NN; i++)
	if (prime[i]==0) {
		prime[i] = i;
		for (ll j=i*i;j<NN;j+=i) if(!prime[j]) prime[j]=i;
	}
// phi, uses seive and power from above. The formula is phi(p^i)=(p-1)*p^(c-1).
ll phi(ll n) {
  ll ans = n;
  while (n>1) {
    ll p = prime[n];
    while (n%p==0) n/=p;
    ans = ans/p*(p-1);
  }
  return ans;
}
