#ifndef MANDEL_H
#define MANDEL_H

#include <iostream>
#include <fstream>
#include <complex>
#include <QColor>

class mandel 
{
private:
	static int maxIterations;
	static std::complex<double> originalPoint; // Used in recursive algorithm
	// This formula is called by val_recur() passing values for maxIterations
	// This allows for a default value for the maxIterations that the client
	// doesn't need to see
	static std::complex<double> val_recur_helper(std::complex<double> num, int n);

public:
	static double magnitude(std::complex<double> num);
	static std::complex<double> pointVal(std::complex<double> num);
	static void setMaxIterations(int n);
    static int getMaxIterations();
	static void printmaxIterations();
	static int colorValue(std::complex<double> );
	static void exportImg(double xMin, double xMax, double yMin, double yMax,
                            QColor color, int imgWidth,
							int imgHeight, int numIterations, std::string path);
};
#endif
