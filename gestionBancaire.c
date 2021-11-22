#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int n;
//menu
void menuprincipale()
{
printf("\n1-Introduire un compte bancaire (CIN, Nom et Prenom, Montant)\n");
printf("2-Introduire plusieurs comptes bancaires (CIN, Nom et Prenom, Montant)\n");
printf("3-Operations\n4-Affichage\n5-Fidelisation\n6-Quitter l'application\n");
}
//structure
typedef struct comptebancaire
{
    char cin[12];
    char nom[100];
    char prenom[100];
    float montant;
}clients;
//
void premierchoix(){
        clients comptebancaire;
        printf("entrer le cin :");
        scanf("%s",&comptebancaire.cin);
        printf("\n entrer le nom :");
        scanf("%s",&comptebancaire.nom);
        printf("\n entrer le prenom :");
        scanf("%s",&comptebancaire.prenom);
        printf("\n entrer le montant :");
        scanf("%f",&comptebancaire.montant);
        printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire.cin, comptebancaire.nom, comptebancaire.prenom,comptebancaire.montant);
            
}
//
void deuxiemechoix(){
       
        int i;
        printf("choisissez le nombre des comptes ");
        scanf("%d",&n);
        
        clients comptebancaire[n];
        
        for(i=0 ; i < n ; i++)
        {
        printf("entrer le cin :");
        scanf("%s",&comptebancaire[i].cin);
        printf("entrer le nom :");
        scanf("%s",&comptebancaire[i].nom);
        printf("entrer le prenom :");
        scanf("%s",&comptebancaire[i].prenom);
        printf("entrer le montant :");
        scanf("%f",&comptebancaire[i].montant);
        }
        
        printf("\nLa liste de vos comptes\n");
        printf("\n----------------------------------------------------------------------\n");
        for(i=0 ; i<n ; i++)
        {
            printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[i].cin, comptebancaire[i].nom, comptebancaire[i].prenom,comptebancaire[i].montant);
        }
        printf("------------------------------------------------------------------------\n");
}
//
void troisiemechoix()
{
clients comptebancaire;
float retrait, depot;
int num;
char cin[12];
int i;


	
    printf("operation :\n1-Retrait\n2-Depot\n");
    printf("choisissez le numero d'operation :");
    scanf("%d",&num);
    
    if(num==1)
    {
        printf("veuillez introduire un ou plusieurs comptes bancaires\n");
        printf("choisissez le nombre des comptes ");
        scanf("%d",&n);
        
        clients comptebancaire[n];
        
        for(i=0 ; i <n ; i++)
        {
        printf("entrer le cin :");
        scanf("%s",&comptebancaire[i].cin);
        printf("entrer le nom :");
        scanf("%s",&comptebancaire[i].nom);
        printf("entrer le prenom :");
        scanf("%s",&comptebancaire[i].prenom);
        printf("entrer le montant :");
        scanf("%f",&comptebancaire[i].montant);
        }
        
        printf("\nLa liste de vos comptes\n");
        printf("\n----------------------------------------------------------------------\n");
        for(i=0 ; i<n ; i++)
        {
            printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[i].cin, comptebancaire[i].nom, comptebancaire[i].prenom,comptebancaire[i].montant);
        }
        printf("------------------------------------------------------------------------\n");
               
        printf("Taper le CIN du compte de retrait ");
        scanf("%s",&cin);
         
        for(i=0 ; i<n ; i++){
        	
        	if(strcmp(comptebancaire[i].cin,cin)== 0 ){
        	printf("taper le montant a retirer\n");
        	scanf("%f",&retrait);	
        	if(retrait < comptebancaire[i].montant)
       		 {
            printf("retrait effectuer  \n");
            
        	printf("montant actuel est %.2f",comptebancaire[i].montant -retrait);   
        
        	}else
            printf("montant indisponible");	
				
			}
		}
          

		}else
		if(num == 2)
		{
		printf("veuillez introduire un ou plusieurs comptes bancaires\n");
        printf("choisissez le nombre des comptes ");
        scanf("%d",&n);
        
        clients comptebancaire[n];
        
        for(i=0 ; i <n ; i++)
        {
        printf("entrer le cin :");
        scanf("%s",&comptebancaire[i].cin);
        printf("entrer le nom :");
        scanf("%s",&comptebancaire[i].nom);
        printf("entrer le prenom :");
        scanf("%s",&comptebancaire[i].prenom);
        printf("entrer le montant :");
        scanf("%f",&comptebancaire[i].montant);
        }
        
        printf("\nLa liste de vos comptes\n");
        printf("\n----------------------------------------------------------------------\n");
        for(i=0 ; i<n ; i++)
        {
            printf("cin: %s\t |Nom et prenom: %s %s\t | montant: %.2f\n",comptebancaire[i].cin, comptebancaire[i].nom, comptebancaire[i].prenom,comptebancaire[i].montant);
        }
        printf("------------------------------------------------------------------------\n");
               
        printf("Taper le CIN du compte de depot ");
        scanf("%s",&cin);
         
        for(i=0 ; i<n ; i++){
        	
        	if(strcmp(comptebancaire[i].cin,cin)== 0 )
			{
        	printf("taper le montant a deposer\n");
        	scanf("%f",&depot);	
        	
            printf("depot effectuer  \n");
            
        	printf("montant actuel est %.2f :\n",comptebancaire[i].montant + depot);   
        
        	}
				
			}
		}

}


