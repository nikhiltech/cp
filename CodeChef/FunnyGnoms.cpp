#include <bits/stdc++.h>
using namespace std;
stack<int> konwn1;
vector<int> value;
//stack<int> mssg;

int main(){
	int n,val,temp,counter;
	cin>>n;
	int gnom[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>gnom[i][j];
		}
	}

//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<gnom[i][j];
//		}
//	}

	int m;
	cin>>m;
//	cout<<"hello";
	int t,c;

	for(int i=0;i<m;i++){
		value.clear();
		while(!konwn1.empty()){
//				val = konwn1.top();
//				value.push_back(val);
				konwn1.pop();
			}
//		cout<<"in for loop";
		
		cin>>t>>c;
		int tt=t;
//		cout<<"in next for loop";
		konwn1.push(c);
//		mssg.push(c);
		while(t>=0){
			temp=0;
			value.clear();
			counter=0;
			
			while(!konwn1.empty()){
				val = konwn1.top();
//				cout<<val<<"\n";
				value.push_back(val);
				konwn1.pop();
			}
			for(int j=0;j<n;j++){
//				cout<<n<<"\n";
//			cout<<value[temp]<<"\n";
//				cout<<temp<<"out if\n";
				if(j==n-1){
					temp++;
					if(temp<value.size()){
//						cout<<"hello\n";
						j=0;				//errorrrrr
					}
				}

				if(temp==value.size())
						break;

				if(gnom[value[temp]-1][j]==1){

//					cout<<"Hi temp: "<<temp<<"\t";
//					cout<<temp<<"in if\n";
//					cout<<j+1<<"\n";
					konwn1.push(j+1);
					counter++;
//					cout<<counter;



//					mssg.pop();
//					mssg.push(j);
					
				}
			}
			
			t--;
		}
		if(tt>0)
			cout<<counter<<"\n";
		else
			cout<<"1\n";

		if(value.size()==0)
			cout<<"-1";
		else{
			for(int k=0; k<value.size(); k++){
				cout<<value[k]<<" ";
			}
		}
		cout<<"\n";
		

	}

}