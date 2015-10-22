//Name: Sandra Flores
//Date: October 22, 2015
//Description: Programing practice - File IO A

#include <iostream>
#include <fstream>// read and write files
#include <cstdlib>
#include <string>//strings

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    ofstream fout2;
    ofstream fout3;
    
    string word;
    int count = 0;
    int letter = 0;
    int average, total;
    int length2 = 0;
    int length3 = 0;
    int length4 = 0;
    int length11 = 0;
    
    fin.open("gba.txt");//file we are getting the information from 
    fout.open("result.txt");// new files
    fout2.open("capitalize.txt");
    fout3.open("uppercase.txt");
    
    if(fin.fail())//error check if file does not open
    {
        cout << "Error opening input file" << endl;
        exit(1);
    }
    
    if(fout.fail())
    {
        cout << "Error opening ouput file" << endl;
        exit(1);
    }
    
    while (fin >> word)
    {
        count++;//keep count of words 
        letter += word.length();//keep count of all the letters
        
        switch(word.length())
        {
            case 2:
            
                length2++;//keep count for the words with 2 letters
                break;
                
            case 3:
            
                length3++;//count for words with 3 letters
                break;
            
            case 4:
            
                length4++;//count for words with 4 letters
                break;
            
            default:
            
                length11++;//count for words with more than 4
        }  
        
        word[0] = toupper(word[0]);//capitalize the first letter of every word
        fout3 << word << " ";
        
        for(int i = 0; i < word.length(); i++)
        {
            
            word[i] = toupper(word[i]);//capitalize all the letters
            
        }
        
        fout2 << word <<  " ";//send all the capitalized words with a space after each word into file fout2
        
    }
    
    average = letter/count;
    total = length2 + length3 + length4 + length11;
    fout << "Average characters per word: "<< average << endl;//send average and the length of the words to the file result
    fout << length2 << " words of length 2" << endl;
    fout << length3 << " words of length 3" << endl;
    fout << length4 << " words of length 4" << endl;
    fout << length11 << " words of length 11 or longer" << endl;
    fout << "The total number of words: " << total << endl;
    
    fin.close();//close files
    fout.close();
    fout2.close();
    fout3.close();
    return 0;
}
