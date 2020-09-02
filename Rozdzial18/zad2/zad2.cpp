#include <string>
#include <iostream>

class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };
private:
    Info *pi;
public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv & cp);
    Cpmv(Cpmv && mv);
    ~Cpmv();
    Cpmv & operator=(const Cpmv & cp);
    Cpmv & operator=(Cpmv && mv);
    Cpmv operator+(const Cpmv & obj) const;
    void Display() const;
};

int main()
{
    Cpmv one;
    std::cout << "Obiekt one:\n";
    one.Display();
    Cpmv two("first", "second");
    std::cout << "Obiekt two:\n";
    two.Display();
    std::cout << "\none = two:\n";
    one = two;
    std::cout << "Obiekt one:\n";
    one.Display();
    std::cout << "\nCpmv three = one + one:\n";
    Cpmv three = one + one;
    std::cout << "Obiekt three:\n";
    three.Display();
    std::cout << "Obiekt one:\n";
    one.Display();
    std::cout << "Obiekt two:\n";
    two.Display();
    Cpmv four = three;
    std::cout << "Obiekt four:\n";
    four.Display();
    four = std::move(two);
    std::cout << "Obiekt four po std::move(two):\n";
    four.Display();
    two.Display();
    return 0;
}

Cpmv::Cpmv()
{
    pi = new Info;
    std::cout << "Konstruktor domyślny. Adres: " << pi << '\n';    
    pi->qcode = "";
    pi->zcode = "";
}

Cpmv::Cpmv(std::string q, std::string z) 
{    
    pi = new Info;
    std::cout << "Konstruktor z argumentami. Adres: " << pi << '\n';    
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp)
{
    std::cout << "Konstruktor kopiujący. Adres: " << pi << '\n';
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;    
}

Cpmv::Cpmv(Cpmv && mv)
{
    std::cout << "Konstruktor przenoszący. Adres: " << pi << '\n';
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
    std::cout << "Destruktor. Adres: " << pi << '\n';
    delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    std::cout << "Kopiujący operator przypisania. Adres: " << pi << '\n';
    if(this == &cp)
        return *this;
    delete pi;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode; 
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
    std::cout << "Przenoszący operator przypisania. Adres: " << pi << '\n';
    if(this == &mv)
        return *this;
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    std::cout << "operator+() wejście:\n";
    Cpmv temp = Cpmv(pi->qcode + obj.pi->zcode, pi->zcode + obj.pi->qcode);
    std::cout << "operator+() wyjście:\n";
    return temp;
}

void Cpmv::Display() const
{
    if(pi != nullptr)
    {
        std::cout << "qcode: " << pi->qcode << '\n';
        std::cout << "zcode: " << pi->zcode << '\n';
    } else
    {
        std::cout << "nullptr: " << pi << '\n';
    }
    
}