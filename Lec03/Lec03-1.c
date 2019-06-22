#include<stdio.h>

#define h 1
#define dz 0.000001
#define g 9.80665
#define rho 1200

int main(){
  int i,j;
  double sig=1013.25,hi=0.0;
  for(i=0;i<1000000;i++){
    sig+=(dz*rho*g)/100.0;
    hi+=dz;
    if(i%10000==9999){
      printf("%.12lf %.12lf\n",hi,sig);
      //printf("%.12lf %.12lf\n",hi,1013.25+(rho*g*hi)/100.0);
    }
  }
  return 0;
}
