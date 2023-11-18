// Bundle Adjustment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Eigen/Sparse"
#include "Camera.cpp"
#include "Point.cpp"

int main()
{

    std::string filename = "problem - 49 - 7776 - pre.txt";

    std::ifstream file(filename); 

    Eigen::Vector<Camera, -1> cameras;
    Eigen::Vector<Point, -1> points;

    int num_cam, num_points, num_observations;
    file >> num_cam;
    file >> num_points;
    file >> num_observations;

    cameras = Eigen::Vector<Camera, -1>(num_cam);
    points = Eigen::Vector<Point, -1>(num_points);

    for (int i = 0; i < num_observations; i++) {
        int camera_id, point_id;
        file >> camera_id;
        file >> point_id;

        float pos_x, pos_y;
        file >> pos_x;
        file >> pos_y;

        // TOOD: organise into observation array
    }

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

    for (int i = 0; i < num_points; i++) {
        float pos_x, pos_y, pos_z;
        file >> pos_x;
        file >> pos_y;
        file >> pos_z;

        points[i] = Point(i, pos_x, pos_y, pos_z);
    }

    std::cout << "Hello World!\n";
}
