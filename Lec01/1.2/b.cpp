#include <bits/stdc++.h>
using namespace std;

int main(){
  ofstream oftvx("bvx_t.dat");
  ofstream oftvy("bvy_t.dat");
  ofstream oftyx("by_x.dat");
  

  double p=1.3;
  p*=0.6;
  double s=0.015;
  double theta=5;
  theta*=3.14/180;
  double g=9.87;
  double dt=0.01;
  double v0=72;
  double m=0.056;

  double vx,vy,x,y;
  vx=v0*cos(theta);
  vy=v0*sin(theta);
  x=0;
  y=2;
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