#include "State.h"
#include "engine.h"

namespace IA {

  /// class ia - 
  class ia {
    // Attributes
  public:
    /// This variable, gets if the player is in the main phase, or attack phase. 
    int turn;
    // Operations
  public:
    void run (Engine::Engine& engine);
    void GetCard (Decks NewCard);
    ia ();
    ~ia ();
  };

  /// class random_attack - this random class will read from the deck which are the available card, and the
  class random_attack : public ia {
    // Attributes
  public:
    int turn;
    // Operations
  public:
    void run (Engine engine);
    void attackPlayer (state Decks);
    random_attack ();
    ~random_attack ();
  };

};

