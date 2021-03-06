#ifndef TRIP_H
#define TRIP_H

#include <stack>
#include "Flight.h"

class Trip
{
public:
    Trip();
    Trip(const Trip& other);
    Trip(string _from, string _to);

    void insertFlight(Flight flight);
    void showTrip();
    void operator =(const Trip& other);

    friend
    bool operator ==(const Trip& LHS, const Trip& RHS);

private:
    void copy(const Trip& other);

    stack<Flight> flights;
    string from, to;
};

Trip::Trip()
{
    from = to = "Unknown";
}

Trip::Trip(const Trip &other)
{
    copy(other);
}

Trip::Trip(string _from, string _to)
{
    from = _from;
    to = _to;
}

void Trip::insertFlight(Flight flight)
{
    flights.push(flight);
}

void Trip::showTrip()
{
    int distanceSum = 0;
    if (flights.size() > 1) {
        int counter = 1;
        cout << "Trip from " << from << " to " << to << " required " << flights.size() << " flights:" << endl;
        while(!flights.empty()) {
            cout << "    #" << counter++ << ": ";
            distanceSum += flights.top().showFlightDetail();
            flights.pop();
        }
    } else if (flights.size() == 1) {
        cout << "Non-stop trip:" << endl;
        distanceSum += flights.top().showFlightDetail();
        flights.pop();
    } else {
        cout << "There is no route avaliable from " << from << " to " << to << endl;
        return;
    }
    cout << "Total disrance for this trip is " << distanceSum << " miles."<< endl << endl;
}

void Trip::operator =(const Trip &other)
{
    copy(other);
}

void Trip::copy(const Trip &other)
{
    if (this != &other) {
        from = other.from;
        to = other.to;
        flights = other.flights;
    }
}

#endif // TRIP_H
