#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void show_board(int board_height, int board_width,int board[10][40]);
int calculate_cell(int board_height, int board_width, int board[10][40], int i, int j);

int main()
{

    int board_width;
    int board_height;
    int board[10][40];
    int next_board[10][40];
    char str;
    int i;
    int j;
    int c;
    int size = 1024;
    char *buffer = (char *)malloc(size);
    FILE *f = fopen("data.txt", "r");
    board_width     = 40;
    board_height    = 10;

    for (i=0;i < board_height; ++i){
            for( j=0; j < board_width; ++j){
                board[i][j]=0;
                next_board[i][j]=0;
            }
    }



    for (i=0;i < board_height; ++i){
    for( j=0; j < board_width; ++j){
                fscanf(f, "%1d", &board[i][j]);
                            }
    }



    do{
        show_board(board_height,board_width,board);
        for (i=0;i < board_height; i++){
            for( j=0; j < board_width; j++){
                 next_board[i][j]=calculate_cell(board_height,board_width,board, i, j);
            }
        }
        for (i=0;i < board_height; i++){
            for( j=0; j < board_width; j++){
                 board[i][j]=next_board[i][j];
            }
        }

        scanf("%s", &str);

    }while (str!='q');

        return 0;
}

void show_board(int board_height, int board_width,int board[10][40]){
        int i;
        int j;
        for (i=0;i < board_height; i++){
            for( j=0; j < board_width; j++){
                printf("%d", board[i][j]);
            }
            printf("\n");
        }
        }

    int calculate_cell(int board_height, int board_width, int board[board_height][board_width], int i, int j){
        int neighbour_counter=0;
        int ni;
        int nj;

        int x;
        int y;
        for(y=-1; y<=1 ; y++){
              for(x=-1; x<=1 ; x++){
                  if(y==0 && x==0)
                    continue;
                   ni=i+y;
                   nj=j+x;
                  if(ni<0)
                    ni=board_height;
                  if(ni>board_height)
                    ni=0;
                  if(nj<0)
                    nj=board_width;
                  if(ni>board_width)
                    nj=0;

                  neighbour_counter+=board[ni][nj];
              }
        }

        if (board[i][j]==0){
            if(neighbour_counter==3){
                return 1;
            }else{
                return 0;
            }
        }
        if (board[i][j]==1){
            if(neighbour_counter==3 || neighbour_counter==2){
                return 1;
            }else{
                return 0;
            }
        }
}
