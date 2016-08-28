
/* n(logn)^2 solution*/


#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x;
	int y;
};


bool Xcompare(point p1,point p2 )
{
	return p1.x < p2.x;
}

bool Ycompare(point p1,point p2 )
{
	return p1.y < p2.y;
}

float findDistance(point vec1,point vec2)
{
	return sqrt((vec1.x-vec2.x)*(vec1.x-vec2.x) +((vec1.y-vec2.y)*(vec1.y-vec2.y)));
}

float bruteForce(vector<point> vec,int start,int end)
{
	float minval=FLT_MAX;
	for(int i=start;i<end;i++)
	{
		for(int j=i+1;j<=end;j++)
		{
			float dist=findDistance(vec[i],vec[j]);
			minval=min(minval,dist);
		}
	}
	return minval;
}

float stripClosest(vector<point>& strip,float mindist)
{
	sort(strip.begin(),strip.end(),Ycompare);
	float Min=mindist;

	for(int i=0;i<strip.size();i++)
	{
		for(int j=i+1;j<strip.size()&& (strip[j].y -strip[i].y)< Min;j++)
		{
			float dist=findDistance(strip[i],strip[j]);
			Min=min(Min,dist);
		}

	}
	return Min;

}

float closestDistance(vector<point>& vec,int start,int end)
{
	int n=end-start+1;
	if(n<=3)
		return bruteForce(vec,start,end);
	int mid=start+(end-start)/2;
	point midpoint=vec[mid];

	float dl=closestDistance(vec,start,mid);
	float dr=closestDistance(vec,mid+1,end);

	float mindist=min(dl,dr);

	vector<point> strip;
	for(int i=0;i<vec.size();i++)
	{
		if(abs(vec[i].x - midpoint.x)<mindist)
			strip.push_back(vec[i]);
	}

	return min(mindist,stripClosest(strip,mindist));
}

int main()
{
	int n;
	cin>>n;
	vector<point> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i].x>>vec[i].y;

	sort(vec.begin(),vec.end(),Xcompare);
	cout<<closestDistance(vec,0,n-1)<<endl;

	return 0;
}