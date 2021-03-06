#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int a[10]={1,7,3,25,6,13,3,8,3,7};

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	cout<<max(1,3)<<" "<<min(1,3)<<endl<<endl;

	vector<int> vec;
	for(int i=0;i<10;i++)
		vec.push_back(100-i);
	sort(vec.begin(),vec.end());
	stable_sort(vec.begin(),vec.end());

	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	sort(a,a+10,cmp);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	sort(a,a+10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;


	cout<<lower_bound(a,a+10,4)-a<<endl;
	cout<<upper_bound(a,a+10,4)-a<<endl;
	cout<<lower_bound(a,a+10,3)-a<<endl;
	cout<<upper_bound(a,a+10,3)-a<<endl<<endl;
	
	int n=unique(a,a+10)-a;
	cout<<n<<endl;
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;

	int ia=3,ib=5;
	swap(ia,ib); cout<<ia<<" "<<ib<<endl<<endl;

	

	int b[3]={1,2,3};
	do
	{
		for(int i=0;i<3;i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}while(next_permutation(b,b+3));
	cout<<endl;
	do
	{
		for(int i=0;i<3;i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}while(prev_permutation(b,b+3));
	cout<<endl;
	//b[0]=3; b[1]=2; b[2]=1;
	do
	{
		for(int i=0;i<3;i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}while(prev_permutation(b,b+3));
	cout<<endl;

	int c[10]={27,13,26,15,19,11,99,102,2,98};
	nth_element(c,c+3,c+10);
	for(int i=0;i<10;i++)
		cout<<c[i]<<" ";
	cout<<endl;

	nth_element(c,c+7,c+10);
	for(int i=0;i<10;i++)
		cout<<c[i]<<" ";
	cout<<endl<<endl;

	//set operation, A,B,C can be sorted vector list set 
	set<int> A,B,C;
	A.insert(1);A.insert(3);
	A.insert(7);A.insert(9);
	A.insert(13);
	B.insert(1);B.insert(2);
	B.insert(3);B.insert(5);
	B.insert(6);B.insert(8);

	//A u B
	set_union(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.end()));
	for(int i:C) cout<<i<<" "; cout<<endl;

	//B is subset of A
	cout<<includes(A.begin(),A.end(),B.begin(),B.end())<<" "
		<<includes(C.begin(),C.end(),A.begin(),A.end())<<" "
		<<includes(A.begin(),A.end(),C.begin(),C.end())<<endl;

	//A n B
	C.clear();
	set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.end()));
	for(int i:C) cout<<i<<" "; cout<<endl;

	//A - B
	C.clear();
	set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.end()));
	for(int i:C) cout<<i<<" "; cout<<endl;

	//(A - B) u (B - A)
	C.clear();
	set_symmetric_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.end()));
	for(int i:C) cout<<i<<" "; cout<<endl<<endl;


	vector<int> D={1,2,2,3,3,3};
	vector<int> E={2,3,5,5,6,8};
	vector<int> F;
	//D u E
	F.clear();
	set_union(D.begin(),D.end(),E.begin(),E.end(),inserter(F,F.end()));
	for(int i:F) cout<<i<<" "; cout<<endl;

	//D is subset of F
	cout<<includes(F.begin(),F.end(),D.begin(),D.end())<<" "
		<<includes(B.begin(),B.end(),D.begin(),D.end())<<endl;

	//D n E
	F.clear();
	set_intersection(D.begin(),D.end(),E.begin(),E.end(),inserter(F,F.end()));
	for(int i:F) cout<<i<<" "; cout<<endl;

	//D - E
	F.clear();
	set_difference(D.begin(),D.end(),E.begin(),E.end(),inserter(F,F.end()));
	for(int i:F) cout<<i<<" "; cout<<endl;

	//(D - E) u (E - D)
	F.clear();
	set_symmetric_difference(D.begin(),D.end(),E.begin(),E.end(),inserter(F,F.end()));
	for(int i:F) cout<<i<<" "; cout<<endl<<endl;


	F.clear();	
	set_union(A.begin(),A.end(),B.begin(),B.end(),inserter(F,F.end()));
	for(int i:F) cout<<i<<" "; cout<<endl;
	F.clear();
	merge(A.begin(),A.end(),B.begin(),B.end(),inserter(F,F.end()));
	for(int i:F) cout<<i<<" "; cout<<endl;


	return 0;
}