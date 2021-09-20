#include <complex>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

using Real = double ;
using Complex = std::complex<Real> ;
using Complexes = std::vector<Complex> ;

// random unitary complexes
void generate( Complexes & cs )
 {
  srand(20181118) ;
  for ( auto & c : cs )
   { 
    Real angle = rand()/(Real(RAND_MAX)+1)*2.0*M_PI ;
    c = Complex(cos(angle),sin(angle)) ;
   }
 }

// compute xs^degree and store it into ys
void complexes_pow
 ( int numtask, int nbtasks,
   const Complexes & xs, int degree, Complexes & ys )
 {
  int size = xs.size() ;
  int width = size/nbtasks ;
  width = size%nbtasks?width+1:width ;
  int min = numtask*width ;
  int max = (numtask+1)*width ;
  max = max<size?max:size ;
  for ( int i=min ; i<max ; ++i )
   {
    ys[i] = Complex(1.,0.) ;
    for ( int d=0 ; d<degree ; ++d )
     { ys[i] *= xs[i] ; }
   }
 }

// display the angle of the complexes global product
void postprocess( Complexes const & cs )
 {
  Complex prod(1.,0.) ;
  for( auto c : cs ) { prod *= c ; }
  double angle = atan2(prod.imag(),prod.real()) ;
  std::cout<<"result = "<<int(angle/2./M_PI*360.)<<"\n" ;
 }

// programme principal
int main ( int argc, char * argv[] )
 {
  assert(argc==4) ;
  int nbtasks = atoi(argv[1]) ;
  int dim = atoi(argv[2]) ;
  int degree = atoi(argv[3]) ;

  // prepare input
  Complexes input(dim) ;
  generate(input) ;
   
  // compute ouput
  Complexes output(dim) ;
  for ( int numtask=0 ; numtask<nbtasks ; ++numtask )
   { complexes_pow(numtask,nbtasks,input,degree,output) ; }
  
  // post-process
  postprocess(output) ;
 }