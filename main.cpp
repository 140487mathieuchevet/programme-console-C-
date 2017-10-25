#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

string melangerLettres(string mot);
int tailleFichier();

int main()
{
    srand(time(0));

    string ligne, motMystere, motJoueur, motMelange;
    int essai(0), nbPartie(0), pointsTotal(0), moyenneJoueur(0), nbLigne(0), nbAleatoire(0), nbMots(0);
    bool partie(0);
    do
    {
        nbMots = tailleFichier();
        ifstream dico("dico.txt");
        if(dico)

        {


            cout << nbMots << endl;
            nbAleatoire = rand() % nbMots;
            cout << nbAleatoire << endl;

            while (nbAleatoire > 0)
            {
                getline(dico, ligne);
                nbAleatoire--;
            }

            motMystere = ligne;

        }

        else

        {

            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

        }




        essai = 5 ;
        motMelange = melangerLettres(motMystere);
        do
        {
            cout << "quel est ce mot ? " << motMelange << endl << "vous avez " << essai << " essai" << endl ;
            cin >> motJoueur ;
            essai--;
            if (motMystere != motJoueur)
            {
                cout << "ce n'est pas le mot "<< endl << endl;
                if ( essai == 0)
                {
                    cout << "vous avez perdu il ne vous reste plus d'essai le mot etait " << motMystere << endl;
                }

            }


            else
            {
                cout << "bravo ! vous avez trouve le mot " << motMystere << endl;
            }

        }
        while (motMystere != motJoueur && essai > 0);
        nbPartie++;
        pointsTotal += essai;
        cout << "voulez vous rejouer? ((0) arreter / (1) continuer " << endl;
        cin >> partie;
    }
    while (partie);
    moyenneJoueur = pointsTotal / nbPartie ;
    cout << "votre score est de " << pointsTotal << " points pour " << nbPartie << " parties jouees " << endl << " moyenne  " << moyenneJoueur << endl;
    return 0;
}

string melangerLettres(string mot)
{
    string melange;
    int position(0);
    while (mot.size() != 0)
    {
        position = rand() % mot.size();
        melange += mot[position];
        mot.erase(position,1);
    }
    return melange;

}

int tailleFichier()
{

    int nbMots(0);
    string ligne;

    ifstream dico("dico.txt");
    if(dico)

    {





        while (getline(dico,ligne))
        {
            getline(dico, ligne);
            nbMots++;
        }
    }
    else

    {

        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

    }
    return nbMots;
}
