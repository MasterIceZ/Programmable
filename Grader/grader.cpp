#include<bits/stdc++.h>
using namespace std;

#define OS "WINDOWS"

char tmp[10100];

void to_char(string s){
	memset(tmp, '\0', sizeof tmp);
	for(int i=0; i<s.size(); ++i){
		tmp[i] = s[i];
	}
	return ;
}

void cmd(string s){
	to_char(s);
	system(tmp);
	return ;
}

void clear(){
	if(OS == "WINDOWS"){
		cmd("cls");
	}
	else{
		cmd("clear");
	}
}

void remove(string file){
	if(OS == "WINDOWS"){
		cmd("del " + file);
	}
	else{
		cmd("rm " + file);
	}
}

int testcase = 10;
string res;

void run(string file){
	string com;
	if(OS == "WINDOWS"){
		com = file;
	}
	else{
		com = "./" + file;
	}
	// Grading
	for(int i=1; i<=testcase; ++i){
		cmd(com + " < " + to_string(i) + ".in > " + to_string(i) + ".out");
		cmd("diff -wb " + to_string(i) + ".out " + to_string(i) + ".sol > DIFF");	
		ifstream read("DIFF");
		if(read.peek() == EOF){
			res += "P";
		}
		else{
			res += "-";
		}
		remove(to_string(i) + ".out");
		remove("DIFF");
	}
}

int main(int argc, char* argv[]){
	try{
		testcase = atoi(argv[1]);
	}
	catch(...){
		testcase = 10;
	}
	string sol;
	cout << "Enter Solution File : ";
	cin >> sol;
	// Compile and Run
	cmd("g++ -std=c++14 -Wall " + sol + " -o sol.out");
	run("sol.out");
	// Clean Up
	remove("sol.out");
	cout << res << "\n";
	return 0;
}
