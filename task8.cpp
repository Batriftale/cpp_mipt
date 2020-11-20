#include "iostream"
#include "cstdlib"
#include "fstream"
#include "string"

using namespace std;
№1
long long factorial(int n){
    if (n < 0)
        throw "n can't be negative";
    else if (n == 1)
        return n;
    return n * factorial(n-1);
}

int main(){
    int n;
    cout << "Введите число" << endl;
    cin >> n;
    try
    {
    cout << " Факториал числа" << n << " " << factorial(n) << endl;
    }
    catch(const char* exception)
    {
    cerr<< "Error: " << exception << endl;
    exit(1);
    }

    return 0;
}
№2
int main()
{
    try
    {
        ifstream file("nofile.txt");
        if (!file)
            throw "No such file";
        else
        {
        while (file)
        {
            string strInput;
            getline(file, strInput);
            cout << strInput << endl;
        }
        }
    }
    catch (const char* exception)
    {
    cerr << "Error: " << exception << endl;
    }
}

