#include "iostream"
#include "cmath"
#include "string"

//#1
/*bool XOR(int a, int b){
    if ((!(bool)a) && (!(bool)b){
        return true;
    }
    return false;
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << std::boolalpha;
    std::cout << XOR(a, b);
return 0;
}    */

/*#2
float resistance(double r){
    return r * pow(10, 9);
}
float magFieldStrength(double h, const float pi){
    return 4 * pi * h * pow(10, -3);
}
float magFlux(double f){
    return f * pow(10, 8);
}
int main(){

    const float pi = 3.14;
    double value;
    std::string name;


    std::cout << "What do you want to convert?"<<std::endl;
    std::cin >> name;
    std::cout << "Type the value in SI" << std::endl;
    std::cin >> value;
    if (name == "H"){
        std::cout << value << " A/m = " << magFieldStrength(value, pi) << " statA/cm";
    }
    if (name == "R"){
        std::cout << value << " Om = " << resistance(value) << " sec/cm";
    }
    if (name == "F"){
        std::cout << value << " Wb = " << magFlux(value) << " statWb";
    }
    return 0;
} */


/* #3
int main(){
    int x = 9;
    int y = 5;

    x = x^y;
    y = y^x;
    x = x^y;

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
} */

/* #4
int main(){
    double x;

    std::cout << "Type the value" << std::endl;
    std::cin >> x;

    x = sqrt(x);
    x = pow(x, 2.3);
    x = floor(x);
    x = sin(x);
    x = ceil(x);
    std::cout << "The result is " << x << std::endl;

    return 0;
} */


int main(){
    double a, b, c, d;
    double first, second;

    std::cout << "Type a,b and c" << std::endl;
    std::cin >> a >> b >> c;

    if (a != 0){
        d = b*b - 4*a*c;
        if (d >= 0){
            first = (-b+sqrt(d))/(2*a);
            second = (-b - sqrt(d))/(2*a);
            if (first == second){
                std::cout << first;
            }
            else{
                std::cout << first <<" " << second;
            }
        }
    }
    else if ((a == 0) && (b != 0)){
        first = (-1 * c) / b;
        std::cout << first;
    }
return 0;
}



