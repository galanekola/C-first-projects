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
    int suma = 1;
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
    cout<<"Min"<<min<<endl;
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

void lab2_1 ()//Napisać program wyznaczający n-ty wyraz ciągu Fibonacciego określonego rekurencyjnie: Fn+2=Fn+Fn+1,n≥1, przy czym F1=F2=1. Liczbę n należy pobrać od użytkownika.
{
    int fib;
    cout<<"Podaj numer wyrazu ktory chcesz wyznaczyc:";
    int n;
    cin>>n;

//wczytac liczbe n (numer wyrazu, ktory chcemy wyznaczyc):

    int przedostatni_wyraz= 1; //wyraz i w danym kroku, tutaj: wstepna wartosc tego wyrazu
    int przedprzedostatni_wyraz = 0; //wyraz i+1 w danym kroku, tutaj: wstepna wartosc tego wyrazu
    if (n==0)
    {
        fib = 0;
    }
    if (n==1)
    {
        fib =1;
    }
    for (int i=2; i<=n; i++)
    {
        fib = przedostatni_wyraz + przedprzedostatni_wyraz;
        //aktualizujemy wartosci zmiennych przedostatni_wyraz, przedprzedostatni_wyraz:

        przedprzedostatni_wyraz = przedostatni_wyraz;
        przedostatni_wyraz  = fib;
    }
    cout<<fib<<endl;
}

