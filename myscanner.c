#include <map>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include "myscanner.h"
#include "TypeMolecule.h"
#include "Molecule.h"
#include <vector>
#include <cmath>
#include "Reaction.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include<random>
#include<cmath>
#include <ctime>
#include<chrono>
extern int yylex();
extern int yylineno;
extern char* yytext;
#define PI 3.14159265
int v ;
int t = 0 ;


#include "lex.yy.c"
// map type de molecule (nom,clé)
std::map<std::string, TypeMolecule> mapOfTypeMolecule;
//vecteur Raction de reactions
std::vector<Reaction> reactions ;
Reaction reaction ;
// vecteur de Molecule de molecules
std::vector<Molecule> molecules ;
Molecule mollecule ;

// fonction pour parser les type de molecule (analyse syntaxique)
void recmolecule ()
{
	int ntoken = yylex();
	if (ntoken == PointVirgule){
	printf("PointVirgule \n" );
		return ;
	}
	else 	if(ntoken == Virgule) {
				printf("Virgule \n" );

				if(yylex() == Identificateur) {
						printf("Identificateur de Type moleculaire \n" );
						vtoken = yytext ;
						std::string kh(vtoken);
						TypeMolecule tm;
						tm.name = kh;
						mapOfTypeMolecule.insert(std::make_pair(kh,tm));
						if(yylex() == PointVirgule) {
								printf("PointVirgule \n" );
			}

}
}
}
// fonction etape Methode Monte carlo
void etape () {

	srand (time(NULL));
	double x = 0 ;
	double vo = 0 ;
	double re = 0 ;
	int e = 0 ;
int iSecret;
	float f = 0 ;
	re = t/200. ;
	vo = 4*M_PI*re*re*re/3 ;
//	 cout<< "v = "<<vo <<endl ;
	for (vector<Reaction>::iterator iter = reactions.begin();
			 iter != reactions.end(); ++iter){
	Reaction &r = *iter;

	if (r.B == nullptr) {
//		cout << " b = null " <<endl ;
		 x = r.A->ppp * r.proba ;
	//	cout <<r.A->name<<endl ;
	//	cout<<r.A->ppp <<endl ;
	//	cout<<r.proba<<endl ;

	}
else {
//	cout << " b !!= null " <<endl;
   x = (r.A->ppp * r.B->ppp * r.proba * 7.4e-7)/vo ;
 }
//cout<< "x = "<<x <<endl ;

e = (int) x ;
//cout<< "e = "<<e <<endl ;

f = x - e ;
//cout<< "f = "<<f <<endl ;


iSecret = rand() % 2 ;
//cout<< "random  = "<<iSecret <<endl ;
//cout<<"random =  "<<iSecret<<endl;

if (iSecret < f) {
//nbr de fois que j'effectue la reaction Reaction ;
//cout << " random < 1 " <<endl;
	e+=1 ;
}

for (size_t i = 0; i < e; i++) {

	if( r.B == nullptr && r.A->ppp >0  && e>0) {
	//	cout << " b = null et pop de A >0  on diminue la pop de A  " <<endl;
r.A->ppp -= 1;
//cout<<"molecule A"<<r.A->name<<endl;

e -=1 ;
	}
else if (r.A->ppp >0 && r.B->ppp >0  && e>0){
	//cout << " b = null  on diminue la pop de A et de B si les deux > 0" <<endl;
r.A->ppp -= 1;
r.B->ppp -= 1;
//cout<<"molecule A"<<r.A->name<<endl;

//cout<<"molecule B"<<r.B->name<<endl;
e -=1 ;
}



//cout << " pop de C += 1 " <<endl;
if (r.D == nullptr){
	r.C->ppp +=1;
//	cout<<"molecule C"<<r.C->name<<endl;

//cout << " D == null " <<endl;
}

else {
	//cout << " D != null et pop de D += 1" <<endl;
	r.C->ppp +=1;
r.D->ppp +=1;
//cout<<"molecule C"<<r.C->name<<endl;
//cout<<"molecule D"<<r.D->name<<endl;

}
 // afficher les pop de molecules apres chaque etape

std::map<std::string,TypeMolecule>::iterator it = mapOfTypeMolecule.begin();
	 while(it != mapOfTypeMolecule.end())
	 {

			 std::cout<<it->second.ppp<<",";
    //   myfile <<it->second.ppp<< "," ;
			 it++;
}
std::cout<<""<<endl ;




}

}

}


