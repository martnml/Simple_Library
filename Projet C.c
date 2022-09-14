#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#define  ENTER 13
#define TAB 9
#define BKSP 8


int a=5;

char *categorie[30];

typedef struct livre{
	char cat[30];
	int lid;
	char lnom[30];
	char aut[30];
	int qt;
	float pr;
	struct livre *suiv;} livre;
	
typedef struct livre *liste;




//------------    ajouter un livre    ----------//
liste ajouter(liste l)	{
	
	int i;
    char qst='y';

	
	   
while(qst=='y'){

  
	
	liste c=malloc(sizeof(liste));
	
	

	printf("------------------------  Entre les information --------------------------");
	printf("\n\n\n");
	strcpy(c->cat,*categorie);
	
	printf("Categorie :");
    printf("%s",c->cat); 
    printf("\n\n");
	
	
	liste p=l;
	for(i=0;i++;(p)!=NULL){
	(p)=(p)->suiv;
	i++;
	} 
	c->lid=i;
	 
	printf("Livre_id :");
	printf("%d",c->lid);
	printf("\n\n");

	printf("Livre_nom : ");
	scanf("%s",c->lnom);
	printf("\n");

	printf("Auteur : ");
	scanf("%s",c->aut);
	printf("\n");


	printf("Quantite : ");
	scanf("%d",&c->qt);
	printf("\n");

	printf("Prix : ");
	scanf("%f",&c->pr);
	printf("\n\n");
   

    c->suiv=l;
   
    printf("\n\n****  livre a ete enregistrer avec succes  **** ");
    printf("\n\nAjouetr un nouveau ? Y/N :");
    
	scanf("%c",&qst);
	}
	
	return l;
		
	}	

//-----------      main menu     -------//
void mainmenu(liste l){

int c,d;

	printf("\n\n----------------------  Main Menu  --------------------------------- ");
	printf("\n\n");
	printf("   1.Ajouter un livre ");
	printf("\n\n   2.Supprimer un livre ");
	printf("\n\n   3.Recherche d'un livre");
	printf("\n\n   4.Issue d'un livre");
	printf("\n\n   5.Voir la liste des livres");
	printf("\n\n   6.Modifier un livre");
	printf("\n\n   7.Fermer l'application");
	printf("\n\n\n\n");
	printf("Entre votre choix: ");
	scanf("%d",&c);
	
	if(c==7) 
	{
	 printf("\n\n\n\n ------------ ! APPLICATION EST FERME !-------------\n\n\n");
	 quiter();}
	 
	else {
	printf("\n\n--------------------- Choisir une categorie ---------------------------- ");
    printf("\n\n");
 
    
     	printf("   1.informatique");
        printf("\n\n   2.electronique");
	    printf("\n\n   3.electrique");
	    printf("\n\n   4.genie civil");
	    printf("\n\n   5.mechanique");
	    printf("\n\n   6.architecture");
	    printf("\n\n   7.retour au menu principal"); 
	printf("\n\n");
	printf("Entrer votre choix :");
	
	    scanf("%d",&d);
	
	switch(d){
	       	case 1:*categorie="informatique";break;
	       	case 2:*categorie="electronique";break;
			case 3:*categorie="electrique";break;
			case 4:*categorie="genie civil";break;
			case 5:*categorie="mechanique";break;
			case 6:*categorie="architecure";break;
			case 7:mainmenu(l);break;}

	switch(c){                         		
	case 1:l=ajouter(l);break;
	case 2:supprimer(l);break;
	case 3:recherche(l);break;     
	case 4:issue(l);break;
	case 5:voir(l);break;
	case 6:modifier(l);break;
	
			}
	}
	printf("\n\n------------------EXIT-------------------\n\n");
}


//---------      supprimer un livre     --------------//


void supprimer(liste *l) {
  
  
  	liste p,pp;
    char r,qst='y';
	int id;
	int v=0;
	   
while(qst=='y'){
	     
		 printf("\nentrer ID de livre ");	
          scanf("%d",&id);
          

if((l)==NULL) {
               printf("\n\nil  n'existe  aucun livre   !!");
                 v=1; }
   
   else {  p=(*l);
		   while((p->suiv!=NULL)&&(p->lid!=id)) {   pp=p;
		                                            p=p->suiv;
											                     }
		   
		   if(p->lid==id){
		                  pp=p->suiv;
		                  free(p);
						  printf("**** Livre est supprimee avec succes **** "); } 
						  			                                     
						  
           else printf("\nce Livre n'existe pas   !! ");    }

  
  if(v!=1){
             printf("\n\nSupprimer un Autre livre  ? Y/N : ");
             scanf("%c",&qst);}
               
}

}