void lab2_2 () //Napisać program wyznaczający rozstęp ciągu n liczb całkowitych (rozstęp, to różnica pomiędzy maksimum,
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
void lab2_4 ()//program który jest grą polegającą na zgadywaniu przez użytkownika liczby wylosowanej przez generator liczb pseudolosowych.
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
void lab2_5 ()//Napisać program wyznaczający przybliżoną wartość całki I=∫10x3dx za pomocą metody trapezów (patrz: Całkowanie numeryczne (wikipedia)). Przedział ⟨0;1⟩ podzielić na n punktów, przy czym liczbę n podaje użytkownik. Wynik obliczeń numerycznych porównać z wynikiem dokładnym I=0,25, tzn. wyznaczyć błąd względny przybliżenia i wyrazić go w procentach (błąd względny, to bezwzględna wartość różnicy przybliżenia i dokładnej wartości podzielona przez dokładną wartość, aby wyrazić go w procentach należy jego wartość pomnożyć przez 100). Czy zwiększenie ilości punktów pośrednich n poprawia wynik? co się dzieje kiedy podamy za duże n (np. n=10000)? Wskazówka: zdefiniować zmienną delta_x=1/(float)n (długość przedziału przez ilość punktów pośrednich) oraz zmienną calka, której wartość początkowo wynosi zero. W pętli for zdefiniować zmienne x1 i x2, które są kolejnymi punktami pośrednimi oraz do aktualnej wartości zmiennej calka dodać pole odpowiedniego trapezu.
{
    int przedzial_min=0;
    int przedzial_max=1;
    cout<<"Podaj n:"<<endl;
    float n;
    cin>>n;
    float calka =0;
    float h=(przedzial_max - przedzial_min)/n;

    for (int i=1; i<n; i++)
    {
        calka += pow((przedzial_min + i *h),3);
    }
    calka += (pow(przedzial_min,3) + pow(przedzial_max,3))/2;
    calka *=h;
    cout<<"Wynik calkowania: "<<calka<<endl;
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


void lab3_1 () //Wskaźnik masy ciała BMI

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

void lab3_2 ()//Napisać program, który wyznacza średnią arytmetyczną liczb z przedziału ⟨5,100⟩, które nie są podzielne przez 3 dla ciągu n liczb całkowitych wprowadzonego przez użytkownika z klawiatury (ilość wyrazów ciągu n także podaje użytkownik). Zabezpieczyć program przed sytuacją kiedy takich liczb w wprowadzonym ciągu nie ma (wtedy średnia jest nieokreślona).
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

void lab3_3 () //Napisać program wyznaczający sumę wszystkich dzielników wprowadzonej liczby naturalnej n≥1
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

void lab3_4 ()//Napisać program, który wyznacza liczby wystąpień poszczególnych liter alfabetu w słowie wprowadzonym z klawiatury przez użytkownika, przy czym wyświetlane są tylko ilości wystąpień tych liter, które faktycznie występują w danym słowie.
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
float celcjusz_na_farenhajty (float a)
{

    return (((a*9)/5)+32);
}
float farenhajty_na_celcjusze (float a)
{
    return ((((a-32)*5)/9));
}
void lab3_5() //Zmodyfikować trzeci program (gra Czolgi) w ten sposób aby każdy z czołgów potrzebował trzech trafień aby zostać zniszczony, po każdym trafieniu zwiększyć odległość pomiędzy czołgami losowo w zakresie od 100m do 500m. Oczywiście po każdym trafieniu należy podać informację o nowej odległości, podobnie jak i informację o ilości trafień obu czołgów
{
        srand(time(NULL));
    bool trafiony_gracz_1 = false; //zmienna logiczna: true, jesli gracz 1 zostal trafiony
    bool trafiony_gracz_2 = false; //zmienna logiczna: true, jesli gracz 2 zostal trafiony
    int zycie_czolgu_1 = 3;
    int zycie_czolgu_2 = 3;
    float w = 4; //szerokosc czolgu w [m]
    float dx = 2000; //odleglosc miedzy czolgami w [m]
    float v0; //predkosc poczatkowa pocisku w [m/s]
    float alpha; //kat nachylenia lufy do poziomu w stopniach
    int kolejka = 0; //zmienna pozwalajaca wyznaczyc gracza, ktory ma wykonac ruch
    float wplyw_wiatru; //wplyw wiatru na predkosc poczatkowa pocisku
    float xpocisku; //miejsce uderzenia pocisku w ziemie
    string nazwa_gracz_1, nazwa_gracz_2; //nazwy graczy 1 i 2;
    const float g = 9.81; //przyspieszenie ziemskie
    const float PI = 3.14; //przyblizenie liczby PI

    cout<<"Nazwa gracza 1: ";
    cin>>nazwa_gracz_1;
    cout<<"Nazwa gracza 2: ";
    cin>>nazwa_gracz_2;

    system("cls");

    while (zycie_czolgu_1 > 0 && zycie_czolgu_2 > 0) {
          wplyw_wiatru = rand()%9-4; //losuje liczbe ze zbioru {-4,-3,-2,-1,0,1,2,3,4}
          if (kolejka == 0) {
             //ruch gracza 1:
             cout << "Twoje zycie: "<<zycie_czolgu_1<<endl;
             cout << "Zycie przeciwnika: "<<zycie_czolgu_2<<endl;
             cout<<nazwa_gracz_1<<" podaj predkosc poczatkowa pocisku (w [m/s]): ";
             cin>>v0;
             cout<<nazwa_gracz_1<<" podaj kat nachylenia lufy do poziomu (w stopniach): ";
             cin>>alpha;
             xpocisku = v0*v0*sin(2*alpha*PI/180.0)/g;
             xpocisku += wplyw_wiatru;
             if (fabs(dx-xpocisku)<= 0.5*w) {
                int random = rand() % 401 + 100;
                dx += random;
                zycie_czolgu_2--;
                cout<<"TRAFIENIE!"<<endl;
                cout << "Pozostale zycie przeciwnika: "<<zycie_czolgu_2;
                system("pause");
             }
             else {
                cout<<"Pudlo! Pocisk wyladowal w odleglosci: "<<xpocisku<<endl;
                cout<<"Spudlowales o "<<fabs(dx-xpocisku)<<" [m]"<<endl;
                cout<<"Wiatr zmienil miejsce uderzenia pocisku o "<<wplyw_wiatru<<" [m]"<<endl<<endl;
             }

             kolejka = 1; //po wykonaniu ruchu przez gracza 1, kolejka przechodzi na gracza 2
          } else {
             //ruch gracza 2
             cout << "Twoje zycie: "<<zycie_czolgu_1<<endl;
             cout << "Zycie przeciwnika: "<<zycie_czolgu_2<<endl;
             cout<<nazwa_gracz_2<<" podaj predkosc poczatkowa pocisku (w [m/s]): ";
             cin>>v0;
             cout<<nazwa_gracz_2<<" podaj kat nachylenia lufy do poziomu (w stopniach): ";
             cin>>alpha;
             xpocisku = v0*v0*sin(2*alpha*PI/180.0)/g;
             xpocisku += wplyw_wiatru;
             if (fabs(dx-xpocisku)<= 0.5*w) {
                int random = rand() % 401 + 100;
                dx += random;
                zycie_czolgu_1--;
                cout<<"TRAFIENIE!"<<endl;
                cout << "Pozostale zycie przeciwnika: "<<zycie_czolgu_1;
                system("pause");
             }
             else {
                cout<<"Pudlo! Pocisk wyladowal w odleglosci: "<<xpocisku<<endl;
                cout<<"Spudlowales o "<<fabs(dx-xpocisku)<<" [m]"<<endl;
                cout<<"Wiatr zmienil miejsce uderzenia pocisku o "<<wplyw_wiatru<<" [m]"<<endl<<endl;
             }

             kolejka = 0; //po wykonaniu ruchu przez gracza 2, kolejka przechodzi na gracza 1
          }
    }

    system("cls");

    //wyswietlic komunikat o wygranej gracza 1 lub 2
    if (zycie_czolgu_1 <= 0)
       cout<<nazwa_gracz_2<<" wygral!"<<endl;
    else
       cout<<nazwa_gracz_1<<" wygral!"<<endl;


    system("PAUSE");
}

void lab5_1 () //Napisać program, który wykorzystuje dwie funkcje: cejsjusze_na_fahrenheity i fahrenheity_na_celsjusze (obie zwracają wartości typu float i mają jeden argument także typu float) do odpowiedzi na pytania:
//W jakiej temperaturze (w skali Fahrenheita) zamarza woda, a w jakiej wrze?
//Jaka temperatura (w skali Celsjusza) odpowiada temperaturze 0∘F i 100∘F w skali Fahrenheita?
{
    float a;
    char wybor;
    cout<<"1 - zamiana z F na C"<<endl;
    cout<<"2 - zamiana z C na F"<<endl;
    cin>>wybor;
    cout<<"Podaj liczbe ktora chcesz zamienic"<<endl;
    cin>>a;
   switch (wybor)
   {

   case '1':
    {
       cout<<farenhajty_na_celcjusze(a)<<endl;
        break;
    }
   case '2':
    {
        cout<<celcjusz_na_farenhajty (a)<<endl;

        break;
    }
   }
}
void lab5_2() //Wykorzystując funkcję czy_pierwsza z przykładowego programu pierwszego, napisać program wyświetlający wszystkie liczby pierwsze z przedziału ⟨2,1000⟩ oraz wyznaczający ich ilość.
{
    int pierwsze = 0;
    for (int i=2; i<=1000; i++)
    {
        int ilosc = 0;
        for (int dzielnik=2; dzielnik<i; dzielnik++)
        {
            if (i%dzielnik == 0)
            {
                ilosc++;
            }
        }
        if(ilosc == 0)
        {
            pierwsze++;
        }
    }
    cout<<"ilosc liczb pierwwszych wynosi: "<<pierwsze<<endl;

     double aproksymacja = 1000 / log(1000);
    cout << "Aproksymacja ilości liczb pierwszych: " << aproksymacja << endl;
    cout << "Różnica między ilością a aproksymacją: " << abs(pierwsze - aproksymacja) << endl;
}

int lab5_3(int x, int n) //Za pomocą funkcji rekurencyjnej potega(int x,int n) wyznaczyć xn (liczby x i n podaje użytkownik, wskazówka: wykorzystaj rekurencyjną definicję potęgi: x0=1 oraz xn=xn−1⋅x dla n≥1
{
    if(n == 0)
    {
        return 1;
    }
    else return lab5_3(x,n-1) * x;
}

void odgadywanie(string haslo,char znak,string &napis,int &ilosc_odslonietych)
{
    for (int i=0;i<haslo.length();i++)
       if (haslo[i] == znak)
       {
           napis[i] = znak;
           ilosc_odslonietych++;
       }

}


void lab5_4() //Napisać program, który polega na zgadywaniu przez użytkownika hasła przechowywanego w zmiennej haslo typu string. Warunek zakończenia pętli: zgadnięcie hasła przez użytkownika.
{
    string haslo = "ola galanek";
    string odgadywanie_hasla;
    char znak;
    int ile_odslonietych = 0;
    odgadywanie_hasla = haslo;

    for (int i=0; i<odgadywanie_hasla.length();i++)
        if (haslo[i] != ' ')
            odgadywanie_hasla[i]='*';

         else
            ile_odslonietych++;

    while (ile_odslonietych < haslo.length())
    {
        system("cls");
        cout<<odgadywanie_hasla<<endl;
        cout<<"Podaj litere:";
        cin>>znak;
        odgadywanie (haslo,znak,odgadywanie_hasla, ile_odslonietych);
    }
     system("cls");
  cout<<"HASLO: "<<haslo<<endl;
  cout<<"Brawo!!! Haslo zostalo odgadniete."<<endl;
  system("pause");
}


void odgadywanie2(string haslo,char znak,string &napis,int &ilosc_odslonietych, int &zysk)
{
    srand(time(NULL));
    int losowanie;
    losowanie = 1+rand()%100;

    for (int i=0;i<haslo.length();i++)
       if (haslo[i] == znak)
       {
           napis[i] = znak;
           ilosc_odslonietych++;
           if(losowanie<26)
           {
               zysk +=100;
           }
           if(losowanie>25 && losowanie<51)
           {
               zysk +=200;
           }
           if(losowanie>50 && losowanie<61)
           {
               zysk +=400;
           }
           if(losowanie>60)
           {
               zysk = 0;
           }
           cout<<"Obecny stan konta: "<<zysk<<endl;
       }

}


void lab5_5() //Napisać program, który polega na zgadywaniu przez użytkownika hasła przechowywanego w zmiennej haslo typu string. Warunek zakończenia pętli: zgadnięcie hasła przez użytkownika.
{
    int zysk =0;
    string haslo = "ola galanek";
    string odgadywanie_hasla;
    char znak;
    int ile_odslonietych = 0;
    odgadywanie_hasla = haslo;

    for (int i=0; i<odgadywanie_hasla.length();i++)
        if (haslo[i] != ' ')
            odgadywanie_hasla[i]='*';

         else
            ile_odslonietych++;

    while (ile_odslonietych < haslo.length())
    {
        system("cls");
        cout<<odgadywanie_hasla<<endl;
        cout<<"Obecny stan konta: "<<zysk<<endl;
        cout<<"Podaj litere:";
        cin>>znak;
        odgadywanie2 (haslo,znak,odgadywanie_hasla, ile_odslonietych, zysk);
    }
     system("cls");
  cout<<"HASLO: "<<haslo<<endl;
  cout<<"Brawo!!! Haslo zostalo odgadniete."<<endl;
  cout<<"Nagroda wynosi: "<<zysk<<endl;
  system("pause");

}
vector<int>oceny;
void lab6_1 () //Napisać program, który pobiera od użytkownika ilość ocen (nie większą niż 100), następnie wypełnia podanymi przez użytkownika ocenami tablicę, a następnie wyznacza średnią arytmetyczną ocen i ich odchylenie standardowe σ
{
    int suma = 0;
    cout<<"Podaj ilosc ocen"<<endl;
    int rozmiar;
    cin>>rozmiar;

    for (int i=0; i<rozmiar; i++)
    {
        cout<<"Podaj ocene"<<endl;
        int ocena;
        cin>>ocena;
        oceny.push_back(ocena);
        suma += ocena;

        if (i>100)
        {
            break;
        }
    }
    cout<<"Srednia arytmetyczna wynosi: "<<suma/oceny.size()<<endl;
int a;
    for (int i=0; i<oceny.size(); i++)
    {
        a += pow((oceny[i] - (suma/oceny.size())),2);
    }
    cout<<"Odchylenie standardowe wynosi: "<<sqrt(a/oceny.size())<<endl;
}

vector<int>fibonaczi;
void lab6_2()//Napisać program, który wyznacza 20 pierwszych liczb Fibonacciego (definicja: F1=F2=1, Fn=Fn−1+Fn−2, dla n=3,4,…) i przechowuje je w tablicy. A następnie dla i=2,3,…,18 sprawdzić czy zachodzi równość:
{
int przedostatni_wyraz = 1;
int przedprzedostatni_wyraz = 1;
fibonaczi.push_back(1);
fibonaczi.push_back(1);
int fib;
    for (int i=2; i<21; i++)
    {
        fib = przedostatni_wyraz + przedprzedostatni_wyraz;
        przedprzedostatni_wyraz = przedostatni_wyraz;
        przedostatni_wyraz = fib;
        fibonaczi.push_back(fib);
    }
    for (int i=0; i<21; i++)
    {
        cout<<fibonaczi[i]<<endl;
    }
}

bool czy_palindrom (string napis)
{
    for (int i=0; i<napis.length(); i++)
    {
       if (napis[i]!=napis[napis.length()-1-i])
           {
               return (false);
           }
    }
    return (true);
}
    //definicje zadeklarowanych funkcji:
void wektor(float x[], float y[], float v[])
{
     for (int i=0;i<3;i++)
     {
         v[i] = y[i]-x[i];
     }
}

float iloczyn_skalarny(float u[],float v[])
{
     return (u[0]*v[0]+u[1]*v[1]+u[2]*v[2]);
}

void iloczyn_wektorowy(float u[], float v[], float w[])
{
     w[0] = u[1]*v[2]-u[2]*v[1];
     w[1] = -u[0]*v[2]+u[2]*v[1];
     w[2] = u[0]*v[1]-u[1]*v[2];
}

float dlugosc(float v[])
{
     return sqrt(pow(v[0],2) +pow (v[1],2)+pow(v[2],2));
}
void lab6_3()//Napisać program, który dla podanych trzech wierzchołków trójkąta A=(xA,yA,zA), B=(xB,yB,zB), C=(xC,yC,zC) wyznacza: kąty wewnętrzne trójkąta i wyraża je w stopniach (sprawdzamy także czy suma kątów wewnętrznych wynosi 180∘ długości boków trójkąta pole trójkąta
{
const float PI = 3.14159; //przyblizenie dziesietne liczby pi
    //1) definiujemy punkty A, B, C:
    float A[] = {-1,2.34,5}; //wspolrzedne pierwszego punktu
    float B[] = {2.6,3.5,-1.3}; //wspolrzedne drugiego punktu
    float C[] = {0.5,-2.1,1}; //wspolrzedne trzeciego punktu

    //wyznaczamy katy wewnatrzne trojkata:
    //- kat przy wierzcholku A:
    float AB[3];
    wektor(A,B,AB);
    float AC[3];
    wektor(A,C,AC);
    float dAB = dlugosc(AB);
    float dAC = dlugosc(AC);
    float katA = 180/PI*acos(iloczyn_skalarny(AB,AC)/(dAB*dAC)); //acos to arccos (arcus cosinus)
    cout<<"kat przy wierzcholku A wynosi: "<<katA<<" stopni"<<endl;
    //- kat przy wierzcholku B:
    float BA[3];
    wektor (B,A,BA);
    float BC[3];
    wektor (B,C,BC);
    float dBC = dlugosc(BC);
    float dBA = dlugosc(BA);
    float katB = 180/PI*acos(iloczyn_skalarny(BA,BC)/(dBA*dBC));
     cout<<"kat przy wierzcholku B wynosi: "<<katB<<" stopni"<<endl;

    //- kat przy wierzcholku C:
    float CA[3];
    wektor (C,A,CA);
    float CB[3];
    wektor (C,B,CB);
    float dCB = dlugosc(CB);
    float dCA = dlugosc (CA);
    float katC = 180/PI*acos(iloczyn_skalarny(CA,CB)/(dCA*dCB));
  cout<<"kat przy wierzcholku C wynosi: "<<katC<<" stopni"<<endl;
   //wyswietlmy sume katow wewnetrznych trojkata (powinno wyjsc 180):
   cout<<" Suma katow wewnetrznych trojkata wynosi:" <<katA+katB+katC<<endl;


    //wyswietlamy dlugosci bokow trojkata
    cout<<"Bok AB wynosi: "<<dAB<<endl;
    cout<<"Bok AC wynosi: "<<dAC<<endl;
    cout<<"Bok BC wynosi: "<<dBC<<endl;



    //wyznaczamy pole trojkata ABC:
    float n[3];
    iloczyn_wektorowy(AC,AB,n);
    cout<<"Pole trojkata ABC: "<<dlugosc(n)/2<<endl;

    system("PAUSE");
}

void lab6_4()//Napisać program, który dla pobranego od użytkownika napisu bez spacji sprawdza czy jest on palindromem czy też nie (palindrom, to wyraz, który czyta się tak samo wspak i normalnie, np. kajak, abba, "kobyła ma mały bok" itp.). Sprawdzanie czy dany napis jest palindronem zaimplementować w funkcji bool czy_palindrom(string napis);
{
string napis;
    cout<<"Podaj wyraz"<<endl;
    cin>>napis;
    if (czy_palindrom(napis)== true)
        cout<<"Wyraz jest palindromem"<<endl;
    else
        cout<<"Wyraz nie jest palindromem"<<endl;
}

vector<int>zywi;
void lab6_5() //Napisać program rozwiązujący problem Flawiusza dla k=2 (patrz link z Wikipedii). W skrócie sformułowanie problemu Flawiusza jest następujące: w kole stoją osoby ponumerowane od 1 do n (osoby n i 1 są sąsiadami)zabijana jest co druga osoba, aż do momentu kiedy pozostanie tylko jedna dla danej liczby osób n, wyznaczyć numer osoby przeżywającej
{
    int k=2;
    int n;
    cout<<"Podaj n"<<endl;
    cin>>n;
    int nastepny = 0;
    int nastepny_nastepny = 1;

    for (int i=1; i<=n; i++)
        zywi.push_back(i);

    bool czy_zostal_ostatni = false;

    while (czy_zostal_ostatni == false)
    {
        zywi[nastepny_nastepny]=0;
        bool wyznacz_nastepny = false;
        bool wyznacz_nastepny_nastepny = false;
        int i = nastepny_nastepny;
        while (wyznacz_nastepny == false)
        {
            i+=1;
            if (i>=zywi.size())
                i=0;
            if (zywi[i]!= 0)
            {
                nastepny =i;
                wyznacz_nastepny = true;
            }
        }

        i= nastepny;
        while (wyznacz_nastepny_nastepny ==false)
        {
            i+=1;
            if (i>=zywi.size())
                i=0;
            if (zywi[i]!= 0)
            {
                nastepny_nastepny =i;
                wyznacz_nastepny_nastepny = true;
            }
        }
        int a =0;
        for(int j=0; j<zywi.size(); j++)
        {
            if (zywi[j]!= 0)
                a++;
        }
        if (a==1)
            czy_zostal_ostatni = true;
    }
    for(int j=0; j<zywi.size(); j++)
        {
            if (zywi[j]!= 0)
                cout<<"Ostatnia osoba to: "<<zywi[j]<<endl;
        }
}

int main()
{
    lab6_5();
    return 0;
}



