
namespace engine {

  /// class ChooseDeck - this class will manage the internal changes
  class ChooseDeck {
    // Attributes
  protected:
    state::Decks deck;
    // Operations
  public:
    void chooseDeck (state::Decks deck);
    void execute ();
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
    ModifyHand ();
    ModifyHand (state::Decks deck);
    void drawCard (int attacktype);
    void placeCard (state::Cards card);
    void execute ();
  };

  /// class Attack - this class will manage the internal changes
  class Attack {
    // Attributes
  protected:
    state::Players attackPlayer;
    state::Monsters attackMonster;
    state::Monsters attackingMonster;
    // Operations
  public:
    Attack ();
    Attack (state::Monsters monster, int attacktype);
    ~Attack ();
    void execute ();
  };

  /// class ModifyBoard - this class will manage the internal changes
  class ModifyBoard {
    // Attributes
  public:
    state::Boards board;
    // Operations
  public:
    ModifyBoard ();
    ModifyBoard (state::Cards card, state::Boards board);
    void change_monster_state (state::Monsters monster);
    void send_graveyard (state::Monsters monster);
    void triggerTrapSpell (state::Cards card);
    void execute ();
    void change_monster_state (state::Monsters monster, state::Boards board);
  };

  /// class Command - this class will manage the internal changes
  class Command {
    // Attributes
  protected:
    state::Players player;
    state::GameStates state;
    // Operations
  public:
    Command ();
    Command (state::Players player, state::GameStates state);
    ~Command ();
    void writeJSON (Command* command);
    void readJSON (std::vector<Command*> command);
  };

  /// class Engine - to manage the user commands
  class Engine {
    // Associations
    engine::Command* unnamed;
    // Attributes
  public:
    state::Players player;
  private:
    std::vector<Command> commands;
    state::GameStates state;
    std::vector<Command> past_commands;
  protected:
    Attack attack;
    ModifyBoard modifyBoard;
    ModifyHand modifyHand;
    ChooseDeck chooseDeck;
    // Operations
  public:
    Engine ();
    ~Engine ();
    /// 		
    /// @param state		(???) 
    void init ();
    void runCommands ();
    void addCommand ();
    void updateState ();
    void writeJSON (std::vector<Command> vect_command);
    void readJSON (std::vector<Command>& vect_command);
    int execute (int status);
    void execute_attackPlayerWmonster ();
    void execute_Monster_state ();
    void execute_send_graveyard ();
    void execute_trigger_trap_spell ();
    void execute_Place_Card ();
    void execute_attackMonsterWmonster ();
    void setPlayer (state::Players player);
  };

};

