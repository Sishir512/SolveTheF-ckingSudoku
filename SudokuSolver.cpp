#include<iostream>


bool IsRowNotRepeated(int board[][9] , int value , int rowindex , int columnindex){
    for(int i = 0 ; i < 9 ; i++){

        if(i == columnindex){
            continue;
        }

        if(board[rowindex][i] == value){
            return false;
        }
        
    }
    return true;
}

bool IsColumnNotRepeated(int board[][9] , int value , int rowindex , int columnindex){
    for(int i = 0 ; i < 9 ; i++){
        if(i == rowindex){
            continue;
        }
        if(board[i][columnindex] == value){
            return false;
        }
    }
    return true;
}

bool IsNotRepeatedInBox(int board[][9] , int value , int rowstart , int columnstart){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[rowstart + i][columnstart + j] == value){
                return false;
            }
        }
    }
    return true;
}


bool IsSafeEverywhere(int board[][9] , int value , int rowindex , int columnindex){
    return (IsRowNotRepeated(board , value , rowindex , columnindex) && IsColumnNotRepeated(board , value , rowindex , columnindex)) && IsNotRepeatedInBox(board , value , rowindex - rowindex % 3 , columnindex - columnindex % 3);
}

bool GetPossibleLocation(int board[][9] , int &x , int &y){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            if(board[i][j] == 0){
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

bool Solve(int board[][9]){
    int row , column;
    if(!GetPossibleLocation(board , row , column)){
        return true;
    }
    for(int j = 1 ; j <= 9 ; j++){
        if(IsSafeEverywhere(board , j , row , column)){
            board[row][column] = j;
            if(Solve(board)){
                return true;
            }
            board[row][column] = 0;
            
        }
        
    }
    return false;
}  





void ShowBoard(int board[][9]){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            std::cout<<board[i][j]<<" ";
            if(j == 2 || j == 5) std::cout<<" ";
        }
        std::cout<<std::endl;
        if(i == 2 || i == 5) std::cout<<std::endl;
    }
}


int main(){
    int board[9][9] = {{9 , 0 , 8 , 0 , 7 , 0 , 0 , 5 , 0}, 
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                       {0 , 0 , 0 , 0 , 9 , 0 , 0 , 0 , 0},
                       {0 , 0 , 0 , 0 , 8 , 0 , 0 , 0 , 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
                       {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}};
                       
    if(Solve(board)) ShowBoard(board);
    else std::cout << "Canot be solved ";
    


}
