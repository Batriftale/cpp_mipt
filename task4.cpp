#include "iostream"
#include "cmath"

using namespace std;

#1
class Condensator{
    private:
        int m_C;
        int m_U;

    public:
        Condensator(int cond, int voltage){
            m_C = cond;
            m_U = voltage;
            }
            double energy(){ return 0.5 * m_C * pow(m_U,2); };
};

int main(){
    int c,u;
    cout << "Type capacity and voltage"<< endl;
    cin >> c >> u;
    Condensator cond(c, u);
    cout << "Capacitor's energy is " <<  cond.energy();

}
#2
class Product{
    private:
        string m_name;
        int m_quant;
        double m_price;
    public:
        Product(string name, int quantity, double price){
            m_quant = quantity;
            m_price = price;
            m_name = name;
        }
        void summ(){
            double s = m_quant * m_price;
            cout << m_name << " is " << s << " in total" << endl;
           };
};
int main(){
    int q;
    double p;
    string name;

    cout << "Type name, quantity and price of a product " << endl;
    cin >> name >> q >> p;

    Product prod(name, q, p);
    prod.summ();

}
