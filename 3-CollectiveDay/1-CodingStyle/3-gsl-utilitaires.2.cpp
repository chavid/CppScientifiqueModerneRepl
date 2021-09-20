#include <iostream>
 
// ... struct ActionFinale ...
 
// ... my_finally ...

int main()
 {     
  std::cout<<"Etape 1"<<std::endl ;
  auto _ = my_finally([](){ std::cout<<"Etape 3"<<std::endl ; }) ;
  std::cout<<"Etape 2"<<std::endl ;
 }