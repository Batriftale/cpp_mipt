#include "iostream"
#include "fstream"
#include "cmath"
#include "sstream"
#include "vector"


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
           ComplexNum C(d1.m_re + d2.m_re, d1.m_im + d2.m_im);
           return C;
        };
    
        friend ComplexNum operator-(const ComplexNum &d1, const ComplexNum &d2){
            ComplexNum C(d1.m_re - d2.m_re, d1.m_im - d2.m_im);
           return C;
        };
    
        friend ComplexNum operator/(const ComplexNum &d1, const ComplexNum &d2){
            float re_s, im_s;

            re_s = (d1.m_re * d2.m_re + d1.m_im * d2.m_im) / (pow(d2.m_re, 2) + pow(d2.m_im, 2));
            im_s = (d2.m_re * d1.m_im - d1.m_re * d2.m_im) / (pow(d2.m_re, 2) + pow(d2.m_im, 2));

            ComplexNum C(re_s, im_s);
            return C;
        };
    
        friend ComplexNum operator*(const ComplexNum &d1, const ComplexNum &d2){
            float re_s, im_s;
            
            re_s = d1.m_re * d2.m_re - d1.m_im * d2.m_im;
            im_s = d1.m_re * d2.m_im + d2.m_re * d1.m_im;

            ComplexNum C(re_s, im_s);
            return C;
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
#3
class ComplexNum{
    private:
        int re, im;
    public:
        ComplexNum(int r = 0, int i =0)
        {  re = r;   im = i; }
        friend ostream & operator << (ostream &out, const ComplexNum &c);
        friend istream & operator >> (istream &in,  ComplexNum &c);
    };

ostream & operator << (ostream &out, const ComplexNum &c){
    out << c.re;
    out << " +i" << c.im << endl;
    return out;
}

istream & operator >> (istream &in,  ComplexNum &c){
    cout << "Enter Real Part ";
    in >> c.re;
    cout << "Enter Imaginary Part ";
    in >> c.im;
    return in;
}

int main(){
   ComplexNum c1;
   ComplexNum c2;
   cin >> c1;
   cin >> c2;
   cout << c1;
   cout << c2;
   return 0;
}

#4
int main(){
    fstream iofile("task5_data.txt" , ios::in | ios::out);

    float res = 0;
    float ims = 0;
    vector<float> values;

    while (iofile){
        string strInput;
        float tmp;

        getline(iofile, strInput);
        istringstream ist(strInput);

        while (ist >> tmp){
            values.push_back(tmp);
        }

    }

    res = static_cast<float>(values[0]) + static_cast<float>(values[2]);
    ims = static_cast<float>(values[2]) + static_cast<float>(values[3]);
    iofile.put(res);
    iofile.put('  ');
    iofile.put(ims);
}



