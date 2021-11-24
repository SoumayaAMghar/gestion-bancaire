#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//structure
typedef struct compte
{
    char cin[12];
    char nom[100];
    char prenom[100];
    float montant;
}client;

client comptebancaire[50];

//declaration des entiers globales.
int n=0;
int i,j,num;
client tmp;
float chiffre;


void premierchoix();
void deuxiemechoix();
void troisiemechoix();
void quatriemechoix();
void cinquiemechoix();
void sixiemechoix();

void affichagecompte()
{
	printf("\nLa liste de vos comptes\n");
        printf("\n----------------------------------------------------------------------\n");
        
        for(i=0 ; i<n ; i++)
        {
            printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[i].cin, comptebancaire[i].nom, comptebancaire[i].prenom,comptebancaire[i].montant);
        }
        printf("------------------------------------------------------------------------\n");
}
//---------------------------------------------
int main()
{

int opnum;

menuprincipale:
printf("\n1-Introduire un compte bancaire (CIN, Nom et Prenom, Montant)\n");
printf("2-Introduire plusieurs comptes bancaires (CIN, Nom et Prenom, Montant)\n");
printf("3-Operations\n\t-retrait\n\t-depot\n");
printf("4-Affichage\n\t-Par ordre ascendant\n\t-Par Ordre Descendant\n\t");
printf("-Par ordre ascendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n\t");
printf("-Par ordre descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n\t-Recherche par CIN");
printf("\n5-Fidelisation\n\t-Ajouter 1.3 pourcent aux comptes ayant les 3 premiers montants superieurs\n6-Quitter l'application\n\n");
printf("choisissez le numero d'operation :");
scanf("%d",&opnum);





switch (opnum){
    case 1:
    {	
        premierchoix();
		
        affichagecompte();
        goto menuprincipale;;
        break;
    }
    
    case 2:
    {
        deuxiemechoix();
        affichagecompte();
        goto menuprincipale;
        break;
    }
    
    case 3:
    {   troisiemechoix();
   		affichagecompte();
        goto menuprincipale;;
        break;
    }
    case 4:
    {   quatriemechoix();
   		goto menuprincipale;
        break;
    }
    case 5 :
    {
        
		cinquiemechoix();
		goto menuprincipale;
        break;
    }
    case 6:
    {
        system("cls");
        sixiemechoix();
        break;
    }

}
}
//
void premierchoix()
{
      	 
        printf("entrer le cin :");
        scanf("%s",comptebancaire[n].cin);
        printf("entrer le nom :");
        scanf("%s",comptebancaire[n].nom);
        printf(" entrer le prenom :");
        scanf("%s",comptebancaire[n].prenom);
        printf("entrer le montant :");
        scanf("%f",&comptebancaire[n].montant);
        
        printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[n].cin, comptebancaire[n].nom, comptebancaire[n].prenom,comptebancaire[n].montant);
        n++;
}
//
void deuxiemechoix()
{
       int nbr;

        printf("choisissez le nombre des comptes ");
        scanf("%d",&nbr);
        
        for(i=n ; i < nbr+n ; i++)
        {
	        printf("entrer le cin :");
	        scanf("%s", comptebancaire[i].cin);
	        printf("entrer le nom :");
	        scanf("%s", comptebancaire[i].nom);
	        printf("entrer le prenom :");
	        scanf("%s", comptebancaire[i].prenom);
	        printf("entrer le montant :");
	        scanf("%f",&comptebancaire[i].montant);

	        
		}
		n +=nbr;

}
//
void troisiemechoix()
{

float retrait, depot;
char cin[12];


	
    printf("operation :\n1-Retrait\n2-Depot\n");
    printf("choisissez le numero d'operation :");
    scanf("%d",&num);
    
    if(num==1)
    {
                      
        printf("Taper le CIN du compte de retrait ");
        scanf("%s",&cin);
         
        for(i=0 ; i<n ; i++)
		{
        	if((strcmp(comptebancaire[i].cin,cin))== 0 )
			{
	        	printf("taper le montant a retirer\n");
	        	scanf("%f",&retrait);	
        		if(retrait < (comptebancaire[i].montant))
       			{
		            printf("retrait effectuer  \n");
		            comptebancaire[i].montant -=retrait;
		            
		        	printf("montant actuel est %.2f", comptebancaire[i].montant );   
        
        		}
				else printf ("montant indisponible");
				
			} else if (i== n-1) {printf ("CIN introuvable");}
		}
          

	}else
		if(num == 2)
		{
      		printf("Taper le CIN du compte de depot ");
       		scanf("%s",&cin);
         
      		 for(i=0 ; i<n ; i++)
			{	
        		if(strcmp(comptebancaire[i].cin,cin)== 0 )
				{
        			printf("taper le montant a deposer\n");
        			scanf("%f",&depot);	
        	
          			printf("depot effectuer  \n");
            		comptebancaire[i].montant +=depot;
      			  	printf("montant actuel est %.2f :\n",comptebancaire[i].montant);   
        
       		 	}
       		 	else if (i== n-1) {printf ("CIN introuvable");}
				
			}
		}

}

