#include <iostream>
#include <random>

int main()
{
    // Generator liczb losowych
    std::mt19937 gen { std::random_device{}() };
    // Rozklad jednorodny na przedziale -1.0 do 1.0
    std::uniform_real_distribution<double> losuj{ -1., 1. };

    int punktow_w_kwadracie = 0; // Liczba punktow w kwadracie
    int punktow_w_kole = 0;      // Liczba punktow w kole

    // Liczby punktow mozemy przyjac jako dyskretna forme pola powierzchni,
    // stad, im wiecej punktow zalozymy, tym lepsza dokladnosc liczby pi

    std::cout << "Podaj liczbe losowanych punktow: ";
    std::cin >> punktow_w_kwadracie;

    double x, y;
    for (int i = 0; i < punktow_w_kwadracie; ++i)
    {
        x = losuj(gen);
        y = losuj(gen);

        // Sprawdzamy czy wylosowany punkt o wspolrzednych (x, y)
        // znajduje sie w kole o wzorze x^2 + y^2 <= 1
        // Wzor ten okresla kolo wpisane w kwadrat na przedziale
        // x i y = < -1, 1 >

        if (x * x + y * y <= 1)
        {
            // Akceptujemy punkty w kole
            ++punktow_w_kole;
        }
    }

    // Wiemy, ze pole powierzchni kola wpisanego w kwadrat o boku 2
    // wynosi dokladnie pi. Stosunek pola tego kola do kwadratu to
    // pi/4. A wiec aby uzyskac przyblizenie liczby pi wystarczy
    // policzyc stosunek punktow_w_kole do punktow_w_kwadracie razy 4

    std::cout << "Liczba punktow w kole = " << punktow_w_kole << std::endl;
    std::cout << "Liczba punktow w kwadracie = " << punktow_w_kwadracie << std::endl;
    double _PI_ = 4. * punktow_w_kole / punktow_w_kwadracie;
    std::cout << "Szukana liczba pi = " << _PI_ << std::endl;
}
