// Huge integer division
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<cmath>
using std::log10;

// returns true if and only if the specified huge integer is zero
bool isZero(int hugeInt[], int size);

// returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int size1, int size2);

// --hugeInt
void decrement(int hugeInt[], int& size);

// multiplicand *= multiplier
void multiAssign(int multiplicand[], int multiplier[], int& multiplicandSize, int multiplierSize);

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int dividend[], int divisor[], int quotient[], int remainder[],
	int dividendSize, int divisorSize, int& quotientSize, int& remainderSize);

// product = multiplicand * multiplier * ( 10 ^ multiplierPos )
void multiplication(int multiplicand[], int multiplier, int product[],
	int multiplicandSize, int multiplierPos, int& productSize);

// minuend -= subtrahend
void subtraAssign(int minuend[], int subtrahend[], int& minuendSize, int subtrahendSize);

const int arraySize = 200;

int main()
{
	int t, a, b;
	while (cin >> t >> a >> b)
	{
		cout << "(" << t << "^" << a << "-1)/(" << t << "^" << b << "-1) ";

		if (t == 1)
			cout << "is not an integer with less than 100 digits.\n";
		else if (a == b)
			cout << "1\n";
		else if (a < b)
			cout << "is not an integer with less than 100 digits.\n";
		else if (a % b != 0)
			cout << "is not an integer with less than 100 digits.\n";
		else if ((a - b) * static_cast<int>(log10(t)) > 95)
			cout << "is not an integer with less than 100 digits.\n";
		else
		{
			int dividend[arraySize] = {};
			int divisor[arraySize] = {};
			int quotient[arraySize] = {};
			int remainder[arraySize] = {};

			int dividendSize = 1;
			int divisorSize = 1;
			int quotientSize = 1;
			int remainderSize = 1;

			// put all digits of t into base
			int base[arraySize] = {};
			int baseSize = 0;
			for (int i = t; i > 0; i /= 10)
				base[baseSize++] = i % 10;

			// dividend = pow( t, a )
			dividend[0] = 1;
			for (int i = 0; i < a; ++i)
			{
				multiAssign(dividend, base, dividendSize, baseSize);
				if (dividendSize > arraySize)
					break;
			}

			if (dividendSize > arraySize)
				cout << "is not an integer with less than 100 digits.\n";
			else
			{
				// divisor = pow( t, b )
				divisor[0] = 1;
				for (int i = 0; i < b; ++i)
					multiAssign(divisor, base, divisorSize, baseSize);



				decrement(dividend, dividendSize); // --dividend
				decrement(divisor, divisorSize);   // --divisor

				division(dividend, divisor, quotient, remainder,
					dividendSize, divisorSize, quotientSize, remainderSize);

				// quotient is an integer with less than 100 digits
				if (quotientSize < 100 && isZero(remainder, remainderSize))
					for (int i = quotientSize - 1; i >= 0; i--)
						cout << quotient[i];
				else
					cout << "is not an integer with less than 100 digits.";
				cout << endl;
			}
		}
	}
}

// returns true if and only if the specified huge integer is zero
bool isZero(int hugeInt[], int size)
{
	for (int i = 0; i < size; i++)
		if (hugeInt[i] != 0)
			return false;
	return true;
}

// returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int size1, int size2)
{
	if (size1 > size2)
		return false;
	if (size2 > size1)
		return true;
	if (size1 == size2)
	{
		for (int i = size1 - 1; i >= 0; i--)
		{
			if (hugeInt1[i] > hugeInt2[i])
				return false;
			if (hugeInt2[i] > hugeInt1[i])
				return true;
		}
		return false;
	}

}

// --hugeInt
void decrement(int hugeInt[], int& size)
{
	hugeInt[0]--;
	for (int i = 0; i < size; i++)
	{
		if (hugeInt[i] < 0)
		{
			hugeInt[i + 1] -= 1;
			hugeInt[i] += 10;
		}
	}

	for (int i = size - 1; i >= 0; i--)
	{
		if (hugeInt[i] == 0)
			size--;
		else break;//忘記了吼
	}
}

