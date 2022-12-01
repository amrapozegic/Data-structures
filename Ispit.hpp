#include <iostream>

#include"Datum.hpp"

class Ispit{
public:
Ispit(Datum datum,std::string nazivPredmeta);

Datum datum();

std::string nazivPredmeta();
  
private:
  Datum datumIspita_;
  std::string nazivPredmeta_;
};

