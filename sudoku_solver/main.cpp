#include<iostream>

using namespace std;

int table[10][10];

bool check_table(){

}

void get_table();
	int n,m;
	n = m = 3;
	vector<vector<int>>t(n,vector<int>(m));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++i){
			cin >> tablt[i][j];
		}
	}
}

int32_t main (void){
	ios::sync_with_stdio(0); cin.tie(0);
	get_table();
	if(!check_table()){
		cout << "Wrong Table" ;
		return 0;	
	}		
	return 0;
}
