#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long N,A,B,C,i,j;
        cin>>N;
        double arr[N],temp;
        long C1[N],C2[N],in1=0,in2=0;
        for(i=0;i<N;i++)
        {
            cin>>A>>B>>C;
            if(B)
            {
                arr[in1]=static_cast<double>(-1*A)/B;
                C1[in1++]=C;
            }
            else
                C2[in2++]=C;
        }/*
        for(i=0;i<in1;i++)
        {
            cout<<"Slope: "<<arr[i];
            cout<<" C: "<<C1[i]<<endl;
        }
        cout<<endl;*/
        for(i=0;i<in1-1;i++)
        {
            for(j=i+1;j<in1;j++)
            {
                if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }/*
        for(i=0;i<in1;i++)
        {
            cout<<"Slope: "<<arr[i];
            cout<<" C: "<<C1[i]<<endl;
        }
        cout<<endl;*/
        long max=0,count=0;
        for(i=0;i<in1-1;i++)
        {
            if(A[i]==A[i+1])
        }
    }
}
