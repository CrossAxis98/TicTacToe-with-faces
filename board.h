#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

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
sf::Texture background, firstFigure, secondFigure;
sf::Sprite backgroundSprite, firstFigureSprite[5], secondFigureSprite[5];
sf::Event event;
sf::Vector2i pressedPosition;
int pressedSector;
int firstFigureCounter{-1}, secondFigureCounter{-1};
bool firstFigureMove{true};
public:
void display();
void eventsHandling();
void uploadGraphics();
void draw();
void checkingPressedSector();
void givePressedPosition();

};
