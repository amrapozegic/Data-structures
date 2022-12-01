#include "Meni.hpp"

void Meni::dodajNovogaStudenta(){
int index;
std::string ime,prezime;
std::cout << "Unesite broj indexa od studenta kojeg želite da dodate" << std::endl;
std::cin >> index;
std::cout << "Unesite ime studenta" << std::endl;
std::cin >> ime;
std::cout << "Unesite prezime od studenta" << std::endl;
std::cin >> prezime;
popisStudenata_.emplace(index,Student(index,ime,prezime));
}

void Meni::dodajIspit(){
  std::string nazivPredmeta;
  int dan,mjesec,godina;
  std::cout <<"Unesite datum na koji je održan ispit u formi dan-mjesec-godina"<< std::endl;
  std::cin >> dan;
  std::cin.ignore(1,'-');
  std::cin >> mjesec;
  std::cin.ignore(1,'-');
  std::cin >> godina;
  Datum datum(dan,mjesec,godina);
  std::cout << "Sada unesite naziv predmeta iz kojeg je ispit održan" << std::endl;
  std::cin >> nazivPredmeta;
  popisIspita_[datum.datumZaMapu()].push_back(Ispit(datum,nazivPredmeta));
}

void Meni::dodajPredmet(){
  std::string nazivPredmeta;
  std::cout << "Unesite naziv predmeta" << std::endl;
  std::cin >> nazivPredmeta;

popisPredmeta_.emplace(nazivPredmeta,Predmet(nazivPredmeta));
}


void Meni::dodajRezultat(){
std::cout <<"Molim vas unesite datum za koji želite dodat rezultat u formi dan-mjesec-godina "<<std::endl;
int temp1,temp2,temp3;
std::cin >> temp1;
std::cin.ignore(1,'-');
std::cin >> temp2;
std::cin.ignore(1,'-');
std::cin >> temp3;
Datum datum(temp1,temp2,temp3);
std::string nazivPredmeta;
std::cout << "Sada unesite naziv predmeta" << std::endl;
std::cin >> nazivPredmeta;
std::cout << "Index studenta" << std::endl;
std::cin >> temp1;
std::cout << "Ocjenu koju je dobio student: " << std::endl;
std::cin >> temp2;
rezultati_[datum.datumZaMapu()][nazivPredmeta].push_back(RezultatIspita(temp1,temp2,nazivPredmeta,datum));
if (temp2>=6)
  popisStudenata_[temp1].polozeniIspit(RezultatIspita(temp1,temp2,nazivPredmeta,datum));
}

void Meni::dohvatiIspitePoDatumu(){
std::cout <<"Molim vas unesite datum za koji želite dohvatit ispite u formi dan-mjesec-godina"<<std::endl;
int dan,mjesec,godina;
std::cin >> dan;
std::cin.ignore(1,'-');
std::cin >> mjesec;
std::cin.ignore(1,'-');
std::cin >> godina;
Datum datum(dan,mjesec,godina);

std::vector<Ispit> collector=popisIspita_[datum.datumZaMapu()];
if(collector.size()==0){
  std::cout << "Na ovaj dan nije održan niti jedan ispit" << std::endl;}
else{
  std::cout << "Na ovaj dan su održani sledećih predmeta:" << std::endl;
for(auto& ispit:collector){
std::cout << ispit.nazivPredmeta() << std::endl;
}

}
}

void Meni::dohvatiStudenteKojiSuPolozili(){
std::cout <<"Molim vas unesite datum za koji želite dohvatit ispite u formi dan-mjesec-godina"<<std::endl;
int temp1,temp2,temp3;
std::string predmet;
std::cin >> temp1;
std::cin.ignore(1,'-');
std::cin >> temp2;
std::cin.ignore(1,'-');
std::cin >> temp3;
Datum datum(temp1,temp2,temp3);
std::cout << "Unesite ime predmeta" << std::endl;
std::cin >> predmet;
std::unordered_map<std::string,std::vector<RezultatIspita>> ispiti=rezultati_[datum.datumZaMapu()];
std::vector<RezultatIspita> rezultati=ispiti[predmet];
if(rezultati.size()==0)
  std::cout << "Nema ispita za ovaj datum" << std::endl;
else{
  std::cout << "Studenti koji su položili ispit na ovaj dan: " << std::endl;
for(auto& rezultat:rezultati) 
 if(rezultat.ocjena()>5)
  std::cout << popisStudenata_[rezultat.index()].imePrezime() <<" Ocjena: " <<rezultat.ocjena()<< std::endl;
}
}


void Meni::dohvatiSvePolozeneIspiteStudenta(){
int brIndex;
std::cout << "Unesite broj indexa" << std::endl;
std::cin >> brIndex;
popisStudenata_[brIndex].dohvatiPolozeneIspiteProsjek();
}


