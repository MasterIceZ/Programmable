#include<iostream>
#include<cstring>

using namespace std;

int table[10][10];
int mark[12];

//Check Every 3*3
bool check_ev(int n,int m){
	memset(mark, 0, sizeof mark);
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			mark[table[i+n][j+m]]++;
		}
	}	
	for(int i=1;i<10;++i){
		if(mark[i] > 1){
			return false;
		}
	}
	return true;
}

//Use for every 3*3
bool check_table_2(){
	for(int i=1;i<9;i+=3){
		for(int j=1;i<9;j+=3){
			bool mk = check_ev(i,j);
			if(!mk){
				return false;
			}
		}
	}	
	return true;
}

//Use for Vertical and Horizontal line only
bool check_table(){
	//It looks like O(n^2) but it is O(1)
	//Because of using Const in the game!
	for(int i=1;i<=9;++i){
		for(int j=1;j<=9;++j){
			for(int k=1;k+i<=9;++k){
				if(table[i][j] == table[i+k][j] and table[i][j]!=0){
					return false;
				}
			}	
			for(int k=1;k+j<=9;++k){
				if(table[i][j] == table[i][j+k] and table[i][j]!=0){
					return false;
				}
			}	
		}
	}	
	return true;
}

void get_table(){
	int n = 3;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin >> table[i][j];
		}
	}
}

int32_t main (void){
	ios::sync_with_stdio(0); cin.tie(0);
	get_table();
	if(!check_table()){
		cout << "Wrong Table" << endl;
		cerr << "v/t" << endl;
		return 0;	
	}	
	if(!check_table_2()){
//		cout << "Wrong Table" << endl; 
//		cerr << "3*3" << endl;
		return 0;
	}
	cerr << "able";	
	return 0;
}
