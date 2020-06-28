#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define inf 1000000000000000000
#define eps 0.00001
#define cost 100

typedef struct{
  double x;
  double y;
}point;

bool iseq(point a,point b){
  if(fabs(a.x-b.x)>eps){return false;}
  if(fabs(a.y-b.y)>eps){return false;}
  return true;
}

point vector_plus(point a,point b){
  point r;
  r.x=a.x+b.x;
  r.y=a.y+b.y;
  return r;
}

point vector_minus(point a,point b){
  point r;
  r.x=a.x-b.x;
  r.y=a.y-b.y;
  return r;
}

//naiseki
double dotproduct(point a,point b){
  return a.x*b.x+a.y*b.y;
}

//gaiseki
double crossproduct(point a,point b){
  return a.x*b.y-a.y*b.x;
}

double length(point a){
  return sqrt(a.x*a.x+a.y*a.y);
}

double dist(point a,point b){
  double xv,yv;
  xv=b.x-a.x;
  yv=b.y-a.y;
  return sqrt(xv*xv+yv*yv);
}

double radius(point a,point b,point c){
  double w;
  if(iseq(a,b) && iseq(b,c)){return 0.0;}
  if(iseq(a,b) || iseq(a,c) || iseq(b,c)){return -1.0;}
  point p,q,r;
  p=vector_minus(b,a);
  q=vector_minus(c,a);
  r=vector_minus(c,b);
  if(crossproduct(p,q)==0.0){
    return inf;
  }
  w=fabs(crossproduct(p,q))/(length(p)*length(q));
  return ((length(r)/w)/2.0);
}

double curvature(double (*xt)(double),double (*yt)(double),double t){
  point a,b,c;
  a.x=xt(t-2.0*eps);a.y=yt(t-2.0*eps);
  b.x=xt(t);b.y=yt(t);
  c.x=xt(t+2.0*eps);c.y=yt(t+2.0*eps);
  return radius(a,b,c);
}

//Daikei-Soku
double trapezoidal(double (*func)(double),double st,double fi,unsigned int k){
  unsigned int i;
  double h=((fi-st)/((double)k)),r=0.0,p,q;
  for(i=0;i<k;i++){
    p=st+((double)i)*h;
    q=st+((double)i+1)*h;
    r+=(func(p)+func(q));
  }
  return ((r*h)/2.0);
}

//Cyuten-Soku
double midpoint(double (*func)(double),double st,double fi,unsigned int k){
  unsigned int i;
  double h=((fi-st)/((double)k)),r=0.0,p,q;
  for(i=0;i<k;i++){
    p=st+(0.5+(double)i)*h;
    r+=func(p);
  }
  return (r*h);
}

//Simpson-Soku
double simpson(double (*func)(double),double st,double fi,unsigned int k){
  unsigned int i;
  double h=((fi-st)/((double)k)),r=0.0,p;
  for(i=0;i<k;i++){
    p=st+((double)i)*h;
    r+=func(p);
    p=st+(0.5+(double)i)*h;
    r+=func(p)*4.0;
    p=st+(1.0+(double)i)*h;
    r+=func(p);
  }
  return ((r*h)/3.0);
}

double cxf(double t){
  return cos(t*t/2.0);
}

double clothoid_x(double t){
  //return trapezoidal(cxf,0.0,t,cost);
  //return midpoint(cxf,0.0,t,cost);
  return simpson(cxf,0.0,t,cost);
}

double cyf(double t){
  return sin(t*t/2.0);
}

double clothoid_y(double t){
  //return trapezoidal(cyf,0.0,t,cost);
  //return midpoint(cyf,0.0,t,cost);
  return simpson(cyf,0.0,t,cost);
}

int main(){
  int i;
  double a[32768],b[32768];
  for(i=0;i<=20000;i++){
    a[i]=clothoid_x(0.001*(double)i);
    b[i]=clothoid_y(0.001*(double)i);
    //a[i]=(0.001*(double)i);
    //b[i]=curvature(clothoid_x,clothoid_y,(0.001*(double)i));
  }
  for(i=0;i<=20000;i++){
    printf("%.12lf %.12lf\n",a[i],b[i]);
  }
  return 0;
}
