#include "mandel.h"

int mandel::maxIterations = 80;
std::complex<double> mandel::originalPoint; // Originally declared value to be (0,0), removed (unnecessary)

double mandel::magnitude(std::complex<double> num) {
	return sqrt( pow(std::real(num),2) + pow(std::imag(num),2) );
}

std::complex<double> mandel::pointVal(std::complex<double> num) {
	
	originalPoint = num;

	for (unsigned int i = 0; i<maxIterations; ++i) {
		num = num * num + originalPoint;
		if (magnitude(num)>2) {
			break;
		}
	}
	// Reset values of orig point

	return num;
}

int mandel::colorValue(std::complex<double> num) {
	double iterationCount = 0; // using double to avoid static cast later
	originalPoint = num;
	double mag; // local variable to store magnitude
	
	for (unsigned int i = 0; i<maxIterations; ++i) {
		++iterationCount;
		num = num*num + originalPoint;
		mag = magnitude(num);
		if (mag>2){
			break;
		}
	}

	if (mag<=2) {
		return 0; // Value 0 in HSV is black, represents value in Mandelbrot Set
	}
	else  {
		return 255*(iterationCount/maxIterations); // Solution by [CG]Maxime
		// iteration count definitionally between 0 and max Iterations
		// This means iterationCount/maxIterations is a number between 0 and 1
		// Therefore this returns brightness values banded from black to white
	}

}
void mandel::exportImg(double xMin, double xMax, double yMin, double yMax,
                            QColor color, int imgWidth,
							int imgHeight, int numIterations, std::string path) {

	// Implement export function here
    int r, g, b;
    int originalmandelIter = mandel::getMaxIterations();
    mandel::setMaxIterations(numIterations);

    double deltaX = std::abs(xMax - xMin)/imgWidth;
    double deltaY = std::abs(yMax-yMin)/imgHeight;
    double mandelVal;
    std::complex<double> point(0.0,0.0);

    std::ofstream img(path);
    img << "P3" << std::endl;
    img << imgWidth << " " << imgHeight << std::endl;
    img << "255" << std::endl;

    for (int y = 0; y<imgHeight; ++y) {
        for (int x = 0; x<imgWidth; ++x) {
            point = std::complex<double>(xMin + x*deltaX,yMax-y*deltaY);
            color.setHsv(color.hue(),color.saturation(),colorValue(point));
            color.getRgb(&r,&g,&b);

            img << r << " " << g << " " << b << std::endl;
        }
    }
    mandel::setMaxIterations(originalmandelIter);

}


void mandel::setMaxIterations(int n) {
	maxIterations = n;
}

void mandel::printmaxIterations() {
	std::cout << "maxIterations: " << maxIterations << std::endl;
}

int mandel::getMaxIterations() {
    return maxIterations;
}