//--------    modifier livre    ----------------//
void modifier(liste *l){
	
liste p,pp;	
char r,qst='y';
int id;
int v=0;


while(qst=='y'){
	
printf("\nentrer ID de livre : ");	
scanf("%d",&id);


if(l==NULL){
           printf("\nil n'y a aucun livre");
                v=1;
                         }
			  
	else { liste p=(*l);
	       
		   while((p->suiv!=NULL)&&(p->lid!=id)) p=p->suiv;
		   
		   if(p->lid==id){   printf("\nmodifier le nom de livre y/n ?? :");
                                 scanf("%c",&r);
                  
	                        if (r=='y'){  printf("le nouveau livre_nom: ");
			                                     scanf("%s",&(p->lnom));}
                  
				    printf("modifier l'Auteur  y/n ?? :");
                    scanf("%c",&r);
                  
	                          if (r=='y'){ printf("le nouveau Auteur: ");
			                             scanf("%s",&(p->aut));	                
									                          }
									   
				     printf("modifier le nom de livre y/n ?? :");
                    scanf("%c",&r);
                  
	                        if (r=='y'){ printf("le nouveau livre_nom: ");
			                                scanf("%s",&(p->lnom));					    
								                                   }
         
		             printf("modifier la Quantite y/n ?? :");
                     scanf("%c",&r);        
	              
				                 if (r=='y'){ printf("le nouveau livre_nom: ");
			                                   ("%d",&(p->qt)); }
			                   
			        printf("modifier le Prix y/n ?? :");
                    scanf("%c",&r);        
	              
			                   	if (r=='y'){ printf("le nouveau livre_nom: ");
			                                 scanf("%d",&(p->pr)); }
			
		               
			
			   
			    printf(" \n\n *****Livre modifier avec succes*****  "); 
		   	}
		   	
		   	else printf("\nce livre n'existe pas !!");  
	    }
	
	if(v!=1){

   printf("\n\nSupprimer un nouveau ? Y/N : ");
    scanf("%c",&qst);}
	}
	 
	
	   	  
}


//----------Recherche livre----------//
 void recherche(liste l){
int id;
int v=0;
char qst='y';


while(qst=='y'){
printf("\nEntrer le ID de livre ");	
scanf("%d",&id);




if(l==NULL) {
printf("\nil n'y a aucun livre");
v=1;
}
else {    
	       while((l->suiv!=NULL)&&(l->lid!=id)) l=l->suiv;
		   
		   if(l==NULL) printf("\nce livre n'existe pas");
		   
		   
		   else if  (l->lid==id)  
		  {
		       printf("voici le Livre : %s",l->lnom);
		       
               printf("\nCategorie :");
               printf("%s",l->cat); 
               
               printf("\nLivre_id : ");
               printf("%s",l->lid);
               
               printf("\nLivre_nom : ");
               printf("%s",l->lnom);
               
               printf("\nAuteur : ");
               printf("%s",l->aut);
               
			   printf("\nQuantite : ");
			   printf("%s",l->qt);
			   
               printf("\n Prix : ");
			   printf("%s",l->pr);}
        
            }
	    
	
		
		
		if(v!=1){
			
        printf("\n\nRecherche  un autre livre ? Y/N : ");
        scanf("%c",&qst);}
    
	   }
	
	  }








// ---------  issue livre --------------//
 void issue(liste l){
	int t[10];
	int i,j;
	liste p;
	
	
	
	
	for(i=1;i<=6;i++) t[i]=0;
	
	
   if(l==NULL) printf("il n'y a aucun livre");


	
	else { printf("Voici les categorie disponible:\n");
	     
	     while((l->suiv!=NULL)&&(j<6)){
	     	
	    if((l->cat)[1]=='i'&&(t[1]==0)){ printf("-Informatique");
	     	                              t[1]++;  j++;    }
	     	                            
	    else if ((l->cat)[1]=='e' &&(l->cat)[7]=='o' &&(t[2]==0)){ printf("-Electronique");
	     	                              t[2]++;  j++;        }
										   	
		else if ((l->cat)[1]=='e'&&(l->cat)[7]=='i' &&(t[3]==0)){ printf("-Electrique");
	     	                             t[3]++;   j++;       }
										   									    	                            
		else if ((l->cat)[1]=='g' &&(t[4]==0)){ printf("-Genie civil");
	     	                              t[4]++;  j++;        }
										   								 	
	    
		else if ((l->cat)[1]=='m' &&(t[5]==0)){ printf("-mechanique");
	     	                              t[5]++;  j++;        }
										   	
	    else if ((l->cat)[1]=='a' &&(t[6]==0)){ printf("-Architecture");
	     	                             t[6]++;   j++;     }	 
	  								
		l=l->suiv;								   	                              
		 }
	     
          
		  
		  }
	
}







// -------   voir la liste des livres      ----------//
void voir(liste l){



  if(l==NULL) printf("\n\nil n'y aucun livre   !!");
  
  else  while(l->suiv!=NULL){
        printf("\n\n Voici les livre disponible  : ");
        printf("\n %d",l->lnom);
       	
		   l=l->suiv; 
		   }
		   
		   
}






//--------     retour au menu principal    --------//
void returnfunc(liste l){
    mainmenu(l);
	} 




//----------- quiter-----------//
void quiter(){
	
exit(0);	
}




//--------------- Password --------------//

void password(liste l) {
	int k=0;
	char ch;
	
	int b;
	const char user[20]="univ mascara";
	const char code[20]="biblio";
	char u[20],c[20];
	int i,j;
	

	b=0;
	while(b==0){
			i=0;
	        j=0;
		
		printf("\n          User :");
		gets(u);
		
	printf("\n          Password :");
 while(1){
	
	ch=getch();	
    if(ch==ENTER||ch==TAB){
    	c[k]='\0';
    	break;	}
	else if(ch==BKSP){
	         	if(k>0) {
			             k--;
			             printf("\b \b");}
	                 }	
	     else {
	     	c[k++]=ch;
	     	printf("* \b");
		 }            
	          
}
		
		
		

		while((i<=11)&&(user[i]==u[i])) i++;
		while((j<=5)&&(code[j]==c[j]))	j++;
			
		
		if((i==12)&&(j==6)) {
		   b=1;
		  mainmenu(l);}
		
		else {
		    b=0;
		    printf("\n\n   -User or Password  incorrect !! ");
		    printf("\n\n   -please try again  :\n\n\n ");
		}
	}
	
}







#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){ 
	liste l;
    l=NULL;
    


password(l);


	return 0;
	
	
}
