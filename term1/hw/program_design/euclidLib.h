# include <cmath>
int some_global_variable = 0;
namespace euclidean_geometry{
    namespace plane
    {
        double dist(double x1, double y1, double x2, double y2){
            return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
        }
    }
}
