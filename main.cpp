#include <iostream> // cout
#include <cstdlib> // standardowa biblioteka z c
using namespace std;

class prostokat
{
public:
    prostokat(); //konstruktor bezargumentowy
    prostokat(float s, float w); //konstruktor z argumentami
    ~prostokat(); //destruktor
    //funkcje skladowe udostepniajce (getter i setter)
    float getSzer(){return szer; }      //4
    float getWys(){return wys; }        //4
    void setSzer(float s) {szer = s; }      //5
    void setWys(float w) {wys = w; }        //5
    //funkcje skaldowe konkretnych czynnosci
    float obliczPole();             //6
    float obliczObwod();            //6
private:
    float szer, wys; // dlugosci bokow
};

prostokat::prostokat()
{
    szer = 1; wys =1;
    cout << "Utworzono obiekt konstruktorem bezargumentowym" << endl;
}

prostokat::prostokat(float s, float w)
{
    szer = s; wys =w;
    cout << "Utworzono obiekt konstruktorem z argumentami" << endl;
}

prostokat::~prostokat()
{
    cout << "Zniszczono obiekt" << endl;
}

float prostokat::obliczPole()
{
    return szer*wys;
}

float prostokat::obliczObwod()
{
    return 2*(szer+wys);
}

int main()
{
    system("clear");
    prostokat p1, p2(2, 3); // oniekt mial nazwe i byl tworzony w sposob statyczny
    cout << "pole = " << p2.obliczPole() << endl;
    cout << "obwod = " << p2.obliczObwod() << endl << endl;

    prostokat *wsk;// zmienna wskaznikowa przechowujaca adres pamieci, wskaznik na obiekt klasy prostokat, dodatkowo wstawiamy 0, żeby nie  pokazywal w kosmos
    wsk = &p1;
    wsk = &p2;
    wsk = new prostokat(4, 5); //tworzenie obiektu w sposob dynamiczny, alokacja(rezerwacja) pamieci
    cout << "pole = " << wsk->obliczPole() << endl;
    cout << "obwod = " << wsk->obliczObwod() << endl << endl;
    delete wsk; //zwolnienie pamieci

    system("pause");
    return 0;
}