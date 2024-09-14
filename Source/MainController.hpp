#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include "MainMenuView.hpp"

class MainController {
public:
	MainController();
	void run();
	void handleMainMenuEvent(const sf::Event& event);
private:
	MainMenuView mainMenuView;

};

#endif
