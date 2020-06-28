#include<stdio.h>
#include<math.h>

const int divide=10;
const double edge=10.0;
const double f=1.0;

//p(x,y)=sqrt(x^2 + y^2)
double p(double x,double y){
  if(x<0) return x*tan(y);
  else if(y==0) return 0;
  else return x/y;
}

int main(){
  int i,j;
  double x,y,dpdx,dpdy,h=(edge/(double)divide);
  for(i=-divide;i<=divide;i++){
    for(j=-divide;j<=divide;j++){
      x=h*((double)i);
      y=h*((double)j);
      dpdx=(p(x+h,y)-p(x-h,y))/(2*h);
      dpdy=(p(x,y+h)-p(x,y-h))/(2*h);
      printf("%.12lf %.12lf %.12lf %.12lf\n",x,y,-dpdy/f,dpdx/f);
    }
  }
}
