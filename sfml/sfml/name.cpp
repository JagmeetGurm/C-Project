#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
//#include <Font.hpp>
int main()
{    //main VOR window
	sf::RenderWindow window(sf::VideoMode(550, 520), "VOR", sf::Style::Close);
	//creating the dial of the VOR with circleshape class
	sf::CircleShape shape(250);
	//setting attributes of the dial of VOR
	shape.setPosition(15, 15);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::White);
	//creating the compass(CDI- Course Deviation Indicator) using rectangleshape class
	sf::RectangleShape compass(sf::Vector2f(230, 5));
	//setting attributes of the CDI
	compass.setPosition(260, 140);
	compass.rotate(90);
	//creating the deflection points by declaring a array of circularshape class
	sf::CircleShape deflection[10];
	//setting the deflection points' attributes
	for (int i = 0,x=120; i < 10; i++)
	{				
			deflection[i].setRadius(4);
			deflection[i].setPosition(x, 260);
			x = x + 30;
	}
	
	sf::Font font;
//	if (!font.loadFromFile("./arial.ttf"))
	std::cout << "Not available"<<std::endl;

	sf::Text text;
	text.setFont(font);
	text.setString("To");
	text.setCharacterSize(14);
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setPosition(300, 100);
	//creating the Rotating course card from 0 to 360 degree using the recatangleshape class
	sf::RectangleShape rects[12];
	//setting its attributes
	int j = 90;
	for (int i = 0; i < 12; i++)
	{
			rects[i].setSize(sf::Vector2f(15, 4));
			rects[i].rotate(j);
			j = j + 30;
	}
	rects[0].setPosition(260, 65);
	rects[1].setPosition(355, 110);
	rects[2].setPosition(410, 185);
	rects[3].setPosition(440, 265);
	rects[4].setPosition(405, 345);
	rects[5].setPosition(335, 410);
	rects[6].setPosition(256, 440);
	rects[7].setPosition(178, 395);
	rects[8].setPosition(120, 335);
	rects[9].setPosition(80, 263);
	rects[10].setPosition(110, 170);
	rects[11].setPosition(175, 105);
	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
				
		window.clear(sf::Color::Black);
	
//drawing the our created elements
		window.draw(shape);
		window.draw(compass);
		window.draw(text);
		for (int i = 0; i < 12; i++)
		{
			window.draw(rects[i]);
		}
		
		for (int i = 0; i < 10; i++)
		{
			window.draw(deflection[i]);
		}
		window.display();
	}

	return 0;
}
