#include "sfmlBasics.h"

int main(int argc, char *argv[])
{
	init();
	while (window.isOpen()) {

		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		window.clear(sf::Color::Red);

		draw();

		window.display();
	}
	return 0;
}

