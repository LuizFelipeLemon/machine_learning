#ifndef _VECTOR_CLASS_LUIZ_
#define _VECTOR_CLASS_LUIZ_

template <class Any>
/// O tipo de dados "lista_valor"
class vector {
  private:
    ///  Numero de valores armazenados na lista
    unsigned N;
    /// Array dinamico (ponteiro) com os valores armazenados
    Any *x;
  public:
    /// Construtores e destrutores
    inline vector(): N(0), x(NULL) {}

    explicit vector(unsigned int Num);

    vector(const vector &L);

    ~vector();
    /// Operador de atribuicao
    void operator=(const vector &L);

    /// Consulta
    inline unsigned getSize() const {
      return N;
    }

    Any operator[](unsigned i) const;

    inline Any primeiro(void) const {
      return operator[](0);
    }

    /// Inclusao e exclusao de valores
    void push_back(Any V);
    void remove_first(void);

};



/// Construtor especifico
template <class Any>
vector<Any>::vector(unsigned int Num): N(Num)
{
  x = (N == 0 ? NULL : new Any[N]);
}

/// Destrutor
template <class Any>
vector<Any>::~vector(void)
{
  if (x != NULL) delete[] x;
}

/// Construtor por copia
template <class Any>
vector<Any>::vector(const vector &L): N(L.N)
{
  x = (N == 0 ? NULL : new Any[N]);
  for (unsigned i = 0; i < N; i++) x[i] = L.x[i];
}

/// Operador de atribuicao
template <class Any>
void vector<Any>::operator=(const vector<Any> &L)
{
  /// Nao faz nada se o usuario estah fazendo uma autoatribuicao (A=A)
  if (this != &L)
  {
    /// Primeiro, faz uma operacao equivalente ao destrutor
    if (x != NULL) delete[] x;
    /// Depois, faz operacoes equivalentes ao construtor por copia
    N = L.N;
    x = (N == 0 ? NULL : new Any[N]);
    for (unsigned i = 0; i < N; i++) x[i] = L.x[i];
  }
}
template <class Any>
Any vector<Any>::operator[](unsigned i) const
{
  if (i >= N)
  {
    // "Indice invalido\n";
    return 0;
  }
  return x[i];
}

template <class Any>
void vector<Any>::push_back(Any V)
{
  Any *prov = new Any[N + 1];
  for (unsigned i = 0; i < N; i++) prov[i] = x[i];
  prov[N] = V;
  if (x != NULL) delete[] x;
  x = prov;
  N++;
}

template <class Any>
void vector<Any>::remove_first(void)
{
  if (N == 0)
  {
    //"Lista vazia. Nao hah o que remover\n";
    return;
  }
  N--;
  Any *prov = (N == 0 ? NULL : new Any[N]);
  for (unsigned i = 0; i < N; i++) prov[i] = x[i + 1];
  delete[] x;
  x = prov;
}


#endif // _ARMAZENADOR_H_