//Ascendant
void ascendant ()
{
	clients comptebancaire;
	clients t[100];
    clients tmp;
    int i,j,num;
    float chiffre;
	printf("Donnez le nombre des comptes:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Donnez le cin du compte  %d:\t",i+1);
        scanf("%s",&t[i].cin);
        printf("Donnez le montant du compte :\t");
        scanf("%f",&t[i].montant);
    }
    for(i=0;i<n;i++)
	{printf("-- Le montant du compte de %s est : %.2f\n",t[i].cin ,t[i].montant);
	}
        
    for(i=0;i<n-1;i++)
	{ for(j=0;j<n-i-1;j++)
        {
             if(t[j].montant<t[j+1].montant)
             {
                 strcpy(tmp.cin,t[j].cin);
                 tmp.montant = t[j].montant;
 
                 strcpy(t[j].cin,t[j+1].cin);
                 t[j].montant = t[j+1].montant;
 
                 strcpy(t[j+1].cin,tmp.cin);
                 t[j+1].montant = tmp.montant;
             }
        }
	}
       
    printf("Les comptes dans l'ordre descendant du montants :\n");
    for(i=0;i<n;i++)
        printf("-- Le montant de %s est : %.2f\n",t[i].cin,t[i].montant);
		
}


//Descendant 
void descendant()
{	clients comptebancaire;
	clients t[100];
    clients tmp;
    int i,j,num;
    float chiffre;
   
	printf("Donnez le nombre des comptes:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Donnez le cin du compte  %d:\t",i+1);
        scanf("%s",&t[i].cin);
        printf("Donnez le montant du compte :\t");
        scanf("%f",&t[i].montant);
    }
    for(i=0;i<n;i++)
	{printf("-- Le montant du compte de %s est : %.2f\n",t[i].cin ,t[i].montant);
	}
       
    for(i=0;i<n-1;i++)
	{ for(j=0;j<n-i-1;j++)
        {
             if(t[j].montant>t[j+1].montant)
             {
                 strcpy(tmp.cin,t[j].cin);
                 tmp.montant = t[j].montant;
 
                 strcpy(t[j].cin,t[j+1].cin);
                 t[j].montant = t[j+1].montant;
 
                 strcpy(t[j+1].cin,tmp.cin);
                 t[j+1].montant = tmp.montant;
             }
        }
	}
       
    printf("Les comptes dans l'ordre ascendant du montants :\n");
    for(i=0;i<n;i++)
        {
		printf("-- Le montant de %s est : %.2f\n",t[i].cin,t[i].montant);
		}

}    

