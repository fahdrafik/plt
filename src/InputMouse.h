#include "ActionCard.h"

/// class InputMouse - 
class InputMouse {
  // Attributes
private:
  Bool Click;
  sf::Vector2i Position;
  // Operations
public:
  bool GetClick (sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
  sf::Vector2i GetMousePosition (sf::RenderWindow &window);
};

