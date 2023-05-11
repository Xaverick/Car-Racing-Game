#include<iostream>
#include<conio.h>
#include <fstream>
#include<string>
#include <windows.h>
#include<map>
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

class cars{
    public:
        virtual char* getcar(int) = 0;
};

class car4by4: protected cars{
            
    char car1[16] = {'*',' ',' ','*',
                    '*', '*', '*', '*',
                    ' ', '*', '*', ' ',
                    '*', '*', '*', '*'};

    char car2[16] = {' ', '*','*', ' ',
                     '*', '*', '*', '*',
                     ' ', '*', '*', ' ',
                     '*', '*', '*', '*'};

    public: 
        char* getcar(int choice){
            if( choice == 1){
                return car1;
            }
            else if( choice ==2){
                return car2;
            }
        }


};


class car3by4: protected cars{
    char car1[12] = {' ','*',' ',
                     '*', '*', '*',
                     ' ', '*', ' ',
                     '*', '*', '*'};

    char car2[12] = {'*', ' ', '*',
                     '*', '*', '*',
                     ' ', '*', ' ',
                     '*', '*', '*'};

    public:
        char *getcar(int choice)
        {
            if (choice == 1)
            {
                return car1;
            }
            else if(choice == 2){
                return car2;
            }
        }    
};

class car4by5 : protected cars{
        char car1[20] = {'*',' ',' ', '*',
                         '*', '*','*','*',
                         ' ', '*','*',' ',
                         '*', '*','*','*',
                         '*', ' ',' ','*'};


        char car2[20] = {' ', '*', '*', ' ',
                         '*', '*', '*', '*',
                         ' ', '*', '*', ' ',
                         ' ', '*', '*', ' ',
                         '*', '*', '*', '*'};

    public:
        char *getcar(int choice)
        {
            if (choice == 1)
            {
                return car1;
            }
            else if (choice == 2)
            {
                return car2;
            }
        }
};


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


void  drawCar(int cartype)
{
    car4by4 sedan;
    car3by4 mini;
    car4by5 suv;
    char *car1 = sedan.getcar(1);
    char *car2 = sedan.getcar(2);
    char *car3 = mini.getcar(1);
    char *car4 = mini.getcar(2);
    char *car5 = suv.getcar(1);
    char *car6 = suv.getcar(2);

    if(cartype == 1){

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << car1[4 * i + j];
            }
            cout << endl;
        }
    }

    else if (cartype == 2)
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << car2[4 * i + j];
            }
            cout << endl;
        }
    }

    else if(cartype == 3){

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << car3[3 * i + j];
            }
            cout << endl;
        }

    }

    else if (cartype == 4)
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << car4[3 * i + j];
            }
            cout << endl;
        }
    }

    else if (cartype == 5)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << car5[4 * i + j];
            }
            cout << endl;
        }
    }

    else if (cartype == 6)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << car6[4 * i + j];
            }
            cout << endl;
        }
    }
}


void eraseCar(int cartype)
{

    if (cartype == 1)
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << " ";
            }
            cout << endl;
        }
    }

    else if (cartype == 2)
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << " ";
            }
            cout << endl;
        }
    }

    else if (cartype == 3)
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << " ";
            }
            cout << endl;
        }
    }

    else if (cartype == 4)
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << " ";
            }
            cout << endl;
        }
    }

    else if (cartype == 5)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << " ";
            }
            cout << endl;
        }
    }

    else if (cartype == 6)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(j + carPos, i + yposition);
                cout << " ";
            }
            cout << endl;
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


