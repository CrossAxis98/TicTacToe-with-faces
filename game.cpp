#include "game.h"

void Board::display()
{
uploadGraphics();
while(window.isOpen())
{
if(start){ menuEvents();}
eventsHandling();
window.clear();
draw();
if((checkIfEnd('o', actualRow, actualColumn))||(checkIfEnd('x', actualRow, actualColumn))||((firstFigureCounter+secondFigureCounter)==7)) {endGameSubtitles(); whatToDo();}
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
firstMenu.loadFromFile("firstStartingImage.png");
secondMenu.loadFromFile("secondStartingImage.png");

backgroundSprite.setTexture(background);
firstMenuSprite.setTexture(firstMenu);
secondMenuSprite.setTexture(secondMenu);
myFont.loadFromFile( "arial.ttf");
text.setFont(myFont);
text.setCharacterSize(60);
text.setFillColor(sf::Color::Red);
text.setPosition(stringPosition);
for(int i=0; i<5; i++)
{
firstFigureSprite[i].setTexture(firstFigure);
secondFigureSprite[i].setTexture(secondFigure);
}
}

void Board::draw()
{

if(start)
{
if(firstImageMenu)
    {window.draw(firstMenuSprite);}
else
    {window.draw(secondMenuSprite);}
}
else
{
window.draw(backgroundSprite);
if(((secondFigureCounter<4)||(firstFigureCounter<4))&&((firstFigureCounter>=0)||secondFigureCounter>=0))
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

        settingPositionOfSprite();








}


void Board::givePressedPosition()
{
        pressedPosition = sf::Mouse::getPosition(window);
}

void Board::settingPositionOfSprite()
{
    if(firstPlayerMove)
        {
        firstFigureCounter++;

        switch(pressedSector)
        {
        case 1:
        firstFigureSprite[firstFigureCounter].setPosition(43,10);
        firstPlayerPositions.push_back(1);
        sign[0][0]='o';
        actualRow=0;
        actualColumn=0;
        break;
        case 2:
        firstFigureSprite[firstFigureCounter].setPosition(213,10);
        firstPlayerPositions.push_back(2);
        sign[0][1]='o';
        actualRow=0;
        actualColumn=1;
        break;
        case 3:
        firstFigureSprite[firstFigureCounter].setPosition(383,10);
        firstPlayerPositions.push_back(3);
        sign[0][2]='o';
        actualRow=0;
        actualColumn=2;
        break;
        case 4:
        firstFigureSprite[firstFigureCounter].setPosition(43,180);
        sign[1][0]='o';
        actualRow=1;
        actualColumn=0;
        break;
        case 5:
        firstFigureSprite[firstFigureCounter].setPosition(213,180);
        sign[1][1]='o';
        actualRow=1;
        actualColumn=1;
        break;
        case 6:
        firstFigureSprite[firstFigureCounter].setPosition(383,180);
        sign[1][2]='o';
        actualRow=1;
        actualColumn=2;
        break;
        case 7:
        firstFigureSprite[firstFigureCounter].setPosition(43,350);
        sign[2][0]='o';
        actualRow=2;
        actualColumn=0;
        break;
        case 8:
        firstFigureSprite[firstFigureCounter].setPosition(213,350);
        sign[2][1]='o';
        actualRow=2;
        actualColumn=1;
        break;
        case 9:
        firstFigureSprite[firstFigureCounter].setPosition(383,350);
       sign[2][2]='o';
       actualRow=2;
        actualColumn=2;
        break;
        default:
        std::cout<<"Something wrong with settingPositionOfSprite"<<std::endl;
        }
        firstPlayerMove=false;

        }
    else
        {
        secondFigureCounter++;

        switch(pressedSector)
        {
        case 1:
        secondFigureSprite[secondFigureCounter].setPosition(35,35);
        sign[0][0]='x';
        actualRow=0;
        actualColumn=0;
        break;
        case 2:
        secondFigureSprite[secondFigureCounter].setPosition(205,35);
        sign[0][1]='x';
        actualRow=0;
        actualColumn=1;
        break;
        case 3:
        secondFigureSprite[secondFigureCounter].setPosition(375,35);
        sign[0][2]='x';
        actualRow=0;
        actualColumn=2;
        break;
        case 4:
        secondFigureSprite[secondFigureCounter].setPosition(35,205);
        sign[1][0]='x';
        actualRow=1;
        actualColumn=0;
        break;
        case 5:
        secondFigureSprite[secondFigureCounter].setPosition(205,205);
        sign[1][1]='x';
        actualRow=1;
        actualColumn=1;
        break;
        case 6:
        secondFigureSprite[secondFigureCounter].setPosition(375,205);
        sign[1][2]='x';
        actualRow=1;
        actualColumn=2;
        break;
        case 7:
        secondFigureSprite[secondFigureCounter].setPosition(35,375);
        sign[2][0]='x';
        actualRow=2;
        actualColumn=0;
        break;
        case 8:
        secondFigureSprite[secondFigureCounter].setPosition(205,375);
        sign[2][1]='x';
        actualRow=2;
        actualColumn=1;
        break;
        case 9:
        secondFigureSprite[secondFigureCounter].setPosition(375,375);
        sign[2][2]='x';
        actualRow=2;
        actualColumn=2;
        break;
        default:
        std::cout<<"Something wrong with settingPositionOfSprite"<<std::endl;

        }
        firstPlayerMove=true;

        }

}


void Board::endGame()
{
auto it=firstPlayerPositions.begin();
if((!firstPlayerPositions.empty())&&(*it==1)&&(*(it+1)==2)&&(*(it+2)==3))
    std::cout<<"HEJ:";

}


bool Board::checkIfEnd(char signToCheck, int row, int column)
{
if((sign[row][0]==signToCheck)&&(sign[row][1]==signToCheck)&&(sign[row][2]==signToCheck))
    {return true;}
if((sign[0][column]==signToCheck)&&(sign[1][column]==signToCheck)&&(sign[2][column]==signToCheck))
    {return true;}
if(((sign[0][0]==signToCheck)&&(sign[1][1]==signToCheck)&&(sign[2][2]==signToCheck))||((sign[2][0]==signToCheck)&&(sign[1][1]==signToCheck)&&(sign[0][2]==signToCheck)))
    {return true;}

    return false;

}


void Board::endGameSubtitles()
{
    text.setString("\n Press Space - to\n play again \n\n Press Esc - to\n quit ");
    window.draw(text);

}


void Board::whatToDo()
{

while( window.pollEvent( event ) )
        {

            if( event.type == sf::Event::Closed )
                 window.close();

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space )
                 reset();

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                 window.close();


        }


}

void Board::reset()
{
firstFigureCounter=(-1);
secondFigureCounter=(-1);

for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
        {
        sign[i][j]='0';
        }

firstPlayerMove=chosenFigure;

}

void Board::menuEvents()
{
while( window.pollEvent( event ) )
        {


            if( event.type == sf::Event::Closed )
                 window.close();

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down )
            {

                firstPlayerMove=false;
                firstImageMenu=false;
                chosenFigure=false;

            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up )
            {

                firstPlayerMove=true;
                firstImageMenu=true;
                chosenFigure=true;

            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space )
                 start=false;


        }


}


int Board::evaluate(char b[3][3])
{
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }

    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return +10;

            else if (b[0][col]==opponent)
                return -10;
        }
    }

    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }

    return 0;
}
