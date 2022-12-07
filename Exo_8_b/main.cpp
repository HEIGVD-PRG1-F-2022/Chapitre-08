#include <array>
#include <iostream>
#include <iterator>

using namespace std;

template <typename T, size_t N> class NTuple {
  std::array<T, N> list;

public:
  NTuple();
  NTuple(std::array<T, N> array);
  void set(size_t index, T value);

  void affichage();

  NTuple &operator+=(const NTuple &lhs);

  friend NTuple operator+(NTuple lhs, const NTuple &rhs) { return lhs += rhs; }

  // Ou alors, en séparé:

  template <typename T_, size_t N_>
  friend NTuple<T_, N_> operator-(NTuple<T_, N_> lhs,
                                  const NTuple<T_, N_> &rhs) {
    for (size_t i = 0; i < N; i++) {
      lhs.list.at(i) -= rhs.list.at(i);
    }
    return lhs;
  }
};

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

template <typename T, size_t N>
NTuple<T, N>::NTuple(): NTuple(array<T, N>()){};

template <typename T, size_t N>
NTuple<T, N>::NTuple(std::array<T, N> list): list(list){};


template <typename T, size_t N> void NTuple<T, N>::set(size_t index, T value) {
  list.at(index) = value;
}

template <typename T, size_t N> void NTuple<T, N>::affichage() {
  for (const auto &l: list){
    cout << l << (&l == list.end() - 1 ? "" : ",");
  }
  cout << endl;
}

template <typename T, size_t N>
NTuple<T, N> &NTuple<T, N>::operator+=(const NTuple<T, N> &lhs) {
  for (size_t i = 0; i < N; i++) {
    list.at(i) += lhs.list.at(i);
  }
  return *this;
}

template <typename T, size_t N>
NTuple<T, N> operator+(NTuple<T, N> lhs, const NTuple<T, N> &rhs) {
  return lhs += rhs;
}

// Définition de la class NTuple ici
