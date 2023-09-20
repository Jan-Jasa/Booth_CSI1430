#include <iostream>
#include "SDL_Plotter.h"
#include <cmath>
#include <fstream>
#include "snakeStuff.h"
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const int NUM_ROW = 750;
const int NUM_COL = 1000;


enum Direction {UP, DOWN, LEFT, RIGHT};

int main(int argc, char **argv)
{
    char key;
    SDL_Plotter g(NUM_ROW,NUM_COL);
    int R=1, G=1, B=1;
    int xLoc = NUM_COL/2, yLoc = NUM_ROW/2;
    vector <int> prevX;
    vector <int> prevY;
    vector <int> eraseX;
    vector <int> eraseY;
    //int prevX, prevY;
    Direction dir = RIGHT;
    int speed = 25;
    int skip = 0, skip_val = 1;
    int candyX, candyY;
    int distanceFromCandy;
    candyX = rand()%750;
    candyY = rand()%500;
    bool flag = true;
    bool bounds = true;
    int count = 0;
    int place = 0;
    ifstream highScore;
    ofstream highScoreSave;
    char scoreCommand;
    string playerName;
    highScoreInfo topDogs[500];
    stringstream scores;
    bool scoreIsHigh = false;
    bool gamePause = false;
    bool gameStart = false;

    prevX.push_back(xLoc);
    prevY.push_back(yLoc);

    while(bounds && !g.getQuit()){


        //user Input
        if(g.kbhit()){
            key = g.getKey();

            switch(key){
                case UP_ARROW   :  dir = UP;
                                   break;

                case DOWN_ARROW :  dir = DOWN;
                                   break;

                case LEFT_ARROW :  dir = LEFT;
                                   break;

                case RIGHT_ARROW:  dir = RIGHT;
                                   break;

                case 'p':          gamePause = true;
                                   break;

                case 'u':          gamePause = false;
                                   break;

                case 's':          gameStart = true;
                                   break;
            }

        }

    //Process

    if(!gamePause && gameStart){
            g.clear();

            prevX.push_back(xLoc);
            prevY.push_back(yLoc);
            /*
            prevX.erase(prevX.begin());
            prevY.erase(prevY.begin());
            */


        switch(dir){
            case RIGHT: xLoc += 5;
                        break;

            case LEFT:  xLoc -= 5;
                        break;

            case UP:    yLoc -= 5;
                        break;

            case DOWN:  yLoc += 5;
                        break;
        }

    //Erase Trail of Snake
/*
        for(int i = 0; i < prevX.size(); i++){
                for(int y=0; y < SIZE; y++){
                    for(int x=0; x < SIZE; x++){
                        g.plotPixel(eraseX.at(0) + x, y + ,255,255,255);
                    }
                }
        }
        */
        /*
        for(int y=0; y < SIZE; y++){
            for(int x=0; x < SIZE; x++){
                    g.plotPixel(prevX.at(1) + x, y + prevY.at(1),255,255,255);
            }
        }
        */

    //Draw Candy
        if(flag){
            for(int y=0; y < SIZE - 10; y++){
                for(int x=0; x < SIZE - 10; x++){
                    g.plotPixel(candyX + x, candyY + y,255,G,B);
                }
            }
        }

        if(!flag){
            for(int y=0; y < SIZE - 10; y++){
                for(int x=0; x < SIZE - 10; x++){
                    g.plotPixel(candyX + x, candyY + y,255,255,255);
                }
            }
            //eraseX.push_back(prevX.at(0));
            //eraseY.push_back(prevY.at(0));
            flag = true;
            candyX = rand()%900;
            candyY = rand()%700;
            count++;
            //void playSound(string sound);
        }

        //Draw Snake Head
        if(bounds){
            for(int i = 0; i <= count * 7; i++){
                for(int y=0; y < SIZE; y++){
                    for(int x=0; x < SIZE; x++){
                        g.plotPixel(prevX.at(prevX.size() - i - 1) + x, prevY.at(prevX.size() - i - 1) + y,R,G,B);
                    }
                }
            }
        }
        //second flag for if bigger than bounds
        distanceFromCandy = sqrt(pow(xLoc - candyX , 2) + pow(yLoc - candyY , 2));

        if(distanceFromCandy < 28){
            flag = false;
        }

        if((xLoc < 0) || (yLoc < 0) || (xLoc > 975) || (yLoc > 730)){
            bounds = false;
        }
        skip = (skip+1)%skip_val;
        if(skip==0){
            g.update();
        }
        g.Sleep(speed);
    }
    }
    cout << "Game over." << endl << "Your score is ";
    cout << count << "." << endl << endl;

    // opens high score file, and then sends last score.
    highScore.open("highScore");

    while(highScore >> topDogs[place].score){
        highScore >> topDogs[place].name;
        place++;
    }

    sortByHighScore(topDogs, place);
    cout << "The Top Scores are: " << endl << endl;

    for(int i = 0; i < 3; i++){
        cout << i+1 << ". ";
        cout << topDogs[i].score << "\t" << topDogs[i].name << endl;
    }
    cout << endl;

    if((count > topDogs[0].score) || (count > topDogs[1].score) || (count > topDogs[2].score)){
        cout << "Add score to scoreboard? Y/N: ";
        do{
            cin >> scoreCommand;

            if(scoreCommand != 'Y' && scoreCommand != 'N'){
                cout << "Only Y/N are valid inputs, try again." << endl;
            }

        }while(scoreCommand != 'Y' && scoreCommand != 'N');
        scoreIsHigh = true;
    }
    highScoreSave.open("highScore");

    if(scoreCommand == 'Y' && scoreIsHigh){
        cout << endl << "Please enter your name: ";
        cin >> playerName;
        cout << endl;
        cout << "Good JOB, " << playerName << "! Play again!" << endl;
        for(int i = 0; i < 2; i++){
            highScoreSave << topDogs[i].score << "\t" << topDogs[i].name << endl;
        }
        highScoreSave << count << "\t" << playerName << endl;
    }
    if(!scoreIsHigh || scoreCommand == 'N'){
        cout << endl << "You suck!" << endl << endl << "Try again!" << endl;

        for(int i = 0; i < 3; i++){
        highScoreSave << topDogs[i].score << " " << topDogs[i].name << endl;
        }

    }

    highScoreSave.close();
    highScore.close();
    return 0;
}

#ifndef SNAKESTUFF_H_INCLUDED
#define SNAKESTUFF_H_INCLUDED
#include <string>

using namespace std;
const int SIZE = 36;

struct highScoreInfo{
    int score;
    string name;
};


void sortByHighScore(highScoreInfo[], int place);


#endif // SNAKESTUFF_H_INCLUDED

#include "snakeStuff.h"

void sortByHighScore(highScoreInfo a[], int place){
    for(int i = 0; i < place -1; i++){
        for(int p = 0; p < place - 1 - i; p ++){
            if(a[p].score < a[p+1].score){
                swap(a[p], a[p+1]);
            }
        }
    }

}
