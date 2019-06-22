#include<stdio.h>

#define h 10000
#define dz 0.01
#define g 9.80665
#define r 287.1

int main(){
  int i,j;
  double p=1013.25,hi=0.0,temp,rho;
  for(i=0;i<1000000;i++){
    temp=(273.15+25.00)-0.0065*h;
    rho=p/(r*temp);
    p-=(rho*g*dz);
    hi+=dz;
    if(i%10000==9999){
      printf("%.12lf %.12lf\n",hi,p);
    }
  }
  return 0;
}