// multiplicand *= multiplier
void multiAssign(int multiplicand[], int multiplier[], int& multiplicandSize, int multiplierSize)
{
	int product[arraySize] = {};
	int productSize = multiplierSize + multiplicandSize + 1;
	for (int i = 0; i < multiplierSize; i++)
	{
		for (int n = 0; n < multiplicandSize; n++)
		{
			product[i + n] += multiplicand[n] * multiplier[i];
		}
	}
	multiplicandSize = productSize;

	for (int i = 0; i < productSize; i++) {
		multiplicand[i] = product[i];
	}

	for (int i = 0; i < multiplicandSize; i++)
	{
		if (multiplicand[i] >= 10)
		{
			multiplicand[i + 1] += multiplicand[i] / 10;
			multiplicand[i] %= 10;
		}
	}
	if (multiplicand[multiplicandSize] == 0) multiplicandSize--;

}

void division(int dividend[], int divisor[], int quotient[], int remainder[],
	int dividendSize, int divisorSize, int& quotientSize, int& remainderSize)
{
	if (isZero(dividend, dividendSize)) {
		quotient[0] = 0;
		quotientSize = 1;
		remainder[0] = 0;
		remainderSize = 1;
		return;
	}




	remainderSize = dividendSize;
	for (int i = 0; i < dividendSize; i++)
	{
		remainder[i] = dividend[i];
	}




	if (less(dividend, divisor, dividendSize, divisorSize)) {
		quotient[0] = 0;
		quotientSize = 1;
		return;
	}


	int buffer[arraySize] = {};
	int bufferSize;



	int n = dividendSize - divisorSize;
	quotientSize = n;
	multiplication(divisor, 1, buffer, divisorSize, n, bufferSize);

	if (!less(dividend, buffer, dividendSize, bufferSize)) {
		quotientSize++;
	}



	int a, b, i, j;
	a = divisor[divisorSize - 1]; //a是除數的最高位數字
	j = dividendSize - 1; //j是在跑餘數的最高位數
	for (i = dividendSize - divisorSize; i >= 0; i--, j--) {
		b = 10 * remainder[j + 1] + remainder[j];
		if (a <= b) {
			quotient[i] = b / a;
			multiplication(divisor, quotient[i], buffer, divisorSize, i, bufferSize);
			while (less(remainder, buffer, remainderSize, bufferSize)) {
				quotient[i]--;
				multiplication(divisor, quotient[i], buffer, divisorSize, i, bufferSize);

			}
			subtraAssign(remainder, buffer, remainderSize, bufferSize);
		}
	}



	/*int bufferSize = remainderSize;
	int f = dividendSize - divisorSize;
	for( int i = 0; i < divisorSize; i++ )
	{
		buffer  [ i + f ] = divisor[ i ];
	}

	for( int i = 0; i < bufferSize; i++ )
	{
		if( remainder[ i ] > buffer[ i ] )
		remainder[ i ] -= buffer[ i ];
	}

	if( less( buffer, remainder, bufferSize, remainderSize ) )
		quotientSize++;
	if( isZero( remainder, remainderSize ) )
		quotient[ 0 ] += 0;
	*/
}

void multiplication(int multiplicand[], int multiplier, int product[],
	int multiplicandSize, int multiplierPos, int& productSize)
{
	/*for( int i = 0; i < multiplierPos; i++ )
	{
		for( int n = 0; n < multiplicandSize; i++ )
		{
			multiplicand[ i + n ] += multiplicand[ n ] * multiplier;
		}
	}*/

	// product = multiplicand * multiplier * ( 10 ^ multiplierPos )

	productSize = multiplicandSize + multiplierPos + 2;
	for (int i = 0; i < productSize; i++) {
		product[i] = 0;
	}

	for (int i = 0; i < multiplicandSize; i++) {
		product[i + multiplierPos] = multiplicand[i] * multiplier;
	}

	for (int i = 0; i < productSize; i++)
	{
		if (product[i] >= 10)
		{
			product[i + 1] += product[i] / 10;
			product[i] %= 10;
		}
	}

	for (int i = productSize - 1; i > 0; i--) {
		if (product[i] == 0) {
			productSize--;
		}
		else {
			break;
		}
	}

}

void subtraAssign(int minuend[], int subtrahend[], int& minuendSize, int subtrahendSize)
{
	for (int i = 0; i < subtrahendSize; i++)
	{
		minuend[i] -= subtrahend[i];
	}

	for (int i = 0; i < minuendSize; i++)
	{
		if (minuend[i] < 0)
		{
			minuend[i + 1] -= 1;
			minuend[i] += 10;
		}
	}
	for (int i = minuendSize - 1; i > 0; i--) //然後昨天說的去0不會去到Size變-1
	{
		if (minuend[i] == 0)
		{
			minuendSize--;
		}
		else break;//又忘了吼
	}

}
