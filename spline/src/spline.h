/*
 * Creating an instance of a function
 * at known points using a cubic spline.
 *
 * Example:
 * >> vector<POINT> staticPoints = {{1, 2}, {3, 10}, {21, 33}};
 * >> FUNCTION* func = createFunction(staticPoints);
 * >> long double new_y = func.getY(10);
 *
 * If you search new point x which isn't in [x0, xn],
 * you'll get {GARBAGE, GARBAGE} ~ invalid input.
 *
 */

#ifndef SPLINE_SPLINE_H
#define SPLINE_SPLINE_H

#include <string>
#include <vector>

#define GARBAGE -2103291932413123

using namespace std;

struct POINT {
    long double x, y;
};

struct CONTAINER {
    long double A, B, C, F;
};

POINT getSplinePoint(vector<POINT>& staticPoints, vector<long double>& gammas,
                     long double x);

struct FUNCTION {
    vector<POINT> staticPoints;
    vector<long double> gammas;

    long double getY(long double x) {
        return getSplinePoint(staticPoints, gammas, x).y;
    }
};

FUNCTION* createFunction(vector<POINT>& staticPoints);
void writeSplineInfoFile(const string& name, vector<POINT>& points);
pair<long double, long double> takeMinMaxSplineX(FUNCTION* function);
vector<POINT> buildSplineData(long double start, long double stop,
                              FUNCTION* function);

#endif  // SPLINE_SPLINE_H
