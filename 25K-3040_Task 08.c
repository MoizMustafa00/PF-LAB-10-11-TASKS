#include<stdio.h>
const float mToKm = 0.001;
float meterToKilometer(float m)
{
	static int callCount = 0;
	callCount++;
	printf("Function was Called %d Times\n", callCount);
	return m * mToKm;
}

int main()
{
	float km = meterToKilometer(1000);
	printf("%.2f Meters = %.4f Kilometers\n", (float)1000, km);
	km = meterToKilometer(10000);
	printf("%.2f Meters = %.4f Kilometers\n", (float)10000, km);
	km = meterToKilometer(15000);
	printf("%.2f Meters = %.4f Kilometers\n", (float)15000, km);
	return 0;
}
