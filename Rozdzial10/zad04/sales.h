namespace SALES {
    class Sales {
        enum { QUARTERS = 4 };
        double sales[QUARTERS];
        double _average;
        double _max;
        double _min;
    public:
        // kopiuje tablicę ar
        // do składowej sales struktury s i oblicza oraz zachowuje w odpowiednich
        // składowych struktury sales wartości: śrenią, minimalną, maksymalną;
        // zeruje pozostałe elementy tablicy sales (jeśli są)
        Sales();
        // pobiera interaktywnie informacje dla 4 kwartałów
        // zachowuje je w składowej sales struktury s i oblicza oraz zachowuje
        // w odpowiednich składowych s wartość średnią, minimalną i maksymalną
        Sales(const double ar[], int n);
        void showSales() const;
    };
}