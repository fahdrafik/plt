
namespace render {

  enum Window {
    NONE,
    MAIN_WINDOW,
    DRAFTING_WINDOW,
    PLAYER_INFO
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
    Player_Renderer player_renderer[2];
    state::Game* game;
    vector<sf::Sprite*> Monster_SP;
    vector<sf::Texture*> Monster_Texture;
    vector<sf::Sprite*> Cementery_SP;
    vector<sf::Texture*> Cemementery_Texture;
    vector<sf::Sprite*> Magic_SP;
    vector<sf::Texture*> Magic_texture;
    vector<sf::Sprite*> Deck_SP;
    vector<sf::Texture*> Deck_Texture;
    // Operations
  public:
    Scene ();
    ~Scene ();
    sf::Sprite getBackground ();
    PlayerRenderer* getPlayerRenderer (int index);
    void changeWindow (Window new_window);
    Window getWindow ();
  };

  /// class PlayerRenderer - 
  class PlayerRenderer {
    // Attributes
  private:
    state::Player* player;
    sf::Font font;
    Window affected_window;
    sf::Sprite Monstercard_sp;
    sp::Texture MonsterCard_texture;
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

};

