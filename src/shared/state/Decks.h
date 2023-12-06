// Generated by dia2code
#ifndef STATE__DECKS__H
#define STATE__DECKS__H

#include <vector>

namespace state {
  class Cards;
}

#include "Cards.h"

namespace state {

  /// class Decks - 
  class Decks {
    // Attributes
  protected:
    int id;
    std::vector<Cards> cardsInDeck;
    std::vector<Cards> cardsInHand;
    int numberOfCards     = 40;
    // Operations
  public:
    Decks (std::vector<Cards> cardsInDeck, std::vector<Cards> cardsInHands);
    Decks ();
    ~Decks ();
    void shuffle ();
    void drawCard ();
    void addCard (Cards card);
    void removeCard (int index);
    // Setters and Getters
    int getId() const;
    void setId(int id);
    const std::vector<Cards>& getCardsInDeck() const;
    void setCardsInDeck(const std::vector<Cards>& cardsInDeck);
    const std::vector<Cards>& getCardsInHand() const;
    void setCardsInHand(const std::vector<Cards>& cardsInHand);
    int getNumberOfCards() const;
    void setNumberOfCards(int numberOfCards);
  };

};

#endif
