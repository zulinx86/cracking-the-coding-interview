#pragma once
#include <iostream>
#include <string>

using namespace std;

enum VehicleSize : unsigned int {
	VehicleSizeSmall,
	VehicleSizeMedium,
	VehicleSizeLarge,
	VehicleSizeNone,
};

string size2str(VehicleSize size);

class ParkingLot;
class Vehicle {
public:
	Vehicle() : _id(-1), _size(VehicleSizeNone), _lot(NULL) {}
	Vehicle(unsigned int id) : _id(id), _size(VehicleSizeNone), _lot(NULL) {}
	Vehicle(unsigned int id, VehicleSize size) : _id(id), _size(size), _lot(NULL) {}
	~Vehicle() {}

	bool park(ParkingLot *lot); 
	bool depart();

	VehicleSize size() const { return _size; }
	unsigned int id() const { return _id; }

protected:
	unsigned int _id;
	VehicleSize _size;
	ParkingLot *_lot;
};

class Bus : public Vehicle {
public:
	Bus(unsigned int id) : Vehicle(id, VehicleSizeLarge) {}
	~Bus() {}
};

class Car : public Vehicle {
public:
	Car(unsigned int id) : Vehicle(id, VehicleSizeMedium) {}
	~Car() {}
};

class Bike : public Vehicle {
public:
	Bike(unsigned int id) : Vehicle(id, VehicleSizeSmall) {}
	~Bike() {}
};

