
namespace state {

  /// class GameStates - 
  class GameStates {
    // Attributes
  protected:
    int turn;
    std::vector<Cards> cardList;
    std::vector<Players> playerList;
    bool end;
    // Operations
  public:
    GameStates ();
    ~GameStates ();
    void init ();
    void incrementTurn ();
    void displayScore ();
    void addPlayer ();
    void addBot ();
    void deletePlayer ();
    void createPlayer ();
    void deleteBot ();
  };

  enum DeckChoice {
    NoChoice,
    DeckDragon,
    DeckSynchro,
    DeckSoldier
  };

  enum CardTypes {
    NoType,
    TypeMonster,
    TypeTrap,
    TypeSpell
  };

  /// class Cards - 
  class Cards {
    // Attributes
  private:
    static int nombreDeCartes;
  protected:
    int idCard;
    std::string name;
    std::string path;
    CardTypes typeCarte;
    // Operations
  public:
    Cards (int idCard, std::string name, std::string path, CardTypes typeCarte);
    Cards (std::string name, std::string path, CardTypes typeCarte);
    Cards ();
    ~Cards ();
    bool isMonster ();
    bool isSpell ();
    bool isTrap ();
  };

  /// class Decks - 
  class Decks {
    // Attributes
  protected:
    int id;
    std::vector<Cards> cardsInDeck;
    std::vector<Cards> cardsInHand;
    int numberOfCards;
    // Operations
  public:
    Decks (std::vector<Cards> cardsInDeck);
    Decks (DeckChoice DeckChoice);
    Decks ();
    ~Decks ();
    void shuffle ();
    void drawCard ();
    void addCard (Cards card);
    void removeCard (int index);
  };

  enum TypePlayer {
    HUMAN,
    BOT
  };

  enum GameStatus {
    PLAYING,
    WON,
    LOOSE
  };

  /// class Boards - 
  class Boards {
    // Attributes
  public:
    static int nb_boards;
  protected:
    int id;
    std::vector<Monsters> monsters;
    std::vector<Spells> spells;
    std::vector<Traps> traps;
    std::vector<Cards> graveyard;
    // Operations
  public:
    Boards (std::vector<Spells> spells, std::vector<Traps> traps, std::vector<Monsters> monsters, std::vector<Cards> graveyard);
    Boards ();
    ~Boards ();
    void attackPosition (int index);
    void defensePosition (int index);
    void addMonster (state::Monsters monster);
    void removeMonster (int index);
    void addSpell (state::Spells spell);
    void removeSpell (int index);
    void addTrap (state::Traps trap);
    void removeTrap (int index);
  };

  /// class Players - 
  class Players {
    // Attributes
  private:
    static int nbPlayers;
  protected:
    int id;
    TypePlayer type;
    GameStatus status;
    Decks deck;
    Boards board;
    int lifepoints;
    // Operations
  public:
    Players (Decks Deck, Boards Board, TypePlayer type, int lifepoints);
    Players ();
    ~Players ();
    void drawCard ();
    void placeCard ();
    void setSpell ();
    void endTurn ();
    void looseLifePoints (int degat );
  };

  /// class Calculation - 
  class Calculation {
    // Attributes
  protected:
    int  lifePointsPlayer1;
    int lifePointsPlayer2;
    int attackPointsPlayer1;
    int attackPointsPlayer2;
    int defensePointsPlayer1;
    int defensePointsPlayer2;
    // Operations
  public:
    Calculation (int lifePointsPlayer1, int lifePointsPlayer2, int attackPointsPlayer1, int attackPointsPlayer2, int defensePointsPlayer1, int defensePointsPlayer2);
    ~Calculation ();
  };

  enum spellEffect {
    Ritual,
    NormalSpell,
    ContinuousSpell,
    Field ,
    Equiped ,
    Quickplay,
    Equipement,
    Revival,
    Retrieve,
    Control
  };

  /// class Spells - 
  class Spells : public Cards {
    // Attributes
  protected:
    spellEffect effect;
    bool On;
    int spellParameter;
    // Operations
  public:
    Spells ();
    ~Spells ();
    Spells (int idCard, std::string name, std::string path, CardTypes typeCarte, spellEffect effect, int spellParameter);
    Spells (std::string name, std::string path, CardTypes typeCarte, spellEffect effect, int spellParameter);
    void activate ();
    void desactivate ();
  };

  /// class Monsters - 
  class Monsters : public Cards {
    // Attributes
  protected:
    int level;
    int attack;
    int defense;
    bool position;
    int effet ;
    // Operations
  public:
    void attackCard (Cards card);
    void attackPlayer (Players player);
    void setSpell ();
    Monsters (int idCard, std::string name, std::string path, CardTypes typeCarte, int effet, int level, int attack, int defense, bool position);
    Monsters (std::string name, std::string path, CardTypes typeCarte, int  effet, int level, int attack, int defense, bool position);
    ~Monsters ();
  };

  enum trapEffect {
    NormalTrap,
    ContinuousTrap,
    Counter,
    DeleteCard,
    DeleteCardWithTreshold,
    DeleteCardLoosingLP,
    ReturnAttackToSender
  };

  /// class Traps - 
  class Traps : public Cards {
    // Attributes
  protected:
    trapEffect effect;
    int trapParameter;
    // Operations
  public:
    void activate ();
    void desactivate ();
    bool isOn ();
    Traps ();
    ~Traps ();
    Traps (int idCard, std::string name, std::string path, CardTypes typeCarte, trapEffect effect, int trapParameter);
    Traps (std::string name, std::string path, CardTypes typeCarte, trapEffect effect, int trapParameter);
  };

  /// class Observable - 
  class Observable : public GameStates {
    // Attributes
  protected:
    std::vector<IObserver*> observers;
    // Operations
  public:
    void registerObserver (IObserver* observer);
    void notifyObservers (const StateEvent& event, GameStates& state);
  };

  // interface
  /// class IObserver - 
  class IObserver {
    // Associations
    state::Observable* unnamed;
    // Operations
  public:
    virtual void stateChanged (const StateEvent& event, GameStates& state) = 0;
  };

  enum StateEventID {
    ALLCHANGED,
    TURNCHANGED,
    CARDCHANGED,
    TEXTCHANGED,
    ALERT,
    WINNER
  };

  /// class StateEvent - 
  class StateEvent {
    // Associations
    state::StateEventID* unnamed;
    // Attributes
  public:
    StateEventID stateEventID;
    std::string text;
    std::string infoText;
    std::string statsText;
    bool isInBase;
    // Operations
  public:
    StateEvent (StateEventID Sevent);
    void setStateEventID (StateEventID newID);
  };

};

