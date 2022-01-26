#include "parkinglot.hpp"
#include "vehicle.hpp"

bool ParkingLot::in(const Vehicle *v) {
	auto itr = _capacity.find(v->size());
	if (itr != _capacity.end() && itr->second) {
		itr->second--;
		_in_time[v->id()] = system_clock::now();
		return true;
	}

	return false;
}

bool ParkingLot::out(const Vehicle *v) {
	auto itr = _capacity.find(v->size());
	if (itr != _capacity.end()) {
		itr->second++;

		cout << calc_duration(v->id()) << endl;
		_in_time.erase(v->id());

		return true;
	}

	return false;
}

void ParkingLot::show_capacity() {
	cout << "=== capacity ===" << endl;
	for (auto i : _capacity)
		cout << size2str(i.first) << "\t: " << i.second << endl;
}

void ParkingLot::show_usage() {
	cout << "=== usage ===" << endl;
	cout << "id\t: duration" << endl;
	for (auto i : _in_time)
		cout << i.first << "\t: " << calc_duration(i.first) << endl;
}

double ParkingLot::calc_duration(unsigned int id) {
	system_clock::time_point now = system_clock::now();
	return duration_cast<seconds>(now - _in_time[id]).count();
}
