
#include <iostream>
using namespace std;
class Exception
{
protected:

    char m_message[100];

public:

    Exception(const char* message)
    {
        strcpy_s(m_message, message);
    }

    const char* GetMessage() const
    {
        return m_message;
    }
};
class ArrayDataException : public Exception
{
public:
    ArrayDataException(const char* mes) :Exception(mes)
    {

    }
    virtual const char* GetMessage() const
    {
        return m_message;
    }
};
class ArrayValueCalculator
{
    int arr1[4][4];
public:
    ArrayValueCalculator()
    {
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
                arr1[i][j] = 0;
        }
    }
    int* doCalc(string arr[4][4])
    {
        int newarr[4][4];
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t y = 0; y < 4; y++)
            {
                int temp = 0;
                for (int j = 0; j < arr[i][j].length(); j++)
                {
                    temp *= 10;
                    if (arr[i][y][j] == '1')
                        temp += 1;
                    else if (arr[i][y][j] == '2')
                        temp += 2;
                    else if (arr[i][y][j] == '3')
                        temp += 3;
                    else if (arr[i][y][j] == '4')
                        temp += 4;
                    else if (arr[i][y][j] == '5')
                        temp += 5;
                    else if (arr[i][y][j] == '6')
                        temp += 6;
                    else if (arr[i][y][j] == '7')
                        temp += 7;
                    else if (arr[i][y][j] == '8')
                        temp += 8;
                    else if (arr[i][y][j] == '9')
                        temp += 9;
                    else if (arr[i][y][j] == '0')
                    {
                        temp *= 10;
                    }
                    else
                    {
                        cout << "Index: " << i << ' ' << y<< ' ';
                        throw ArrayDataException("Wrong data");
                    }
                }
                newarr[i][y] = temp;
            }
        }
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
                arr1[i][j] = newarr[i][j];
        }
    }
    void Show()
    {
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
                cout << arr1[i][j] << ' ';
            cout << endl;
        }
    }
};
int main()
{
    srand(time(0));
    string arr[4][4];
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            arr[i][j] =(50 +  rand() % 10);
        }
    }
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    ArrayValueCalculator a;
    try
    {
        a.doCalc(arr);
        a.Show();
    }
    catch (ArrayDataException exception)
    {
        cout << exception.GetMessage() << endl;
    }
}
