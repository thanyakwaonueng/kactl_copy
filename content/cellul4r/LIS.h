/**
 * Author: Theerada Siri
 * Description: find hte length of LIS.
 * default is non-decreasing
 * 
 * Time: O()
 */
//Length of LIS (default is non-decreasing)

vl lis;
ll n, a[N];
int main() {
    F(i, 0, n) {
        if(lis.empty() || a[i] >= lis.back()) lis.push_back(a[i]); //change to > for strictly increasing
        else *upper_bound(A(lis), a[i]) = a[i]; //change to lower_bound for strictly increasing
    }
    cout << lis.size() << '\n';
}
