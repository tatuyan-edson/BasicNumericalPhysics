#include<stdio.h>
#include<math.h>
#define pi 3.14
#define g 9.81
#define mu 0.0000179

int main(){
  int i,j;
  double v,xv,yv,theta,h;
  double xa=0.0,ya=0.0;
  double xarr[128],yarr[128];
  v=5.0;
  theta=pi/4.0;
  h=0.01;
  xv=v*sin(theta);
  yv=v*cos(theta);
  for(i=0;i<100;i++){
    xa+=(xv*h);
    ya+=(yv*h);
    printf("%.12lf %.12lf\n",xa,ya);
    xarr[i]=xa;
    yarr[i]=ya;
    xv-=(xv*mu+g*h);
    yv-=(yv*mu);
  }
  //for(i=0;i<100;i++){
  //  printf("%.12lf\n",xarr[i]);
  //}printf("\n\n\n");
  //for(i=0;i<100;i++){
  //  printf("%.12lf\n",yarr[i]);
  //}//printf("\n\n\n");
  return 0;
}
