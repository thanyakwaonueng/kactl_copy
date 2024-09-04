/**
 * Author: Theerada Siri
 * Description: pow mod manul
 */
ll powmod(ll x, ll y){
  if(y==0) return 1LL;
  ll t=powmod(x,y/2);
  if (y%2==0) return (t*t)%M;
  return (((x*t)%M)*t)%M;
}

