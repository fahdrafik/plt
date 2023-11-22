#include <iostream>
#include <vector>
#include <cstring>
#include <string>

//#include <boost/test/included/unit_test.hpp>

#define BOOST_TEST_DYN_LINK

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.h>
#include <render.h>

using namespace std;
using namespace state;
using namespace render;

int main(int argc,char* argv[])
{

    if (argc == 1)
    {
        cout << "Hello World from Cergy !" << endl;
    }
    else if (strcmp(argv[1], "hello") == 0)
    {
        cout << "Ca fonctionne ENFIN !!!!" << endl;
    }
    else if (strcmp(argv[1], "state") == 0)
    {
        cout << "Tests" << endl;
    }
    return 0;
}
