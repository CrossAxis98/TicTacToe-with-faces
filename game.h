#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

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


class Board
{
sf::RenderWindow window;
sf::Texture background, firstFigure, secondFigure, firstMenu, secondMenu;
sf::Sprite backgroundSprite, firstFigureSprite[5], secondFigureSprite[5], firstMenuSprite, secondMenuSprite;
sf::Event event;
sf::Vector2i pressedPosition;
sf::Vector2f stringPosition{10,10};
int pressedSector;
int firstFigureCounter{-1}, secondFigureCounter{-1};
int actualRow{-1}, actualColumn{-1};
bool firstPlayerMove{true};
std::vector<int> firstPlayerPositions;
std::vector<int> secondPlayerPositions;
char sign[3][3];
char player = 'o', opponent = 'x';
sf::Font myFont;
sf::Text text;
bool start{true};
bool firstImageMenu{true};
bool chosenFigure{true};
public:
void display();
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

int evaluate(char board[3][3]);
};
