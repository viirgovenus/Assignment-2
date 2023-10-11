
#include <iostream>
#include <employeeClass.h>

// Creating class Employee
class Employee {
protected:
    double hourlyRate;  // Hourly rate for nonprofessional employees

public:
    
    Employee(double rate) : hourlyRate(rate) {}

    virtual double calcWeeklySalary(int hoursWorked) const = 0;
    virtual double calcHealthCareContribution() const = 0;
    virtual int calcVacationDays() const = 0;
};

class Professional : public Employee {
private:
    double monthlySalary;  // Monthly salary for professional employees
    int vacationDays;

public:
    Professional(double monthlySalary, int vacationDays)
        : Employee(0), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

    double calcWeeklySalary(int hoursWorked) const override {
        return monthlySalary / 4;  // Assume a month is 4 weeks
    }

    double calcHealthCareContribution() const override {
        return monthlySalary * 0.1;  // Assume 10% contribution for health insurance
    }

    int calcVacationDays() const override {
        return vacationDays;
    }
};

class Nonprofessional : public Employee {
private:
    int vacationHours;  // Vacation hours for nonprofessional employees

public:
    Nonprofessional(double hourlyRate, int vacationHours)
        : Employee(hourlyRate), vacationHours(vacationHours) {}

    double calcWeeklySalary(int hoursWorked) const override {
        return hourlyRate * hoursWorked;
    }

    double calcHealthCareContribution() const override {
        return hourlyRate * 40;  // Assume $40 per week for health insurance
    }

    int calcVacationDays() const override {
        return vacationHours / 8;  // Convert vacation hours to days (8 hours per day)
    }
};

int main() {
    // Creating instances of Professional and Nonprofessional employees
    Professional professionalEmployee(5000, 10);  // Monthly salary: $5000, Vacation days: 10
    Nonprofessional nonprofessionalEmployee(25, 40);  // Hourly rate: $25, Vacation hours: 40

    // Testing the functions
    int hoursWorked = 30;  // Example: worked for 30 hours in a week

    std::cout << "Professional Employee Weekly Salary: $" << professionalEmployee.calcWeeklySalary(hoursWorked) << "\n";
    std::cout << "Professional Employee Health Care Contributions: $" << professionalEmployee.calcHealthCareContribution() << "\n";
    std::cout << "Professional Employee Vacation Days: " << professionalEmployee.calcVacationDays() << "\n\n";

    std::cout << "Nonprofessional Employee Weekly Salary: $" << nonprofessionalEmployee.calcWeeklySalary(hoursWorked) << "\n";
    std::cout << "Nonprofessional Employee Health Care Contributions: $" << nonprofessionalEmployee.calcHealthCareContribution() << "\n";
    std::cout << "Nonprofessional Employee Vacation Days: " << nonprofessionalEmployee.calcVacationDays() << "\n";

    return 0;
}

