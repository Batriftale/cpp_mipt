#include "iostream"
#include "algorithm"
#include "string"
#include "vector"


void insertionSort(int *arr, int n){
    for (int i = 1; i < n; i++){
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--){
            arr[j - 1] = arr[j - 1] ^ arr[j];
            arr[j] = arr[j] ^ arr[j-1];
            arr[j-1] = arr[j-1] ^ arr[j];
            }
    }
}
#1
int main(){
    int arr[7] = {56, 1, 343, 34, 2, 6, 6};
    int n = 7;

    insertionSort(arr,n);

    for (int i = 0; i <= n-1; i++){
        std::cout << arr[i] << std::endl;
    }
    return 0;
}   

#2
int main(){
    int arr[10];
    int key;

    std::cout << "Type 10 values" << std::endl;

    for(int i = 0; i < 10; i++){
        std::cin >> arr[i];
    }

    std::cout << "Type the value you're looking for" << std::endl;
    std::cin >> key;

    insertionSort(arr, 10);

    bool flag = false;
    int left_border = 0;
    int right_border = 9;
    int middle;

    while ((left_border <= right_border) && (flag != true)){
        middle = (left_border + right_border) / 2;
        if (arr[middle] == key){
            flag = true;
            }
        if (arr[middle] > key){
            right_border = middle - 1;
        }
        else {
            left_border = middle + 1;
        }
    }
    if (flag){
        std::cout << "The answer is " << middle << std::endl;
    }
    else{
        std::cout << "No such number in array" << std::endl;
    }


    return 0;
} 

#3
int main(){
    std::string a;
    std::string b;
    std::cout << "Type two lines" << std::endl;
    std::cin >> a >> b;
    std::vector<std::vector<int> > max_len;
        max_len.resize(a.size() + 1);
        for(int i = 0; i <= a.size(); i++)
            max_len[i].resize(b.size() + 1);
        for(int i = a.size() - 1; i >= 0; i--)
        {
            for(int j = b.size() - 1; j >= 0; j--)
            {
                if(a[i] == b[j])
                {
                    max_len[i][j] = 1 + max_len[i+1][j+1];
                }
                else
                {
                    max_len[i][j] = std::max(max_len[i+1][j], max_len[i][j+1]);
                }
            }
        }
        std::string res;
        for(int i = 0, j = 0; max_len[i][j] != 0 && i < a.size() && j < b.size(); )
        {
            if(a[i] == b[j])
            {
                res.push_back(a[i]);
                i++;
                j++;
            }
            else
            {
                if(max_len[i][j] == max_len[i+1][j])
                    i++;
                else
                    j++;
            }
        }
        std::cout << res;
        return 0;
        }
#4
int main(){
	string x, y, x_l, x_r, y_l, y_r;
	cout << "Type two numbers" << endl;
	cin >> x >> y;
	int n, i1, i2, j1, j2, prod1, prod2, prod3, result;
	n = x.length();
	if (n == 1){
		i1 = atoi(x.c_str());
		j1 = atoi(y.c_str());
		result = i1 * j1;
		cout << result;
	}
	else {

	x_l = x.substr(0, n/2);
	x_r = x.substr(n/2, n);
	y_l = y.substr(0, n/2);
	y_r = y.substr(n/2, n);

	i1 = atoi(x_l.c_str());
	i2 = atoi(x_r.c_str());
	j1 = atoi(y_l.c_str());
	j2 = atoi(y_r.c_str());

	prod1 = i1*j1;
	prod2 = i2*j2;
	prod3 = (i1 + i2)*(j1+j2);

	result = prod1 * pow(10, ((n/2)*2)) + (prod3 - prod1 - prod2) * pow(10, (n/2)) + prod2;
	cout << result;
	}
    return 0;
}


