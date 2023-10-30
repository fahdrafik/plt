#include <iostream>
#include <vector>
#include <cstring>
#include <string>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.h>

using namespace std;
using namespace state;

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