int collision(int i,int cartype){


    if(cartype == 3 || cartype == 4){
        if ((enemyX[i] + 3 - carPos >= 0 && enemyX[i] + 3 - carPos < 7) && (enemyY[i] + 4 - yposition >= 1 && enemyY[i] + 4 - yposition < 8))
        {
            return 1;
        }
    }
    else if (cartype == 5 || cartype == 6)
    {
        if ((enemyX[i] + 4 - carPos >= 0 && enemyX[i] + 4 - carPos < 9) && (enemyY[i] + 5 - yposition >= 1 && enemyY[i] + 5 - yposition < 10))
        {
            return 1;
        }
    }
    else{
        if ((enemyX[i] + 4 - carPos >= 0 && enemyX[i] + 4 - carPos < 9) && (enemyY[i] + 4 - yposition >= 1 && enemyY[i] + 4 - yposition < 8))
        {
            return 1;
        }
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


void play(int speed,user u1,int cartype){

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
            if(cartype == 3 || cartype == 4){
                if (ch == 'a' || ch == 'A')
                {
                    if (carPos > 20)
                        carPos -= 3;
                }
                if (ch == 'd' || ch == 'D')
                {
                    if (carPos < WIN_WIDTH - 22)
                        carPos += 3;
                }
            }

            else{
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

        drawCar(cartype);

        drawCoin(0);
        drawCoin(1);
        drawCoin(2);

        drawEnemny(0);
        drawEnemny(1);

        if (collision(0,cartype) == 1)
        {
            ofstream of;
            of.open("user.txt", ios::app);
            of << u1.get_name() << "  " << u1.get_age() << "  " << score << endl;
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


        if (collision(1,cartype) == 1)
        {
            ofstream of;
            of.open("user.txt", ios::app);
            of << u1.get_name() << "  " << u1.get_age() << "  " << score << endl;
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
        
        eraseCar(cartype);

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


int selectcar(){
    car4by4 sedan;
    car3by4 mini;
    car4by5 suv;
    system("cls");
    while (true)
    {
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t------------------------------------ " << endl;
        cout << " \t\t\t|            Select Car            | " << endl;
        cout << " \t\t\t------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        char *car1 = sedan.getcar(1);
        char *car2 = sedan.getcar(2);
        char *car3 = mini.getcar(1);
        char *car4 = mini.getcar(2);
        char *car5 = suv.getcar(1);
        char *car6 = suv.getcar(2);

        while(true){
            char choice;
            system("cls");
            cout << "\t\t\t------------------------------------ " << endl;
            cout << " \t\t\t|            Select Car            | " << endl;
            cout << " \t\t\t------------------------------------" << endl;
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    gotoxy(j + 40, i + 6);
                    cout << car2[4 * i + j];
                }
                cout << endl;
            }
            gotoxy(30, 12);
            cout << "To select this car Press y else n ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){
                return 2;
            }

            else{
                system("cls");
                cout << "\t\t\t------------------------------------ " << endl;
                cout << " \t\t\t|            Select Car            | " << endl;
                cout << " \t\t\t------------------------------------" << endl;
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        gotoxy(j + 40, i + 6);
                        cout << car1[4 * i + j];
                    }
                    cout << endl;
                }
            }

            gotoxy(30, 12);
            cout << "To select this car Press y else n ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                return 1;
            }

            else
            {
                system("cls");
                cout << "\t\t\t------------------------------------ " << endl;
                cout << " \t\t\t|            Select Car            | " << endl;
                cout << " \t\t\t------------------------------------" << endl;
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        gotoxy(j + 40, i + 6);
                        cout << car3[3 * i + j];
                    }
                    cout << endl;
                }
            }
            gotoxy(30, 12);
            cout << "To select this car Press y else n ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                return 3;
            }

            else
            {
                system("cls");
                cout << "\t\t\t------------------------------------ " << endl;
                cout << " \t\t\t|            Select Car            | " << endl;
                cout << " \t\t\t------------------------------------" << endl;
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        gotoxy(j + 40, i + 6);
                        cout << car4[3 * i + j];
                    }
                    cout << endl;
                }
            }
            gotoxy(30, 12);
            cout << "To select this car Press y else n ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                return 4;
            }

            else
            {
                system("cls");
                cout << "\t\t\t------------------------------------ " << endl;
                cout << " \t\t\t|            Select Car            | " << endl;
                cout << " \t\t\t------------------------------------" << endl;
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        gotoxy(j + 40, i + 6);
                        cout << car5[4 * i + j];
                    }
                    cout << endl;
                }
            }
            gotoxy(30, 12);
            cout << "To select this car Press y else n ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                return 5;
            }


            else
            {
                system("cls");
                cout << "\t\t\t------------------------------------ " << endl;
                cout << " \t\t\t|            Select Car            | " << endl;
                cout << " \t\t\t------------------------------------" << endl;
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        gotoxy(j + 40, i + 6);
                        cout << car6[4 * i + j];
                    }
                    cout << endl;
                }
            }
            gotoxy(30, 12);
            cout << "To select this car Press y else n ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                return 6;
            }
            system("cls");
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

            string name;
            int age;
            int speed;
            int speed_choice;
            system("cls");
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\t\t\t\tEnter Name ";
            getline(cin,name);
            cout << "\t\t\t\tEnter Age ";
            cin >> age;
            u1.setName(name);
            u1.setAge(age);

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
                int cartype = selectcar();
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
                    play(speed,u1,cartype);
                }
                else if (choice2 == 2)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    cout << "Enter a valid choice ";
                    for(int i = 0; i<2; i++){
                        await();
                    }
                }

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
            // loading();
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
