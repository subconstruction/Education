#include <iostream>
#include <string>

using namespace std;

void tabliza() 
{
    string alfavit = "абвгдежзийклмнопрстуфхцчшщъыьэюя 0123456789";
    cout << endl;
    for (int i = 1; i <= alfavit.length(); i++)
    {
        printf("%*d", 3, i);
    }
    cout << " Номер символа" << endl;

    for (int i = 0; i < alfavit.length(); i++)
    {
        printf("%*c", 3, alfavit[i]);
    }
    cout << " Алфавит" << endl;

    for (int i = 0; i < alfavit.length(); i++)
    {
        printf("%*d", 3, i);

    }
    cout << " Номер индекса в строке" << endl;
}

string cipher(string mytext, int key, char* METHOD)
{   
    string alfavit = "абвгдежзийклмнопрстуфхцчшщъыьэюя 0123456789";
    string shifr_text="";
    int a = mytext.length();
    int b = alfavit.length();
    key = key % b;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (mytext[i] == alfavit[j])
            {
                uint index = METHOD == "enc" ? ( (j - key + b) % b ) : ( (j + key) % b );

                shifr_text += alfavit[index];
                break;
            }
        }
    }
    return shifr_text;
}

int main()
{
    system("mode 650");
    setlocale(LC_ALL, "Russian");

    tabliza();

    string text = "1234";

    string encodedText = cipher(text, 2, "enc");
    string decodedText = cipher(encodedText, 2, "dec");

    printf("Source Text: [%s] | Encoded Text: [%s] | Decoded Text: [%s]", text.c_str(), encodedText.c_str(), decodedText.c_str());
}
