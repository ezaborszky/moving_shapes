#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "circle.h"
#include "rectangle.h"
using std::string;




int main() {

    const int wWidth = 1024;
    const int wHeight = 768; 
    
    std::vector<Circle> circles;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Shapes");
    window.setFramerateLimit(60);

    
    Circle myCircle;
    Circle myCircle2("Circle2", 200, 250, 5.f, 3.f, 20, 100, 90, 20);
    Rectangle myRectangle("Rect", 100, 600, 5, 5, 200, 100, 30, sf::Vector2f(200,100));

    circles.push_back(myCircle);
    circles.push_back(myCircle2);
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    window.clear(sf::Color(100,100,5));
 

    for(auto &c : circles) 
    {
        c.draw(window);
        c.detectCol(wWidth, wHeight);
        c.move();
    };

    // myCircle.draw(window);
    // myCircle.detectCol(wWidth, wHeight);
    // myCircle2.draw(window);
    // myCircle2.detectCol(wWidth, wHeight);
    // myCircle2.move();
    // myCircle.move();

    myRectangle.draw(window);
    myRectangle.detectCol(wWidth, wHeight);
    myRectangle.move();
    window.display();

    }

return 0;
}

 
