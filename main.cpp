#include "Meni.hpp"

int main() {
  Meni meni;
  int izbor;

  while (true) {
    std::cout << "Odaberite jednu od opcija" << std::endl;
    std::cout << "1. Dodajte novog studenta" << std::endl;
    std::cout << "2. Dodajte novi ispit" << std::endl;
    std::cout << "3. Dodajte novi predmet" << std::endl;
    std::cout << "4. Dodajte novi rezultat ispita "
              << std::endl;
    std::cout << "5. Dohvatite sve ispite za određeni datum " << std::endl;
    std::cout << "6. Dohvatite po datumu i imenu predmeta sve studente koji su "
                 "položili ispit"
              << std::endl;
    std::cout << "7. Dohvatite po indexu sve ispite koje je student položio "
                 "hronološki te prosječnu ocjenu"
              << std::endl;
    std::cin >> izbor;

    switch (izbor) {
      case 1:
        meni.dodajNovogaStudenta();
        break;
      case 2:
        meni.dodajIspit();
        break;
      case 3:
        meni.dodajPredmet();
        break;
      case 4:
        meni.dodajRezultat();
        break;

      case 5:
        meni.dohvatiIspitePoDatumu();
        break;
      case 6:
        meni.dohvatiStudenteKojiSuPolozili();
        break;
      case 7:
        meni.dohvatiSvePolozeneIspiteStudenta();
        break;
      default:
        std::cout << "Vaš izbor mora biti validan" << std::endl;
        break;
    }
  }
  return 0;
}
