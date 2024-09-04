/**
 * Author: Theerada Siri
 * Description: Chinese Remainder Theorm
 */
ll CRT(vector<ll> &a, vector<ll> &n) {
  ll prod = 1;
  for (auto ni:n) prod*=ni;

  ll sm = 0;
  for (int i=0; i<n.size(); i++) {
    ll p = prod/n[i];
    sm += a[i]*inv(p, n[i])*p;
  }
  return sm % prod;
}

