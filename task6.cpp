#include "iostream"
#include "cmath"
#include "cstdlib"
#include "ctime"

using namespace std;

double getRandomNumber(double minimum, double maximum)
{
    double randZeroOne = rand()/static_cast<double>(RAND_MAX);
    double randInterval = randZeroOne * (maximum - minimum);
    double randMinMax = randInterval + minimum;
    return randMinMax;
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int n = 0;
    int N = 10000000;
    double R ;

    cout << "Enter radius" << endl;
    cin >> R;

    for (int i = 0; i < N; i++)
    {
        double x = getRandomNumber(-R, R);
        double y = getRandomNumber(-R, R);
        if (pow(x, 2) + pow(y, 2) <= pow(R, 2))
        {
        n += 1;
        }
    }
    cout << "pi is ~ " <<  4 * (double)n/(double)N;
    }

class ArrayInt
{
    private:
        int m_length;
        int *m_ptr;
    public:
        ArrayInt(int length = 0, int *ptr = nullptr);
        ArrayInt(int len)
        {
            m_length = len;
            int *arr = new int[m_length];
            m_ptr = arr;
        };
        ~ArrayInt()
        {
            delete[] m_ptr;
        };
    void reallocate(int newlength)
    {
        delete[] m_ptr;
        int *m_ptr = new int[newlength];
    }
    void insertBefore(int value, int index)
    {
        int *newar = new int[m_length + 1];
        for(int i = 0; i < index; i++)
        {
            newar[i] = m_ptr[i];
        }
        newar[index - 1] = value;
        for(int i = index; i < m_length + 1; i++)
        {
            newar[i] = m_ptr[i - 1];
        }
        delete[] m_ptr;
        m_ptr = newar;

    }
};
