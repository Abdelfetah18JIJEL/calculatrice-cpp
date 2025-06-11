// Project Calculatrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<string>
using namespace std;

// Fonctions des opérations
float additionner(float a, float b) {
    return a + b;
}

float soustraire(float a, float b) {
    return a - b;
}

float multiplier(float a, float b) {
    return a * b;
}

float diviser(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Erreur : Division par zéro non autorisée.\n";
        return 0;
    }
}
static string NumberToText(int Number)
{

    if (Number == 0)
    {
        return "";
    }

    if (Number >= 1 && Number <= 19)
    {
        string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
    "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
      "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

        return  arr[Number] + " ";

    }

    if (Number >= 20 && Number <= 99)
    {
        string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return  arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
    {
        return  "One Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999)
    {
        return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 1999)
    {
        return  "One Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999)
    {
        return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 1999999)
    {
        return  "One Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 2000000 && Number <= 999999999)
    {
        return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return  "One Billion " + NumberToText(Number % 1000000000);
    }
    else
    {
        return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }


}

float lireNombre(string message) {
    float n;
    while (true) {
        cout << message;
        cin >> n;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "Entrée invalide. Veuillez entrer un nombre.\n";
        }
        else {
            return n;
        }
    }
}




int main() {
    int choix;
    float nombre1, nombre2, resultat;

    do {
        // Affichage du menu
        cout << "\n===== Menu de la Calculatrice =====\n";
        cout << "1. Addition (+)\n";
        cout << "2. Soustraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Quitter\n";
        cout << "Choisissez une option (1-5) : ";
        cin >> choix;

        if (choix >= 1 && choix <= 4) {
            nombre1 = lireNombre("Entrez le premier nombre : ");
            if (choix == 4) {
                do {
                    nombre2 = lireNombre("Entrez le deuxième nombre (≠ 0) : ");
                    if (nombre2 == 0) {
                        cout << "Erreur : Le dénominateur ne peut pas être zéro. Réessayez.\n";
                    }
                } while (nombre2 == 0);
            }
            else {
                nombre2 = lireNombre("Entrez le deuxième nombre : ");
            }
        
        }

        switch (choix) {
        case 1:
            resultat = additionner(nombre1, nombre2);
            cout << "Resultat : " << resultat << endl;
            cout << "Score in letters: " <<NumberToText( resultat ) << endl;
            break;
        case 2:
            resultat = soustraire(nombre1, nombre2);
            cout << "Résultat : " << resultat << endl;
            cout << "Score in letters: " << NumberToText(resultat) << endl;
            break;
        case 3:
            resultat = multiplier(nombre1, nombre2);
            cout << "Résultat : " << resultat << endl;
            cout << "Score in letters: " << NumberToText(resultat) << endl;
            break;
        case 4:
            resultat = diviser(nombre1, nombre2);
            cout << "Résultat : " << resultat << endl;
            cout << "Score in letters: " << NumberToText(resultat) << endl;
            break;
        case 5:
            cout << "Merci d'avoir utilisé la calculatrice.\n";
            break;
        default:
            cout << "Choix invalide. Veuillez réessayer.\n";
        }

    } while (choix != 5);

    return 0;
}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
