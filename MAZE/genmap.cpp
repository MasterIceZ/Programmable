#include<bits/stdc++.h>
using namespace std;

const int GRID_WIDTH = 79;
const int GRID_HEIGHT = 17;

#define north 0
#define east 1
#define south 2
#define west 3

char grid[GRID_WIDTH * GRID_HEIGHT];

void reset();
int xytoidx(int x, int y);
int isinbound(int x, int y);
void visit(int x, int y);
void print();

int main(){
	freopen("map.txt", "w", stdout);
	srand(time(0));
	cout << GRID_HEIGHT << " " << GRID_WIDTH << endl;
	reset();
	visit(1, 1);
	print();
	return 0;
}

void reset(){
	for(int i=0; i<GRID_WIDTH * GRID_HEIGHT; ++i){
		grid[i] = '#';
	}
}

int xytoidx(int x, int y){
	return y * GRID_WIDTH + x;
}

int isinbound(int x, int y){
	if(x < 0 || x >= GRID_WIDTH){
		return false;
	}
	if(y < 0 || y >= GRID_HEIGHT){
		return false;
	}
	return true;
}

void visit(int x, int y){
	grid[xytoidx(x, y)] = ' ';
	int dir[] = {0, 1, 2, 3};
	for(int i=0; i<4; ++i){
		int r = rand() & 3;
		int tmp = dir[r];
		dir[r] = dir[i];
		dir[i] = tmp;
	}
	for(int i=0; i<4; ++i){
		int dx = 0, dy = 0;
		switch(dir[i]){
			case north:
			   dy = -1;
		   		break;
		 	case south:
				dy = 1;
				break;
			case east:
				dx = 1;
				break;
			case west:
				dx = -1;
				break;
		}
		int x2 = x + (dx << 1), y2 = y + (dy << 1);
		if(isinbound(x2, y2)){
			if(grid[xytoidx(x2, y2)] == '#'){
				grid[xytoidx(x2-dx, y2-dy)] = ' ';
				visit(x2, y2);
			}
		}
	}
}

void print(){
	for(int y=0; y<GRID_HEIGHT; ++y){
		for(int x=0; x<GRID_WIDTH; ++x){
			if(x == GRID_WIDTH - 2 && y == GRID_HEIGHT - 2){
				cout << "E";
			}
			else{
				cout << grid[xytoidx(x, y)];
			}
		}
		cout << endl;
	}
}
