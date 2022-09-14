#include "std_lib_facilities.h"

int main()
{
		vector<double> temps; // temperatures
		for (double temp; cin >> temp; ) // read and put into temps
			temps.push_back(temp);
		double sum = 0;
		double high_temp = -100;
		double low_temp = 200;
		for (double x : temps)
		{
			if (x > high_temp) high_temp = x; // find high
			if (x < low_temp) low_temp = x; // find low
			sum += x; // compute sum
		}
		cout << "High temperature: " << high_temp << '\n';
		cout << "Low temperature: " << low_temp << '\n';
		cout << "Average temperature: " << sum / temps.size() << '\n';

	/*try
	{
		int i{};
		cin >> i;
		if (i > 1) error("error");
	}
	catch (runtime_error)
	{
		cout << "Fialure.\n";
	}
	system("pause");*/
	
	return 0;
}
