#include <bits/stdc++.h>
using namespace std;

int main(){
  ofstream oftvx("vx_t.dat");
  ofstream oftvy("vy_t.dat");
  ofstream oftyx("y_x.dat");
  

  double p=1.3;
  double s=3.14/10000;
  double theta=1.0;
  double g=9.87;
  double dt=0.01;
  double v0=150;
  double m=0.14;

  double vx,vy,x,y;
  vx=v0*cos(theta);vy=v0*sin(theta);x=y=0;
  for(double t=0;t<=10;t+=dt){
    oftvx<<t<<"\t"<<vx<<endl;
    oftvy<<t<<"\t"<<vy<<endl;
    oftyx<<x<<"\t"<<y<<endl;

    double v=sqrt(vx*vx+vy*vy);

    x+=vx*dt;
    y+=vy*dt;
    vx+=(-p*s*v/m)*vx*dt;
    vy+=(-g+(-p*s*v/m)*vy)*dt;
  }
}