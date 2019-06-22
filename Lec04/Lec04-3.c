#include<stdio.h>
#include<math.h>

const double dt = 1e-3;
const int cnt = 86400000;
const double omega = 7.292e-5;
const double pi = 3.1415926535897932384;

//deg to rad
double dtr(double x){return (x*pi)/180.0;}

int main(){
  int i,j;
  double velocity,theta,vx,vy,nvx,nvy,phi,x,y,fz,f;
  scanf("%lf%lf%lf",&velocity,&theta,&phi);
  vx=velocity*cos(dtr(theta));
  vy=velocity*sin(dtr(theta));
  x=0.0;
  y=phi*(40000.0e3/360.0);
  fz=2*omega;
  for(i=0;i<cnt;i++){
    //f=fz*sin(dtr(phi));//f-approximation
    //f=fz*(1+dtr(y*(360.0/40000.0e3)));//beta-approximation
    f=fz*sin(dtr(y*(360.0/40000.0e3)));
    if(i%10000==0){
      printf("%.12lf %.12lf\n",x/1e3,y/1e3);
    }
    x+=dt*vx;
    y+=dt*vy;
    nvx=vx+f*vy*dt;
    nvy=vy-f*vx*dt;
    vx=nvx;
    vy=nvy;
  }
}
