#include<stdio.h>
#include<math.h>

const double h=20000;
const double dz=0.01;
const double g=9.80665;
const double r=287.1;
const double gamma=0.0065;
const double az=-273.15;
const double pz=1000;
const double cp=1004;
const double rd=287;

int main(){
  int i,j;
  double p[128],hi[128],temp[128],thtv[128],kt[128],rho,dcp[128],mcp[128];
  for(i=0;i<4;i++){scanf("%*[^\n]%*c");}
  //fprintf(stderr,"ok\n");
  scanf("%lf%lf%lf%*51[^\n]%lf%*c",&p[0],&hi[0],&temp[0],&thtv[0]);
  //printf("<%.12lf %.12lf %.12lf %.12lf>\n",p[0],hi[0],temp[0],thtv[0]);
  dcp[0]=p[0];
  mcp[0]=p[0];
  kt[0]=thtv[0]*pow(cp/pz,(rd/cp));
  i=1;
  while(scanf("%lf%lf%lf%*51[^\n]%lf%*c",&p[i],&hi[i],&temp[i],&thtv[i])!=EOF){
    kt[i]=thtv[i]*pow(cp/pz,(rd/cp));
    dcp[i]=dcp[i-1]+((-dcp[i-1])*g*(hi[i]-hi[i-1])/(r*(-az+((temp[i-1]+temp[i])/2.0))));
    mcp[i]=mcp[i-1]+((-mcp[i-1])*g*(hi[i]-hi[i-1])/(r*((kt[i-1]+kt[i])/2.0)));
    i++;
  }
  for(j=0;j<i;j++){
    printf("%.12lf %.12lf %.12lf %.12lf\n",hi[j],dcp[j],mcp[j],p[j]);
  }
  return 0;
}
