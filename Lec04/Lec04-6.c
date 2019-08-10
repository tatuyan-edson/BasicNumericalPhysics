#include<stdio.h>
#include<math.h>

const double omega = 7.292e-5;
const double phi=0.6;
const double dt=1;
const double g=9.8;
const long long times=1000000;
const long long l=60;

typedef struct{
  double x;
  double y;
}vec;

int main(){
  long long i;
  double k,f=2*omega*sin(phi);
  vec bx,bv,ba;
  vec x,v,a;
  vec nx,nv,na;
  double tmp;
  x=(vec){0.1,0};
  v=(vec){0,0};
  a=(vec){0,0};
  for(i=0;i<times;i++){
    k=sqrt(x.x*x.x + x.y*x.y + l*l);
    na=(vec){-(g*x.x)/k - f*v.y ,-(g*x.y)/k + f*v.x};
    if(!i){
      nv=(vec){v.x + a.x*dt,v.y + a.y*dt};
      nx=(vec){x.x + v.x*dt,x.y + v.y*dt};
    }
    else{
      nv=(vec){bv.x + 2.0*a.x*dt,bv.y + 2.0*a.y*dt};
      nx=(vec){bx.x + 2.0*v.x*dt,bx.y + 2.0*v.y*dt};
    }
    bx=x;
    bv=v;
    ba=a;
    x=nx;
    v=nv;
    a=na;
    if(i%1000==0){
      printf("%.12lf %.12lf\n",bx.x,bx.y);
    //  printf("v:%.12lf %.12lf\n",bv.x,bv.y);
    //  printf("a:%.12lf %.12lf\n",ba.x,ba.y);
    }
  }

  return 0;
}
