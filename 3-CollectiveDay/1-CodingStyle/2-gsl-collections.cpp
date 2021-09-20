#include <iostream>
#include <array>
#include <cassert>

// ... my_span ..

template <typename T>
void affiche( my_span<T> donnees )
 {
   for( std::size_t i = 0 ; i < donnees.size() ; ++i )
     std::cout << donnees[i] << ' ' ;
   std::cout << std::endl ;
 }
 
int main()
 {
  std::array<int,5> arr = { 1, 2, 3, 4, 5 } ;
  my_span<int> s { arr } ;
  affiche(s) ;  
  return 0 ;
}