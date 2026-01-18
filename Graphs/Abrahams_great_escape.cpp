#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	
	while(t-->0){
		int n,k;
		cin>>n>>k;
		if(k==n*n-1){
			cout<<"NO"<<endl;
			continue;
		}
		else cout<<"YES"<<endl;
		vector<vector<char>>v(n,vector<char>(n,'X'));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(k>0){
					v[i][j]='U';
					k--;
				}
				else if(i!=n-1){
					v[i][j]='D';
				}
				else if(i==n-1 && j!=n-1){
					v[i][j]='R';
				}
				else if(i==n-1 && j==n-1){
					v[i][j]='L';
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<v[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
