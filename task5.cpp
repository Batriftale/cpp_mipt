#include "iostream"

#include "cmath"
#include "sstream"


using namespace std;
#1
class ComplexNum{
    private:
        float m_re;
        float m_im;
    public:
        ComplexNum (float re, float im){
            m_re = re;
            m_im = im;
        }
        float complexMod(){
            return sqrt(pow(m_re,2) + pow(m_im,2));
        }
};
int main(){
    float re, im;

    cin >> re >> im;

    ComplexNum comp(re,im);
    cout << comp.complexMod() << endl;
} 
#2
class ComplexNum{
    private:
        float m_re;
        float m_im;
    public:
        ComplexNum(float re, float im){
            m_re = re;
            m_im = im;
        }
       friend ComplexNum operator+(const ComplexNum &d1, const ComplexNum &d2){
            float re_s, im_s;
            stringstream myString;

            re_s = d1.m_re + d2.m_re;
            im_s = d1.m_im + d2.m_im;

            myString << re_s << " " << im_s;

            string str_re, str_im;
            myString >> str_re >> str_im;
            cout << str_re << " + " << str_im << "i" << endl;;
        };
    
        friend ComplexNum operator-(const ComplexNum &d1, const ComplexNum &d2){
            float re_s, im_s;
            stringstream myString;

            re_s = d1.m_re - d2.m_re;
            im_s = d1.m_im - d2.m_im;

            myString << re_s << " " << im_s;

            string str_re, str_im;
            myString >> str_re >> str_im;
            cout << str_re << " + " << str_im << "i" << endl;
        };
    
        friend ComplexNum operator/(const ComplexNum &d1, const ComplexNum &d2){
            float re_s, im_s;
            stringstream myString;

            re_s = (d1.m_re * d2.m_re + d1.m_im * d2.m_im) / (pow(d2.m_re, 2) + pow(d2.m_im, 2));
            im_s = (d2.m_re * d1.m_im - d1.m_re * d2.m_im) / (pow(d2.m_re, 2) + pow(d2.m_im, 2));

            myString << re_s << " " << im_s;

            string str_re, str_im;
            myString >> str_re >> str_im;
            cout << str_re << " + " << str_im << "i" << endl;
        };
    
        friend ComplexNum operator*(const ComplexNum &d1, const ComplexNum &d2){
            float re_s, im_s;
            stringstream myString;

            re_s = d1.m_re * d2.m_re - d1.m_im * d2.m_im;
            im_s = d1.m_re * d2.m_im + d2.m_re * d1.m_im;

            myString << re_s << " " << im_s;

            string str_re, str_im;
            myString >> str_re >> str_im;
            cout << str_re << " + " << str_im << "i" << endl;
        };

};

int main(){
    float re1, im1;
    float re2, im2;

    cin >> re1 >> im1;
    cin >> re2 >> im2;

    ComplexNum comnum1(re1, im1);
    ComplexNum comnum2(re2, im2);

    ComplexNum comnum_sum = comnum1 + comnum2;
    ComplexNum comnum_min = comnum1 - comnum2;
    ComplexNum comnum_div = comnum1 / comnum2;
    ComplexNum comnum_mul = comnum1 * comnum2;

}


