#pragma once
#include "Eigen/Sparse"
#include "unsupported/Eigen/AutoDiff"
#include "Point.cpp"
#include "Observation.cpp"
#include "Camera.cpp"
#include "JacobianFunctionWithRespectToRotation.cpp"
#include <iostream>

/*! \brief A class to handle bundle adjustment logic.
* 
* This class handles bundle adjustment logic. It accepts arrays of camera, point and observation objects and calculates and applies deltas via jacobian matrices.
* 
* TODO: Fix this when i figure out how exactly i'm calculating stuff.
*/
class BundleAdjustment {
	public:

		/*! 
		* Constructor function. Used to assign cameras, points and observation arrays.
		* 
		* @param cameras - a hash map of cameras
		* @param points - a hash map of points
		* @param observations - an eigen vector of observations
		*/
		BundleAdjustment(std::map<int, Camera> cameras, std::map<int, Point> points, Eigen::Vector<Observation, -1> observations);
		/*!
		* Destructor function.
		*/
		virtual ~BundleAdjustment();
		/*!
		* A function to build a jacobian matrix for given observations.
		*/
		virtual void buildJacobian();
		/*!
		* A function to calculate residual value between the projection of a 3D point and observed point.
		*/
		virtual void calculateResiduals();
		/*!
		* A function to solve the jacobian matrix and calculate deltas.
		*/
		virtual void solveJacobian();
		/*!
		* A function to apply deltas to the cameras and points.
		*/
		virtual void updateParams();

		std::map<int, Camera> cameras; /*! hash map of camera objects */
		std::map<int, Point> points; /*! hash map of point objects */
		Eigen::Vector<Observation, -1> observations; /*! array of observation objects */

	private: 

		//Eigen::Vector2f pointProjection(Point point, Camera camera);
		//Eigen::Vector3f pointWorldToCameraCoordinates(Point point, Camera camera);
		//float radialDistortion(Point point, Camera camera);
		//Eigen::Vector2f perspectiveDivision(Point point, Camera camera);
};