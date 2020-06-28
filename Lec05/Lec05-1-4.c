//Sweeping for Multidiagonal
//https://atcoder.jp/contests/indeednow-finala-open/tasks/indeednow_2015_finala_e
//https://atcoder.jp/contests/indeednow-finala-open/submissions/7084156
#include<stdio.h>
#include<math.h>
#include<complex.h>
const double eps=1e-12;

//diagonal ... k=1
//tridiagonal ... k=2
//5-diagonal ... k=3
int sweeping_multidiagonal(double complex a[1024][32],int k,int n){
  int i,j,p;
  double complex t;
  //for(i=0;i<n;i++){
  //  for(j=0;j<=3*k+1;j++){
  //    printf("[%.12lf %.12lf]",creal(a[i][j]),cimag(a[i][j]));
  //  }printf("\n");
  //}
  for(i=0;i<n;i++){
    for(j=0;j<=k;j++){
      if(i+j>=n){
        if(j==k){return -1;}
        continue;
      }
      if(cabs(a[i+j][k-j])>eps){
        for(p=k-j;p+j<=3*k;p++){
          t=a[i][p+j];
          a[i][p+j]=a[i+j][p];
          a[i+j][p]=t;
        }
        t=a[i][3*k+1];
        a[i][3*k+1]=a[i+j][3*k+1];
        a[i+j][3*k+1]=t;
        break;
      }
      return -1;
    }
    for(j=1;j<=k;j++){
      if(i+j>=n){continue;}
      t=a[i+j][k-j]/a[i][k];
      a[i+j][k-j]=0.0;
      for(p=1;p<=2*k;p++){
        a[i+j][k-j+p]-=(t*a[i][k+p]);
      }
      a[i+j][3*k+1]-=(t*a[i][3*k+1]);
    }
  }
  //for(i=0;i<n;i++){
  //  for(j=0;j<=3*k+1;j++){
  //    printf("[%.12lf %.12lf]",creal(a[i][j]),cimag(a[i][j]));
  //  }printf("\n");
  //}
  for(i=n-1;i>=0;i--){
    for(j=1;j<=2*k;j++){
      if(i+j>=n){continue;}
      a[i][3*k+1]-=a[i][k+j]*a[i+j][3*k+1];
    }
    a[i][3*k+1]/=a[i][k];
  }
  return 0;
}

int main(){
  int i,j,n=1000,m;
  double complex matrix[1024][32];
  double complex last=10.0+5.0*I;
  double complex midk=-2.0+0.00007*I;
  for(i=0;i<1024;i++){
    for(j=0;j<32;j++){matrix[i][j]=0.0;}
  }
  for(i=1;i<n;i++){
    matrix[i][1]=1.0;
    matrix[i][2]=midk;
    matrix[i][3]=1.0;
  }
  matrix[0][2]=1.0;
  matrix[0][7]=(last*0.25);
  matrix[n][2]=1.0;
  matrix[n][7]=last;
  m=sweeping_multidiagonal(matrix,2,n+1);
  for(i=0;i<n+1;i++){
    printf("%.12lf %.12lf %.12lf\n",creal(matrix[i][7]),cimag(matrix[i][7]),(double)i);
  }
  //printf("%d\n",m);
}
