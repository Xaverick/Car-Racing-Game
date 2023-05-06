#include<iostream>
#include<conio.h>
#include <fstream>
#include<string>
#include <windows.h>
using namespace std;

void await(){
    for (int i = 0; i < 200000000;i++){

    }
}
void loading(){
    cout << endl;
    cout << endl;
    cout << "loading";
    for(int i = 0; i <= 5; i++){
        await();
        cout << ".";
    }
}


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 25
#define WIN_WIDTH  77


class user{
    string name;
    int age;
    int score;

    public:
        string get_name()
        {
            return name;
            }

            int get_age(){
                return age;
            }

            void setName(string name){
                this->name = name;
            }

            void setAge(int age){
                this->age = age;
            }
};



int carPos = (WIN_WIDTH / 2 )-1;
int yposition = 21;

int enemyX[2];
int enemyY[2];
int Enemy[2];

int coinX[3];
int coinY[3];
int coin[3];

char Coin = '$';

char car[4][4] = {' ', '*', '*', ' ',
                  '*', '*', '*', '*',
                  ' ', '*', '*', ' ',
                  '*', '*', '*', '*'};



// int mod(int a){
//     if(a < 0){
//         a = -a;
//     }
//     return a;
// }

void setcursor(bool visible, DWORD size)
{
    if (size == 0)                           //THIS IS FOR DISAPPERAING THE CURSOR 
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}


void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;                                                   //For taking the cursor to any part of the console
    SetConsoleCursorPosition(console, CursorPosition);
}


void drawBorder()
{
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            gotoxy(0 + j, i);
            cout << "=";
            gotoxy(WIN_WIDTH - j, i);
            cout << "=";
        }
    }
    for (int i = WIN_WIDTH; i < SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < SCREEN_HEIGHT; j++)
        {
            gotoxy(i, j);
            if(j == SCREEN_HEIGHT-1 || j == SCREEN_HEIGHT-2){
                cout << "#";
            }
            else{
                cout << " ";
            }
            
        }
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        gotoxy(WIN_WIDTH, i);
        cout << "#";
        gotoxy(SCREEN_WIDTH, i);
        cout << "#";
    }
}

void  drawCar()
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + carPos, i + yposition);
            cout << car[i][j];
        }
    }
}

void eraseCar()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + carPos, i + yposition);
            cout << " ";
        }
    }
}

void genEnemy(int i){
    
    enemyX[i] = 19 + (rand() % 37);
    
}


void drawEnemny(int i){
    if(Enemy[i]){
        gotoxy(enemyX[i], enemyY[i]);
        cout << "****";
        gotoxy(enemyX[i], enemyY[i] + 1);
        cout << " ** ";
        gotoxy(enemyX[i], enemyY[i] + 2);
        cout << "****";
        gotoxy(enemyX[i], enemyY[i] + 3);
        cout << " ** ";
    }    
}


void eraseEnemy(int i)
{
    if (Enemy[i])
    {
        gotoxy(enemyX[i], enemyY[i]);
        cout << "    ";
        gotoxy(enemyX[i], enemyY[i] + 1);
        cout << "    ";
        gotoxy(enemyX[i], enemyY[i] + 2);
        cout << "    ";
        gotoxy(enemyX[i], enemyY[i] + 3);
        cout << "    ";
    }
}

void gencoin(int i)
{
    coinX[i] = 19 + (rand() % 37);
    coinY[i] = 1;
}

void drawCoin(int i)
{
    if (coin[i])
    {
        gotoxy(coinX[i], coinY[i]);
        cout << Coin;
    }
}

void eraseCoin(int i)
{
    if (coin[i])
    {
        gotoxy(coinX[i], coinY[i]);
        cout << " ";

    }
}

void scorecount(int &score){
    gotoxy(WIN_WIDTH + 2, 1);
    ifstream MyFile3("score.txt");
    string file_score;
    getline(MyFile3, file_score);
    int int_file_score = stoi(file_score);
    MyFile3.close();
    if(int_file_score > score){
        cout << "Highest Score: " << int_file_score;
    }
    else{
        cout << "Highest Score: " << score;
    }

    gotoxy(WIN_WIDTH + 9, 5);
    cout << "Score: " << score << endl;
}


int collision(int i){

    
    if ((enemyX[i] + 4 - carPos >= 0 && enemyX[i] + 4 - carPos < 9) && (enemyY[i] + 4 - yposition >= 1 && enemyY[i] + 4 - yposition < 8))
    {
        return 1;
    }

    return 0;

}


