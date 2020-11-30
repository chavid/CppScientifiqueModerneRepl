#include <iostream>
#include <cassert>

// ... my_narrow ...
 
int main()
 {     
  double d1 = 42 ;
  int i1 = my_narrow<int>(d1) ;
  std::cout<<i1<<std::endl ;
    
  double d2 = 3.14 ;
  int i2 = my_narrow<int>(d2) ;
  std::cout<<i2<<std::endl ;
 }