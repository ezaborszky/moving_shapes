#include<SFML/Graphics.hpp>

using std::string;

class Circle {

    string m_name = "Default";
    int m_xPos = 300;
    int m_yPos = 300;
    float m_xVel = 5.5f;
    float m_yVel = 5.5f;
    std::vector<int> m_rgb = {0,100,25};
    float m_size = 50.f;
    sf::Font m_font;
    int m_charSize = m_size / 2;

public:

    Circle() 
    {
        circle.setRadius(m_size);
        circle.setFillColor(sf::Color(m_rgb[0], m_rgb[1], m_rgb[2]));
        m_font.loadFromFile("font.ttf");
        text.setFont(m_font);
        text.setString(m_name);
        circle.setPosition(m_xPos, m_yPos);
        text.setPosition(m_xPos + (m_size/4), m_yPos + (m_size/2) + m_charSize/2);
        text.setCharacterSize(m_charSize);
    }

    Circle(float size) 
    : m_size(size)
    {
        circle.setRadius(m_size);
        m_font.loadFromFile("font.ttf");
        text.setFont(m_font);
        text.setString(m_name);
        circle.setPosition(m_xPos, m_yPos);
        text.setPosition(m_xPos + (m_size/4), m_yPos + (m_size/2) + m_charSize/2);
        text.setCharacterSize(m_charSize);
    }

    Circle(string name, int xpos, int ypos, float xvel, float yvel, int r, int g, int b, float size)
    : m_name(name)
    , m_xPos(xpos)
    , m_yPos(ypos)
    , m_xVel(xvel)
    , m_yVel(yvel)
    , m_rgb({r,g,b})
    , m_size(size)
    
    {
        circle.setRadius(m_size);
        circle.setFillColor(sf::Color(m_rgb[0], m_rgb[1], m_rgb[2]));
        m_font.loadFromFile("font.ttf");
        text.setFont(m_font);
        text.setString(m_name);
        circle.setPosition(m_xPos, m_yPos);
        text.setPosition(m_xPos + (m_size/4), m_yPos + (m_size/2) + m_charSize/2);
        text.setCharacterSize(m_charSize);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(circle);
        window.draw(text);
    }

    void move() 
    {
        circle.setPosition(circle.getPosition().x + m_xVel, circle.getPosition().y + m_yVel);
        text.setPosition(text.getPosition().x + m_xVel, text.getPosition().y + m_yVel);
    }

    void detectCol(int width, int height) 
    {
        if( (circle.getPosition().x >= (width - (m_size*2) )) || circle.getPosition().x < 0) 
        {
            m_xVel *= -1;
        }

        if( (circle.getPosition().y >= (height - (m_size*2) )) || circle.getPosition().y < 0) 
        {
            m_yVel *= -1;
        }

           if( (text.getPosition().x >= (width - (m_size*2) )) || text.getPosition().x < 0) 
        {
            m_xVel *= -1;
        }

        if( (text.getPosition().y >= (height - (m_size) )) || text.getPosition().y < 0) 
        {
            m_yVel *= -1;
        }


    }



private:
    sf::CircleShape circle;
    sf::Text text; 
    sf::Font myFont;
};