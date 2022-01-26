#pragma once
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Vehicle;
enum VehicleSize : unsigned int;

class ParkingLot {
public:
	ParkingLot(map<VehicleSize, unsigned int> capacity) : _capacity(capacity) {}
	~ParkingLot() {}

	bool in(const Vehicle *v);
	bool out(const Vehicle *v);

	void show_capacity();
	void show_usage();

private:
	double calc_duration(unsigned int id);

private:
	map<VehicleSize, unsigned int> _capacity;
	map<unsigned int, system_clock::time_point> _in_time; // id -> time of in
};

