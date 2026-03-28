#include <iostream>
#include "appe/math/vec3.h"

int main() {
	std::cout << "----- PHYSICS ENGINE by abhinavp06 -----" << std::endl;

	try {
		Vec3 a(2.0f, 4.0f, -1.0f);
		Vec3 b(3.0f, 6.0f, 9.0f);
		Vec3 result = cross(a, b);
		printf("%f %f %f\n", result.x, result.y, result.z);
	} catch (const std::exception& e) {
		std::cerr << "[Error] " << e.what() << "\n";
		return 1;
	}

	std::cout << "----- GOODBYE -----" << std::endl;

	return 0;
}