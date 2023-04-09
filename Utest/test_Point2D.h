#pragma once
//#include "pch.h"

#include "../Point2D.h"
#include <string>


// тест метода получения координат getX и getY
TEST(TestPoint2D, TestConstuctor) {
	int x[] = { -10, 67, 10, -1000, 0, 234412 };
	int y[] = { -2, 217, 111, -1023, 0, 4412 };

	int x_size = sizeof(x) / sizeof(x[0]);
	int y_size = sizeof(y) / sizeof(y[0]);

	for (int i = 0; i < x_size - 1; i++)
	{
		for (int j = 0; j < y_size - 1; j++) {

			Point2D point(x[i], y[j]);

			ASSERT_EQ(point.getX(), x[i]);
			ASSERT_EQ(point.getY(), y[j]);
		}
	}

}
// тест оператора сравнения ==
TEST(TestPoint2D, TestEQcheck) {

	int x[] = { -10, 67, 10, -1000, 0, 234412 };
	int y[] = { -2, 217, 111, -1023, 0, 4412 };

	int x_size = sizeof(x) / sizeof(x[0]);
	int y_size = sizeof(y) / sizeof(y[0]);

	for (int i = 0; i < x_size - 1; i++)
	{
		for (int j = 0; j < y_size - 1; j++) {

			Point2D point1(x[i], y[j]);
			Point2D point2(x[i], y[j]);

			ASSERT_TRUE(point1 == point2);

			Point2D point3(x[i] + 1, y[j]);
			Point2D point4(x[i], y[j]);

			ASSERT_FALSE(point3 == point4);

			Point2D point5(x[i], y[j]);
			Point2D point6(x[i], y[j] - 1);

			ASSERT_FALSE(point5 == point6);
		}
	}
}

// тест для std::ostream& operator<<(std::ostream& out, const Point2D& point)
TEST(TestPoint2D, TestСonclusion) {

	int x[] = { -10, 67, 10, -1000, 0, 234412 };
	int y[] = { -2, 217, 111, -1023, 0, 4412 };

	int x_size = sizeof(x) / sizeof(x[0]);
	int y_size = sizeof(y) / sizeof(y[0]);

	for (int i = 0; i < x_size - 1; i++)
	{
		for (int j = 0; j < y_size - 1; j++) {

			Point2D point1(x[i], y[j]);
			std::string s2 = "(" + std::to_string(x[i]) + ", " + std::to_string(y[j]) + ')';
			testing::internal::CaptureStdout();                                                    //CaptureStdout начинает захват из области stdout
			std::cout << point1;
			std::string output = testing::internal::GetCapturedStdout();                           //GetCapturedStdout останавливает захват из stdout и передает захваченную строку в переменную
			ASSERT_EQ(output,s2);
			
		}
	}
}


