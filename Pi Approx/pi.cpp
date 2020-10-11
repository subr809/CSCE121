#include <cstdlib>
#include <cmath>

using std::sqrt;

double approx_pi(int seed, int n) {
	double x, y, landed, pi;
	double counter = 0;
	srand(seed);
	for (int i = 0; i < n; ++i) {
		x = static_cast<double>(rand()) / RAND_MAX;
		y = static_cast<double>(rand()) / RAND_MAX;
		landed = sqrt(pow(x, 2) + pow(y, 2));
		if (landed >= 0 && landed <= 1) {
			counter += 1;
		}
	}
	pi = (counter / n) * 4;
	return pi;
}