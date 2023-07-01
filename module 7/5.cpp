#include <bits/stdc++.h>
using namespace std;


string int_to_binary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary = '0' + binary;
        }
        else {
            binary = '1' + binary;
        }
        decimal /= 2;
    }
    return binary;
}

int con_binary(int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % 2 + 10 *
                con_binary(decimal_number / 2));
}


int main(){
   int binary = con_binary(5);
   cout<<binary;

 return 0;
}
