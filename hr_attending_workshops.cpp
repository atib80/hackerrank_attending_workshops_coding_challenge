//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
// #include <memory>

template <typename... _Args>
void unused_args(const _Args&...) { }

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {

	int start_time;
	int duration;
	int end_time;

};

struct Available_Workshops {

	Available_Workshops(const int ws_size) : n{ ws_size }, workshops{ new Workshop[ws_size]{} } {

	}

	~Available_Workshops() {

		if (workshops) {

			delete[] workshops;

			workshops = nullptr;
		}
	}

	const int n;

	Workshop* workshops;

};

Available_Workshops* initialize(const int* start_time, const int* duration, const int n) {

	Available_Workshops* ws = new (nothrow) Available_Workshops(n);

	if (!ws) return nullptr;

	for (int i{}; i != n; i++) {

		ws->workshops[i].start_time = start_time[i];

		ws->workshops[i].duration = duration[i];

	}

	// delete[] start_time;
	// delete[] duration;

	sort(ws->workshops, ws->workshops + n, [](const Workshop& lhs, const Workshop& rhs) {
		return ((lhs.start_time + lhs.duration) < rhs.start_time);
	});


	return ws;
}

int CalculateMaxWorkshops(const Available_Workshops* ws) {

	if (!ws) return 0;

	if (1 == ws->n) return 1;

	map<int, set<int>> workshop_start_times_and_durations{};

	for (int i{}; i < ws->n; i++) {

		if (workshop_start_times_and_durations.find(ws->workshops[i].start_time) == end(workshop_start_times_and_durations)) {

			workshop_start_times_and_durations.insert(make_pair(ws->workshops[i].start_time, set<int>{}));

			workshop_start_times_and_durations[ws->workshops[i].start_time].insert(ws->workshops[i].duration);

		}
		else {

			workshop_start_times_and_durations[ws->workshops[i].start_time].insert(ws->workshops[i].duration);

		}

	}

	int max_workshops_to_attend{};

	int last_end_time{ -1 };

	vector<pair<int, int>> shortest_courses{};

	for (const auto& c : workshop_start_times_and_durations) {

		for (const int ct : c.second) {

			shortest_courses.emplace_back(make_pair(c.first, ct));

		}

	}

	stable_sort(begin(shortest_courses), end(shortest_courses), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
		return ((lhs.first + lhs.second) < (rhs.first + rhs.second));
	});

	for (size_t i{}; i < shortest_courses.size(); i++) {

		if (last_end_time <= shortest_courses[i].first) {
			max_workshops_to_attend++;
			last_end_time = shortest_courses[i].first + shortest_courses[i].second;
		}

	}

	// delete ws;

	return max_workshops_to_attend;

}

int main(int argc, char **argv) {

	unused_args(argc, argv);

	int n{}; // number of workshops

	cin >> n;

	// create arrays of unknown size n
	int* start_time = new (nothrow) int[n];

	if (!start_time) return 1;

	int* duration = new (nothrow) int[n];

	if (!duration) {

		if (start_time) {

			delete[] start_time;
		}

		return 2;
	}

	for (int i{}; i != n; i++) {
		cin >> start_time[i];
	}
	for (int i{}; i != n; i++) {
		cin >> duration[i];
	}

	const Available_Workshops* ptr{ initialize(start_time, duration, n) };

	if (!ptr) return 0;

	cout << CalculateMaxWorkshops(ptr) << endl;

	if (start_time) {

		delete[] start_time;

	}

	if (duration) {

		delete[] duration;

	}

	if (ptr) {
		delete ptr;
	}

	return 0;
}
