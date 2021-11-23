#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int n=0;
int i;

//structure
struct compte
{
    char cin[12];
    char nom[100];
    char prenom[100];
    float montant;
};
void premierchoix(struct compte *comptebancaire);
void deuxiemechoix(struct compte *comptebancaire);
void troisiemechoix(struct compte *comptebancaire);
//void quatriemechoix();

void affichagecompte(struct compte *comptebancaire)
{
	printf("\nLa liste de vos comptes\n");
        printf("\n----------------------------------------------------------------------\n");
        
        for(i=0 ; i<n ; i++)
        {
            printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",(comptebancaire+i)->cin, (comptebancaire+i)->nom, (comptebancaire+i)->prenom,(comptebancaire+i)->montant);
        }
        printf("------------------------------------------------------------------------\n");
}

//---------------------------------------------
int main()
{

struct compte *comptebancaire;
comptebancaire = (struct compte*)malloc(10*sizeof(struct compte));


int opnum;

menuprincipale:
printf("\n1-Introduire un compte bancaire (CIN, Nom et Prenom, Montant)\n");
printf("2-Introduire plusieurs comptes bancaires (CIN, Nom et Prenom, Montant)\n");
printf("3-Operations\n\t-retrait\n\t-depot\n");
printf("4-Affichage\n\t-Par ordre ascendant\n\t-Par Ordre Descendant\n\t");
printf("-Par ordre ascendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n\t");
printf("-Par ordre descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n\t-Recherche par CIN");
printf("5-Fidelisation\n\t-Ajouter 1.3 pourcent aux comptes ayant les 3 premiers montants superieurs\n6-Quitter l'application\n\n");
printf("choisissez le numero d'operation :");
scanf("%d",&opnum);





switch (opnum){
    case 1:
    {	
        premierchoix( comptebancaire);
		
        affichagecompte(comptebancaire);
//        n++;
//        system("cls");
        goto menuprincipale;;
        break;
    }
    
    case 2:
    {
        deuxiemechoix(comptebancaire);
        affichagecompte(comptebancaire);
        goto menuprincipale;
        break;
    }
    
    case 3:
    {   troisiemechoix(comptebancaire);
   		affichagecompte(comptebancaire);
        goto menuprincipale;;
        break;
    }
//    case 4:
//    {    quatriemechoix();
//   		 goto menuprincipale;
//        break;
//    }
//    case 5:
//    {
//        cinquiemechoix();
//        break;
//    }
//    case 6:
//    {
//        sixiemechoix();
//        break;
//    }
}

}
//
void premierchoix(struct compte *comptebancaire)
{
      	 
        printf("entrer le cin :");
        scanf("%s",&(comptebancaire+n)->cin);
        printf("entrer le nom :");
        scanf("%s",&(comptebancaire+n)->nom);
        printf(" entrer le prenom :");
        scanf("%s",&(comptebancaire+n)->prenom);
        printf("entrer le montant :");
        scanf("%f",&(comptebancaire+n)->montant);
        printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",(comptebancaire+n)->cin, (comptebancaire+n)->nom, (comptebancaire+n)->prenom,(comptebancaire+n)->montant);
        n++;
}
//
void deuxiemechoix(struct compte *comptebancaire)
{
       int nbr;

        printf("choisissez le nombre des comptes ");
        scanf("%d",&nbr);
        
        for(i=0 ; i < nbr ; i++)
        {
	        printf("entrer le cin :");
	        scanf("%s",& (comptebancaire+n)->cin);
	        printf("entrer le nom :");
	        scanf("%s",&(comptebancaire+n)->nom);
	        printf("entrer le prenom :");
	        scanf("%s",&(comptebancaire+n)->prenom);
	        printf("entrer le montant :");
	        scanf("%f",&(comptebancaire+n)->montant);
	        n++;
	        
		}

}
//
void troisiemechoix(struct compte *comptebancaire)
{

float retrait, depot;
int num;
char cin[12];
int i;


	
    printf("operation :\n1-Retrait\n2-Depot\n");
    printf("choisissez le numero d'operation :");
    scanf("%d",&num);
    
    if(num==1)
    {
                      
        printf("Taper le CIN du compte de retrait ");
        scanf("%s",&cin);
         
        for(i=0 ; i<n ; i++)
		{
        	if((strcmp((comptebancaire+i)->cin,cin))== 0 )
			{
	        	printf("taper le montant a retirer\n");
	        	scanf("%f",&retrait);	
        		if(retrait < ((comptebancaire+i)->montant))
       			{
		            printf("retrait effectuer  \n");
		            (comptebancaire+i)->montant -=retrait;
		            
		        	printf("montant actuel est %.2f",(comptebancaire+i)->montant );   
        
        		}
				else printf("montant indisponible");	
				
			}
		}
          

	}else
		if(num == 2)
		{
      		printf("Taper le CIN du compte de depot ");
       		scanf("%s",&cin);
         
      		 for(i=0 ; i<n ; i++)
			{	
        		if(strcmp((comptebancaire+i)->cin,cin)== 0 )
				{
        			printf("taper le montant a deposer\n");
        			scanf("%f",&depot);	
        	
          			printf("depot effectuer  \n");
            		(comptebancaire+i)->montant +=depot;
      			  	printf("montant actuel est %.2f :\n",(comptebancaire+i)-> montant);   
        
       		 	}
				
			}
		}

}
//
////Ascendant
//void ascendant (struct compte *comptebancaire))
//{
//	clients t[100];
//    clients tmp;
//    int i,j,num;
//    float chiffre;
//	printf("Donnez le nombre des comptes:\t");
//    scanf("%d",&n);
//    for(i=0;i<n;i++)
//    {
//        printf("Donnez le cin du compte  %d:\t",i+1);
//        scanf("%s",&t[i].cin);
//        printf("Donnez le montant du compte :\t");
//        scanf("%f",&t[i].montant);
//    }
//    for(i=0;i<n;i++)
//	{printf("-- Le montant du compte de %s est : %.2f\n",t[i].cin ,t[i].montant);
//	}
//        
//    for(i=0;i<n-1;i++)
//	{ for(j=0;j<n-i-1;j++)
//        {
//             if(t[j].montant<t[j+1].montant)
//             {
//                 strcpy(tmp.cin,t[j].cin);
//                 tmp.montant = t[j].montant;
// 
//                 strcpy(t[j].cin,t[j+1].cin);
//                 t[j].montant = t[j+1].montant;
// 
//                 strcpy(t[j+1].cin,tmp.cin);
//                 t[j+1].montant = tmp.montant;
//             }
//        }
//	}
//       
//    printf("Les comptes dans l'ordre descendant du montants :\n");
//    for(i=0;i<n;i++)
//        printf("-- Le montant de %s est : %.2f\n",t[i].cin,t[i].montant);
//		
//}
//
//
////Descendant 
//void descendant()
//{	clients comptebancaire;
//	clients t[100];
//    clients tmp;
//    int i,j,num;
//    float chiffre;
//   
//	printf("Donnez le nombre des comptes:\t");
//    scanf("%d",&n);
//    for(i=0;i<n;i++)
//    {
//        printf("Donnez le cin du compte  %d:\t",i+1);
//        scanf("%s",&t[i].cin);
//        printf("Donnez le montant du compte :\t");
//        scanf("%f",&t[i].montant);
//    }
//    for(i=0;i<n;i++)
//	{printf("-- Le montant du compte de %s est : %.2f\n",t[i].cin ,t[i].montant);
//	}
//       
//    for(i=0;i<n-1;i++)
//	{ for(j=0;j<n-i-1;j++)
//        {
//             if(t[j].montant>t[j+1].montant)
//             {
//                 strcpy(tmp.cin,t[j].cin);
//                 tmp.montant = t[j].montant;
// 
//                 strcpy(t[j].cin,t[j+1].cin);
//                 t[j].montant = t[j+1].montant;
// 
//                 strcpy(t[j+1].cin,tmp.cin);
//                 t[j+1].montant = tmp.montant;
//             }
//        }
//	}
//       
//    printf("Les comptes dans l'ordre ascendant du montants :\n");
//    for(i=0;i<n;i++)
//        {
//		printf("-- Le montant de %s est : %.2f\n",t[i].cin,t[i].montant);
//		}
//
//}    
//
//void quatriemechoix()
//{
//	clients comptebancaire;
//	clients t[100];
//    int i,n,num;
//    float chiffre;
//   
//    
////    Affichage
//    printf("Affichage :\n1-Par Ordre Ascendant\n2-Par Ordre Descendant\n3-Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n4-Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n5-Recherche par CIN\n");
//    printf("choisissez le numero d'operation :");
//	scanf("%d",&num);
////Par Ordre Ascendant
//    if(num==1)
//	{ 
//	ascendant();
//	}else 
////Par Ordre Descendant	
//	if(num == 2)
//	{
//	descendant();
//	}else
////Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)	
//	if(num == 3)
//	{
//	clients comptebancaire;
//	clients t[100];
//    clients tmp;
//    int i,j,num;
//    float chiffre;
//	printf("Donnez le nombre des comptes:\t");
//    scanf("%d",&n);
//    for(i=0;i<n;i++)
//    {
//        printf("Donnez le montant du compte  %d:\t",i+1);
//        scanf("%f",&t[i].montant);
//    }
//           
//    for(i=0;i<n-1;i++)
//	{ for(j=0;j<n-i-1;j++)
//        {
//             if(t[j].montant<t[j+1].montant)
//             {
//                 strcpy(tmp.cin,t[j].cin);
//                 tmp.montant = t[j].montant;
// 
//                 strcpy(t[j].cin,t[j+1].cin);
//                 t[j].montant = t[j+1].montant;
// 
//                 strcpy(t[j+1].cin,tmp.cin);
//                 t[j+1].montant = tmp.montant;
//             }
//        }
//	}
//       
//    printf("Les comptes dans l'ordre descendant du montants :\n");
//    for(i=0;i<n;i++)
//    printf("-- Le montant de %d est : %.2f\n",i+1,t[i].montant);
//        
//	printf("introduire un chiffre");
//	scanf("%f",&chiffre);
//	
//	printf("Les comptes dans l'ordre ascendant du montants ayant un montant superieur au chiffre introduit :\n");
// for(i=0 ;i< n ;i++)
// {
//     if(chiffre<t[i].montant)
//	{
//        printf("-- Les montants sont %.2f\n",t[i].montant);
//	}	
// }
//
//	}		
//   
////Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)   
//if(num == 4)
//{
//	clients comptebancaire;
//	clients t[100];
//    clients tmp;
//    int i,j,num;
//    float chiffre;
//   
//	printf("Donnez le nombre des comptes:\t");
//    scanf("%d",&n);
//    for(i=0;i<n;i++)
//    {
//        printf("Donnez le montant du compte %d:\t",i+1);
//        scanf("%f",&t[i].montant);
//    }
//    
//    for(i=0;i<n-1;i++)
//	{ for(j=0;j<n-i-1;j++)
//        {
//             if(t[j].montant>t[j+1].montant)
//             {
//                 strcpy(tmp.cin,t[j].cin);
//                 tmp.montant = t[j].montant;
// 
//                 strcpy(t[j].cin,t[j+1].cin);
//                 t[j].montant = t[j+1].montant;
// 
//                 strcpy(t[j+1].cin,tmp.cin);
//                 t[j+1].montant = tmp.montant;
//             }
//        }
//	}
//       
//    printf("Les comptes dans l'ordre ascendant du montants :\n");
//    for(i=0;i<n;i++)
//        {
//		printf("-- Le montant de %d est : %.2f\n",i+1,t[i].montant);
//		}
//
//    printf("Les comptes dans l'ordre descendant du montants ayant un montant superieur au chiffre introduit :\n");
//    printf("introduire un chiffre");
//	scanf("%f",&chiffre);
//	
// for(i=0;i<n;i++)
// 	{
//     if(chiffre<t[i].montant)
//	{
//        printf("-- Les montants sont %.2f\n",t[i].montant);
//	}	
// 	}
//}else
////Recherche par CIN	
//if(num == 5)
//{
//}
//
//
//}