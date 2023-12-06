
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
    CardTypes CarteMonstre (TypeMonster);
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
    CardTypes CarteMonstre (TypeMonster);
    Monsters elmoro(0,"elmoro","monstre",CarteMonstre,1,2,13,3,true);
    BOOST_CHECK_EQUAL(elmoro.getEffet(), 1);
    BOOST_CHECK_EQUAL(elmoro.getLevel(), 2);
    BOOST_CHECK_EQUAL(elmoro.getAttack(), 13);
    BOOST_CHECK_EQUAL(elmoro.getDefense(), 3);
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
