#include "cmath"
#include "iostream"
#include <utility>
#include "string"
#include "sstream"

using namespace std;

class Figure
{
    public:
        virtual double perimeter() = 0;
        virtual double area() = 0;
        virtual ostream& print (ostream &out) {return out;}
        friend ostream& operator<< (ostream &out, Figure &f)
            {
            f.print(out);
            return out;
            }
};
class Ellipse: public Figure
{
private:
    double m_a;
    double m_b;
public:
    Ellipse(double a, double b)
    {
        m_a = a;
        m_b = b;
    }
    virtual double area(){return M_PI * m_a * m_b;};
    virtual double perimeter(){return (4 * M_PI * m_a * m_b + (m_a - m_b))/(m_a + m_b);};
    virtual ostream& print(ostream& out)
    {
        out << "Ellipse, ";
        out << "a " << m_a << ", ";
        out << "b " << m_b << ", ";
        out << "perimeter " << perimeter() << ", ";
        out << "area " << area() << endl;
        return out;
    }
};

class Polygon: public Figure
{
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
        virtual double area()
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
         virtual double perimeter()
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
        virtual ostream& print(ostream& out)
        {
            out << "Polygon, ";
            out << "Number of vertices " << m_numVertices << ", ";
            out << "perimeter " << perimeter() << ", ";
            out << "area " << area() << endl;
        }

};
class Circle: public Ellipse
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
};

int main()
{
 Ellipse e(2, 3);
 Circle c(4);
 Triangle t(3, "0.0 0.0 0.0 1.0 1.0 0.0");
 Figure *figures[] = {&e, &c, &t};
 for (int i = 0; i < 3; i++)
 {
 cout << *figures[i];
 }
return 0;
}










