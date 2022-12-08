#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T> class C {
public:
  C(T t) : t(t){};
  void afficher() const;

private:
  T t;
};

template <typename T> void C<T>::afficher() const { cout << t; }

/// Solution la plus simple en utilisant une spécialisation de la méthode
/// 'afficher'.
template <> void C<int*>::afficher() const { cout << t; }

int main() {
  int n = 1;
  C<int> c1(n);
  c1.afficher();
  cout << endl;
  C<int *> c2(&n);
  c2.afficher();
  cout << endl;
  C<const char *> c3("Hello");
  c3.afficher();
  cout << endl;
  return EXIT_SUCCESS;
}

// Autre solution en faisant une spécialisation de la classe.
// L'avantage est que ça marchera aussi pour les 'double' et autres.
// Ici on prend un autre nom pour que ça passe dans la compilation.
// Donc voici la classe D comme avant:
template <typename T> class D {
public:
  D(T t) : t(t){};
  void afficher() const;

private:
  T t;
};

template <typename T> void D<T>::afficher() const { cout << t; }

// Et on spécialise la classe D en faisant une classe utilisant un pointeur.
// Attention: le pointeur doit aller dans la déclaration de la classe et pas
// dans le 'typename':
template <typename T> class D<T *> {
public:
  D(T *t) : t(t){};
  void afficher() const;

private:
  T *t;
};

// Utilisant une déréférence pour afficher les valeurs des pointeurs:
template <typename T> void D<T *>::afficher() const { cout << *t; }
// Attention: pour les char*, la déréférence ne va imprimer que le premier
// charactère, donc ici on doit spécialiser la spécialisation:
template <> void D<const char *>::afficher() const { cout << t; }
