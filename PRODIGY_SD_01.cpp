#include <iostream>
#include <iomanip>
using namespace std;

double celsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}
double celsiusToKelvin(double celsius)
{
    return celsius + 273.15;
}
double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
double fahrenheitToKelvin(double fahrenheit)
{
    return (fahrenheit + 459.67) * 5.0 / 9.0;
}
double kelvinToCelsius(double kelvin)
{
    return kelvin - 273.15;
}
double kelvinToFahrenheit(double kelvin)
{
    return (kelvin * 9.0 / 5.0) - 459.67;
}
void convertTemperature(double value, char unit)
{
    cout << fixed << setprecision(2);
    if (unit == 'C' || unit == 'c')
    {
        double fahrenheit = celsiusToFahrenheit(value);
        double kelvin = celsiusToKelvin(value);
        cout << value << " degree Celsius is: " << fahrenheit << " degree Fahrenheit and " << kelvin << " Kelvin" << endl;
    }
    else if (unit == 'F' || unit == 'f')
    {
        double celsius = fahrenheitToCelsius(value);
        double kelvin = fahrenheitToKelvin(value);
        cout << value << " degree Fahrenheit is " << celsius << " degree Celsius and " << kelvin << " Kelvin" << endl;
    }
    else if (unit == 'K' || unit == 'k')
    {
        double celsius = kelvinToCelsius(value);
        double fahrenheit = kelvinToFahrenheit(value);
        cout << value << " Kelvin is " << celsius << " degree Celsius and " << fahrenheit << " degree Fahrenheit" << endl;
    }
    else
    {
        cout << "Invalid unit of measurement. Please enter C for Celsius, F for Fahrenheit, or K for Kelvin." << endl;
    }
}

int main()
{
    double value;
    char unit;

    cout << "                        TEMPERATURE CONVERSION                " << endl;
    cout << "                #   Welcome to the conversion page.   #" << endl;
    cout << endl;
    cout << "                         ****INSTRUCTIONS****           " << endl;
    cout << "1. You will be providing us with a value of certain temperature along with its unit measurement." << endl;
    cout << "My task will be to convert it to another units." << endl
         << "START" << endl;

    cout << "Enter the temperature value: ";
    cin >> value;
    cout << "Enter the unit of measurement (C, F, K): ";
    cin >> unit;

    convertTemperature(value, unit);

    return 0;
}