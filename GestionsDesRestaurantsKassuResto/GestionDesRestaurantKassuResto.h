/*************************************************************************************************************************************************/
#ifndef GESTIONDESRESTAURANTKASSURESTO_H_INCLUDED
#define GESTIONDESRESTAURANTKASSURESTO_H_INCLUDED
/*************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define     OUI         1
#define     NON         0
/*************************************************************************************************************************************************/
#define    taille       25
/*************************************************************************************************************************************************/

typedef struct commandes
{
    int codeCommande;
    char article[taille];
    char libele[taille];
    double prix;
}Commande;
int static ordreCommande = 0;
/*************************************************************************************************************************************************/
//typedef enum
//{
//
//}Entre;
//typedef enum
//{
//
//}Resistance;
//typedef enum
//{
//
//}Desert;
typedef enum
{
    false,
    true
}Bool;
typedef struct node
{
    Commande commande;
    struct node *suivant;
}Node;
/*************************************************************************************************************************************************/
typedef struct files
{
    Node *in;
    Node *out;
    int compteurCommande;
}FileCommande;
typedef struct client
{
    int idClient;
    char nom[taille];
    char prenom[taille];
    FileCommande file;
}Client;
typedef struct nodeClient
{
    Client client;
    struct nodeClient *next;
}NodeClient;
typedef struct filesClient
{
    NodeClient *in;
    NodeClient *out;
    int compteurClient;
}FileClient;
/*************************************************************************************************************************************************/
//Les Fonctionnalités du systeme du restaurant kassu resto
FileClient initialiserFileClient(void);
FileCommande initialiserFileCommande(void);
Bool isEmptyFileClient(FileClient file);
void afficherCLient(NodeClient node);
void afficherFileClient(FileClient file);
NodeClient saisirClientt(void);
Node saisirCommande(void);
void afficherCommandeNombre(int numeroCommade);
FileCommande genereCommande(void);
FileClient genereClient(void);
void enFilecommande(FileCommande* addFileCommande,Node node);
void enFileClient(FileClient *addFileclient,NodeClient node);
void deFileClient(FileClient *addFileClient);
Bool isEmptyFileCommand(FileCommande file);
void afficherCommande(Node node);
void afficherFileCommande(FileCommande file);
void deletecommande(FileCommande *addFilecommande);
void viderFileClient(FileClient *addFileClient);
void deleteClient(FileClient *addFileClient);
void viderFileCommande(FileCommande *addFileCommande);
void menu(void);
int menuPrincipale(void);
/*************************************************************************************************************************************************/
#endif // GESTIONDESRESTAURANTKASSURESTO_H_INCLUDED
/*************************************************************************************************************************************************/
