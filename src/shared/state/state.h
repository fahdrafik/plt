//
// Created by ZAIK on 24/10/2023.
//

#ifndef PLT_STATE_H
#define PLT_STATE_H
#endif //PLT_STATE_H

#include <string>
#include <vector>

using namespace std;

namespace state {

    enum trapEffect {
        NormalTrap,
        ContinuousTrap ,
        Counter
    };

    enum spellEffect {
        Ritual,
        NormalSpell,
        ContinuousSpell,
        Field ,
        Equipped,
        Quickplay
    };

    /// class CardTypes -
    class CardTypes {
        // Attributes
    private:
        string type;
        // Operations
    public:
        CardTypes(string type);
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
        static int nbDeCartes;
    private:
        Cards(string name,string description, CardTypes type);
    };

    /// class Spells -
    class Spells : public Cards{
        // Attributes
    private:
        string effect;
        // Operations
    public:

        bool isOn ();
    };

    /// class Traps -
    class Traps : public Cards{
        // Attributes
    private:
        trapEffect effect;
        // Operations
    public:
        void activate ();
        bool isOn ();
    };

    /// class Monsters -
    class Monsters : public Cards {
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
        void attackCard (Cards c);
        void setSpell ();
    };

    /// class Decks -
    class Decks {
        // Attributes
    private:
        int id;
        int numberOfCards;
        vector<Cards> cardsInDeck;
        vector<Cards> cardsInHand;
        // Operations
    public:
        ~Decks();
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
        vector<Monsters>  monsters;
        vector<Spells>  spells;
        vector<Traps>  traps;
        vector<Cards>  graveyard;
        // Operations
    public:
        Boards(int id, Monsters monsters, Spells spells, Traps traps, Cards graveyard);
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
};

