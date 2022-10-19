#include<iostream>  
#include<string>  
#include<vector>  
#include<stack>  
#include<math.h>  
#include<ctime>  
using namespace std;  
  
int main()  
{  
    long long int inputNumber, inputDivisor;  
  
    long long int output[10000];  
  
    long long int temp;  
  
      
  
    while (cin >> inputNumber >> inputDivisor)  
    {  
        /*if (inputNumber == 1 && inputDivisor == 1) 
            cout << 1 << endl;*/  
  
        if (inputNumber == 0 || inputDivisor == 0 || inputDivisor == 1)  
        {  
            cout << "Boring!" << endl;  
            continue;  
        }  
  
        if (inputNumber < inputDivisor)  
        {  
            cout << "Boring!" << endl;  
            continue;  
        }  
  
        /*if (inputDivisor == 1) 
        { 
            cout << inputNumber << " " << 1 << endl; 
            continue; 
        }*/  
  
        int count = 0;  
        int temp = inputNumber;  
        while (inputNumber % inputDivisor == 0)  
        {  
            //cout << inputNumber << " ";  
            output[count] = inputNumber / inputDivisor;  
            inputNumber /= inputDivisor;  
            count++;  
              
        }  
  
        if (output[count-1] == 1)  
        {  
            cout << temp << " ";  
            for (int i = 0; i < count - 1; i++)  
                cout << output[i] << " ";  
            cout << 1;  
            cout << endl;  
        }  
  
        else  
        {  
            cout << "Boring!" << endl;  
        }  
        //cout << 1;  
        //cout << endl;  
          
    }  
} 