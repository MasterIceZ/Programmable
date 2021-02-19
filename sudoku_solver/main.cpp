#include<iostream>

using namespace std;

int table[10][10];


bool check_table_2(){
	
	return true;
}

//Use for Vertical and Horizontal line only
bool check_table(){
	//It looks like O(n^2) but it is O(1)
	//Because of using Const in the game!
	for(int i=1;i<=9;++i){
		for(int j=1;j<=9;++j){
			for(int k=1;k+i<=9;++k){
				if(table[i][j] == table[i+k][j]){
					return false;
				}
			}	
			for(int k=1;k+j<=9;++k){
				if(table[i][j] == table[i][j+k]){
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
		return 0;	
	}	
	if(!check_table_2()){
		cout << "Wrong Table" << endl; 
		return 0;
	}	
	return 0;
}
