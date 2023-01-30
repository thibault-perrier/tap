#include "math.h"
#include "tools.h"

//
//  TSP - BRUTE-FORCE
//
// -> la structure "point" est définie dans "tools.h"
// -> tsp_main peut être testé dès les 3 premières fonctions codées
//

void copy(int* P, int* Q, int n) {
	for (int i = 0; i < n; i++)
		Q[i] = P[i];
}

double dist(point A, point B) {
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

double value(point* V, int n, int* P) {
	double sum = 0;
	for (int i = 1; i < n; i++)
		sum += dist(V[P[i - 1]], V[P[i]]);
	return sum + dist(V[P[n - 1]], V[P[0]]);
}

double tsp_brute_force(point* V, int n, int* Q) {
	int P[n];
	for (int i = 0; i < n; i++)
		P[i] = i;
	copy(P, Q, n);

	double min_dist = value(V, n, P), curr_dist = 0;

	while (NextPermutation(P, n)) {
		curr_dist = value(V, n, P);
		if (curr_dist < min_dist) {
			min_dist = curr_dist;
			copy(P, Q, n);
		}
	}
	return min_dist;
}

void MaxPermutation(int* P, int n, int k) {
	int tmp;
	for (int i = 0; i < n - k; i++) {
		tmp = P[i + k];
		P[i + k] = P[n - 1 - i];
		P[n - 1 - i] = tmp;
	}
	return;
}

double value_opt(point* V, int n, int* P, double w) {
	double sum = 0;
	for (int i = 1; i < n; i++)
		sum += dist(V[P[i - 1]], V[P[i]]);
	return sum + dist(V[P[n - 1]], V[P[0]]);
	return 0;
}

double tsp_brute_force_opt(point* V, int n, int* Q) {
	int P[n];
	for (int i = 0; i < n; i++)
		P[i] = i;
	copy(P, Q, n);

	double min_dist = value(V, n, P), curr_dist = 0;

	while (NextPermutation(P, n - 1)) {
		curr_dist = value(V, n, P);
		if (curr_dist < min_dist) {
			min_dist = curr_dist;
			copy(P, Q, n);
		}
	}
	return min_dist;
	return 0;
}
