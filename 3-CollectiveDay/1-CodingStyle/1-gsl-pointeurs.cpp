#include <iostream>
#include <type_traits>

class Demo
 {
  public:
    Demo() { std::cout<<"Constructeur"<<std::endl ; }
    void affiche() { std::cout<<"Affichage"<<std::endl ; }
    ~Demo() { std::cout<<"Destructeur"<<std::endl ; }
 } ;


//... my_owner ...

//... my_not_null ...

int main()
 {
  //my_owner<Demo> d1 ;              // ERREUR DE COMPILATION, car Demo n'est pas un pointeur
  //my_not_null<Demo*> p1 ;          // ERREUR DE COMPILATION, car p1 n'a pas de valeur initiale
  //my_not_null<Demo*> p2(nullptr) ; // ERREUR DE COMPILATION, car p2 ne peut pas être nul
  my_owner<Demo *> d2 = new Demo() ;
  my_not_null<Demo *> p3 = d2 ; 
  //p3 = nullptr ;                   // ERREUR D'EXECUTION, car p3 ne peut pas être nul
  p3->affiche() ;
  delete d2 ;
 }