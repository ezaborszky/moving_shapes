#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "circle.h"

using std::string;




int main() {

    const int wWidth = 1024;
    const int wHeight = 768; 
    
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Shapes");
    window.setFramerateLimit(60);

    
    Circle myCircle;
    Circle myCircle2("Circle2", 200, 250, 5.f, 3.f, 20, 100, 90, 20);

   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    window.clear();
 
    myCircle.draw(window);
    myCircle.detectCol(wWidth, wHeight);
    myCircle2.draw(window);
    myCircle2.detectCol(wWidth, wHeight);
    myCircle2.move();
    myCircle.move();
    window.display();

    }

return 0;
}

 
