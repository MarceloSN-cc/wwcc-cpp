#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

double calculateDistance (double x1, double y1, double x2, double y2) 
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dsqrd = (pow(dx, 2)) + (pow(dy, 2));
    double result = sqrt(dsqrd);
    return result;
}

void calculateMidPoint(double x1, double y1, double x2, double y2, double &mx, double &my)
{
    mx = (x1 + x2)/2;
    my = (y1 + y2)/2;
}

int main () 
{
    double x1, y1, x2, y2;
    cout << "Enter the coordinates of the first point: " << endl;
    cout << "x1: " << endl;
    cin >> x1;
    cout << "y1: " << endl;
    cin >> y1;
    cout << "Enter the coordinates of the second point: " << endl;
    cout << "x2: " << endl;
    cin >> x2;
    cout << "y2: " << endl;
    cin >> y2;
    
    double dist = calculateDistance (x1, y1, x2, y2);
    double mx, my;
    calculateMidPoint(x1, y1, x2, y2, mx, my);

    cout << fixed << setprecision(2);
    cout << "The distance between (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is: " << dist << endl;
    
    cout << " The midpoint between these coordinates is: (" << mx << "," << my << ")" << endl;

    return 0;
}