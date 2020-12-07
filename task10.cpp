#include "cmath"
#include "iostream"
#include <utility>
#include "string"
#include "sstream"

using namespace std;

№1
template <typename... T>
auto memSum(T... s)
{
    return(... +sizeof(s));
}

int main()
{
    cout << memSum(1, "Hi", 2) <<endl;
    return 0;
}
№2
template<typename T>
auto pointer(T arg)
{
T *ptr = new T(arg);
return(ptr);
}

template<typename T, typename... Types>
auto pointer(T first, Types... args)
{
pointer(first);
pointer(args...);
}

int main()
{
cout << pointer("hello") << endl;
}

№3
template<typename T, typename... Type>
auto lms(T (*func)(Type...), Type... args)
{
return func(args...);
}


№4
template <typename T>
class Figure
{
    public:
        double n_perimeter()
        {
            self()->perimeter()
        };
        double n_area()
        {
            self()->area()
        };
        ostream& print (ostream &out) {return out;}
        friend ostream& operator<< (ostream &out, Figure &f)
            {
            f.print(out);
            return out;
            }
};
class Ellipse: public Figure<Ellipse>
{
    friend class Figure<Ellipse>;
private:
    double m_a;
    double m_b;
public:
    Ellipse(double a, double b)
    {
        m_a = a;
        m_b = b;
    }
    double area(){return M_PI * m_a * m_b;};
    double perimeter(){return (4 * M_PI * m_a * m_b + (m_a - m_b))/(m_a + m_b);};
    ostream& print(ostream& out)
    {
        out << "Ellipse, ";
        out << "a " << m_a << ", ";
        out << "b " << m_b << ", ";
        out << "perimeter " << perimeter() << ", ";
        out << "area " << area() << endl;
        return out;
    }
};

class Polygon: public Figure<Polygon>
{
        friend class Figure<Ellipse>;
    private:
        int m_numVertices;
        pair<double, double> *points;
    public:
        Polygon(int numVertices, string pointStr)
        {
            m_numVertices = numVertices;
            points = new pair<double, double>[m_numVertices];

            stringstream ss;
            ss << pointStr;
            for (int i = 0; i<numVertices; i++)
            {
                ss >> points[i].first;
                ss >> points[i].second;
            }
        }
        double area()
        {
            double sum1 = 0;
            double sum2 = 0;
            double S;
            for(int i = 1; i < m_numVertices ; i++)
            {
                sum1 += points[i - 1].first * points[i].second;
                sum2 += points[i].first * points[i - 1].second;

            }
            S = 0.5 * abs(sum1 + points[m_numVertices - 1].first * points[0].second - sum2 - points[m_numVertices - 1].second * points[0].first);
            return S;
        }
        double perimeter()
        {
            double sum1 = 0;
            double P;
            for(int i = 1; i < m_numVertices ; i++)
            {
                sum1 += sqrt(pow(points[i - 1].first - points[i].first, 2) + pow(points[i - 1].second - points[i].second, 2));

            }
            P = sum1 + sqrt(pow(points[m_numVertices - 1].first - points[0].first, 2) + pow(points[m_numVertices - 1].second - points[0].second, 2));
            return P;
        }
        ostream& print(ostream& out)
        {
            out << "Polygon, ";
            out << "Number of vertices " << m_numVertices << ", ";
            out << "perimeter " << perimeter() << ", ";
            out << "area " << area() << endl;
        }

};

