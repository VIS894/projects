
#include<iostream>



using namespace std;



class RatMaze{
        public:
      static const  int n = 4;
      int sol[n][n] = {{0,0,0,0},
                        {0,0,0,0},
                         {0,0,0,0},
                         {0,0,0,0} };
bool move(int maze[n][n],int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y] == 1)
    return true;
}
        bool solution(int maze[n][n],int x,int y,int sol[n][n])
{
    if(x == n-1 && y == n-1)
    {
        sol[x][y]=1;
        return true;
    }
    if(move(maze,x,y) == true)
    {
        sol[x][y]== 1;
        if(solution(maze,x+1,y,sol)){
            return true;
        }
        if(solution(maze,x,y+1,sol)){
            return true;
        }
        sol[x][y]=0;
        return false;
    }
    return false;
}
void printSolution() {
    
        for (int i = 0; i <n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
      };
       


int main() {
    RatMaze ratMaze;
    int maze[RatMaze::n][RatMaze::n] = { {1, 0, 0, 0}, {1, 1, 0, 0},
                                         {0, 1, 0, 0},
                                         {1, 1, 1, 1} };

    if (ratMaze.solution(maze, 0, 0, ratMaze.sol)) {
        ratMaze.printSolution();
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}