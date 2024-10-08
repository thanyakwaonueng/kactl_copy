/**
 * Author: Theerada Siri
 * Description: return determinant of matrix
 * matrix multiplication, inverse matrix.
 * Time: O()
 */

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<vector<ld>> mat;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define A(a) (a).begin(), (a).end()
#define MAT(a, n, m) mat a(n, vector<ld>(m, 0));  
#define N 100010

ld elim(mat& a) { //a is n x m augmented matrix (m >= n), returns determinant
    ll n = a.size(), m = a[0].size();
    ld det = 1;
    F(i, 0, n) {
        ll bI = i;
        F(j, i, n) if(fabs(a[j][i]) > fabs(a[bI][i])) bI = j;
        swap(a[i], a[bI]);
        det *= i - bI ? -a[i][i] : a[i][i];
        if(!det) return 0;
        FD(k, m - 1, i - 1) a[i][k] /= a[i][i];
        F(j, 0, n) if(j - i) FD(k, m - 1, i - 1) a[j][k] -= a[j][i] * a[i][k];
    }
    return det;
}

mat mult(mat& a, mat& b) {
    ll n = a.size(), m = b.size(), p = b[0].size();
    MAT(c, n, p)
    F(i, 0, n) F(j, 0, m) F(k, 0, p) c[i][k] += a[i][j] * b[j][k];
    return c;
}

mat pw(mat& a, ll p) { //only works for p > 0
    if(p == 1) return a;
    mat t = pw(a, p / 2);
    t = mult(t, t);
    return p & 1 ? mult(t, a) : t;
}

mat inv(mat& a) { //inverts a, returns empty matrix if non-invertible
    ll n = a.size();
    MAT(b, n, 2 * n)
    F(i, 0, n) copy(A(a[i]), b[i].begin()), b[i][n + i] = 1;
    if(!elim(b)) return {{}};
    F(i, 0, n) FD(j, n - 1, -1) b[i][j] = b[i].back(), b[i].pop_back();
    return b;
}
