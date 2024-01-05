
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
  private:
    state::Players* player;
    sf::Font font;
    Window affected_window;
    sf::Texture Infos_Texture;
    sf::Texture Cards_Texture;
    sf::Texture CementeryCards_Texture;
    sf::Texture ZoneCards_texture;
  protected:
    sf::Sprite Infos_SP;
    sf::Sprite Cards_SP;
    sf::Sprite CementeryCards_Sp;
    sf::Sprite ZoneCards_sp;
    // Operations
  public:
    Dynamic_scene ();
    Dynamic_scene (sf::Transform transform, Window affected_window);
    ~Dynamic_scene ();
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
    sf::Sprite getBackground ();
    Dynamic_scene getDynamic_scene (int index);
    void changeWindow (Window new_window);
    Window getWindow ();
    void setTitleScene ();
    void setInGameScene ();
    void setMenuScene ();
    void setConsultScene ();
    void setPlayerOneChoice ();
    void setPlayerTwoChoice ();
    void addSprite (render::Window window, int x, int y, float factorX, float factorY);
    void drawSprite (render::Window choix, sf::RenderWindow& window);
  };

};