void creationmolecule(string abbes,double x,double y,double z){



					if(mapOfTypeMolecule.find(abbes) != mapOfTypeMolecule.end()){

						mollecule.typMol = &(mapOfTypeMolecule.find(abbes)->second) ;

					}


	        mollecule.p.x = x  ;
	        mollecule.p.y = y  ;
	        mollecule.p.z = z  ;

				 molecules.push_back(mollecule) ;
         cout<<"Creation Molecule  "<<abbes<<"  avec succes"<<endl;


}

// fonction colision entre les molecules
void colision(string name,double x,double y,double z,float d){
	int iaer;
			for (vector<Molecule>::iterator iaer = molecules.begin();
					 iaer != molecules.end(); ++iaer){
			Molecule &m = *iaer;
			int d2 = (x-m.p.x)*(x-m.p.x) + (y-m.p.y)*(y-m.p.y) + (z-m.p.z)*(z-m.p.z);
   if (d2 > (d + m.typMol->diam)*(d + m.typMol->diam)){

// cration de la nouvelle molecules
//supression des molecules qui ont fais la colision
int iter;
    for (vector<Reaction>::iterator iter = reactions.begin();
         iter != reactions.end(); ++iter){
    Reaction &r = *iter;


	           if((r.B) && (((r.B->name==name) && (r.A->name==m.typMol->name))||
                 ((r.A->name==name) && (r.B->name==m.typMol->name)))){
									 cout<<"Molecule C "<<r.C->name<<endl;
									//	cout<<"colision"<<endl ;
									string k = r.C->name ;
		 		//		creationmolecule(k,x,y,z);
								 }
								 else{

								 }
}
   }

}
}

// fonction Multi agent (une etape)
void MultiAgent(){
 srand (time(NULL));
	int iper;
	    for (vector<Molecule>::iterator iper = molecules.begin();
	         iper != molecules.end(); ++iper){
	    Molecule &m = *iper;
	//		cout << "debut de Multi agent pour Molecule " << m.typMol->name << "  "<< m.typMol->vitese << "  "
		//	<< m.p.x << "  " << "  "<< m.p.y << "  "<< m.p.z << endl;


//// A CHaque MOlecule je tire un nombre Aleatoire
 		 int prob = rand() % 2 ;
	//	 cout<< "prob  = "<<prob <<endl ;
 		// si il est inferieur a sa vitesse de diffusion
		//la molecule diffuse sinon je passe a la suivante;
		 if(prob < m.typMol->vitese){
		  double d = 1.0 ;

       	int angleY = rand() % 361 ;
				int angleZ = rand() % 361 ;

// on fait bouger les molecules aleatoirement
				double siny =  sin (angleY*PI/180);
				double cosy =  cos (angleY*PI/180);
				double cosz = cos (angleZ*PI/180);
				double sinz = sin (angleZ*PI/180);


			 double dx =  d * (cosz * siny);
			 double dy =  d * (sinz) ;
			 double dz =  d * (cosz * cosy) ;

			 m.p.x = m.p.x + dx ;
			 m.p.y = m.p.y + dy ;
			 m.p.z = m.p.z + dz ;
// detecction de colision entre la molecule qu'on a fait bouger et les autres
		colision(m.typMol->name,m.p.x,m.p.y,m.p.z,m.typMol->diam);

 }



	}


}


