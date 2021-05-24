#include<bits/stdc++.h>
using namespace std;

#ifndef LINUX
#include<conio.h>
#endif

bool mark = false;
int n, m;
char a[1010][1010];
pair<int, int>player;
void init();
void dbg();
void play();

int main(){
    init();
    while(1){
        //system("cls");
        play();
        if(mark){
            break;
        }
    }
	system("del map.txt");
	system("del gen.exe");
    return 0;
}

void init()
{
    freopen("map.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    ++n;
	system("g++ genmap.cpp -o gen");
	system(".\\gen");
	for (int i=0; i<n; ++i){
        gets(a[i]);
    }
    fclose(stdin);
    player = make_pair(n-2, 1);
    return;
}
void dbg(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(player.first == i && player.second == j){
                printf("O");
            }
            else{
                printf("%c", a[i][j]);
            }
        }
        printf("\n");
    }
}
void play(){
    dbg();
    if (a[player.first][player.second] == 'E')
    {
        mark = true;
        printf("YOU WIN!\n");
        return;
    }
    char now = getch();
    system("cls");
    pair<int, int> np;
    switch(now){
        case 'w':
            np = make_pair(-1, 0);
            break;
        case 'a':
            np = make_pair(0, -1);
            break;
        case 'd':
            np = make_pair(0, 1);
            break;
        case 's':
            np = make_pair(1, 0);
            break;
        case 'x':
            mark = true;
            return ;
    }
    if(a[player.first + np.first][player.second + np.second] == '#'){
        return ;
    }
    player.first += np.first;
    player.second += np.second;
    return ;
}
