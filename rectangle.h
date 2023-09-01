#include<SFML/Graphics.hpp>

using std::string;

class Rectangle {

    string m_name = "Default";
    int m_xPos = 300;
    int m_yPos = 300;
    float m_xVel = 5.5f;
    float m_yVel = 5.5f;
    std::vector<int> m_rgb = {0,100,25};
    sf::Vector2f m_size = sf::Vector2f(16.5f, 24.f);
    sf::Font m_font;
    int m_charSize = m_size.y / 2;

public:

    Rectangle() 
    {
        rectangle.setSize(m_size);
        rectangle.setFillColor(sf::Color(m_rgb[0], m_rgb[1], m_rgb[2]));
        m_font.loadFromFile("font.ttf");
        text.setFont(m_font);
        text.setString(m_name);
        rectangle.setPosition(m_xPos, m_yPos);
        text.setPosition(m_xPos + (m_size.x/4), m_yPos + (m_size.y/2) + m_charSize/2);
        text.setCharacterSize(m_charSize);
    }

    Rectangle(sf::Vector2f size) 
    : m_size(size)
    {
        rectangle.setSize(m_size);
        m_font.loadFromFile("font.ttf");
        text.setFont(m_font);
        text.setString(m_name);
        rectangle.setPosition(m_xPos, m_yPos);
        text.setPosition(m_xPos + (m_size.x/4), m_yPos + (m_size.y/2) + m_charSize/2);
        text.setCharacterSize(m_charSize);
    }

    Rectangle(string name, int xpos, int ypos, float xvel, float yvel, int r, int g, int b, sf::Vector2f size)
    : m_name(name)
    , m_xPos(xpos)
    , m_yPos(ypos)
    , m_xVel(xvel)
    , m_yVel(yvel)
    , m_rgb({r,g,b})
    , m_size(size)
    
    {
        rectangle.setSize(m_size);
        rectangle.setFillColor(sf::Color(m_rgb[0], m_rgb[1], m_rgb[2]));
        m_font.loadFromFile("font.ttf");
        text.setFont(m_font);
        text.setString(m_name);
        rectangle.setPosition(m_xPos, m_yPos);
        text.setPosition(m_xPos + (m_size.x/4), m_yPos + (m_size.y/4));
        text.setCharacterSize(m_charSize);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(rectangle);
        window.draw(text);
    }

    void move() 
    {
        rectangle.setPosition(rectangle.getPosition().x + m_xVel, rectangle.getPosition().y + m_yVel);
        text.setPosition(text.getPosition().x + m_xVel, text.getPosition().y + m_yVel);
    }

    void detectCol(int width, int height) 
    {
        if( (rectangle.getPosition().x >= (width - m_size.x)) || rectangle.getPosition().x < 0) 
        {
            m_xVel *= -1;
        }

        if( (rectangle.getPosition().y >= (height - m_size.y)) || rectangle.getPosition().y < 0) 
        {
            m_yVel *= -1;
        }

      

    }



private:
    sf::RectangleShape rectangle;
    sf::Text text; 
    sf::Font myFont;
};