// parser les raction (analyse syntaxique)
void reactionpr()
{
	int ntoken = yylex();
int ktoken ;
	if(ntoken == PLUS) {
printf("Plus \n" );
		if(yylex() == Identificateur) {
     printf("Identificateur type Moluculaire B \n");
		//	printf("Identificateur apres le plus %s \n",vtoken );
			if(mapOfTypeMolecule.find(vtoken) != mapOfTypeMolecule.end()){


				reaction.B = &(mapOfTypeMolecule.find(vtoken)->second) ;
				 // printf("B = %s\n ",vtoken );
			}

			ntoken = yylex();

		}
		else {

			printf("error \n" );
		}
  }else {
			reaction.B = nullptr ;
	}

	if(ntoken != Arrow){
		printf("-> %d \n", ntoken);
		exit(1);
	}
printf("Arrow \n" );

 	 if(yylex() != Identificateur) {
		 exit(1);
 		 //ntoken = yylex();


 	 }
printf("Identificateur Type Moluculaire C \n" );

if(mapOfTypeMolecule.find(vtoken) != mapOfTypeMolecule.end()){


	reaction.C = &(mapOfTypeMolecule.find(vtoken)->second) ;
	 // printf("C = %s\n ",vtoken );
}
	 ktoken = yylex();



	 if(ktoken == PLUS) {
		 printf("Plus \n" );
		 if(yylex() == Identificateur) {
			 //ntoken = yylex();
			 printf("Identificateur type moleculaire D \n" );
			 if(mapOfTypeMolecule.find(vtoken) != mapOfTypeMolecule.end()){


 				reaction.D = &(mapOfTypeMolecule.find(vtoken)->second) ;
				 // printf("D = %s\n ",vtoken );
 			}
			 ktoken = yylex();

		 }
		 else {
			 printf("error \n" );

		 }

	 } else {
		 reaction.D = nullptr ;
	 }

	 if(ktoken != AccO){
	 	exit(1);
	 }

 printf("AccO \n" );
 ktoken = yylex();
	  if(ktoken != FLoat) {
     //cout << vtoken << endl ;
		//	printf("Sortie reaction");
	 	 exit(1);
	 	 //ntoken = yylex();


	  }

	  printf("FLoat \n" );
		vtoken = yytext ;
		std::string fr(vtoken);
		float f =std::stof(fr);
		reaction.proba = f ;
		int abbes = yylex();
		if(abbes != AccF) {
		//	printf("WHY ? \n" );
		//	printf("%d\n", abbes);
	 	 exit(1);
	 	 //ntoken = yylex();


	  }
printf("AccF \n" );

if(yylex() != PointVirgule) {
 exit(1);
 //ntoken = yylex();


}
reactions.push_back(reaction);
printf("PointVirgule \n" );
printf("Fin de La Reaction \n" );

}

