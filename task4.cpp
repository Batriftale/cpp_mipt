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
№3
class Student{
    private:
        string  m_name;
        double m_avscore;
    public:
        Student(string name, double avscore){
            m_name = name;
            m_avscore = avscore;
        }
};
class Group{
    public:
        vector< pair<string, double> > lst;
        void add(string name, double avscore){
            lst.push_back(make_pair(name, avscore));
        };
        double avarageScore(){
            double summ = 0;

            for(int i = 0; i < lst.size(); i++){
                summ += lst[i].second;
            }
            return (summ / lst.size());
        }
        ~Group(){
            lst.clear();
        }

};
int main(){
    int n;
    string name;
    double score;

    cout << "Number of students is" << endl;
    cin >> n;
    cout << "Type students' names and their scores" << endl;
    Group g;
    for(int i = 0; i < n; i++){
        string fname, lname;
        cin >> fname >> lname;
        string name = fname + " " + lname;
        cin >> score;
        Student s(name, score);
        g.add(name, score);
    }
    cout << g.avarageScore() << endl;
}


