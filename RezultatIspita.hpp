#pragma once
#include <iostream>
#include"Datum.hpp"

class RezultatIspita{
  public:
RezultatIspita(int index,int ocjena,std::string nazivPredmeta,Datum datum);

std::string nazivPredmeta() const{
return nazivPredmeta_;
}
int index() const{
return index_;
}
int ocjena() const{
return ocjena_;}

Datum datum(){
return datum_;
}
  private:
  int index_;
  int ocjena_;
  std::string nazivPredmeta_;
  Datum datum_;
};

