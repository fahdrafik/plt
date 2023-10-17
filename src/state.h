
namespace state {

  /// class Decks - 
  class Decks {
    // Attributes
  private:
    int id;
    Cards[] cardsInDeck;
    Cards[] cardsInHand;
    int numberOfCards;
    // Operations
  public:
    void shuffle ();
    void drawCard ();
    void addCard ();
    void removeCard ();
  };

  enum GameStatus {
    PLAYING,
    WON,
    LOOSE
  };

  /// class Boards - 
  class Boards {
    // Attributes
  private:
    int id;
    Monsters[] monsters;
    Spells[] spells;
    Traps[] traps;
    Cards[] graveyard;
    // Operations
  public:
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
    int id;
    GameStatus status;
    Decks deck;
    Boards board;
    int lifepoints;
    // Operations
  public:
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
    string type;
    // Operations
  public:
    void isMonster ();
    void isSpell ();
    void isTrap ();
  };

  /// class Cards - 
  class Cards {
    // Attributes
  protected:
    int idCard;
    string name;
    string description;
    CardTypes type;
    etat  state ;
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
  };

  enum TypePlayer {
    HUMAN,
    BOT
  };

  /// class Spells - 
  class Spells {
    // Attributes
  private:
    string effect;
    // Operations
  public:
    bool isOn ();
  };

  /// class Monsters - 
  class Monsters {
    // Attributes
  public:
    int effet ;
  private:
    int level;
    int attack;
    int defense;
    bool position;
    // Operations
  public:
    void attack (carte c);
    void setSpell ();
  };

  enum trapEffect {
    Normal,
    Continuous ,
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
  };

  enum spellEffect {
    Ritual,
    Normal,
    Continuous,
    Field ,
    Equipped,
    Quickplay
  };

};

