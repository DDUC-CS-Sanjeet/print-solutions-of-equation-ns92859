/*
  	By : Neeraj Sharma
   	Roll no. : 19HCS4037
   	Description : To display all the possible combinations of the lenear eq.n x1+x2+.....+xN=C
   				where C is a constant and x1,x2,x3....xN are non negative integers
*/
#include<iostream>
#include<cmath>
using namespace std;
int combin(int n,int r)
{
	if(r==0||r==n)
	{
		return 1;
	}
	else
	{
		return (combin(n-1,r-1)+combin(n-1,r));
	}
}
int NewSumOfDigits(int ar[],int var)
{
	int sum=0;
	for(int i=0;i<var;i++)
	{
		sum+=ar[i];
	}
	return sum;
}
int sumOFdigits(int numbr)
{
	int sum=0;
	while(numbr!=0)
	{
		int rem=numbr%10;
		numbr=numbr/10;
		sum+=rem;
	}
	return sum;
}
int main()
{
	int var,cnst,bit=0,num=0,counter=0;
	cout<<"Enter the Constant : ";
	cin>>cnst;
	cout<<"Enter the number of variable positions : ";
	cin>>var;
	int ar[var]={0};
	long long lrgstNo=pow(10,var)-1;
	int number=0;
	cout<<"Total number of combinations that can be formed are : ";
	int ans=combin(var+cnst-1,cnst);
	cout<<ans;
	cout<<"\n\nYour required combinations are : \n\n";
	for(int i=1;i<=lrgstNo;i++)
	{
		num=i;
		while(num!=0)
		{
			num=num/10;
			counter++;
		}
		if(counter!=var)
		{
			num=i;
			for(int j=var-1;j>=0;j--)
			{
				ar[j]=num%10;
				num=num/10;
			}
			int rcvNewno=NewSumOfDigits(ar,var);
			if(rcvNewno==cnst)
			{
				++bit;
				for(int j=0;j<var;j++)
				{
					cout<<ar[j];
				}
				cout<<"\n";
			}
			counter=0;
			ar[var]={0};
		}
		else
		{
			int rcvNo=sumOFdigits(i);
			if(rcvNo==cnst)
			{
				cout<<i;
				++bit;
				if(bit<ans)
				{
					cout<<"\n";
				}
			}
			if(bit==ans)
			{
				break;
			}
		}
	}
	cout<<"\n\nThese are your total "<<bit<<" combination of number whose sum of digits is "<<cnst<<"      :)\n\n";
}
