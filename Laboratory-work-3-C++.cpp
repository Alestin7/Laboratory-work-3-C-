#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000

using namespace std;

void Hard_lvl()
{
    cout << "Hard task:\n\n";
    string ap;
    int numberWords;
    char even[20];
    char notEven[20];

    int count = 0;
    int position = 0;
    int evenPosition = 0;
    int notEvenPosition = 0;

    cout << "Enter 17 items with space: " << ap << endl;

    getline(cin, ap);

    while (ap.length() > 17)
    {
        cout << "Your entered more that 17 items!\n";
        getline(cin, ap);
    }

    while (ap.length() < 17)
    {
        cout << "Your entered less that 17 items!\n";
        getline(cin, ap);
    }

    for (int i = 0; i <= ap.length(); i++)
    {
        if (ap[i] == ' ' || ap[i] == '\0')
        {
            count++;
            if (count % 2 == 0)
            {
                do
                {
                    even[evenPosition++] = ap[position++];
                } while (ap[position - 1] != ' ' && ap[position - 1] != '\0');
                even[evenPosition - 1] = ' ';
                even[evenPosition] = '\0';
            }

            if (count % 2 != 0)
            {
                do
                {
                    notEven[notEvenPosition++] = ap[position++];
                } while (ap[position - 1] != ' ' && ap[position - 1] != '\0');
                notEven[notEvenPosition - 1] = ' ';
                notEven[notEvenPosition] = '\0';
            }


        }
    }

    numberWords = count;
    count = 0;
    position = 0;
    evenPosition = 0;
    notEvenPosition = 0;

    for (int i = 0; i <= numberWords; i++)
    {
        count++;
        if (count % 2 == 0)
        {
            do
            {
                if (notEven[notEvenPosition] != '\0')
                    ap[position++] = notEven[notEvenPosition++];
            } while (notEven[notEvenPosition - 1] != ' ' && notEven[notEvenPosition - 1] != '\0');
        }

        if (count % 2 != 0)
        {
            do
            {
                if (even[evenPosition] != '\0')
                    ap[position++] = even[evenPosition++];
            } while (even[evenPosition - 1] != ' ' && even[evenPosition - 1] != '\0');
        }
    }

    cout << "String with the change of even/odd words: " << endl << ap << endl;
}

int search(const char* str, char k)
{
    int count = 0;
    const char* c = str + strlen(str) - 1; 
    while (c != str && isspace(*c)) --c;    
    while (c >= str && !isspace(*c))
        if (*c-- == k) ++count;
    return count;
}

int main()
{
    cout << "Medium task:" << endl;
    char str[SIZE];
    for (;;)
    {
        cout << ("\nEnter the string (ENTER to exit): ") << endl;
        fgets(str, SIZE, stdin);
        if (strlen(str) == 1) break;
        cout << ("\nThe number of letters k in the last word - %d\n", search(str, 'k'));
    };

    Hard_lvl();
}