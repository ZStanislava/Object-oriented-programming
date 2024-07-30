#include <iostream>
#include<iomanip>
using namespace std;
const int MAX_VECTOR_SIZE = 10;
const int MAX_MATRIX_SIZE = 10;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
    ValType* pVector;
    int Size;       // размер вектора
public:
    TVector(int s = 10);
    TVector(const TVector& v);                // конструктор копирования
    ~TVector();
    int GetSize() { return Size; } // размер вектора
    ValType& operator[](int pos);             // доступ
    int operator==(const TVector& v) const;   // сравнение
    int operator!=(const TVector& v) const;   // сравнение
    TVector& operator=(const TVector& v);     // присваивание

    // скалярные операции
    TVector operator+(const ValType& val);    // прибавить скаляр
    TVector  operator-(const ValType& val);   // вычесть скаляр
    TVector  operator*(const ValType& val);   // умножить на скаляр

    // векторные операции
    TVector  operator+(const TVector& v);     // сложение
    TVector  operator-(const TVector& v);     // вычитание
    ValType  operator*(const TVector& v);     // скалярное произведение
    friend TVector  vecMult(TVector& a, TVector& b) //векторное произведение для трехмерного вектора
    {
        if (a.GetSize() != b.GetSize() || a.GetSize() != 3)
            throw a.GetSize();
        TVector<ValType> v(3);
        v[0] = a[2] * b[1] - a[1] * b[2];
        v[1] = a[0] * b[2] - a[2] * b[0];
        v[2] = a[1] * b[0] - a[0] * b[1];
        return v;

    }
    // ввод-вывод
    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            in >> v.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            out << v.pVector[i] << ' ';
        return out << std::endl;
    }
};

template <class ValType>
TVector<ValType>::TVector(int s)
{
    if (s <= 0 || s > MAX_VECTOR_SIZE)
        throw s;
    Size = s;
    pVector = new ValType[Size];
}

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType>& v)
{
    pVector = new ValType[v.Size];
    Size = v.Size;
    for (int i = 0; i < Size; i++)
        pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector()
{
    delete[] pVector;
}

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
    if (pos < 0 || pos >= Size)
        throw pos;
    return pVector[pos];
}

template <class ValType> // сравнение
int TVector<ValType>::operator==(const TVector& v) const
{
    if (this != &v)
    {
        if (Size != v.Size)
            return -1;
        for (int i = 0; i < Size; i++)
            if (pVector[i] != v.pVector[i])
                return -1;
    }
    return 1;
}

template <class ValType> // сравнение
int TVector<ValType>::operator!=(const TVector& v) const
{
    return !(*this == v);
}

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
    if (this != &v)
    {
        if (Size != v.Size)
        {
            delete[] pVector;
            Size = v.Size;
            pVector = new ValType[Size];
        }
        for (int i = 0; i < Size; i++)
            pVector[i] = v.pVector[i];
    }
    return (*this);
}

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
    TVector<ValType> v(*this);
    for (int i = 0; i < v.Size; i++)
        v.pVector[i] += val;
    return v;
}

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
    TVector<ValType> v(*this);
    for (int i = 0; i < v.Size; i++)
        v.pVector[i] -= val;
    return v;
}

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
    TVector<ValType> v(*this);
    for (int i = 0; i < v.Size; i++)
        v.pVector[i] *= val;
    return v;
}

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
    if (Size != v.Size)
        throw v.Size;
    TVector<ValType> res(Size);
    for (int i = 0; i < Size; i++)
        res.pVector[i] = pVector[i] + v.pVector[i];
    return res;
}

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    if (Size != v.Size)
        throw v.Size;
    TVector<ValType> res(Size);
    for (int i = 0; i < Size; i++)
        res.pVector[i] = pVector[i] - v.pVector[i];
    return res;
}

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
    if (Size != v.Size)
        throw v.Size;
    ValType res = pVector[0] * v.pVector[0];
    for (int i = 1; i < Size; i++)
        res += pVector[i] * v.pVector[i];
    return res;
}

// матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:

    TMatrix(int s = 10);
    TMatrix(const TMatrix& mt);                    // копирование
    TMatrix(const TVector<TVector<ValType> >& mt); // преобразование типа
    int operator==(const TMatrix& mt) const;       // сравнение
    int operator!=(const TMatrix& mt) const;       // сравнение
    TMatrix& operator= (const TMatrix& mt);        // присваивание
    TMatrix  operator+ (const TMatrix& mt);        // сложение
    TMatrix  operator- (const TMatrix& mt);        // вычитание
    TMatrix  operator+ (const ValType& v);        // сложение со скаляром
    TMatrix  operator- (const ValType& v);        // вычитание со скаляром
    TMatrix  operator* (const ValType& v);        // умножить на скаляр
    TMatrix  operator* (const TMatrix& mt);        // умножить на матрица

    // ввод / вывод
    friend istream& operator>>(istream& in, TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            out << mt.pVector[i] << endl;
        return out;
    }
};
template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
    if (s <= 0 || s > MAX_MATRIX_SIZE)
        throw s;
    for (int i = 0; i < s; i++)
    {
        TVector<ValType> tmp(s);
        this->pVector[i] = tmp;
    }
}

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
int TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
    if (this != &mt)
    {
        if (this->Size != mt.Size)
            return -1;
        for (int i = 0; i < this->Size; i++)
        {
            if (this->pVector[i] != mt.pVector[i])
                return -1;
        }
    }
    return 1;
}

template <class ValType> // сравнение
int TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
    return !(*this == mt);
}

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
    if (this != &mt)
    {
        if (this->Size != mt.Size)
        {
            delete[] this->pVector;
            this->Size = mt.Size;
            this->pVector = new TVector <ValType>[this->Size];
        }
        for (int i = 0; i < this->Size; i++)
            this->pVector[i] = mt.pVector[i];
    }
    return(*this);
}
template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
    return TVector<TVector<ValType>>::operator+(mt);
}
template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
    return TVector<TVector<ValType>>::operator-(mt);
}
template <class ValType> // умножить на скаляр
TMatrix<ValType> TMatrix<ValType>::operator*(const ValType& v)
{
    TMatrix<ValType> tmp(*this);
    for (int i = 0; i < this->Size; i++)
        tmp.pVector[i] = this->pVector[i] * v;
    return tmp;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+ (const ValType& v)
{
    TMatrix<ValType> tmp(*this);
    for (int i = 0; i < this->Size; i++)
        tmp.pVector[i] = this->pVector[i] + v;
    return tmp;
}
template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator- (const ValType& v)
{
    TMatrix<ValType> tmp(*this);
    for (int i = 0; i < this->Size; i++)
        tmp.pVector[i] = this->pVector[i] - v;
    return tmp;
}
template <class ValType> // умножение на матрицу
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix<ValType>& mt)
{
    TMatrix<ValType> res(*this);
    for (int i = 0; i < this->Size; i++)
    {
        for (int j = i; j < this->Size; j++)
        {
            res.pVector[i][j] = 0;
            for (int k = i; k < (j + 1); k++)
                res.pVector[i][j] += this->pVector[i][k] * mt.pVector[k][j];
        }
    }
    return res;
}
