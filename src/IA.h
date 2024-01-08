#include "engine.h"
#include "State.h"

namespace IA {

  /// class ia - 
  class ia {
    // Attributes
  public:
    /// This variable, gets if the player is in the main phase, or attack phase. 
    int turn;
    // Operations
  public:
    void run (Engine::Engine& Engine);
    void GetCard ( ModifyBoard);
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
    void run (Engine Engine);
    void attackPlayer (state Decks);
    random_attack ();
    ~random_attack ();
  };

};

