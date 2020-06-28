#include<stdio.h>
#include<math.h>
#define pi 3.14
#define g 9.81
#define mu 0.0000179//粘性抵抗力

int main(){
  int i,j;
  double v,xv,yv,theta,h,wei,t;
  double xa=0.0,ya=0.0;
  double cx,cy;
  v=5.0;//初速
  wei=1;//質量
  theta=pi/4.0;//投射角
  h=0.0003;//微小時間
  xv=v*cos(theta);//x速度
  yv=v*sin(theta);//y速度
  for(i=0;i<100000000;i++){
    xa+=(xv*h);//x座標の変動
    ya+=(yv*h);//y座標の変動
    t=h*(double)i;
    cx=(v*cos(-theta))*exp(-mu*t/wei);
    cy=-((wei*g-(wei*g-mu*v*sin(-theta))*exp(-mu*t/wei))/mu);
    if(i%100==0){
      printf("%.12lf %.12lf\n",xv,yv);
      printf("<%.12lf %.12lf>\n",cx,cy);
      printf("error : %.12lf %.12lf\n",t,fabs(yv-cy));
    }
    if(cy<=0.0){break;}
    xv-=(((xv*mu)/wei)*h);//x速度の微小時間での変動
    yv-=(((wei*g+yv*mu)/wei)*h);//y速度の微小時間での変動
  }
  printf("%.12lf %.12lf\n",xv,yv);
  printf("<%.12lf %.12lf>\n",cx,cy);
  printf("error : %.12lf %.12lf\n",t,fabs(yv-cy));
  return 0;
}
