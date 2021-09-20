#include <iostream>
#include <vector>

struct Particule
 {
  virtual void affiche() = 0 ;
  virtual ~Particule() = default ;
 } ;

struct Electron : public Particule
 { virtual void affiche(){ std::cout<<"E"<<std::endl ; } } ;

struct Proton : public Particule
 { virtual void affiche(){ std::cout<<"P"<<std::endl ; } } ;

struct Neutron : public Particule
 { virtual void affiche(){ std::cout<<"N"<<std::endl ; } } ;

int main()
 {
  std::vector<Particule *> ps =
   { new Electron, new Proton, new Neutron } ;

  for ( auto p : ps )
   { p->affiche() ; }
 }