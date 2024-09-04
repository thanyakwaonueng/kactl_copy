/**
 * Author: Theerada Siri
 * Description: modular inverse a^-1 mod b
 */
ll inv(ll a, ll b){return 1<a ? b - inv(b%a,a)*b/a : 1;}

