
namespace render {

  enum Window {
    NONE,
    MAIN_WINDOW,
    MENU_WINDOW,
    IN_PLAY_WINDOW,
    VIEW_CARDS_WINDOW,
    TITLE_SCREEN_WINDOW
  };

  /// class PlayerRenderer - 
  class PlayerRenderer {
    // Attributes
  private:
    state::Players* player;
    sf::Font font;
    Window affected_window;
    sf::Sprite Monstercard_sp;
    sf::Texture MonsterCard_texture;
    sf::Sprite MagiCard_sp;
    sf::Texture MagiCard_Texture;
    sf::Sprite CementeryCards_Sp;
    sf::Texture CementeryCards_Texture;
    sf::Sprite ZoneCards_sp;
    sf::Texture ZoneCards_texture;
    // Operations
  public:
    PlayerRenderer ();
    PlayerRenderer (sf::Transform transform, Window affected_window);
    ~PlayerRenderer ();
    sf::Sprite* getSprite (int index);
    sf::Transform getSpriteTransform (int index);
    int getNumberSprite ();
    sf::Text* getText (int index);
    sf::Transform getTextTransform (int index);
    int getNumberText ();
  };

  /// class Static_scene - 
  class Static_scene {
    // Attributes
  public:
    /// Here we put the name of the player, along with the lifepoints
    sf::RectangleShape info_box;
  private:
    Window current_window;
    /// It's the image displayed at the background
    sf::Sprite background;
    sf::Texture background_texture;
    /// This is a list with two players, because its a 2 players game.
    PlayerRenderer PlayerRenderers[2];
    state::GameStates* Game;
    std::vector<sf::Sprite*> Monster_SP;
    std::vector<sf::Texture*> Monster_Texture;
    std::vector<sf::Sprite*> Cementery_SP;
    std::vector<sf::Texture*> Cemementery_Texture;
    std::vector<sf::Sprite*> Magic_SP;
    std::vector<sf::Texture*> Magic_texture;
    std::vector<sf::Sprite*> Deck_SP;
    std::vector<sf::Texture*> Deck_Texture;
    // Operations
  public:
    Static_scene ();
    ~Static_scene ();
    sf::Sprite getBackground ();
    PlayerRenderer getPlayerRenderer (int index);
    void changeWindow (Window new_window);
    Window getWindow ();
  };

};

