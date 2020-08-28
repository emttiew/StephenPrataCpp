#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

void ShowStr(const std::string & str);
void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr);

class Store
{
private:
    std::ofstream * outfile;
public:
    Store(std::ofstream & file) : outfile(&file) {}
    ~Store() {}
    Store & operator()(const std::string str)
    {
        size_t len = str.length();
        outfile->write((char *) &len, sizeof(size_t));
        outfile->write(str.data(), len);
        return *this;
    }
};

// częśc kodu (main) z podręcznika: 

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

// pobierz łańcuchy
    cout << "Podaj łańcuchy (aby zakończyć, wprowadź pusty wiersz):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Oto Twoje dane wejściowe.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	
// zapisz w pliku
	ofstream fout("lancuchy.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

// odczytaj zawrtośc pliku
	vector<string> vistr;
	ifstream fin("lancuchy.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Nie można otworzyć pliku do odczytu.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nOto łańcuchy odczytane z pliku:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}

void ShowStr(const std::string & str)
{
    std::cout << str << '\n';
}

void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr)
{
    size_t len;
	std::string temp;
	char ch;
    fin.seekg(0);
	while (fin.read((char *) &len, sizeof(size_t))) 
	{		
		for (size_t i = 0; i < len; i++)
		{
			fin.read(&ch, sizeof(char));
			temp.push_back(ch);
		}
		vistr.push_back(temp);
		temp.clear();
	}
}