#include "CardTypes.h"
#include <iostream>
using namespace std;

CardTypes::CardTypes(string type){
    this->type=type;
}
void CardTypes::isMonster (){
    cout<<"isMonster\n";
}
void CardTypes::isSpell (){
    cout<<"isSpell\n";
}
void CardTypes::isTrap (){
    cout<<"isTrap\n";
}