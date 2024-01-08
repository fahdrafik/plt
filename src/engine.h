
namespace engine {

  /// class internal_changes - this class will manage the internal changes
  class internal_changes {
    // Operations
  public:
    void change_monster_state ();
    void rotate_card ();
    void change_lifepoints ();
    void send_graveyard ();
    void runInternalCommand ();
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

  /// class Engine - to manage the user commands
  class Engine {
    // Attributes
  public:
    state::Players player;
  private:
    std::vector<Command> commands;
    state::GameStates state;
    std::vector<Command> past_commands;
    // Operations
  public:
    Engine ();
    /// 		
    /// @param state		(???) 
    void init ();
    void runCommands ();
    void addCommand ();
    void updateState ();
    void writeJSON (std::vector<Command> vect_command);
    void readJSON (std::vector<Command>& vect_command);
  };

  /// class Command - this class will manage the internal changes
  class Command {
    // Attributes
  protected:
    state::Players player;
    state::GameStates phase;
    // Operations
  public:
    Command (state::Players player, state::GameStates state);
    ~Command ();
    void execute (state::Players player, state::GameStates status);
    void writeJSON (Command* command);
    void readJSON (std::vector<Command*> command);
  };

  /// class Attack - this class will manage the internal changes
  class Attack {
    // Attributes
  protected:
    state::Players attackPlayer;
    state::Monsters attackMonster;
    // Operations
  public:
    Attack ();
    ~Attack ();
    Attack (int attacktype);
  };

  /// class ModifyBoard - this class will manage the internal changes
  class ModifyBoard {
    // Attributes
  public:
    state::Boards board;
    // Operations
  public:
    ModifyBoard (state::Cards card, state::Boards board);
    void change_monster_state (state::Monsters monster);
    void send_graveyard (state::Monsters monster);
    void triggerTrapSpell (state::Cards card);
  };

  /// class ModifyHand - this class will manage the internal changes
  class ModifyHand {
    // Attributes
  private:
    int RandomIndex;
  protected:
    state::Decks deck;
    // Operations
  public:
    ModifyHand (state::Decks deck);
    void drawCard (int attacktype);
    void placeCard (state::Cards card);
  };

  /// class ChooseDeck - this class will manage the internal changes
  class ChooseDeck {
    // Attributes
  protected:
    state::Decks deck;
    // Operations
  public:
    void chooseDeck (state::Decks deck);
  };

};

