#include "state.h"

namespace render {

  enum Window {
    NONE,
    MAIN_WINDOW,
    MENU_WINDOW,
    IN_PLAY_WINDOW,
    VIEW_CARDS_WINDOW,
    TITLE_SCREEN_WINDOW,
    PLAYER_1_CHOICE,
    PLAYER_2_CHOICE,
    DECK_CHOICE
  };

  /// class Dynamic_scene - 
  class Dynamic_scene {
    // Attributes
  protected:
    state::Players* player;
    sf::Font font;
    Window affected_window;
    sf::RenderWindow* window;
    sf::Sprite Infos_SP;
    sf::Texture Infos_Texture;
    sf::Sprite CardsInHands_SP;
    sf::Texture CardsInHands_Texture;
    sf::Sprite CardsInBoard_SP;
    sf::Texture CardsInBoard_Texture;
    sf::Text LifepointsText;
    std::vector<sf::Text> MonsterAttackText;
    std::vector<sf::Text> MonsterDefenseText;
    // Operations
  public:
    Dynamic_scene ();
    Dynamic_scene (state::Players* player, sf::RenderWindow* window);
    ~Dynamic_scene ();
    void displayCardInHands ();
    void displayCardsInBoard ();
    void displayLifePoints ();
    void displayMonsterParameter ();
    void initialiseCardsInHands ();
    void initialiseLifePoints ();
  };

  /// class Static_scene - 
  class Static_scene {
    // Attributes
  private:
    Window current_window;
    /// It's the image displayed at the background
    sf::Sprite background;
    sf::Texture background_texture;
    /// This is a list with two players, because its a 2 players game.
    Dynamic_scene playerDynamic_scene[2];
    state::GameStates* Game;
  protected:
    std::vector<sf::Sprite> Cards_SP;
    std::vector<sf::Texture> Cards_Texture;
    std::vector<sf::Sprite> Menu_SP;
    std::vector<sf::Texture> Menu_Texture;
    std::vector<sf::Sprite> In_Game_SP;
    std::vector<sf::Texture> In_Game_Texture;
    std::vector<sf::Sprite> Title_Screen_SP;
    std::vector<sf::Texture> Title_Screen_Texture;
    std::vector<sf::Sprite> Consult_Cards_SP;
    std::vector<sf::Texture> Consult_Cards_Texture;
    std::vector<sf::Sprite> Choice_1_Deck_SP;
    std::vector<sf::Texture> Choice_1_Deck_Texture;
    std::vector<sf::Sprite> Choice_2_Deck_SP;
    std::vector<sf::Texture> Choice_2_Deck_Texture;
    /// Here we put the name of the player, along with the lifepoints
    sf::RectangleShape info_box;
    // Operations
  public:
    Static_scene ();
    ~Static_scene ();
    void init ();
    sf::Sprite getBackground ();
    Dynamic_scene getDynamic_scene (int index);
    void changeWindow (Window new_window);
    Window getWindow ();
    void setTitleScene ();
    void setInGameScene ();
    void setMenuScene ();
    void setConsultScene ();
    void setPlayerOneChoiceScene ();
    void setPlayerTwoChoiceScene ();
    void addSprite (render::Window window, int x, int y, float factorX, float factorY);
    void drawSprite (render::Window choix, sf::RenderWindow& window);
  };

  /// class ChoiceMenu - 
  class ChoiceMenu {
    // Associations
    render::Static_scene* unnamed;
    // Attributes
  protected:
    Static_scene* scene;
    sf::RenderWindow* window;
    // Operations
  public:
    ChoiceMenu ();
    ChoiceMenu (Static_scene* scene);
    ChoiceMenu (Static_scene* scene, sf::RenderWindow* window);
    ~ChoiceMenu ();
    state::DeckChoice handleDeckChoice1 (sf::Vector2f mousePosition);
    state::DeckChoice handleDeckChoice2 (sf::Vector2f mousePosition);
    void handleTitleScreen (sf::Vector2f mousePosition);
    void handleMenuScene (sf::Vector2f mousePosition);
    void handleViewCards (sf::Vector2f mousePosition);
  };

  /// class Menu - 
  class Menu {
    // Associations
    render::ChoiceMenu* unnamed;
    // Attributes
  protected:
    ChoiceMenu* choice;
    sf::RenderWindow* window;
    Static_scene* scene;
    bool GameInit;
    state::DeckChoice deckChoice1;
    state::DeckChoice deckChoice2;
    // Operations
  public:
    Menu ();
    Menu (ChoiceMenu* choice, sf::RenderWindow* window, Static_scene* scene);
    ~Menu ();
    void run ();
    void play ();
  };

};

