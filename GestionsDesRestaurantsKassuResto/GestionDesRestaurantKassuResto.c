/*************************************************************************************************************************************************/
#include "GestionDesRestaurantKassuResto.h"
#include <string.h>
/*************************************************************************************************************************************************/
FileClient initialiserFileClient(void)
{
    FileClient client;

    client.in = NULL;
    client.compteurClient = 0;
    client.out = NULL;

    return client;
}
/*************************************************************************************************************************************************/
FileCommande initialiserFileCommande(void)
{
    FileCommande file;

    file.in = NULL;
    file.compteurCommande = 0;
    file.out = NULL;

    return file;
}
/*************************************************************************************************************************************************/
Bool isEmptyFileClient(FileClient file)
{
    return (file.compteurClient == 0)?true:false;
}
/*************************************************************************************************************************************************/
void afficherCLient(NodeClient node)
{
    printf("Le client :\n\t identifiant Client :[%d]\n\t Nom:[%s]\n\t Prenom :[%s]",node.client.idClient,node.client.nom,node.client.prenom);
    afficherFileCommande(node.client.file);
}
/*************************************************************************************************************************************************/
void afficherFileClient(FileClient file)
{
    while(!isEmptyFileClient(file))
    {
        afficherCLient(*file.out);
        file.out = file.out->next;
    }
}
/*************************************************************************************************************************************************/
NodeClient saisirClientt(void)
{
    NodeClient node;
    fflush(stdin);
    printf("Entre le code client svp : ");
    scanf("%d",&node.client.idClient);
    fflush(stdin);
    printf("Entre le Nom du Client svp : ");
    gets(node.client.nom);
    fflush(stdin);
    printf("Entre le prenom du client svp : ");
    gets(node.client.prenom);
    fflush(stdin);
    return node;
}
/*************************************************************************************************************************************************/
Node saisirCommande(void)
{
    Node node;
    ordreCommande ++;
    fflush(stdin);
    printf("Entre le code du commande svp \n");
    scanf("%d",&node.commande.codeCommande);
    fflush(stdin);
    printf("Entre l'artivle de la commande svp \n");
    printf("> ");
    gets(node.commande.article);
    fflush(stdin);
    printf("Entre libelle de la commande svp \n");
    printf("> ");
    gets(node.commande.libele);
    fflush(stdin);
    printf("Entre le prix de la commande svp \n");
    printf("> ");
    scanf("%lf",&node.commande.prix);
    fflush(stdin);
    return node;
}
/*************************************************************************************************************************************************/
void enFilecommande(FileCommande* addFileCommande,Node node)
{}
/*************************************************************************************************************************************************/
void enFileClient(FileClient *addFileclient,NodeClient node)
{
    NodeClient *ptr;
    ptr = (NodeClient *) malloc(sizeof(NodeClient));

    if(ptr == NULL)
    {
        fprintf(stderr,"Probleme d'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }
    *ptr = node;
    ptr ->next = NULL;
    addFileclient ->compteurClient ++;
    if(addFileclient ->compteurClient == 1)
    {
        addFileclient ->in = ptr;
        addFileclient ->out = ptr;
    }else{
        addFileclient ->in ->next = ptr;
        addFileclient ->in = ptr;
    }
}
/*************************************************************************************************************************************************/
void deFileClient(FileClient *addFileClient)
{}
/*************************************************************************************************************************************************/
Bool isEmptyFileCommand(FileCommande file)
{
    return (file.compteurCommande == 0)?true:false;
}
/*************************************************************************************************************************************************/
void afficherCommande(Node node)
{
    printf("La commande est :\n\t Identifiant du commande: [%d]\n\t Article :[%s]\n\t Libelle :[%s] \n\t Prix :[%lf]\n",node.commande.codeCommande,node.commande.article,node.commande.libele,node.commande.prix);
}
/*************************************************************************************************************************************************/
void afficherFileCommande(FileCommande file)
{
    while(!isEmptyFileCommand(file))
    {
        afficherCommande(*file.out);
        file.out = file.out ->suivant;
    }
}
/*************************************************************************************************************************************************/
void deletecommande(FileCommande *addFilecommande)
{
    Node *ptr;
    if(isEmptyFileCommand(*addFilecommande)) printf("Rien a supprimer,car la file des commandes est vider....\n");
    else{
        ptr = addFilecommande ->out;
        addFilecommande ->out = ptr ->suivant;
        free(ptr);
        addFilecommande ->compteurCommande --;
        if(isEmptyFileCommand(*addFilecommande))
            addFilecommande->in = NULL;
    }
}
/*************************************************************************************************************************************************/
void deleteClient(FileClient *addFileClient)
{
    NodeClient *ptr;
    if(isEmptyFileClient(*addFileClient)) printf("Rien a supprimer, car la file est deja vider...\n");
    else{
        ptr = addFileClient ->out;
        addFileClient ->out = ptr ->next;
        free(ptr);
        addFileClient ->compteurClient --;
        if(isEmptyFileClient(*addFileClient)) addFileClient->in = NULL;
    }
}
/*************************************************************************************************************************************************/
void viderFileClient(FileClient *addFileClient)
{
    if(isEmptyFileClient(*addFileClient)) printf("Rien a faire car la file est deja vider...\n");
    else
    {
        deleteClient(addFileClient);
        viderFileClient(addFileClient);
    }
}
/*************************************************************************************************************************************************/
void viderFileCommande(FileCommande *addFileCommande)
{
    if(isEmptyFileCommand(*addFileCommande)) printf("Rien a vider car la file est deja vider...\n");
    else
    {
        deletecommande(addFileCommande);
        viderFileCommande(addFileCommande);
    }
}
/*************************************************************************************************************************************************/
FileCommande genereCommande(void)
{
    FileCommande file = initialiserFileCommande();
    int reponse = NON;
    char entre;
    Node node;
    do{
        node = saisirCommande();
        enFilecommande(&file,node);
        printf("Voulez-vous ajouter d'autre commande si OUI tape 1 sinon 0 #\n");
        printf("> ");
        scanf("%d%c",&reponse,&entre);
    }while(reponse == OUI);
    printf("Merci de vouloir faire la commande cher Kassu resto on s'occupe de vous dans 5 mn ::)\n");
    return file;
}
/*************************************************************************************************************************************************/
FileClient genereClient(void)
{
    FileClient file = initialiserFileClient();
    char entre;
    int reponse = NON;
    NodeClient node;
    do{
        node = saisirClientt();
        enFileClient(&file,node);
        printf("Voulez-vous ajouter d'autre client si OUI tape 1 sinon 0 #\n");
        printf("> ");
        scanf("%d%c",&reponse,&entre);
    }while(reponse == OUI);
    printf("Merci de vouloir s'interesse à cher Kassu resto ::)\n");
    return file;
}
/*************************************************************************************************************************************************/
int menuPrincipale(void)
{
    int indice;
    int reponse = NON;
    char entre;
    do{
    printf("\n FAITES VOTRE CHOIX DANS LE MENU\n\n Entre :\n\t 1.Salade-Cambodgienne-Epicee-Boeuf \n\t 2.Asperges-Vertes-Blanches-Espuma "
           "\n\n Resistance :\n\t 3.Gratin de carotte polenta chèvre\n\t 4.Tomato Cream Sauce Fettuccine Pasta Recipe\n\n Desert:\n\t 5.Panna-Cotta-Ivoire-a-la-Feve-Tonka-Coulis-de-Fraise\n\t 6.Biscuit-Moelleux-Chocolat-Framboise");
    printf("\n > ");
//    printf("Voulez-vous continue à faire d'autre commande si OUI tape 1 sinon 0 #\n");
//    printf("\n > ");
//    scanf("%d%c",&reponse,&entre);
    scanf("%d",&indice);
    }while(indice < 1 || indice > 6);
    return indice;
}
/*************************************************************************************************************************************************/
void menu(void)
{
    printf("l'indice est : [%d]\n",menuPrincipale());
    genereCommande();
}
/*************************************************************************************************************************************************/
