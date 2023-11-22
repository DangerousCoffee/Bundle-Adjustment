#include "BA_Algorithm.h"

template <short N_IN, short N_OUT>
class JacobianFunction {	
	public:
		
		enum {
			InputesAtCompile = N_IN,
			ValuesAtCompile = N_OUT
		};

		typedef Eigen::Matrix<float, N_IN, 1> InputType;
		typedef Eigen::Matrix<float, N_OUT, 1> ValueType;

		template <typename T>
		void operator()
		{
			const Eigen::Matrix<T, N_IN, 1>& vIn,
			Eigen::Matrix<T, N_OUT, 1>* vOut
		} const
		{
			
		}
};