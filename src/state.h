
namespace state {

  /// class States - 
  class States {
    // Attributes
  protected:
    int turn;
    std::vector<Cards> cardList;
    std::vector<Players> playerList;
    // Operations
  public:
    States ();
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
  private:
    int id;
    std::vector<Cards> cardsInDeck;
    std::vector<Cards> cardsInHand;
    int numberOfCards;
    // Operations
  public:
    Decks (int id, std::vector<Cards> cardsInDeck, std::vector<Cards> cardsInHands, int numberOfCards);
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

  /// class Players - 
  class Players {
    // Attributes
  private:
    int id;
    TypePlayer type;
    GameStatus status;
    std::vector<Decks> deck;
    std::vector<Boards> board;
    int lifepoints;
    // Operations
  public:
    Players ();
    void drawCard ();
    void placeCard ();
    void setSpell ();
    void endTurn ();
    void looseLifePoints (int degat );
  };

  /// class CardTypes - 
  class CardTypes {
    // Attributes
  private:
    std::string type;
    // Operations
  public:
    void isMonster ();
    void isSpell ();
    void isTrap ();
    CardTypes (std::string type);
  };

  /// class Cards - 
  class Cards {
    // Attributes
  protected:
    int idCard;
    std::string name;
    std::string description;
    CardTypes typeCarte;
    int nombreDeCartes;
    // Operations
  public:
    Cards (int  idCard, std::string name, std::string description, CardTypes typeCarte, int nombreDeCartes);
  };

  /// class Calculation - 
  class Calculation {
    // Attributes
  private:
    int  lifePointsPlayer1;
    int lifePointsPlayer2;
    int attackPointsPlayer1;
    int attackPointsPlayer2;
    int defensePointsPlayer1;
    int defensePointsPlayer2;
    // Operations
  public:
    int getDefensePointsPlayer1 ();
    int getDefensePointsPlayer2 ();
    int getAttackPointsPlayer1 ();
    int getAttackPointsPlayer2 ();
    int getLifePointsPlayer1 ();
    int getLifePointsPlayer2 ();
    Calculation (int lifePointsPlayer1, int lifePointsPlayer2, int attackPointsPlayer1, int attackPointsPlayer2, int defensePointsPlayer1, int defensePointsPlayer2);
  };

  /// class Boards - 
  class Boards {
    // Attributes
  private:
    int id;
    std::vector<Monsters> monsters;
    std::vector<Spells> spells;
    std::vector<Traps> traps;
    std::vector<Cards> graveyard;
    // Operations
  public:
    Boards (int  id, std::vector<Spells> spells, std::vector<Traps> traps, std::vector<Monsters> monsters, std::vector<Cards> graveyard);
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
  private:
    spellEffect effect;
    // Operations
  public:
    bool isOn ();
    Spells ();
  };

  /// class Monsters - 
  class Monsters {
    // Attributes
  private:
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
  };

  enum trapEffect {
    NormalTrap,
    ContinuousTrap,
    Counter
  };

  /// class Traps - 
  class Traps {
    // Attributes
  private:
    trapEffect effect;
    // Operations
  public:
    void activate ();
    bool isOn ();
    Traps ();
  };

};

