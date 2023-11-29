#pragma once
#ifndef JACOBIAN_H
#define JACOBIAN_H


#include "Eigen/Sparse"
#include "unsupported/Eigen/AutoDiff"
#include "Point.cpp"
#include "Observation.cpp"
#include "Camera.cpp"
#include <iostream>

class JacobianCalculator {

	public: 

		JacobianCalculator(Camera camera, Point point);
		~JacobianCalculator();
		void calculateComponentVectors();

		Eigen::Matrix<float, 2, 3> pointCoordinatesJacobian();
		Eigen::Matrix<float, 2, 3> cameraCoordinatesJacobian();
		Eigen::Matrix<float, 2, 9> rotationMatrixJacobian();

	private:
		Camera camera;
		Point point;

		Eigen::Vector3f u;
		Eigen::Vector3f v;
		Eigen::Vector3f w;
		Eigen::Matrix3f rotation_matrix;
		Eigen::Quaternion<float> quaternion;
		Eigen::Vector3f u_partial;
		Eigen::Vector3f v_partial;
		Eigen::Vector3f w_partial;
		Eigen::Vector3f w_squared;
};

#endif