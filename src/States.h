/// class States - playing

class States {
  // Attributes
private:
  Playing playing;
protected:
  int turn;
  std::vector<std::shared_ptr<Cards>> cardList;
  std::vector<std::shared_ptr<Players> playerList;
  // Operations
public:
  void State ();
  void init ();
  void incrementTurn ();
  void displayScore ();
  void addPlayer ();
  void addBot ();
  void deletePlayer ();
  void createPlayer ();
  void deleteBot ();
};