using namespace std;
int main(void)
{
	// Set up random number generators
	 unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	 std::mt19937 generator (seed);
	 std::uniform_real_distribution<double> uniform01(0.0, 1.0);
	 // methode monte carlo resultat dans un fichier csv
	ofstream myfile;
	myfile.open ("resultat.csv");
	int ntoken;


ntoken = yylex();
while(ntoken){


	   switch (ntoken) {

		case taille:
		   printf("Taille \n" );
			if(yylex() == Egal) {
				//ntoken = yylex();
				printf("Egal \n");

				if(yylex() == INTEGER) {

						std::string rk(vtoken);
						int i=std::stoi(rk);
						t = i ;
					//	printf("%d\n",t);
						printf("INTEGER \n" );

					if(yylex() == PointVirgule) {
						printf("PointVirgule \n");
			}
		}
		}

			else {
				printf("Syntax error in line %d,%s", yylineno, yytext);
				return 1;
			}
break;

case molecule:
  printf("\nMolecule \n" );
if(yylex() == Identificateur) {
	printf("Identificateur de Type Moluculaire \n" );

	//ntoken = yylex();
	vtoken = yytext ;
	std::string str(vtoken);
	TypeMolecule tm;
	tm.name = str;
	mapOfTypeMolecule.insert(std::make_pair(str,tm));
  recmolecule();

}
	else {
		printf("Syntax error in line %d,%s", yylineno, yytext);
		return 1;
	}
break;
case vitesse:
printf("\nVitesse\n" );
if(yylex() == SepO) {
	//ntoken = yylex();
	printf("parenthese \n" );

	if(yylex() == Identificateur) {
			printf("Identificateur Type Moluculaire \n" );
			vtoken = yytext ;
			std::string st(vtoken);
	//		std::cout<<st<<" +++++"<<std::endl;
			TypeMolecule &tm = mapOfTypeMolecule.at(st);


			if(yylex() == SepF) {
					printf("parenthese \n" );
					if(yylex() == Egal) {
							printf("Egal \n" );
							if(yylex() == FLoat) {
								vtoken =yytext ;
								std::string fs(vtoken);
								float f=std::stof(fs);
								tm.vitese = f ;
		//						printf("%2f\n",f );
									printf("FLoat \n" );
									if(yylex() == PointVirgule) {
											printf("PointVirgule \n" );
								}
		}}

}
}

}
else {
	printf("Syntax error in line %d,%s", yylineno, yytext);
	return 1;
}
break;
case diametre:
  printf("\nDiametre\n");
	if(yylex() == SepO) {
		//ntoken = yylex();
		printf("parenthese \n" );

		if(yylex() == Identificateur) {
				printf("Identificateur Type Moluculaire\n" );
				vtoken = yytext ;
				std::string sr(vtoken);
				TypeMolecule &tm = mapOfTypeMolecule.at(sr);


				if(yylex() == SepF) {
						printf("parenthese \n" );
						if(yylex() == Egal) {
								printf("Egal \n" );
								if(yylex() == FLoat) {
									vtoken = yytext ;
									std::string sk(vtoken);
                  float f=std::stof(sk);
									tm.diam = f ;
			//						printf("%2f\n",f );
										printf("FLoat \n" );
										if(yylex() == PointVirgule) {
												printf("PointVirgule \n" );
									}
			}}

}
}

}
	else {
		printf("Syntax error in line %d,%s", yylineno, yytext);
		return 1;
	}
break;

case Identificateur :
printf("\nDebut des Reaction \n" );
// printf("AAAABBBBBBCCCCC %s\n",vtoken );
if(mapOfTypeMolecule.find(vtoken) != mapOfTypeMolecule.end()){

//  printf("A = %s\n ",vtoken );
  printf("Identificateur type Moluculaire A \n" );
	reaction.A = &(mapOfTypeMolecule.find(vtoken)->second) ;
}
reactionpr();
break ;

case pop :
printf("\nPopulation\n");
if(yylex() == SepO) {
	//ntoken = yylex();
	printf("parenthese \n" );

	if(yylex() == Identificateur) {
			printf("Identificateur Type Moluclaire \n" );
			vtoken = yytext ;
			std::string kk(vtoken);
			TypeMolecule &tm = mapOfTypeMolecule.at(kk);
			if(yylex() == SepF) {
					printf("parenthese \n" );
					if(yylex() == Egal) {
							printf("Egal \n" );
							if(yylex() == INTEGER) {
								vtoken = yytext ;
								std::string rk(vtoken);
								int i=std::stoi(rk);
								tm.ppp = i ;
							//	printf("%d\n",i );
									printf("INTEGER \n" );
									if(yylex() == PointVirgule) {
											printf("PointVirgule \n" );
								}
		}}

}
}
printf("\n" );
}
else {
	printf("Syntax error in line %d,%s", yylineno, yytext);
	return 1;
}
break;
	default:
			printf("Syntax error in line %d\n",yylineno);
		}
		ntoken = yylex();
}

/////////////////////////debut affichage type moleculle //////////////////


std::map<std::string,TypeMolecule>::iterator iz = mapOfTypeMolecule.begin();
	 while(iz != mapOfTypeMolecule.end())
	 {
		    std::cout<<""<<endl ;
        std::cout<<"Nom ->"<<iz->second.name<< " " ;
				std::cout<<"Diametre ->"<<iz->second.diam<< " " ;
				std::cout<<"Vitesse ->"<<iz->second.vitese<< " " ;
				std::cout<<"Pop ->"<<iz->second.ppp<< " " ;
        std::cout<<""<<endl ;

			 iz++;
}

//////////////////////fin///////////////////////



/////////////// debut affichage reaction ///////////
// afficher les reactions avec leur probabilité

int iter;
    for (vector<Reaction>::iterator iter = reactions.begin();
         iter != reactions.end(); ++iter){
    Reaction &r = *iter;

if (r.B){
	cout << r.A->name << " + ";
	cout << r.B->name << " -> ";
}
else {
	cout << r.A->name << " -> ";
}


		if(r.D){
			cout << r.C->name << " + ";
			cout << r.D->name<<" " << "[ "<< r.proba <<" ]"<< endl;
}
else {
	cout << r.C->name<<" " << "[ "<< r.proba <<" ]"<< endl;
}
}

/////////////////////fin /////////////////////



// ////////////debut fichier csv  ////////////////////////

printf("Methode Monte Carlo \n\n" );
std::map<std::string,TypeMolecule>::iterator ia = mapOfTypeMolecule.begin();
	 while(ia != mapOfTypeMolecule.end())
	 {
        std::cout<<ia->second.name<< "," ;

        myfile <<ia->second.name<< "," ;

			 ia++;
}

std::cout<<""<<endl ;
myfile <<""<<endl ;



std::map<std::string,TypeMolecule>::iterator ik = mapOfTypeMolecule.begin();
	 while(ik != mapOfTypeMolecule.end())
	 {
        std::cout<<ik->second.ppp<< "," ;

        myfile <<ik->second.ppp<< "," ;

			 ik++;
}

std::cout<<""<<endl ;
myfile <<""<<endl ;


/////////////fin fichier csv ///////



////////////// debut methode monte carlo////////////
/// methode monte carlo plusieurs etapes (10ms * 10 )

for (size_t i = 0; i < 15000; i++) {

	etape() ;

std::map<std::string,TypeMolecule>::iterator it = mapOfTypeMolecule.begin();
	 while(it != mapOfTypeMolecule.end())
	 {

			// std::cout<<it->second.ppp<<",";
       myfile <<it->second.ppp<< "," ;
			 it++;
}
//std::cout<<""<<endl ;
myfile <<""<<endl ;

}


/////////////////////////////////// fin /////////////////////////



///////////////////// debuuuuuuuuuuuuuut //////////////////////
// methode multi agent creation pour chaque type de molecules des molecules en fonction de la
//population de chaque type moleculaire et on donne aleatoirement une position a chaque molecule
// dans la sphere
/*

printf("Creation des Molecule \n\n");
std::map<std::string,TypeMolecule>::iterator it = mapOfTypeMolecule.begin();
	 while(it != mapOfTypeMolecule.end())
	 {

				if(mapOfTypeMolecule.find(it->second.name) != mapOfTypeMolecule.end()){

					mollecule.typMol = &(mapOfTypeMolecule.find(it->second.name)->second) ;

				}

				for (size_t i = 0; i < it->second.ppp; i++) {

			  double theta = 2 * M_PI * uniform01(generator);
			  double phi = M_PI * uniform01(generator);
			  double x = (sin(phi) * cos(theta));
			  double y = (sin(phi) * sin(theta));
			  double z = (cos(phi));
				//  on multiplie fois le rayon
        mollecule.p.x = x * 0.25 ;
        mollecule.p.y = y * 0.25 ;
        mollecule.p.z = z * 0.25 ;

			 molecules.push_back(mollecule) ;

				}

		 it++;
}



int iner;
    for (vector<Molecule>::iterator iner = molecules.begin();
         iner != molecules.end(); ++iner){
    Molecule &m = *iner;
		cout << "Molecule " << m.typMol->name << "  "<< m.typMol->vitese << "  "
		<< m.p.x << "  " << "  "<< m.p.y << "  "<< m.p.z << endl;


}

*/
/////////////////////// fin //////////////////////////////




myfile.close();

//////////////////////////// debut///////////////////////////////
// methode multi agent plusieurs fois

/*
for (size_t i = 0; i < 10; i++) {

MultiAgent();



}
*/
/////////// fiiiiiiiiiiin /////////////////////////////
	return 0;
}
