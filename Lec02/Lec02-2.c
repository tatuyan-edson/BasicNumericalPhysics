#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define inf 1000000000000000000
#define eps 0.00001

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

double sq(double a){
  return a*a;
}

double re(double a){
  return a;
}

int main(){
  int i;
  printf("%.12lf\n",curvature(re,sq,2.0));
  return 0;
}
