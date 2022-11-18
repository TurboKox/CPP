#include <iostream>

enum UnitsOfTime
{
	SECONDS, MINUTES, HOURS, DAYS, YEARS
};

float unitValues[] = {
	60.0f, 60.0f, 24.0f, 365.0f
};

float ConvertTimeUnits(float time, UnitsOfTime fromUnit, UnitsOfTime toUnit)
{
	if (fromUnit < toUnit)
	{
		for (int i = fromUnit; i < toUnit; i++)
		{
			time /= unitValues[i];
		}
	}
	else if (fromUnit > toUnit)
	{

		for (int i = fromUnit - 1; i >= toUnit; i--)
		{
			time *= unitValues[i];
		}
	}
	else
	{
		std::cout << "Invalid Conversion" << std::endl;
		exit(0);
	}

	return time;
}

int main()
{
	// t' = t / sqrt(1 - v^2 / c^2)

	float observerTime;
	float numberOfDays = 365.0f;
	float frameOfReferenceTime = ConvertTimeUnits(numberOfDays, DAYS, SECONDS); // convert 1 year to seconds, because we need SI unit in formula
	const float SPEED_OF_LIGHT = 299792458.0f; // meters per second
	float velocity = SPEED_OF_LIGHT * 0.97f;

	observerTime = frameOfReferenceTime / sqrt(1 - (velocity * velocity) / (SPEED_OF_LIGHT * SPEED_OF_LIGHT));

	std::cout << "Time measured from an observer\noutside the frame of reference:\n"
		<< ConvertTimeUnits(observerTime, SECONDS, YEARS) << " years" << std::endl;
}
