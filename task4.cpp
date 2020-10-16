#include "iostream"
#include "cmath"

using namespace std;

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
