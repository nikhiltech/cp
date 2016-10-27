#include<bits/stdc++.h>
using namespace std;
#define MAX 9
int visited[MAX][MAX];

struct node{
	int x;
	int y;
	int d;
};

queue <node> que;

int bfs(int x1,int y1){

	node temp;
	temp.x=x1;
	temp.y=y1;
	temp.d=0;
	que.push(temp);

	while(!que.empty())
	{
		node t = que.front();
		que.pop();
		int arr1[8]={-2,-2,1,-1,2,2,1,-1};
		int arr2[8]={1,-1,2,2,1,-1,-2,-2};

		for(int i=0;i<8;i++){
			int tempx=t.x+arr1[i];
			int tempy=t.y+arr2[i];

			if(tempx<=8 && tempx>0 && tempy>0 && tempy<=8 && visited[tempx][tempy]==0 ){
//				cout<<"hello\n";
				temp.x=tempx;
				temp.y=tempy;
				temp.d=t.d+1;
				visited[tempx][tempy]=t.d+1;
				que.push(temp);
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				visited[i][j]=0;
			}
		}

		char x1,y1;
		int x2,y2;
		cin>>x1>>x2>>y1>>y2;
		int z11=x1-'a'+1;
		int z12=y1-'a'+1;
//		cout<<x2<<z11<<" "<<z12<<y2<<"\n";
		visited[z11][x2]=1;
		bfs(z11,x2);
		visited[z11][x2]=0;

		cout<<visited[z12][y2]<<"\n";
	}

}