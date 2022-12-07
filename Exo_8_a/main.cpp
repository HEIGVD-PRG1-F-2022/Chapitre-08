#include <array>
#include <iostream>
#include <numeric>

using namespace std;

// Créer la méthode pour afficher un array ici.
template <typename T, size_t N> void affichage(array<T, N> list) {
  for (const auto &l: list){
    cout << l << (&l == list.end() - 1 ? "" : ",");
  }
  cout << endl;
}

int main() {
  array<int, 4> a{2, 7, 1, 8};
  affichage(a);

  array<int, 2> c{2, 7};
  affichage(c);

  array<double, 8> b{1, 1, 2, 3, 5, 8, 13, 21};
  affichage(b);
  return 0;
}
