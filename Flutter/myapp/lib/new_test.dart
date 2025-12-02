// Define the class
class Car {
  // Properties (Fields)
  String make;
  String model;
  int year;

  // Constructor
  Car(this.make, this.model, this.year);

  // Method to display car details
  void displayDetails() {
    print('Car Make: $make');
    print('Car Model: $model');
    print('Car Year: $year');
  }

  // Method to update car's year
  void updateYear(int newYear) {
    year = newYear;
    print('Car Year Updated: $year');
  }
}

void main() {
    var Q = 90;
    bool hey = Q == 90 ? true : false;
    print(hey);
}
