#include"Ispit.hpp"

  Ispit::Ispit(Datum datum,std::string nazivPredmeta)
  :datumIspita_{datum},nazivPredmeta_{nazivPredmeta}{}
    
  Datum Ispit::datum(){
  return datumIspita_;
  }
  std::string Ispit::nazivPredmeta(){
  return nazivPredmeta_;
  }
  


