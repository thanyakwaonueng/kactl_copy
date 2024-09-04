/**
 * Author: Theerada Siri
 * Description: Gaussian elimination with partial pivoting
 * Also calculates determinant
 */
ld elim(vector<vector<ld> > &A, vector<ld> &b) {
  int n=A.size();
  ld det=1; //OPTIONAL CALCULATE DET, return ld, not void
  //REF
  for (int i=0;i<n-1;i++) {
    //PIVOT
    int bigi=max_element(A.begin()+i, A.end(), [i](vector<ld> &r1, vector<ld> &r2)
            {return fabs(r1[i])<fabs(r2[i]);})-A.begin(); 
    swap(A[i], A[bigi]);
    swap(b[i], b[bigi]);
    if (i!=bigi) det*=-1; //DET PART
    for (int j=i+1;j<n;j++) {
      ld m=A[j][i]/A[i][i];
      for (int k=i;k<n;k++)
        A[j][k]-=m*A[i][k];
      b[j]-=m*b[i];
    }
  }
  //DET PART
  for (int i=0;i<n;i++) det*=A[i][i];
  //BACKSUB
  for (int i=n-1;i>=0;i--) {
    for (int j=i+1;j<n;j++)
      b[i]-=A[i][j]*b[j];
    b[i]/=A[i][i];
  }
  return det;
}
