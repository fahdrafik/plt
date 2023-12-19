#include "State.h"

namespace engine {

  /// class internal_changes - this class will manage the internal changes
  class internal_changes {
    // Operations
  public:
    void change_monster_state ();
    rotate_card ();
    change_lifepoints ();
    send_graveyard ();
    runInternalCommand ();
  };

  /// class Usser_Comands - to manage the user commands
  class Usser_Comands {
    // Attributes
  public:
    bool draw;
    bool place;
    bool changeMonsterState;
    bool flipCard;
    bool attackMonster;
  private:
    /// this detects if a click happended, if the click was on a sprite then it reads a
    bool command;
    // Operations
  public:
    void get_command ();
    void draw_card ();
    void place_in_field ();
    void change_card_state ();
    void attack_monster ();
    void runUserCommand ();
  };

  /// class game - with this class we will update: commands, execution, and more.
  class game {
    // Attributes
  public:
    float dt;
    sf::Clock dtClock;
    sf::event sfEvent;
    /// I will try to eliminate this parametters and adding them in the game function. 
    sf::RenderWindow  window();
    sf::Vector2i windowPosition;
    // Operations
  public:
    void updateSFMLevents ();
    void update ();
    void run ();
    game ();
    ~game ();
    void updateDt ();
    void initWindow ();
  };

};

