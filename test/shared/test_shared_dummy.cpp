
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Cards.h"
#include "../../src/shared/state/CardTypes.h"
#include "../../src/shared/state/Calculation.h"
#include "../../src/shared/state/Spells.h"
#include "../../src/shared/state/Traps.h"
#include "../../src/shared/state/Monsters.h"


using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestCarte)
{
    CardTypes CarteMonstre ("Monstres");
    Cards DragonBlancAuxYeuxBleus (0,"Dragon Blanc Aux Yeux Bleus","Monstre de type dragon",CarteMonstre);
    BOOST_CHECK_EQUAL(DragonBlancAuxYeuxBleus.getIdCard(), 0);
    DragonBlancAuxYeuxBleus.setIdCard(1);
    BOOST_CHECK_EQUAL(DragonBlancAuxYeuxBleus.getIdCard(), 1);
}

BOOST_AUTO_TEST_CASE(TestCalculation)
{
    Calculation Calcul(2000,1000,4000,5000,2000,4000);
    BOOST_CHECK_EQUAL(Calcul.getLifePointsPlayer1(),2000);
    Calcul.setAttackPointsPlayer1(1500);
    BOOST_CHECK_EQUAL(Calcul.getAttackPointsPlayer1(),1500);
}

BOOST_AUTO_TEST_CASE(testSpells) {
    Spells Sort;
    Sort.setEffect(Ritual);
    BOOST_CHECK_EQUAL(Sort.getEffect(),Ritual);
}
BOOST_AUTO_TEST_CASE(testTraps) {
    Traps trap;
    trap.setEffect(NormalTrap);
    BOOST_CHECK_EQUAL(trap.getEffect(),NormalTrap);

}

BOOST_AUTO_TEST_CASE(TestMonsters)
{
    std::string animal="Animal";
    std::string description="Electric";
    std::string name="Pikachu";
    CardTypes Type(animal);
    //Monsters elmoro(1,2,13,3,true);//int idCard, std::string name, std::string description, CardTypes typeCarte, int level, int attack, int defense, bool position,int effet
    //Monsters elmoro(315, name, description,Type, 5, 777, 589,true, 6);
    Monsters elmoro(315, name, description,Type, 5, 777, 589,true, 6);
    //elmoro.setLevel(7);elmoro.setAttack(444);elmoro.setDefense(777);elmoro.setPosition(true);elmoro.setEffet(6);

    BOOST_CHECK_EQUAL(elmoro.getIdCard(),315);
    BOOST_CHECK_EQUAL(elmoro.getName(),name);
    BOOST_CHECK_EQUAL(elmoro.getDescription(),description);
    BOOST_CHECK_EQUAL(elmoro.getEffet(), 6);
    BOOST_CHECK_EQUAL(elmoro.getLevel(), 7);
    BOOST_CHECK_EQUAL(elmoro.getAttack(), 777);
    BOOST_CHECK_EQUAL(elmoro.getDefense(), 589);
    BOOST_CHECK_EQUAL(elmoro.getPosition(), true);
}
BOOST_AUTO_TEST_CASE(TestBoards)
{
//Boards testBoard ()
}
BOOST_AUTO_TEST_CASE(TestSpells)
{

}
BOOST_AUTO_TEST_CASE(TestTraps)
{

}
/* vim: set sw=2 sts=2 et : */
