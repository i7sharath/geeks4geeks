#include<cstdio>
#include<iostream>
#include <cstring>
#include <vector>


using namespace std;

void auxFunc(vector<int>& arr1,int n1, vector<int>& arr2, int n2)
{
	int i=0,j=0,sum1,sum2,result;

	sum1=0;
	sum2=0;
	result=0;
	while(i<n1 && j<n2)
	{
		if(arr1[i]<arr2[j])
		{
			sum1+=arr1[i];
			i++;
		}

		else if (arr2[j]<arr1[i])
		{
			sum2+=arr2[j];
			j++;
		}

		else
		{

			result+=max(sum1,sum2);
			sum1=0;
			sum2=0;
			while(i<n1 && j<n2 && arr1[i]==arr2[j])
			{
				result+=arr1[i];
				i++;
				j++;
			}
		}
	}

	while(i<n1)
		sum1+=arr1[i++];

	while(j<n2)
		sum2+=arr2[j++];
	result+=max(sum1,sum2);
	cout<<result<<endl;
}
				

int main()
{
	int n1,n2;
	cin>>n1>>n2;
	int i;
	vector<int> arr1(n1);
	vector<int> arr2(n2);

	for(i=0;i<n1;i++)
		cin>>arr1[i];
	for(i=0;i<n2;i++)
		cin>>arr2[i];
	
	auxFunc(arr1,n1,arr2,n2);
	return 0;
}
