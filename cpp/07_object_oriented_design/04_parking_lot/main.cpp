#include <iostream>
#include <vector>

#include "parkinglot.hpp"
#include "vehicle.hpp"

using namespace std;

int main(void)
{
	map<VehicleSize, unsigned int> capacity;
	map<unsigned int, Vehicle *> vehicles;
	unsigned int id = 0;

	capacity[VehicleSizeSmall] = 10;
	capacity[VehicleSizeMedium] = 20;
	capacity[VehicleSizeLarge] = 5;
	ParkingLot parking(capacity);

	while (true) {
		unsigned int a;
		cout << "choose action (0: exit, 1: park, 2: depart): ";
		cin >> a;

		if (a == 0) { /* exit */
			break;
		} else if (a == 1) { /* park */
			unsigned int t;
			cout << "choose vehicle type (0: bike, 1: car, 2: bus): ";
			cin >> t;

			Vehicle *v = NULL;
			if (t == 0) v = new Bike(id);
			else if (t == 1) v = new Car(id);
			else if (t == 2) v = new Bus(id);

			if (v) {
				if (v->park(&parking)) {
					vehicles[id++] = v;
				} else {
					cerr << "[ERROR] failed to park." << endl;
					delete v;
				}
			} else {
				cerr << "[ERROR] invalid type." << endl;
			}
		} else if (a == 2) { /* depart */
			unsigned int i;
			cout << "input vehicle id: ";
			cin >> i;

			auto itr = vehicles.find(i);
			if (itr != vehicles.end()) {
				itr->second->depart();
				delete itr->second;
				vehicles.erase(itr);
			} else {
				cerr << "[ERROR] not found." << endl;
			}
		}

		cout << endl;
		parking.show_capacity();
		parking.show_usage();

		cout << "=== vehicles ===" << endl;
		cout << "id\t: size" << endl;
		for (auto v : vehicles)
			cout << v.first << "\t: " << size2str(v.second->size()) << endl;
		cout << endl;
	}

	for (auto v : vehicles)
		delete v.second;

	return 0;
}
