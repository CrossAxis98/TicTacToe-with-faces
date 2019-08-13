#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

enum position
{
first=1,
second=2,
third=3,
fourth=4,
fifth=5,
sixth=6,
seventh=7,
eighth=8,
ninth=9
};

struct Move
{
int row {-1};
int column {-1};

};

class Board
{
sf::RenderWindow window;
sf::Texture background, firstFigure, secondFigure, firstMenu, secondMenu;
sf::Sprite backgroundSprite, firstFigureSprite[5], secondFigureSprite[5], firstMenuSprite, secondMenuSprite;
sf::Event event;
sf::Vector2i pressedPosition;
sf::Vector2f stringPosition{10,10};
int pressedSector{-1};
int firstFigureCounter{-1}, secondFigureCounter{-1};
int actualRow{-1}, actualColumn{-1};
bool firstPlayerMove{true};
char sign[3][3]{{0,0,0}, {0,0,0},{0,0,0}};
char player = 'x', opponent = 'o';
sf::Font myFont;
sf::Text text;
bool start{true};
bool firstImageMenu{true};
bool chosenFigure{true};

bool cpuMove{false};
int cpuSector{-1};
int pressedSectorByAI{-1};
public:
void play();
void eventsHandling();
void uploadGraphics();
void draw();
void checkingPressedSector();
void givePressedPosition();
void settingPositionOfSprite();
void endGame();
bool checkIfEnd(char sign, int row, int column);
void endGameSubtitles();
void whatToDo();
void reset();
void menuEvents();

int evaluate(char sign[3][3]);
bool isMovesLeft(char sign[3][3]);
int minimax(char sign[3][3], int depth, bool isMax);
Move findBestMove(char sign[3][3]);
void whatSectorChooosenAI(Move m);
};
