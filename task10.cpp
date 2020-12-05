#include <iostream>
using namespace std;

/*template <typename... T>
auto memSum(T... s)
{
    return(... +sizeof(s));
}

int main()
{
    cout << memSum(1, "Hi", 2) <<endl;
    return 0;
}

struct Item
{
    int a, b, c;
    Item(int a, int b, int c): a(a), b(b), c(c){}
};

template <typename T>
int create(T it)
{
    T *res = new T;
    return res;
}

int main()
{
    Item it{1, 2, 3};
    int b = ::create<Item>(it);
    cout << b;
}         */

#include "cmath"
#include "iostream"
#include <utility>
#include "string"
#include "sstream"

using namespace std;
template <typename T>
class Figure
{
    public:
        double perimeter();
        double area();
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
/*class Circle: public Ellipse
{
    private:
             double m_rad;
    public:
        Circle(double rad) :Ellipse(rad, rad){m_rad = rad;};
        virtual double area()
        {
            return Ellipse::area();
        }
        virtual double perimeter()
        {
            return Ellipse::perimeter();
        }
        virtual ostream& print(ostream& out)
        {
            out << "Circle, ";
            out << "Radius " << m_rad << ", ";
            out << "perimeter " << perimeter() << ", ";
            out << "area " << area() << endl;
            return out;
        }
        friend ostream& operator<< (ostream &out, Circle &c)
        {
            c.print(out);
            return out;
        }
};
class Triangle: public Polygon
{
    public:
        Triangle(int numVertices, string pointsStr)
        :Polygon(numVertices, pointsStr)
        {}
        virtual double area()
        {
            return Polygon::area();
        }
        virtual double perimeter()
        {
            return Polygon::perimeter();
        }
        virtual ostream& print(ostream& out)
        {
            out << "Triangle, ";
            out << "perimeter " << perimeter() << ", ";
            out << "area " << area() << endl;
        }
        friend ostream& operator<< (ostream &out, Triangle &t)
        {
            t.print(out);
            return out;
        }
};*/

int main()
{
