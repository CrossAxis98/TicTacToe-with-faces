#include "board.h"

void Board::display()
{
uploadGraphics();
while(window.isOpen())
{
eventsHandling();
window.clear();
draw();
window.display();
}

}

void Board::eventsHandling()
{
while( window.pollEvent( event ) )
        {

            if( event.type == sf::Event::Closed )
                 window.close();

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                 window.close();

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
            givePressedPosition();

            checkingPressedSector();

            }
        }
}

void Board::uploadGraphics()
{
window.create(sf::VideoMode( 512, 512, 32 ), "KolkoIDominik");
background.loadFromFile("plansza.jpg");
firstFigure.loadFromFile("iks3.png");
secondFigure.loadFromFile("kolko.png");

backgroundSprite.setTexture(background);

for(int i=0; i<5; i++)
{
firstFigureSprite[i].setTexture(firstFigure);
secondFigureSprite[i].setTexture(secondFigure);
}
}

void Board::draw()
{
window.draw(backgroundSprite);
if((secondFigureCounter<4)&&(firstFigureCounter>=0))
    {
        for(int i=0; i<=firstFigureCounter; i++)
        {
        window.draw(firstFigureSprite[i]);
        }
        for(int i=0; i<=secondFigureCounter; i++)
        {
        window.draw(secondFigureSprite[i]);
        }


    }
    else if(firstFigureCounter>=5)
    {
        exit(11);
    }



}

void Board::checkingPressedSector()
{

        if((pressedPosition.x<170)&&(pressedPosition.y<170))
        {
        pressedSector=position::first;
        }
        else if((171<pressedPosition.x)&&(pressedPosition.x<340)&&(pressedPosition.y<170))
        {
        pressedSector=position::second;
        }
        else if((341<pressedPosition.x)&&(pressedPosition.x<512)&&(pressedPosition.y<170))
        {
        pressedSector=position::third;
        }
        else if((pressedPosition.x<170)&&(pressedPosition.y>170)&&(pressedPosition.y<340))
        {
        pressedSector=position::fourth;
        }
        else if((171<pressedPosition.x)&&(pressedPosition.x<340)&&(pressedPosition.y>170)&&(pressedPosition.y<340))
        {
        pressedSector=position::fifth;
        }
        else if((341<pressedPosition.x)&&(pressedPosition.x<512)&&(pressedPosition.y>170)&&(pressedPosition.y<340))
        {
        pressedSector=position::sixth;
        }
        else if((pressedPosition.x<170)&&(pressedPosition.y>341)&&(pressedPosition.y<512))
        {
        pressedSector=position::seventh;
        }
        else if((171<pressedPosition.x)&&(pressedPosition.x<340)&&(pressedPosition.y>341)&&(pressedPosition.y<512))
        {
        pressedSector=position::eighth;
        }
        else if((341<pressedPosition.x)&&(pressedPosition.x<512)&&(pressedPosition.y>341)&&(pressedPosition.y<512))
        {
        pressedSector=position::ninth;
        }






        if(firstFigureMove)
        {
        firstFigureCounter++;
        firstFigureSprite[firstFigureCounter].setPosition(pressedPosition.x-42,pressedPosition.y-75);
        firstFigureMove=false;
        }
        else
        {
        secondFigureCounter++;
        secondFigureSprite[secondFigureCounter].setPosition(pressedPosition.x-50,pressedPosition.y-50);
        firstFigureMove=true;
        }


}


void Board::givePressedPosition()
{

        pressedPosition = sf::Mouse::getPosition(window);



}
