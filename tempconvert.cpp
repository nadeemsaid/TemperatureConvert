#include <iostream>
#include <stdexcept>

class Temperature {

private:
	double celsius_temp_;

public:
	Temperature();
	void set_C(double c);
	void set_K(double k);
	void set_F(double f);
	double get_C();
	double get_K();
	double get_F();

};

Temperature::Temperature() :
		celsius_temp_ { -273.15 } {
	// Empty Constructor
}

void Temperature::set_C(double c) {
	celsius_temp_ = c;

	if (c < -273.15) {
		celsius_temp_ = -273.15;
		throw std::invalid_argument(
				"Temperature must not be below absolute 0.");
	}
}

void Temperature::set_K(double k) {
	celsius_temp_ = k - 273.15;

	if (k < 0) {
		celsius_temp_ = -273.15;
		throw std::invalid_argument(
				"Temperature must not be below absolute 0.");
	}
}

void Temperature::set_F(double f) {
	celsius_temp_ = (f - 32) / 1.8;

	if (f < -459.67) {
		celsius_temp_ = -273.15;
		throw std::invalid_argument(
				"Temperature must not be below absolute 0.");
	}

}

double Temperature::get_C() {
	return celsius_temp_;
}

double Temperature::get_K() {
	return celsius_temp_ + 273.15;
}

double Temperature::get_F() {
	return ((celsius_temp_) * 1.8) + 32;
}

#ifndef MARMOSET_TESTING
int main();
int main() {
	Temperature T { };

	double Ctemp { 0.0 };
	double Ftemp { 0.0 };
	double Ktemp { 0.0 };

	std::cout << "Please set your desired temperature in Celsius: ";
	std::cin >> Ctemp;
	T.set_C(Ctemp);

	std::cout << "Your temperature in Celsius is " << T.get_C()
			<< " degrees Celsius" << std::endl;
	std::cout << "Your temperature in Celsius is " << T.get_F()
			<< " degrees Fahrenheit" << std::endl;
	std::cout << "Your temperature in Celsius is " << T.get_K() << " Kelvins"
			<< std::endl;

	std::cout << "Please set your desired temperature in Fahrenheit: ";
	std::cin >> Ftemp;
	T.set_F(Ftemp);

	std::cout << "Your temperature in Fahrenheit is " << T.get_C()
			<< " degrees Celsius" << std::endl;
	std::cout << "Your temperature in Fahrenheit is " << T.get_F()
			<< " degrees Fahrenheit" << std::endl;
	std::cout << "Your temperature in Fahrenheit is " << T.get_K() << " Kelvins"
			<< std::endl;

	std::cout << "Please set your desired temperature in Kelvin: ";
	std::cin >> Ktemp;
	T.set_K(Ktemp);

	std::cout << "Your temperature in Kelvins is " << T.get_C()
			<< " degrees Celsius" << std::endl;
	std::cout << "Your temperature in Kelvins is " << T.get_F()
			<< " degrees Fahrenheit" << std::endl;
	std::cout << "Your temperature in Kelvins is " << T.get_K() << " Kelvins"
			<< std::endl;
	return 0;
}
#endif