void quatriemechoix()
{
	clients comptebancaire;
	clients t[100];
    int i,n,num;
    float chiffre;
   
    
//    Affichage
    printf("Affichage :\n1-Par Ordre Ascendant\n2-Par Ordre Descendant\n3-Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n4-Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n5-Recherche par CIN\n");
    printf("choisissez le numero d'operation :");
	scanf("%d",&num);
//Par Ordre Ascendant
    if(num==1)
	{ 
	ascendant();
	}else 
//Par Ordre Descendant	
	if(num == 2)
	{
	descendant();
	}else
//Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)	
	if(num == 3)
	{
	clients comptebancaire;
	clients t[100];
    clients tmp;
    int i,j,num;
    float chiffre;
	printf("Donnez le nombre des comptes:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Donnez le montant du compte  %d:\t",i+1);
        scanf("%f",&t[i].montant);
    }
           
    for(i=0;i<n-1;i++)
	{ for(j=0;j<n-i-1;j++)
        {
             if(t[j].montant<t[j+1].montant)
             {
                 strcpy(tmp.cin,t[j].cin);
                 tmp.montant = t[j].montant;
 
                 strcpy(t[j].cin,t[j+1].cin);
                 t[j].montant = t[j+1].montant;
 
                 strcpy(t[j+1].cin,tmp.cin);
                 t[j+1].montant = tmp.montant;
             }
        }
	}
       
    printf("Les comptes dans l'ordre descendant du montants :\n");
    for(i=0;i<n;i++)
    printf("-- Le montant de %d est : %.2f\n",i+1,t[i].montant);
        
	printf("introduire un chiffre");
	scanf("%f",&chiffre);
	
	printf("Les comptes dans l'ordre ascendant du montants ayant un montant superieur au chiffre introduit :\n");
 for(i=0 ;i< n ;i++)
 {
     if(chiffre<t[i].montant)
	{
        printf("-- Les montants sont %.2f\n",t[i].montant);
	}	
 }

	}		
   
//Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)   
if(num == 4)
{
	clients comptebancaire;
	clients t[100];
    clients tmp;
    int i,j,num;
    float chiffre;
   
	printf("Donnez le nombre des comptes:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Donnez le montant du compte %d:\t",i+1);
        scanf("%f",&t[i].montant);
    }
    
    for(i=0;i<n-1;i++)
	{ for(j=0;j<n-i-1;j++)
        {
             if(t[j].montant>t[j+1].montant)
             {
                 strcpy(tmp.cin,t[j].cin);
                 tmp.montant = t[j].montant;
 
                 strcpy(t[j].cin,t[j+1].cin);
                 t[j].montant = t[j+1].montant;
 
                 strcpy(t[j+1].cin,tmp.cin);
                 t[j+1].montant = tmp.montant;
             }
        }
	}
       
    printf("Les comptes dans l'ordre ascendant du montants :\n");
    for(i=0;i<n;i++)
        {
		printf("-- Le montant de %d est : %.2f\n",i+1,t[i].montant);
		}

    printf("Les comptes dans l'ordre descendant du montants ayant un montant superieur au chiffre introduit :\n");
    printf("introduire un chiffre");
	scanf("%f",&chiffre);
	
 for(i=0;i<n;i++)
 	{
     if(chiffre<t[i].montant)
	{
        printf("-- Les montants sont %.2f\n",t[i].montant);
	}	
 	}
}else
//Recherche par CIN	
if(num == 5)
{
}


}


int main()
{

int opnum;

menuprincipale();
printf("choisissez le numero d'operation :");
scanf("%d",&opnum);

switch (opnum){
    case 1:
    {
        premierchoix();
        menuprincipale();
        break;
    }
    
    case 2:
    {
        deuxiemechoix();
        menuprincipale();
        break;
    }
    
    case 3:
    {    troisiemechoix();
        menuprincipale();
        break;
    }
    case 4:
    {    quatriemechoix();
   		 menuprincipale();
        break;
    }
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