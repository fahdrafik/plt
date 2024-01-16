
namespace state {

  enum Phases {
    DrawPhase,
    FirstMainPhase,
    BattlePhase,
    SecondMainPhase,
    EndPhase
  };

  enum GameStatus {
    PLAYING,
    WON,
    LOOSE
  };

  /// class Observable - 
  class Observable {
    // Attributes
  protected:
    std::vector<Observer*> observers;
    // Operations
  public:
    void addObserver (Observer* observer);
    void notifyObservers (StateEvent& event, GameStates& state);
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
    virtual ~Cards ();
    bool isMonster ();
    bool isSpell ();
    bool isTrap ();
  };

  /// class Decks - 
  class Decks {
    // Attributes
  public:
    std::vector<Monsters> cardsM;
    std::vector<Spells> cardsS;
    std::vector<Traps> cardsT;
  protected:
    int id;
    std::vector<Cards> cardsInDeck;
    std::vector<Cards> cardsInHand;
    int numberOfCards;
    // Operations
  public:
    Decks (std::vector<Cards> cardsInDeck);
    Decks (DeckChoice DeckChoice);
    Decks (int id);
    Decks ();
    ~Decks ();
    void shuffle ();
    void drawCard ();
    void addCardToHand (Cards card);
    void addCard (Cards card);
    void removeCard (int index);
    void removeCardInHand (int index);
    Cards getCardInHand (int index);
    Cards getCardInDeck (int index);
    CardTypes getCardInHandType (int index);
    std::string getCardInHandName (int index);
    void initCardsInHands ();
    void display ();
    std::vector<Cards> getCardsInHand ();
    int getCardsInHandSize ();
    std::string getCardsInHandPath (int index);
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

  /// class Monsters - 
  class Monsters {
    // Attributes
  protected:
    int level;
    int attack;
    int defense;
    bool position;
    int effet ;
    // Operations
  public:
    Monsters (int idCard, std::string name, std::string path, CardTypes typeCarte, int effet, int level, int attack, int defense, bool position);
    Monsters (std::string name, std::string path, CardTypes typeCarte, int  effet, int level, int attack, int defense, bool position);
    ~Monsters ();
    Monsters ();
    void setSpell (int effect);
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
    void getAndRemoveMonsterFromGraveyard (int index);
    void addGraveyard (Cards card);
    int getMonsterAttack (int index);
    void setMonsterAttack (int attack);
    int getMonsterDefense (int index);
    void setMonsterDefense (int attack);
    Monsters getMonster (int index);
    bool getMonsterPosition (int index);
    int getMonsterSize ();
    void display ();
    std::string getCardsInBoardPath (int index);
    std::string getCardsInDeck (int index);
  };

  enum TypePlayer {
    HUMAN,
    BOT
  };

  /// class Players - 
  class Players {
    // Attributes
  public:
    Decks* deck;
    Boards* board;
  private:
    static int nbPlayers;
  protected:
    int id;
    TypePlayer type;
    GameStatus status;
    int lifepoints;
    // Operations
  public:
    Players (Boards* board, Decks* deck, int lifepoints, TypePlayer type);
    Players ();
    ~Players ();
    void drawCard ();
    void placeCard (int index);
    void looseLifePoints (int degat );
    void attackCard (Players* defendingPlayer, int attackingCardIndex, int defendingCardIndex);
    void attackPlayer (int attackingCardIndex, Players* defendingPlayer);
    void display ();
    void initCardInHands ();
    void shuffle ();
    std::vector<state::Cards> getCardsInHand ();
    std::string getCardsInBoardPath (int index);
    std::string getCardsInHandPath (int index);
    int getCardsInHandSize ();
  };

  /// class GameStates - 
  class GameStates : public Observable {
    // Associations
    state::Decks* unnamed;
    state::Decks* unnamed;
    state::Calculation* unnamed;
    state::Boards* unnamed;
    state::Players* unnamed;
    // Attributes
  private:
    int nbPlayers;
    int nbBots;
    Decks* deckChosen;
    int nbTurns;
  protected:
    bool turn;
    std::vector<Cards*> cardList;
    std::vector<Players> playerList;
    std::vector<Boards*> boardList;
    Players* currentPlayer;
    Phases currentPhase;
    bool end;
    char summoning;
    // Operations
  public:
    GameStates ();
    ~GameStates ();
    void init (Players& first, Players& second);
    void incrementTurn ();
    void changeTurn ();
    void displayScore ();
    void addPlayer ();
    void addBot ();
    void deletePlayer ();
    void createPlayer (Players& obj);
    void deleteBot ();
    void chooseDeck (Decks& obj);
    void changePhase ();
    void playPhase ();
    GameStatus getCurrentPlayerStatus ();
    int getCurrentPlayerID ();
    std::string getPhaseName (Phases phase);
    void battlePhase ();
    void mainPhase ();
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
    Control,
    Sacrifice
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
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

  enum trapEffect {
    NormalTrap,
    ContinuousTrap,
    Counter,
    DeleteCard,
    DeleteCardWithTreshold,
    DeleteCardLoosingLP,
    ReturnAttackToSender,
    RevivalBeforeAttack
  };

  /// class Traps - 
  class Traps : public Cards {
    // Attributes
  protected:
    trapEffect effect;
    int trapParameter;
    bool Set ;
    // Operations
  public:
    bool isOn ();
    Traps ();
    ~Traps ();
    Traps (int idCard, std::string name, std::string path, CardTypes typeCarte, trapEffect effect, int trapParameter);
    Traps (std::string name, std::string path, CardTypes typeCarte, int trapParameter, bool set);
    void activate (Boards* attackingBoard, Boards* defendingBoard);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard);
  };

  // interface
  /// class Observer - 
  class Observer {
    // Operations
  public:
    virtual void stateUpdate (const StateEvent& event, GameStates& state) = 0;
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

  /// class SpellEquipement - 
  class SpellEquipement : public Spells {
    // Operations
  public:
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

  /// class SpellRevival - 
  class SpellRevival : public Spells {
    // Operations
  public:
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

  /// class SpellControl - 
  class SpellControl : public Spells {
    // Operations
  public:
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

  /// class SpellSacrifice - 
  class SpellSacrifice : public Spells {
    // Operations
  public:
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

  /// class TrapNormal - 
  class TrapNormal : public Traps {
    // Operations
  public:
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

  /// class TrapCounter - 
  class TrapCounter : public Traps {
    // Operations
  public:
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

  /// class TrapReverse - 
  class TrapReverse : public Traps {
    // Operations
  public:
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

  /// class TrapDelete - 
  class TrapDelete : public Traps {
    // Operations
  public:
    void activate (Boards* attackingBoard, Boards* defendingBoard, int index);
    void desactivate (Boards* attackingBoard, Boards* defendingBoard, int index);
  };

};

