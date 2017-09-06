#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double u,v,w,U,V,W;
        //cin>>u>>v>>w>>W>>V>>U;
        scanf("%lf %lf %lf %lf %lf %lf",&u,&v,&w,&U,&V,&W);
        int u1,v1,w1;
        u1=v*v+w*w-U*U;
        v1=w*w+u*u-V*V;
        w1=u*u+v*v-W*W;
        double volume;
        volume=(1/12)*sqrt(4*u*u*v*v*w*w-u*u*u1*u1-v*v*v1*v1-w*w*w1*w1+u1*v1*w1);
        double s=(U+V+W)/2;
        double area=sqrt(s*(s-U)*(s-V)*(s-W));
        double height=(3*volume)/area;
        double radius=height/4;
        printf("%.4lf\n",radius);
    }
}
