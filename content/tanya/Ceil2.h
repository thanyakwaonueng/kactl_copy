/**
 * Author: Suthana Kwaonueng
 * Description: integer ceiling
 * Time: O(1) 
 */
//ceil2 work for bot positive and nagative a(maybe. never test it)
//ceil(a/b)
int ceil2(int a,int b){
	int res=a/b;
	if(b*res!=a)res+=(a>0)&(b>0);
	return res;
}
