#include "sfmlBasics.h"

int main(int argc, char *argv[])
{
	sf::Clock clock;
	window.setFramerateLimit(60);

	init();

	while (window.isOpen()) {

		updateInput();

		sf::Time dt = clock.restart();
		update(dt.asSeconds());

		window.clear(sf::Color::Red);

		draw();

		window.display();
	}
	return 0;
}

