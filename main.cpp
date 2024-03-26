#include <iostream>
#include <math.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int liczba;
int suma =0;
void zadanie1_1 ()
{
    for (;;) //wyznacza sumę ciągu liczb całkowitych zakończonego zerem (ciąg liczb podaje użytkownik)
    {
        cout <<"Podaj liczbe:";
        cin>>liczba;
        if (liczba == 0)
        {
            break;
        }
        else
        {

            suma = suma + liczba;
        }
    }
    cout <<"Suma wynosi:"<<suma<<endl;
}


void zadanie_1_2 ()//wyznacza sumę kwadratów kolejnych liczb naturalnych 02+12+…+n2, liczbę n podaje użytkownik
{
    cout <<"Podaj liczbe:";
    cin>>liczba;
    for (int i=0; i<=liczba; i++)
    {

        suma= suma+ pow(i,2);

    }
    cout <<"Suma wynosi:"<<suma<<endl;

}

void zadanie_1_3 ()//wyznacza silnię liczby całkowitej, dodatniej n, przypomnijmy, że silnię danej liczby n oznaczamy przez n!, oraz, że 1!=1 oraz n!=1⋅2⋅…⋅n
{
    cout <<"Podaj liczbe:";
    cin>>liczba;
    for (int i=1; i<=liczba; i++)
    {

        suma = suma*i;

    }
    cout <<"Suma wynosi:"<<suma<<endl;
}

//#include <vector>
vector<int> liczby;
void zadanie_2_1 () //wyznacza maksimum liczb z ciągu n liczb całkowitych oraz średnią arytmetyczną liczb dodatnich tego ciągu. Ilość liczb w ciągu jak i kolejne liczby z ciągu podaje użytkownik.
{
    cout<<"Podaj ilość liczb w tablicy:";
    int rozmiar;
    cin>> rozmiar;

    for (int i=0; i<rozmiar; i++)
    {
        cout <<"Podaj liczbe ktora chcesz wstawic";
        int liczba;
        cin>>liczba;
        liczby.push_back(liczba);
    }
    int max = -100000;
    int min = 100000;
    float srednia = 0;
    for(int i =0; i<rozmiar; i++)
    {


        if (liczby[i]>max)
        {
            max = liczby[i];
        }
        if (liczby [i]<min)
        {
            min = liczby[i];
        }
        srednia = srednia + liczby[i];


    }
    cout<<"Max ="<<max<<endl;
    cout<<"Min+"<<min<<endl;
    cout<<"Średnia ="<<srednia/rozmiar<<endl;
}