int collectCoin(int i){
    if((coinX[i] - carPos >=0 && coinX[i] - carPos < 5) && (coinY[i] - yposition >=0 && coinY[i] - yposition < 5)){
        return 1;
    }
    return 0;
}


void gameover(int score)
{
    system("cls");
    cout << endl;
    cout << "\t\t---------------------------" << endl;
    cout << "\t\t-------- Game Over --------" << endl;
    cout << "\t\t---------------------------" << endl<< endl;
    cout << "\t\t-----  Your Score -> " <<score<<" -----"<< endl<<endl;
        
    for (int i = 0; i < 5; i++)
    {
        await();
    }
    

}


void play(int speed,char name[], int age){

    carPos = (WIN_WIDTH / 2) - 1;
    yposition = 21;
    gotoxy(18, 5);
    cout << "Press any key to start";
    getch();
    gotoxy(18, 5);
    cout << "                      ";

    int score = 0;
    enemyY[0] = enemyY[1] = 1;
    Enemy[0] = 1;
    Enemy[1] = 0;
    coin[0] = 1;
    coin[1] = coin[2] = 0;
    genEnemy(0);
    genEnemy(1); //2 ENEMY IS CREATED

    gencoin(0);
    gencoin(1); //genreating 3 coins
    gencoin(2);

    scorecount(score);
    while(1){        

        //CONTROLING THE CAR
        if (kbhit())
        {
            char ch = getch();
            if (ch == 'a' || ch == 'A')
            {
                if (carPos > 20)
                    carPos -= 4;
            }
            if (ch == 'd' || ch == 'D')
            {
                if (carPos < WIN_WIDTH - 22)
                    carPos += 4;
            }
            if (ch == 'w' || ch == 'W')
            {
                if (yposition > 4)
                    yposition -= 2;
            }
            if (ch == 's' || ch == 'S')
            {
                if (yposition < 20)
                    yposition += 2;
            }
            if (ch == 27)
            {
                break;
            }
        }

        drawCar();

        drawCoin(0);
        drawCoin(1);
        drawCoin(2);

        drawEnemny(0);
        drawEnemny(1);

        if (collision(0) == 1)
        {
            ofstream of;
            of.open("user.txt", ios::app);
            of << name << "  " << age << "  " << score << endl;
            of.close();

            ifstream MyFile3("score.txt");
            string file_score;
            getline(MyFile3, file_score);
            int int_file_score = stoi(file_score);
            if(int_file_score < score){
                int_file_score = score;
            }
            MyFile3.close();

            ofstream of1;
            of1.open("score.txt");
            of1 << int_file_score;
            of1.close();

            gameover(score);
            return;
        }


        if (collision(1) == 1)
        {
            ofstream of;
            of.open("user.txt", ios::app);
            of << name << "  " << age << "  " << score << endl;
            of.close();

            ifstream MyFile3("score.txt");
            string file_score;
            getline(MyFile3, file_score);
            int int_file_score = stoi(file_score);
            if (int_file_score < score)
            {
                int_file_score = score;
            }
            MyFile3.close();


            ofstream of1;
            of1.open("score.txt");
            of1 << int_file_score;
            of1.close();


            gameover(score);
            return;
        }

        if(collectCoin(0)){
            score += 5;
            scorecount(score);
            eraseCoin(0);
            coinY[0] = 1;
        }

        if (collectCoin(1))
        {
            score += 5;
            scorecount(score);
            eraseCoin(1);
            coinY[1] = 1;
        }


        if (collectCoin(2))
        {
            score += 5;
            scorecount(score);
            eraseCoin(2);
            coinY[2] = 1;
        }

        // normal = 115
        Sleep(speed);             
        
        eraseCar();

        eraseCoin(0);
        eraseCoin(1);
        eraseCoin(2);

        eraseEnemy(0);
        eraseEnemy(1);

        //MOVING THE ENEMY CODE  
        if (enemyY[0] == 10)
        {
            if (Enemy[1] == 0)
            {
                Enemy[1] = 1; 
            }

        }

        if (Enemy[0])
        {
            enemyY[0] += 1;
        }

        if (Enemy[1])
        {
            enemyY[1] += 1;
        }

        if (enemyY[0] == SCREEN_HEIGHT - 4)
        {
            eraseEnemy(0);
            enemyY[0] = 1;
            genEnemy(0);
            score += 2;
            scorecount(score);
        }

        if (enemyY[1] == SCREEN_HEIGHT - 4)
        {
            eraseEnemy(1);
            enemyY[1] = 1;
            genEnemy(1);
            score += 2;
            scorecount(score);
        }




        if (coinY[0] == 8)
        {
            if (coin[1] == 0)
            {
                coin[1] = 1;
            }
        }

        if (coinY[0] == 16)
        {
            if (coin[2] == 0)
            {
                coin[2] = 1;
            }
        }

        if (coin[0])
        {
            coinY[0] += 1;
        }

        if (coin[1])
        {
            coinY[1] += 1;
        }

        if (coin[2])
        {
            coinY[2] += 1;
        }

        if (coinY[0] == SCREEN_HEIGHT - 1)
        {
            eraseCoin(0);
            coinY[0] = 1;
            gencoin(0);

        }

        if (coinY[1] == SCREEN_HEIGHT - 1)
        {
            eraseCoin(1);
            coinY[1] = 1;
            gencoin(1);
            
        }

        if (coinY[2] == SCREEN_HEIGHT - 1)
        {
            eraseCoin(2);
            coinY[2] = 1;
            gencoin(2);
            
        }
    }


}


