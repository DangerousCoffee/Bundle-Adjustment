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

		//JacobianCalculator();

	private:
		Camera camera;
		Point point;

};

#endif