/**
 * Author: Theerada Siri
 * Description: can hold the number of digit to find that
 * satisfy p(x) for each digit.
 */
#define DP dp[pos][is_eq]
ll solve(int pos, bool is_eq) {
	if (~DP) return DP;
	if (pos==n)
		//check for predicate (here it is p(x)=True)
		return DP=1;
	DP = 0;
	for (int i=0;i<=(is_eq?r[pos]:9);i++)
		DP += solve(pos+1, is_eq && i==r[pos]);
	return DP;
}

