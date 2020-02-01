#include <stdio.h>


float mph_to_kmh(float mph)
{
	const float mile_in_kilometers = 1.609344;
	return mph * mile_in_kilometers;
}

int main()
{
	for (float mph = 5.0; mph <= 100.0; mph += 5.0) {
		float kmh = mph_to_kmh(mph);
		printf("%5.1f mph\t%5.1f km/h\n", mph, kmh);
	}

	return 0;
}
