#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Replace T with U
    string dna = "GCAT";
    for (char &c : dna)
        if (c == 'T')
            c = 'U';
}

string DNAtoRNA(string dna)
{
    replace(dna.begin(), dna.end(), 'T', 'U');
    return dna;
}