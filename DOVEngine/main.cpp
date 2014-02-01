#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow Window(sf::VideoMode(800,600), "DOVEngine", sf::Style::Titlebar | sf::Style::Close);
	sf::Vector2u size(800, 600);

	Window.setPosition(sf::Vector2i(200,200));

	Window.setKeyRepeatEnabled(false);

	std::string message = "Hello my name is DOVEngine";
	std::string display = "asd";

	sf::Clock clock;
	sf::Time time;
	
	int index = 0;

	//main Game loop------------------------------------------------------------------------------------------------------------------------------------------------
	while(Window.isOpen())
	{
		sf::Event Event;

		//Window Event loop
		while(Window.pollEvent(Event))
		{
			switch(Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;

			case sf::Event::GainedFocus:
				Window.setPosition(sf::Vector2i(size.x++,300));
				break;
			case sf::Event::LostFocus:
				//pause?
				break;
			case sf::Event::KeyPressed:
				break;
			case sf::Event::KeyReleased:
				if(Event.key.code == sf::Keyboard::Return)
				{
					std::cout << display;
					Window.setPosition(sf::Vector2i(size.x++,300));
				}
				break;
			case sf::Event::MouseEntered:
				break;
			case sf::Event::MouseLeft:
				break;
			case sf::Event::MouseMoved:
				break;
			case sf::Event::MouseButtonPressed:
				if(Event.mouseButton.button == sf::Mouse::Middle)
				Window.setPosition(sf::Vector2i(size.x++,300));
				break;
			case sf::Event::MouseWheelMoved:
				break;
			}
		}

		time = clock.getElapsedTime();			//this is the equivalent of Time.deltaTime because of the clock.restart - for Time.time, leave out clock.restart()
		clock.restart();
		Window.display();
	}
	//End main Game loop------------------------------------------------------------------------------------------------------------------------------------------------
}