#include "pyramid.hpp"
#include<cmath>

Pyramid::Pyramid(): Triangle(), _depth{1}, _volume{1/3.0}, _surface_area{3.24} {}

Pyramid::Pyramid(int base, int height, int depth) : Triangle(base, height) {
	set_depth(depth);
	get_dependencies();
}

Pyramid::Pyramid(const Pyramid& p) : Triangle(p), _depth{p._depth},
	_volume{p._volume}, _surface_area{p._surface_area} {
	get_dependencies();
	}

double Pyramid::depth() const{
	return _depth;
}

double Pyramid::volume() const{
	return _volume;
}

double Pyramid::surface_area() const{
	return _surface_area;
}

void Pyramid::set_depth(int new_depth) {
	_depth = new_depth;
	get_dependencies();
}

void Pyramid::set_base(int new_base) {
	_base = new_base;
	get_dependencies();
}

void Pyramid::set_height(int new_height) {
	_height = new_height;
	get_dependencies();

}

void Pyramid::calc_volume() {
	_volume = (_base * _height * _depth) / 3.0;
}

void Pyramid::calc_surface_area() {
	float base_area = base() * height();
	float forward_backward_area = base() * sqrt( ((_depth/2.0) * (_depth/2.0))\
			+ (height() * height()));
	float side_area = _depth * sqrt( ((base() / 2.0) * (base() / 2.0))\
			+ (height() * height()));
	_surface_area = base_area + forward_backward_area + side_area;
}

void Pyramid::get_dependencies(){
	calc_surface_area();
	calc_volume();
}


