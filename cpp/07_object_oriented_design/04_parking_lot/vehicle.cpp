#include "vehicle.hpp"
#include "parkinglot.hpp"

string size2str(VehicleSize size) {
	switch (size) {
	case VehicleSizeSmall:
		return "VehicleSizeSmall";
	case VehicleSizeMedium:
		return "VehicleSizeMedium";
	case VehicleSizeLarge:
		return "VehicleSizeLarge";
	case VehicleSizeNone:
		return "VehicleSizeNone";
	}
	return "Invalid";
}

bool Vehicle::park(ParkingLot *lot)
{
	if (!_lot && lot->in(this)) {
		_lot = lot;
		return true;
	}

	return false;
}

bool Vehicle::depart() {
	if (_lot)
		return _lot->out(this);

	return false;
}
