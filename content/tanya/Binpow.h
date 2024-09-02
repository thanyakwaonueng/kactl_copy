/**
 * Author: Suthana Kwaonueng
 * Description: binary exponentation
 * Time: O(\log N) 
 */
long long binpow(long long a, int n){
    long long res = 1;
    while(n>0){
        if(n&1){
            res = res * a;
        }
        a = a * a;
        n>>=1;
    }
    return res;
}