void preplay(){
    int choice;
    user u1;
    while (true){
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t------------------------------------ " << endl;
        cout << " \t\t\t|               Car Game            | " << endl;
        cout << " \t\t\t------------------------------------" << endl;
        cout << endl;
        cout << "\t\t\t\t1. Enter Details And Choose Options "<<endl;
        cout << "\t\t\t\t2. return to main menu" << endl;
        cout << endl;
        cout << "\t\t\t  Select option: ";
        cin >> choice;
        if(choice == 1){

            char name[15];
            int age;
            int speed;
            int speed_choice;
            system("cls");
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\t\t\t\tEnter Name ";
            cin >> name;
            cout << "\t\t\t\tEnter Age ";
            cin >> age;

            int flag = 1;
            while(flag){
                int choice2;
                while (true)
                {
                    system("cls");
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\tSelect the Difficulty " << endl;
                    cout << "\t\t\t\tEnter 1 for Easy " << endl;
                    cout << "\t\t\t\tEnter 2 for Normal " << endl;
                    cout << "\t\t\t\tEnter 3 for Hard " << endl;
                    cout<< endl;
                    cout << "\t\t\t\tEnter the choice ";
                    cin >> speed_choice;

                    if (speed_choice == 1)
                    {
                        speed = 140;
                        break;
                    }

                    else if (speed_choice == 2)
                    {
                        speed = 115;
                        break;
                    }

                    else if (speed_choice == 3)
                    {
                        speed = 65;
                        break;
                    }

                    else{
                        cout << "Enter a valid value ";
                    }
                }


                system("cls");
                cout << endl;
                cout << endl;
                cout << "\t\tEnter 1 to Play the game" << endl;
                cout << "\t\tEnter 2 to return back" << endl;
                cout<< endl;
                cout << "\t\tEnter the choice ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    flag = 1;
                    system("cls");
                    drawBorder();
                    play(speed,name,age);
                }
                else if (choice2 == 2)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    cout << "Enter a valid choice ";
                }


            // Need to get the line from customers and then match the name and the password of the user for this you need to break the senetnce sting into words and then match the first word which is name and the third word which is the password;
            }

        }

        else if( choice == 2){
            break;
        }

        else{
            cout << "Enter a valid choice";
        }

    }

}


int main(){
    setcursor(0, 0);
    while(true){
        int choice1;
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        carPos = (WIN_WIDTH / 2) - 1;
        yposition = 21;
        cout << "\t\t\t------------------------------------ "<<endl;
        cout << " \t\t\t|               Car Game            | "<<endl;
        cout << " \t\t\t------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t1. Start Game" << endl;
        cout << "\t\t\t\t2. Instructions" << endl;
        cout << "\t\t\t\t3. Quit" << endl;
        cout << endl;
        cout << "\t\t\t  Select option: ";
        cin >> choice1;
        if(choice1 == 1){
            loading();
            system("cls");
            preplay();

        }

        else if(choice1 ==2){

            system("cls");
            cout << endl;
            cout << endl;
            cout<< endl;
            cout << "\t\t\tInstructions";
            cout << "\n \t\t\t----------------";
            cout << "\n \t\t\tAvoid Cars by Moving and collect as much coins Possible. " << endl;
            cout << "\n \t\t\tPress 'w' to move Forward";
            cout << "\n \t\t\tPress 's' to move Back";
            cout << "\n \t\t\tPress 'a' to move Left";
            cout << "\n \t\t\tPress 'd' to move Right";
            cout << "\n\n \t\t\tPress any key to go back to menu";
            getch();
        }

        else if(choice1 == 3){
            system("cls");
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\n \t\t\tHope you Enjoyed!!!";
            for(int i = 0 ; i < 4; i++){
                await();
            }
            break;

        }
    }
};
