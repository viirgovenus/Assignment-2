
#ifndef employeeClass
#define employeeClass

class Employee {
protected:
    double hourlyRate;  // Hourly rate for nonprofessional employees

public:
    Employee(double rate);

    virtual double calcWeeklySalary(int hoursWorked) const = 0;
    virtual double calcHealthCareContribution() const = 0;
    virtual int calcVacationDays() const = 0;
};

class Professional : public Employee {
private:
    double monthlySalary;  // Monthly salary for professional employees
    int vacationDays;

public:
    Professional(double monthlySalary, int vacationDays);

    double calcWeeklySalary(int hoursWorked) const override;
    double calcHealthCareContribution() const override;
    int calcVacationDays() const override;
};

class Nonprofessional : public Employee {
private:
    int vacationHours;  // Vacation hours for nonprofessional employees

public:
    Nonprofessional(double hourlyRate, int vacationHours);

    double calcWeeklySalary(int hoursWorked) const override;
    double calcHealthCareContribution() const override;
    int calcVacationDays() const override;
};

#endif  // employeeClass.h
