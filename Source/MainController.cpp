#include "MainController.hpp"

MainController::MainController() : mainMenuView() {}

void MainController::run() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			} else {
				handleMainMenuEvent(event);
			}
		}
		window.clear();
		mainMenuView.draw(window);
		window.display();
	}
}

void MainController::handleMainMenuEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (mainMenuView.isStartButtonClicked(event.mouseButton.x, event.mouseButton.y)) {
            // Start game
        }
        else if (mainMenuView.isChangeColorButtonClicked(event.mouseButton.x, event.mouseButton.y)) {
            // Change color
        }
        else if (mainMenuView.isLeaderboardButtonClicked(event.mouseButton.x, event.mouseButton.y)) {
            // Show leaderboard
        }
        else if (mainMenuView.isExitButtonClicked(event.mouseButton.x, event.mouseButton.y)) {
            // Exit game
            exit(0);
        }
    }
    else if (event.type == sf::Event::MouseMoved) {
        mainMenuView.handleMouseMove(event.mouseMove.x, event.mouseMove.y);
    }
    else if (event.type == sf::Event::KeyPressed) {
        mainMenuView.handleKeyboardInput(event);
    }
}
