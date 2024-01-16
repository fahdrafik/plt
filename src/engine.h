
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
    state::Monsters attackingMonster;
    state::Monsters defendingMonster;
    int attacktype;
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
    int IdCardModify;
    // Operations
  public:
    ModifyBoard ();
    ModifyBoard (state::Cards card, state::Boards board);
    void change_monster_state (state::Monsters monster, state::Boards board);
    void triggerSpell (state::Spells* spell, state::Boards* attackingBoard, state::Boards* defendingBoard, int index);
    /// I assume that board_1 is for the usser and Board_2 is for the rival
    /// @param trap		(???) 
    /// @param attackingBoards		(???) 
    /// @param defendingBoard		(???) 
    /// @param index		(???) 
    void triggerTrap ();
    void SendCardZone (state::Cards card, state::Boards board);
    void execute ();
  };

  /// class Command - this class will manage the internal changes
  class Command {
    // Attributes
  protected:
    state::Players player;
    state::Players opponent;
    state::GameStates state;
    state::Boards board;
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
  private:
    std::vector<Command> commands;
    state::GameStates state;
    std::vector<Command> past_commands;
    state::Players current_player;
    state::Players opponent_player;
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
    void execute_changeTurn ();
    void setOpponent (state::Players opponent);
  };

};

