//No of unique path
int paths(int n,int m){
  int N=m+n-2;
  int r=m-1;
  //calculate nCr
  int res=1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
        }
  return (int)res;
}