//Ascendant
void ascendant()
{	
    for(i=0;i<n-1;i++)
	{ for(j=0;j<n-i-1;j++)
        {
             if(comptebancaire[j].montant>comptebancaire[j+1].montant)
             {
                
				strcpy(tmp.cin,comptebancaire[j].cin);
				strcpy(tmp.nom,comptebancaire[j].nom);
				strcpy(tmp.prenom,comptebancaire[j].prenom);
                tmp.montant = comptebancaire[j].montant;
 
                strcpy(comptebancaire[j].cin,comptebancaire[j+1].cin);
                strcpy(comptebancaire[j].nom,comptebancaire[j+1].nom);
				strcpy(comptebancaire[j].prenom,comptebancaire[j+1].prenom);
                comptebancaire[j].montant = comptebancaire[j+1].montant;
 
                strcpy(comptebancaire[j+1].cin,tmp.cin);
                strcpy(comptebancaire[j+1].nom,tmp.nom);
                strcpy(comptebancaire[j+1].prenom,tmp.prenom);
                comptebancaire[j+1].montant = tmp.montant;
             }
        }
	}

}    

//Descendant 
void descendant ()
{       
    for(i=0;i<n-1;i++)
	{ for(j=0;j<n-i-1;j++)
        {
             if(comptebancaire[j].montant<comptebancaire[j+1].montant)
             {
                strcpy(tmp.cin,comptebancaire[j].cin);
				strcpy(tmp.nom,comptebancaire[j].nom);
				strcpy(tmp.prenom,comptebancaire[j].prenom);
                tmp.montant = comptebancaire[j].montant;
 
                strcpy(comptebancaire[j].cin,comptebancaire[j+1].cin);
                strcpy(comptebancaire[j].nom,comptebancaire[j+1].nom);
				strcpy(comptebancaire[j].prenom,comptebancaire[j+1].prenom);
                comptebancaire[j].montant = comptebancaire[j+1].montant;
 
                strcpy(comptebancaire[j+1].cin,tmp.cin);
                strcpy(comptebancaire[j+1].nom,tmp.nom);
                strcpy(comptebancaire[j+1].prenom,tmp.prenom);
                comptebancaire[j+1].montant = tmp.montant;
             }
        }
	}
	
}


void quatriemechoix()
{
	char cin[12];
	char pcin;
	
	printf("Affichage :\n1-Par Ordre Ascendant\n2-Par Ordre Descendant\n3-Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n4-Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n5-Recherche par CIN\n");
    printf("choisissez le numero d'operation :");
    scanf("%d",&num);
//Par Ordre Ascendant
	if(num==1)
	{ 
		ascendant();
		affichagecompte();
	}
//Par Ordre Descendant	
	if(num == 2)
	{
		descendant();
		affichagecompte();
	}

//Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)	
	else if(num == 3)
	{     
		ascendant();
		printf("introduire un chiffre");
		scanf("%f",&chiffre);
			
		printf("Les comptes dans l'ordre ascendant du montants ayant un montant superieur au chiffre introduit :\n");
 		for(i=0 ;i< n ;i++)
 		{
    		 if(chiffre< comptebancaire[i].montant)
			{
     		    printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[i].cin, comptebancaire[i].nom, comptebancaire[i].prenom,comptebancaire[i].montant);
      		}
		}	
 	}
		
 
//Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)   
	else if(num == 4)
	{
		descendant();
	    
	    printf("introduire un chiffre");
		scanf("%f",&chiffre);
		printf("\nLes comptes dans l'ordre descendant du montants ayant un montant superieur au chiffre introduit :\n");
 		for(i=0 ;i< n ;i++)
 		{
  			if(chiffre<comptebancaire[i].montant)
			{
  	       		printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[i].cin, comptebancaire[i].nom, comptebancaire[i].prenom,comptebancaire[i].montant);
			}
		}	
 	}
//Recherche par CIN
	else if(num == 5)
	{
		printf("Taper le CIN du compte que vous cherchez ");
        scanf("%s",&cin);
         
        for(i=0 ; i<n ; i++)
		{
        	if(strcmp(comptebancaire[i].cin,cin)== 0 )
			{	
				printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[i].cin, comptebancaire[i].nom, comptebancaire[i].prenom,comptebancaire[i].montant);
					
			}
			else if (i == n-1) {printf ("CIN introuvable");}
		}
				
	}
}

void cinquiemechoix()
{	int fidel;
	printf("Vous aver 1.3 pourcent ajouter aux comptes ayant les 3 premiers montants superieurs");
	descendant();
	printf("\n----------------------------------------------------------------------\n");

        for(i=0 ; i<3 ; i++)
        {
        	fidel= (comptebancaire[i].montant *1.3)/100;
        	comptebancaire[i].montant+=fidel;
        	
            printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[i].cin, comptebancaire[i].nom, comptebancaire[i].prenom,comptebancaire[i].montant);
        }
        printf("------------------------------------------------------------------------\n");
}	
void sixiemechoix()
{
	printf("vous avez quiter l'application");
}
