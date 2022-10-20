#ifndef DERIVED_PYRAMID_HPP
#define DERIVED_PYRAMID_HPP
//Header Guards are in place to prevent us from defining something multiple times

#include "triangle.hpp"

class Pyramid : public Triangle, public Shape3D {
	private: 
		void calc_volume() override;
		void calc_surface_area() override;
		void get_dependencies() override;

	public:
		Pyramid();
		Pyramid(int base, int height, int depth);
		Pyramid(const Pyramid& p);

		//Getters have been moved to Shape3D

		//Setters
		void set_depth(int new_depth);
		void set_base(int new_base) override;
		void set_height(int new_height) override;
		
};

#endif
