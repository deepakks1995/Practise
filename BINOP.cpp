/*input
2
101
010
1111
1010
*/
//wrong approach 
#include <iostream>
#include <cstring>
using namespace std;
int check;
long long count,index1,last_index1,i;

int convertToB(string *A, string *B, long long int *i, long long int *j, int *A1, int *A2)
{
	//cout<<"Aj: "<<(*A)[*j]<<" Ai:"<<(*A)[*i]<<endl;
	//cout<<"Bj: "<<(*B)[*j]<<" Bi:"<<(*B)[*i]<<endl;
	if( ((*A)[*i]=='0' && (*A)[*j]=='0' && ((*B)[*i]=='1' || (*B)[*j]=='1')) || ((*A)[*i]=='1' && (*A)[*j]=='1' && ((*B)[*i]=='0' || (*B)[*j]=='0')) )
	{
		//cout<<"a";
		check=1;
	}
	else
	{
		if((*B)[*j]=='1' && (*B)[*i]=='1' && (*A)[*j]=='0' && (*A)[*i]=='1')
		{
			//cout<<"aa\n";
			*A1=1;*A2=1;
			count++;
			return 0;
		}
		else if((*B)[*j]=='1' && (*B)[*i]=='0' && (*A)[*j]=='0' && (*A)[*i]=='1')
		{
			//cout<<"b\n";
			*A1=0;*A2=1;
			count++;
			return 0;
		}
		else if((*B)[*j]=='0' && (*B)[*i]=='0' && (*A)[*j]=='1' && (*A)[*i]=='0')
		{
			//cout<<"c\n";
			*A1=0;*A2=0;
			count++;
			return 0;
		}
		else if((*B)[*j]=='0' && (*B)[*i]=='1' && (*A)[*j]=='1' && (*A)[*i]=='0')
		{
			//cout<<"d\n";
			*A1=1;*A2=0;
			count++;
			return 0;
		}
		else if((*B)[*j]=='0' && (*B)[*i]=='0' && (*A)[*j]=='0' && (*A)[*i]=='1')
		{
			//cout<<"d\n";
			*A1=1;*A2=0;
			count++;
			return 0;
		}
		else if((*B)[*j]=='1' && (*B)[*i]=='1' && (*A)[*j]=='1' && (*A)[*i]=='0')
		{
			//cout<<"d\n";
			*A1=1;*A2=1;
			count++;
			return 0;
		}
		else
		{
			//cout<<"e\n";
			check=1;
		}
	}
	return 0;
}



int main()
{
	int t;
	cin>>t;
	int A1,A2;
	string A,B;
	while(t--)
	{
		check=0;
		count=0;
		last_index1=index1=-1;
		cin>>A>>B;
		for( i=B.length()-1;i>=0;i--)
		{
			if(A[i]==B[i])
				continue;
			else
			{
				if(index1==-1)
					index1=i;
				else
				{
					//cout<<"Aindex1: "<<A[index1]<<" Ai:"<<A[i]<<endl;
					//cout<<"Bindex1: "<<B[index1]<<" Bi:"<<B[i]<<endl;
					convertToB(&A,&B,&i,&index1,&A1,&A2);
					A[i]='0';
					A[index1]='0';
					if(A1==1)
						A[i]='1';
					if(A2==1)
						A[index1]='1';
					//cout<<"Aindex1: "<<A[index1]<<" Ai:"<<A[i]<<endl;
					//cout<<"Bindex1: "<<B[index1]<<" Bi:"<<B[i]<<endl;
					//cout<<"A full "<<A<<endl;
					last_index1=index1;
					index1=-1;
				}
			}
		}
		for(i=B.length()-1;i>=index1;i--)
			if(B[i]==0 && A[index1]==1)
				last_index1=i;
			else if(B[i]==1 && A[index1]==0)
				last_index1=i;

		if(index1!=-1)
			convertToB(&A,&B,&index1,&last_index1,&A1,&A2);
		if(check)
			cout<<"Unlucky Chef\n";
		else
		{
			cout<<"Lucky Chef\n";
			cout<<count<<endl;
		}
	}
}