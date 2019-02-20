#include<stdio.h>
#include<math.h>
#define pi 3.14
#define rho 1.3//大気の密度(kg/m^3)
#define g 9.81
#define h 0.00001//微小時間(s)

double dist(double wei,double rad,double fsp,double theta){
  double xa=0,ya=0;//(x,y)座標
  double xv,yv;//(x,y)速度
  double s=rad*rad*pi;//断面積(m^2)
  double xf,yf;
  xv=cos(theta)*fsp;//x初速(m/s)
  yv=sin(theta)*fsp;//y初速(m/s)
  while(ya>=0){
    xa+=xv*h;//x座標の変動(m)
    ya+=yv*h;//y座標の変動(m)
    if(xv>=0){xf=1.0;}else{xf=-1.0;}
    if(yv>=0){yf=1.0;}else{yf=-1.0;}
    xv-=(((rho*s*xv*xv*xf)*h)/wei);//x速度の変動(m/s)
    yv-=(((rho*s*yv*yv*yf+wei*g)*h)/wei);//y速度の変動(m/s)
  }
  return xa;
}

int main(){
  int i;
  double wei,rad,fsp;
  double st,fi,te1,te2,dis1,dis2,btheta;
  printf("Weight(g)?\n");//質量
  scanf("%lf",&wei);
  wei/=1000;//g -> kg
  printf("Radius(cm)?\n");//半径
  scanf("%lf",&rad);
  rad/=100;//cm -> m
  printf("First Speed(km/h)?\n");//初速
  scanf("%lf",&fsp);
  fsp/=3.6;//km/h -> m/s
  st=0;
  fi=pi/2.0;//直角
  for(i=0;i<100;i++){
    te1=(st*2.0+fi)/3.0;
    te2=(st+fi*2.0)/3.0;
    dis1=dist(wei,rad,fsp,te1);
    dis2=dist(wei,rad,fsp,te2);
    if(dis1>dis2){fi=te2;}
    else{st=te1;}
    if(st>fi){break;}
  }
  btheta=(st+fi)/2;
  printf("Best theta(deg):%.12lf\n",180*btheta/pi);//最良投射角
  printf("Best dist(m):%.12lf\n",dist(wei,rad,fsp,btheta));//最長飛距離
}
