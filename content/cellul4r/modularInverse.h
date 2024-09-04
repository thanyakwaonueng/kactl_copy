/**
 * Author: Theerada Siri
 * Description: 
 *
 * 
 * Time: O()
 */

ll inv(ll a, ll b){return 1<a ? b - inv(b%a,a)*b/a : 1;}
