
namespace state {

  /// class GameStates - 
  class GameStates {
    // Attributes
  protected:
    int turn;
    std::vector<Cards> cardList;
    std::vector<Players> playerList;
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
    Decks (std::vector<Cards> cardsInDeck, std::vector<Cards> cardsInHands);
    Decks ();
    ~Decks ();
    void shuffle ();
    void drawCard ();
    void addCard ();
    void removeCard ();
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
    void attackPosition ();
    void defensePosition ();
    void addMonster ();
    void removeMonster ();
    void addSpell ();
    void removeSpell ();
    void addTrap ();
    void removeTrap ();
    void appel ();
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

  /// class CardTypes - 
  class CardTypes {
    // Attributes
  protected:
    std::string type;
    // Operations
  public:
    void isMonster ();
    void isSpell ();
    void isTrap ();
    CardTypes (std::string type);
    ~CardTypes ();
  };

  /// class Cards - 
  class Cards {
    // Attributes
  public:
    int nombreDeCartes;
  protected:
    int idCard;
    std::string name;
    std::string description;
    CardTypes typeCarte;
    // Operations
  public:
    Cards (int idCard, std::string name, std::string description, CardTypes typeCarte);
    Cards ();
    ~Cards ();
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
    Quickplay
  };

  /// class Spells - 
  class Spells {
    // Attributes
  protected:
    spellEffect effect;
    bool On;
    // Operations
  public:
    Spells ();
    ~Spells ();
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
    void attackCard (Cards card);
    void attackPlayer (Players player);
    void setSpell ();
    Monsters (int effet, int level, int attack, int defense, bool position);
    ~Monsters ();
  };

  enum trapEffect {
    NormalTrap,
    ContinuousTrap,
    Counter
  };

  /// class Traps - 
  class Traps {
    // Attributes
  protected:
    trapEffect effect;
    // Operations
  public:
    void activate ();
    bool isOn ();
    Traps ();
    ~Traps ();
  };

};