//1 - wyznacza sume odwrotnosci liczb 1+1/2+…+1/n, przy czym n podaje użytkownik, 2 - wyświetla na ekranie trójkąt złożony ze znaków '*' (w pierwszym wierszu jest 1 gwiazdka, w drugim dwie, ..., w ostatnim n, n podaje użytkownik), 3 - zakonczenie programu
void operacja1 ()
{
    cout<<"Podaj liczbę:";
    int n;
    cin>>n;
    float suma1 = 0;
    for (int i=1; i<=n; i++)
    {

        suma1 = suma1 + pow(i,-1);
    }
    cout<<suma1<<endl;
}
void operacja2 ()
{
    cout<<"Podaj liczbę:";
    int n;
    cin>>n;
    for (int j =0; j<=n; j++)
    {
        for (int i=0; i<j; i++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void zadanie3_1 ()
{
    for (;;)
    {
        cout<<"Która operacje chcesz wybrac?";
        int wybor;
        cin>> wybor;
        switch(wybor)
        {
        case 1:
        {
            operacja1 ();
            break;
        }

        case 2:
        {
            operacja2 ();
            break;
        }
        case 3:
        {
            exit(1);
        }
        }
    }
}

void zadanie_sam_1 ()
{
    int fib;
    cout<<"Podaj numer wyrazu ktory chcesz wyznaczyc:";
    int n;
    cin>>n;

//wczytac liczbe n (numer wyrazu, ktory chcemy wyznaczyc):

    int przedostatni_wyraz= 1; //wyraz i w danym kroku, tutaj: wstepna wartosc tego wyrazu
    int przedprzedostatni_wyraz = 0; //wyraz i+1 w danym kroku, tutaj: wstepna wartosc tego wyrazu
    for (int i=2; i<=n; i++)
    {
        fib = przedostatni_wyraz + przedprzedostatni_wyraz;
        //aktualizujemy wartosci zmiennych przedostatni_wyraz, przedprzedostatni_wyraz:

        przedprzedostatni_wyraz = przedostatni_wyraz;
        przedostatni_wyraz  = fib;
    }
    cout<<fib<<endl;
}

void zadanie_sam_2 () //Napisać program wyznaczający rozstęp ciągu n liczb całkowitych (rozstęp, to różnica pomiędzy maksimum,
//a minimum ciągu liczb całkowitych), kolejne wyrazy ciągu podaje użytkownik
//poprawione
{
    {
        cout<<"Podaj ilość liczb w tablicy:";
        int rozmiar;
        cin>> rozmiar;

        for (int i=0; i<rozmiar; i++)
        {
            cout <<"Podaj liczbe ktora chcesz wstawic";
            int liczba;
            cin>>liczba;
            liczby.push_back(liczba);
        }
        int max = liczby[0];
        int min = liczby [0];
        float srednia = 0;
        for(int i:liczby)
        {


            if (liczby[i]>max)
            {
                max = liczby[i];
            }
            if (liczby [i]<min)
            {
                min = liczby[i];
            }


        }
        cout<<"Rozstep ciagu n wynosi:"<<abs(max-min)<<endl;
    }

}
//#include <ctime>
//#include <cstdlib>
void zadanie_sam_4 ()//program który jest grą polegającą na zgadywaniu przez użytkownika liczby wylosowanej przez generator liczb pseudolosowych.
// Program losuje liczbę z zakresu od 1 do 100, a następnie pyta użytkownika o nią dopóki on nie poda poprawnej odpowiedzi, po każdej odpowiedzi
//podając podpowiedź użytkownikowi: za duzo! lub za malo
//Wskazówka: aby wylosować liczbę pseudolosową ze zbioru {0,1,…,b−1}, gdzie b
//jest liczbą całkowitą dodatnią, można użyć instrukcji rand()% b, przy czym funkcja rand znajduje się w bibliotece cstdlib.
{
    srand (time(NULL));
    int wylosowana_liczba;
    wylosowana_liczba = 1+rand()%(100);

    for (;;)
    {
        cout<<"Podaj swoja liczbe";
        int strzal;
        cin>>strzal;

        if(strzal>wylosowana_liczba)
        {
            cout<<"Za duza"<<endl;
            continue;
        }
        if(strzal<wylosowana_liczba)
        {
            cout<<"Za mala"<<endl;
            continue;
        }
        if(strzal==wylosowana_liczba)
        {
            cout<<"Zgadles"<<endl;
            break;
        }

    }
}
void lab1_1 () //teraz program, który pobiera od użytkownika wymiar w stopach i wyprowadza na ekran wymiar podany w metrach
//(jedna stopa angielska to 30,48 cm).
{
    float pobierana_liczba;
    cout<<"Wprowadz liczbe w stopach"<<endl;
    cin>>pobierana_liczba;
    float wynik;
    wynik = pobierana_liczba*30.48;
    cout<<"W metrach wynosi:"<<wynik<<endl;
}

void lab_1_zad1 ()//Napisać program, który pobiera od użytkownika temperaturę w stopniach Celsjusza, a na ekran wyprowadza temperaturę podaną w stopniach Fahrenheita.
//Wykorzystać wzór:
{
    float celsjusz;
    cout<<"Wprowadz liczbe w CELCJUSZACH"<<endl;
    cin>>celsjusz;
    float farenhait;
    farenhait = (9*celsjusz)/5 + 32;
    cout<<"Tyle FARENHAJTÓW"<<farenhait<<endl;
}


void lab_1_zad2 () //Napisać program, który pobiera od użytkownika temperaturę w stopniach Celsjusza, a na ekran wyprowadza temperaturę podaną w stopniach Fahrenheita. Wykorzystać wzór:
{
    int TAB[2][2]; //tablica pobiera od uzytkownika elementy macierzy 2x2
    for(int i = 0; i < 2; i++)
    {
        for(int j =0; j<2; j++)
        {
            cin>>TAB[i][j];
        }
    }

      for(int i = 0; i < 2; i++) //pokazuje macierze
    {
        for(int j =0; j<2; j++)
        {
            cout<<" "<<TAB[i][j];
        }
        cout<<endl;
    }

    float wyznacznik;
    wyznacznik = TAB [0][0] * TAB [1][1] - TAB [0][1]* TAB [1][0];
    cout<<"Wyznacznik wynosi "<<wyznacznik;

}

void lab_1_zad_3 ()//Napisać program, który pobiera
//od użytkownika współczynniki a,b i c trójmianu kwadratowego
//ax2+bx+c, a następnie w zależności od wartości Δ=b2−4ac wyświetla dwa pierwiastki rzeczywiste,
//jeden pierwiastek rzeczywisty lub informację o tym,
//że nie ma pierwiastków rzeczywistych
{
float a;
float b;
float c;
float x1;
float x2;

cout<<"Podaj współczynniki abc trójmianu kwadratowego"<<endl;
cin>>a;
cin>>b;
cin>>c;
float delta;
delta = pow(b,2) -4*a*c;

if (delta==0)
{
    x1= -b/(2*a);
    cout<<"Delta = 0, jeden pierwiastek; "<<x1<<endl;
}
else if (delta>0)
{
    x1= (-b+sqrt(delta))/(2*a);
     x2= (-b-sqrt(delta))/(2*a);
    cout<<"Delta większa od 0, jeden pierwiastek; "<<x1<<"Delta większa od 0, drugi pierwiastek; "<<x2<<endl;
}
else if (delta<0)
{

    cout<<"Delta mniejsza od zera - brak rozwiazan"<<endl;
}
}

void lab_1_zad_4 () //Napisać program, który pobiera od użytkownika współrzędne punktu (x0,y0) (w metrach) oraz czas t (w sekundach), a następnie wyznacza współrzędne punktu po t sekundach ruchu, jeśli porusza się on zgodnie z równaniem:
//x(t)=x0+2cos(t), y(t)=y0+3sin(t)
//Dodatkowo wyświetlić informację o tym, w której ćwiartce układu współrzędnych znajduje się punkt po t sekundach ruchu
{
float x0;
float y0;
float t;
float xt;
float yt;

cout<< "Podaj x0 :"<<endl;
cin>>x0;
cout<< "Podaj y0 :"<<endl;
cin>>y0;
cout<< "Podaj t :"<<endl;
cin>>t;

xt = x0 + 2*cos(t);
yt = y0 +3*sin(t);

if (xt<0 && yt>0)
{
    cout<<"Cwiartka 2"<<endl;
}
if (xt>0 && yt>0)
{
    cout<<"Cwiartka 1"<<endl;
}
if (xt<0 && yt<0)
{
    cout<<"Cwiartka 3"<<endl;
}
if (xt>0 && yt<0)
{
    cout<<"Cwiartka 4"<<endl;
}


}


void lab_3_zad_1 () //Wskaźnik masy ciała BMI

{
    string Imie;
    string Nazwisko;
    float BMI;
    float waga;
    float wzrost;
    cout<<"Wpisz Imie ;"<<endl;
    cin>>Imie;
    cout<<"Wpisz Nazwisko ; "<<endl;
    cin>>Nazwisko;
    cout<<"Wpisz wage ; "<<endl;
    cin>>waga;
    cout<<"Wpisz wzrost"<<endl;
    cin>>wzrost;
    BMI = waga/(pow(wzrost,2));
     cout << Imie << " " << Nazwisko << ": " << (BMI < 18.5 ? "niedowaga" : (BMI < 25 ? "w normie" : "nadwaga")) <<endl;
    cout <<BMI<<endl;


}

void lab_3_zad_2 ()//Napisać program, który wyznacza średnią arytmetyczną liczb z przedziału ⟨5,100⟩, które nie są podzielne przez 3 dla ciągu n liczb całkowitych wprowadzonego przez użytkownika z klawiatury (ilość wyrazów ciągu n także podaje użytkownik). Zabezpieczyć program przed sytuacją kiedy takich liczb w wprowadzonym ciągu nie ma (wtedy średnia jest nieokreślona).
{
int x1 = 5;
float n;
cout<<"Podaj do której liczby chcesz obliczyć średnia"<<endl;
cin>>n;
if(n > 101)
    return;
float suma = 0;
float k =0;
for (x1 =5; x1<=n; x1++)
{
    if (x1%3 != 0)
    {
        suma += x1;
        k++;
    }
}
if(k == 0)
    return;
float srednia;
srednia = suma/k;
cout<<"Srednia arytmetyczna wynosi: "<<srednia<<endl;
}

void lab_3_zad_3 () //Napisać program wyznaczający sumę wszystkich dzielników wprowadzonej liczby naturalnej n≥1
{
    cout<<"Wprowadź liczbe której chcesz dzielniki"<<endl;
    int n;
    cin>>n;
    int suma = 0;
    for(int dzielnik =1; dzielnik <= n; dzielnik++)
    {
        if(n%dzielnik == 0)
        {
         suma +=dzielnik;
        }
    }
    cout<<suma;

}

void lab_3_zad_4 ()
{
    string slowo;
    cin>>slowo;
    for (char znak = 'a'; znak <='z'; znak++)
    {
        int ilosc = 0;
        for (int i=0; i<slowo.length(); i++)
        {
            if (slowo [i]==znak)
                ilosc ++;
        }
        if (ilosc >0)
            cout<<"Litera "<<znak<< "wystepuje"<<ilosc<<"razy"<<endl;
    }
}

int main()
{
    zadanie_sam_2();
    return 0;
}



