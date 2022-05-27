#include <iostream>
#include <numeric>
using namespace std;

class TicTacToe{
public:
    void Play();
private:
    void Draw();
    void Turn();
    bool IsOver() const;
    char matrix [3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool player = 0;
};

void TicTacToe::Draw(){
    system("cls");
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
          cout << matrix[i][j] << ' ';
      }
      cout << endl;
    }
}

void TicTacToe::Turn(){
    int cell;
    while(true){
        cout << "Insert the number of the field: ";
        cin >> cell;
        // check that the field is present and not already in  used
        if ( cell > 0 && cell < 10 && matrix[(cell - 1) / 3][(cell - 1) % 3] >= '1'
            && matrix[(cell - 1) / 3][(cell - 1) % 3] <= '9'){

            matrix[(cell - 1) / 3][(cell - 1) % 3] = player == 0? 'X' : 'O';
            player = !(player);
            break;

        }
        cout << "The number is invalid!" << endl;
    }
    
}

bool TicTacToe::IsOver() const{
        // rows
        if (matrix [0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2]){
            // cout << 1;
            return true;
        }
        if (matrix [1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2]){
            // cout << 2;
            return true;
        }
        if (matrix [2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2]){
            // cout << 3;
            return true;
        }
        // columns
         if (matrix [0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0]){
            // cout << 4;
            return true;
        }
        if (matrix [0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1]){
            // cout << 5;
            return true;
        }
        if (matrix [0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2]){
            // cout << 6;
            return true;
        }
        // first diagonal
        if (matrix [0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]){
            /// cout << 7;
            return true;
        }
        // second diagon
        if (matrix [0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]){
            // cout << 8;
            return true;
        }
        return false;
 }

void TicTacToe::Play(){
    int n = 0;
    do{
        if (n == 9){
            cout << "It's a draw!!!";
            return;
        }

        this->Draw();
        this->Turn();
        ++n;

    } while (!IsOver());

    this->Draw();
    if (player == 1)
        cout<< "Player X has won!!!";
    else
        cout << "Player O has won!!!";
}

int main(){
    TicTacToe instance;
    instance.Play();
}