#include <iostream>
#include <fstream>
#include "Eigen/Sparse"
#include "Camera.cpp"
#include "Point.cpp"
#include "Observation.cpp"

int main()
{

    std::string filename = "problem - 49 - 7776 - pre.txt"; /*! store input file name */

    std::ifstream file(filename); 

    Eigen::Vector<Observation, -1> observations; /*! array for observations */
    std::map<int, Camera> cameras; /*! hash map for cameras */
    std::map<int, Point> points; /*! hash map for points */

    /*! TODO: maybe make points and cameras arrays into hash maps(preferrable) or binary trees */

    /*! extract number of entries for cameras, points and observations */
    int num_cam, num_points, num_observations;
    file >> num_cam;
    file >> num_points;
    file >> num_observations;

    observations = Eigen::Vector<Observation, -1>(num_observations);

    /*! iterate over observations and add them to array */
    for (int i = 0; i < num_observations; i++) {
        int camera_id, point_id;
        file >> camera_id;
        file >> point_id;

        float pos_x, pos_y;
        file >> pos_x;
        file >> pos_y;

        observations[i] = Observation(i, camera_id, point_id, pos_x, pos_y);
    }

    /*! iterate over cameras and add them to array */
    for (int i = 0; i < num_cam; i++) {
        float rot_x, rot_y, rot_z, pos_x, pos_y, pos_z, focal, coef1, coef2;
        file >> rot_x;
        file >> rot_y;
        file >> rot_z;
        file >> pos_x;
        file >> pos_y;
        file >> pos_z;
        file >> focal;
        file >> coef1;
        file >> coef2;

        cameras[i] = Camera(i, pos_x, pos_y, pos_z, rot_x, rot_y, rot_z, focal, coef1, coef2);

    }

    /*! iterate over points and add them to array */
    for (int i = 0; i < num_points; i++) {
        float pos_x, pos_y, pos_z;
        file >> pos_x;
        file >> pos_y;
        file >> pos_z;

        points[i] = Point(i, pos_x, pos_y, pos_z);
    }

}
