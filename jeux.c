#include "jeux.h"
void imprime_instruction()                                                                       // Affichage des instructions de jeux
{
    char c;
    printf("\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",                                                 // Les instructions de jeux
           " PAPIER , ROCHE , CISEAUX : \n",
           " p pour \" papier , \" r pour \" roche ,\" et c pour \"CISEAUX""\n",
           " Les deux (joueur et machine) vont choisir \n",
           " l'un des trois p,r,c .\n Si les deux choix sont les meme,\n",
           " le jeux est EGALITE .\n Sinon :\n",
           "  \" papier couvre le roche \" (gain pour papier),\n",
           "  \" roche brise ciseaux \" (gain pour roche),\n",
           "  \" ciseaux  coupe papier \" (gain pour ciseaux).\n\n",
           "  Il ya d'autres possibilits : \n",
           "   g    pour etat du jeux ( nombre des gains ) , \n",
           "   h    help ( aide) ,\n",
           "   i    pour instructions (reeimprimer ceci ),\n",
           "   m    pour retourner au menu principale \n"
           "   q    pour quitter le jeux .\n\n",
           " ce jeux est repete jusqu'a entrer q .\n",
           " AU  REVOIR  ! \n");
    do                                                                                            // Controle de saisie
    {
        printf ("veiller choisir h ou i ou q ou m \n");
        scanf (" %c",&c);
    }
    while((c!='h')&&(c!='i')&&(c!='q')&&(c!='m'));
    switch (c)                                                                                    // Choix de joueur
    {
    case 'q':
        exit(0);                                                                                  // Quitter le jeux si le joueur choisie 'q'
        break;
    case 'h':
        aide_joueur();                                                                            // Afficher l'aide joueur si le joueur choisie 'h'
        break;
    case 'i':
        imprime_instruction();                                                                    // Afficher les instructions si le joueur choisie 'i'
        break;
    case 'm':
        menu_principale();                                                                        // Retour au menu principale si le joueur choisie 'm'
        break;
    }
}
void aide_joueur()                                                                                // Affichage des caracteres qui peuvent etre tapés au clavier
{
    char x;
    printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",                                                // Les caracteres qui peuvent etre tapés au clavier
           " les caracteres suivants peuvent etre tapes au clavier :",
           "       p   papier",
           "       r   roche ",
           "       c   ciseaux",
           "       g   etat du jeux",
           "       h   reimprime ceci",
           "       i   reimprime les instructions",
           "       m   pour retourner au menu principale \n"
           "       q   pour quitter le jeux ");
    do                                                                                            // Controle de saisie
    {
        printf ("veiller choisir h ou i ou q ou m \n");
        scanf (" %c",&x);
    }
    while ((x!='h')&&(x!='i')&&(x!='q')&&(x!='m'));
    switch (x)                                                                                    // Choix de joueur
    {
    case 'q':
        exit(0);                                                                                  // Quitter le jeux si le joueur choisie 'q'
        break;
    case 'h':
        aide_joueur();                                                                            // Afficher l'aide joueur si le joueur choisie 'h'
        break;
    case 'i':
        imprime_instruction();                                                                    // Afficher les instructions de jeux si le joueur choisie 'i'
        break;
    case 'm':
        menu_principale();                                                                        // Retour au menu principale si le joueur choisie 'm'
        break;
    }
}
void menu_principale()                                                                            // Menu principale
{
    int a,b,c,sj=0,sm=0;
    char n;
    do                                                                                            // Controle de saisie
    {
        printf ("%s%s%s%s%s%s",                                                                   // Afficher les choix possibles 
                "********* Veiller choisir un choi parmis les suivants ********** \n",
                "************* [i] Pour afficher les instructions *************** \n",
                "************* [j] Pour commancer le jeux *********************** \n",
                "************* [h] Pour afficher l'aide ************************* \n",
                "************* [q] Pour quitter ********************************* \n",
                "**************************************************************** \n");
        scanf (" %c",&n);
    }
    while((n!='j') && (n!='i') && (n!='q') && (n!='h'));
    if (n=='i')
        imprime_instruction();                                                                    // Afficher les instructions si le joueur choisie 'i'
    else if (n=='j')                                                                              // Lancer le jeux si le joueur choisie 'j'
    {
        do                                                                                        // Repeter le jeux jusqu'a entrer 'q'
        {
            a=choix_joueur();                                                                     // Choix de joueur dans le jeux (enregistrer dans a)
            b=choix_machine();                                                                    // Choix de la machine (enregistrer dans b)
            if (a == 4)
            {
                printf ("**************************************************************** \n");   // Affichage de score quand le joueur entre 'g'
                printf ("            |Votre score: %d | Score machine: %d| \n",sj,sm);            // sj pour le score du joueur et sm pour le score de la machine
                printf ("**************************************************************** \n");
            }
            else if (a == b)                                                                      // Meme choix entre le joueur et la machine
            {
                printf ("%s%s",
                        " meme choix avec la machine \n",                                         // Affichage de la resultat
                        "\n egalite \n");
            }
            else if (a==0 && b==1)                                                                // Le joueur choisie papier (0) et la machine choisie roche (1)
            {
                printf ("\n%s\n%s\n%s",
                        " la machine a choisie roche \n",                                         // Affichage de resultat de la machine
                        " Papier couvre le roche \n",
                        " Felicitation, vous avez gagner \n");                                    // Affichage de la resultat
                sj++;                                                                             // Incrementation de score du joueur
            }
            else if (a==0 && b==2)                                                                // Le joueur choisie papier (0) et la machine choisie ciseaux (2)
            {
                printf ("\n%s\n%s\n%s",
                        " la machine a choisie ciseaux \n",                                       // Afficher le choix de la machine
                        " Ciseaux coupe papier \n",
                        " Vous avez perdus \n");                                                  // Affichage du resultat
                sm++;                                                                             // Incrementation de score de la machine
            }
            else if (a==1 && b==0)                                                                // Le joueur choisie roche (1) et la machine choisie papier (0)
            {
                printf ("\n%s\n%s\n%s",
                        " la machine a choisie papier \n",                                        // Affichage de choix de la machine
                        " Papier couvre le roche \n",
                        " Vous avez perdus \n");                                                  // Affichage du resultat
                sm++;                                                                             // Incrementation du score de la machine
            }
            else if (a==1 && b==2)                                                                // Le joueur choisie roche (1) et la machine choisie ciseaux (2)
            {
                printf ("\n%s\n%s\n%s",
                        " la machine a choisie ciseaux \n",                                       // Afficher le choix de la machine
                        " Roche brise ciseaux \n",
                        " Felicitation, vous avez gagner \n");                                    // Affichage de la resultat
                sj++;                                                                             // Incrementation de score du joueur
            }
            else if (a==2 && b==0)                                                                // Le joueur choisie ciseaux (2) et la machine choisie papier (0)
            {
                printf ("\n%s\n%s\n%s",
                        " la machine a choisie papier \n",                                        // Affichage de choix de la machine
                        " Ciseaux coupe papier \n",
                        " Felicitation, vous avez gagner \n");                                    // Affichage de la resultat
                sj++;                                                                             // Incrementation du score de joueur
            }
            else if (a==2 && b==1)                                                                // Le joueur choisie ciseaux (2) et la machine choisie roche (1)
            {
                printf ("\n%s\n%s\n%s",
                        " la machine a choisie roche \n",                                         // Affichage de choix de la machine
                        " Roche brise ciseaux \n",
                        " Vous avez perdus \n");                                                  // Affichage de la resultat
                sm++;                                                                             // Incrementation de score de la machine
            }
        }
        while (a!=3);                                                                             // Repeter le jeux jusqu'a entrer 'q'
    }
    else if (n=='h')
        aide_joueur();                                                                            // Afficher l'aide joueur si le joueur choisie 'h'
    else if (n=='q')
        exit(0);                                                                                  // Quitter le jeux si le joueur choisie 'q'
}
int choix_joueur()                                                                                // Choix du joueur
{
    int x;
    char n;
    do                                                                                            // Controle de saisie
    {
        printf ("%s%s%s%s%s%s%s \n",                                                              // Affichage des choix possibles pour le joueur
                "_______________________________________________________________\n",
                "Veuiller entrer votre choix: \n",
                "[p] Pour papier \n",
                "[r] Pour roche \n",
                "[c] Pour ciseaux \n",
                "[g] Pour afficher le score \n",
                "[q] Pour quitter le jeux \n"
                "________________________________________________________________\n");
        scanf (" %c",&n);
    }
    while((n!='c') && (n!='p') && (n!='r') && (n!='q') && (n!='g'));
    if (n=='p')
    {
        printf (" \n Vous avez choisi papier \n");                                                // Afficher le choix de joueur 
        x=0;                                                                                      // x=0 si le choix est papier
    }
    else if (n=='r')
    {
        printf (" \n Vous avez choisi roche \n");                                                 // Affichage de choix de joueur 
        x=1;                                                                                      // x= si le choix est roche
    }
    else if (n=='c')
    {
        printf (" \n Vous avez choisi ciseaux \n");                                               // Affichage de choix de joueur
        x=2;                                                                                      // x=2 si le choix est ciseaux
    }
    else if (n=='g')
        x=4;                                                                                      // x=4 si le choix est g pour afficher le score
    else if (n=='q')
    {
        x=3;                                                                                      // x=3 si le joueur choisie de quitter le jeux
        exit(0);
    }
    return x;                                                                                     
}
int choix_machine()                                                                               // Choix de la machine
{
    int x;
    srand(time(NULL));                                                                            // Choix aleatoire 
    x=rand()%3;                                                                                   // Le choix obtenue est compris entre {0,1,2}
    return x;
}
