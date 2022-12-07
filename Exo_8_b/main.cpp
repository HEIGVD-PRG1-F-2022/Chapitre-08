#include <array>
#include <iostream>

using namespace std;

// Définir la class NTuple ici

// La sortie de `main` doit être:
// 0,0,2,3
// 1,5,3,2
// 1,5,5,5
// Sans modifier `main`!
int main() {
  NTuple<int, 4> a, b(array<int, 4>{1, 2, 3, 4});
  a.set(2, 2);
  a.set(3, 3);
  b.set(1, 5);
  b.set(3, 2);
  a.affichage();
  cout << endl;
  b.affichage();
  cout << endl;
  (a + b).affichage();
  cout << endl;
  return 0;
}
