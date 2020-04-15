//vashiot kod ovde
#include <iostream>

using namespace std;

class Matrica
{
private:
    int dimenzija;
    float** matrix;
public:
    Matrica(int dimenzija = 0)
    {
        if (dimenzija > 10)
            dimenzija = 10;
        matrix = new float* [dimenzija];
        for (size_t i = 0; i < dimenzija; i++)
        {
            matrix[i] = new float[dimenzija];
        }
    }

    Matrica(const Matrica& src)
        :dimenzija(src.dimenzija)
    {
        matrix = new float* [dimenzija];
        for (size_t i = 0; i < dimenzija; i++)
            matrix[i] = new float[dimenzija];

        for (size_t i = 0; i < dimenzija; i++)
        {
            for (size_t j = 0; j < dimenzija; j++)
            {
                matrix[i][j] = src.matrix[i][j];
            }
        }
    }

    Matrica& operator+(int n)
    {
        for (size_t i = 0; i < dimenzija; i++)
        {
            for (size_t j = 0; j < dimenzija; j++)
            {
                matrix[i][j] += n;
            }
        }
        return *this;
    }

    Matrica& operator-(const Matrica& src)
    {
        for (size_t i = 0; i < dimenzija; i++)
        {
            for (size_t j = 0; j < dimenzija; j++)
            {
                matrix[i][j] -= src.matrix[i][j];
            }

        }
        return *this;
    }

    Matrica operator*(const Matrica& src)
    {
        Matrica temp(dimenzija);
        for (size_t i = 0; i < temp.dimenzija; i++)
        {
            for (size_t j = 0; j < temp.dimenzija; j++)
            {
                temp.matrix[i][j] = 0;
                for (size_t k = 0; k < temp.dimenzija; k++)
                {
                    temp.matrix[i][j] = temp.matrix[i][j] + this->matrix[i][k] * src.matrix[k][j];
                }
            }

        }
        return temp;
    }

    Matrica& operator=(const Matrica& src)
    {
        if (this == &src)
            return *this;
        this->~Matrica();
        dimenzija = src.dimenzija;
        matrix = new float* [dimenzija];
        for (size_t i = 0; i < dimenzija; i++)
            matrix[i] = new float[dimenzija];

        for (size_t i = 0; i < dimenzija; i++)
        {
            for (size_t j = 0; j < dimenzija; j++)
            {
                matrix[i][j] = src.matrix[i][j];
            }
        }

        return *this;
    }

    ~Matrica()
    {
        for (size_t i = 0; i < dimenzija; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    friend ostream& operator<<(ostream& os, const Matrica& src)
    {
        for (size_t i = 0; i < src.dimenzija; i++)
        {
            for (size_t j = 0; j < src.dimenzija; j++)
            {
                os << src.matrix[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Matrica& src)
    {
        int x;
        is >> x >> x;

        if (x > 10)
            x = 10;

        src.dimenzija = x;

        src.matrix = new float* [src.dimenzija];
        for (size_t i = 0; i < src.dimenzija; i++)
        {
            src.matrix[i] = new float[src.dimenzija];
        }

        for (size_t i = 0; i < src.dimenzija; i++)
        {
            for (size_t j = 0; j < src.dimenzija; j++)
            {
                is >> src.matrix[i][j];
            }
        }
        return is;
    }
};

int main()
{
    Matrica A, B, C;
    cin >> A >> B >> C;
    Matrica D = B * C;
    Matrica R = A - D + 2;
    cout << R;
}