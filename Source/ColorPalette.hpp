

#ifndef COLORPALETTE_HPP
#define COLORPALETTE_HPP

#include <SFML/Graphics.hpp>
#include <array>

class ColorPalette {
public:
    ColorPalette()
        : defaultButtonColor(183, 180, 242),
          selectedButtonColor(159, 110, 227),
          defaultOutlineColor(178, 73, 174),
        selectedOutlineColor(200, 100, 150),
          defaultTextColor(216, 191, 216),
          selectedTextColor(194, 88, 91),
          background(199, 222, 252) {


        set1 = {
            sf::Color(0, 255, 255), // Cyan (I piece)
            sf::Color(255, 0, 0),   // Red (T piece)
            sf::Color(0, 255, 0),   // Green (S piece)
            sf::Color(255, 255, 0), // Yellow (Z piece)
            sf::Color(255, 165, 0), // Orange (L piece)
            sf::Color(0, 0, 255),   // Blue (J piece)
            sf::Color(128, 0, 128), // Purple (O piece)
            sf::Color(255, 255, 255) // White (Unused piece or background)
        };

        set2 = {
            sf::Color(0, 128, 128), // Dark Cyan (I piece)
            sf::Color(128, 0, 0),   // Dark Red (T piece)
            sf::Color(0, 128, 0),   // Dark Green (S piece)
            sf::Color(128, 128, 0), // Dark Yellow (Z piece)
            sf::Color(128, 82, 0),  // Dark Orange (L piece)
            sf::Color(0, 0, 128),   // Dark Blue (J piece)
            sf::Color(64, 0, 64),   // Dark Purple (O piece)
            sf::Color(64, 64, 64)   // Gray (Unused piece or background)
        };

        // Выбираем набор цветов по умолчанию
        colorSet = set1;
    }

    sf::Color defaultButtonColor;
    sf::Color selectedButtonColor;
    sf::Color defaultOutlineColor;
    sf::Color selectedOutlineColor;
    sf::Color defaultTextColor;
    sf::Color selectedTextColor;
    sf::Color background;

    std::array<sf::Color, 8> set1;
    std::array<sf::Color, 8> set2;

    void selectColorSet(bool useSet1) {
        colorSet = useSet1 ? set1 : set2;
    }

    sf::Color getColorForPiece(int pieceType, uint8_t alpha = 255) const {
        if (pieceType >= 1 && pieceType <= 7) {
            sf::Color color = colorSet[pieceType - 1];
            color.a = alpha;
            return color;
        }
        return sf::Color::White;
    }

private:
    std::array<sf::Color, 8> colorSet;
};

#endif //COLORPALETTE_HPP
