#include "sfmlBasics.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main(int argc, char *argv[])
{
	sf::Vector2f viewSize(1024, 768);
	sf::VideoMode vm(viewSize.x, viewSize.y);
	sf::RenderWindow window(vm, "Hello world", sf::Style::Default);

	// Rectangle
	sf::RectangleShape rect(sf::Vector2f(500.0f, 300.0f));
	rect.setFillColor(sf::Color::Yellow);
	rect.setPosition(viewSize.x/2, viewSize.y/2);
	rect.setOrigin(sf::Vector2f(rect.getSize().x/2, rect.getSize().y/2));

	// Circle
	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(viewSize.x/2, viewSize.y/2);
	circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));

	// Triangle
	sf::ConvexShape triangle(3);
	triangle.setPoint(0, sf::Vector2f(-100, 0));
	triangle.setPoint(1, sf::Vector2f(0, -100));
	triangle.setPoint(2, sf::Vector2f(100, 0));
	triangle.setFillColor(sf::Color(128, 0, 128, 200));
	triangle.setPosition(viewSize.x/2, viewSize.y/2);

	window.setActive();
	while (window.isOpen()) {
		// Handle keyboard events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// update game objects in the scene
		window.clear(sf::Color::Red);
		window.draw(rect);
		window.draw(circle);
		window.draw(triangle);
		// render game objects
		window.display();
	}
	window.setActive(false);
	return 0;
}

