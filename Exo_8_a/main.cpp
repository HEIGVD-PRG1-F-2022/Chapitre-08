#include <array>
#include <iostream>

using namespace std;

// Créer la méthode pour afficher un array ici.

int main() {
  array<int, 4> a{2, 7, 1, 8};
  affichage(a);

  array<double, 8> b{1, 1, 2, 3, 5, 8, 13, 21};
  affichage(b);
  return 0;
}
