#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Time
{
	unsigned hour;
	unsigned min;
public:
	Time();
	Time(unsigned int, unsigned int);
	Time(const Time&);
	const Time& operator=(const Time&);
	friend std::ostream& operator<<(std::ostream&, const Time&);
};

///////////////////////////////////////

class Date
{
	unsigned day;
	unsigned mon;
	unsigned year;
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	Date(const Date&);
	unsigned int getDate_day();
	unsigned int getDate_mon();
	unsigned int getDate_year();
	Date putDate_day(unsigned int);
	Date putDate_mon(unsigned int);
	Date putDate_year(unsigned int);
	const Date& operator=(const Date&);
	bool operator==(const Date&);

	friend std::ostream& operator<<(std::ostream&, const Date&);
};

///////////////////////////////////////

class Task
{
public:
	Date date;
	std::string task;
	unsigned id;
	Task();
	virtual ~Task();
	virtual Time get_start() = 0;
	virtual Time get_end() = 0;
	virtual Time set_start(Time);
	virtual Time set_end(Time);
	virtual void print() = 0;
};

///////////////////////////////////////

class Type1 : public Task
{
public:
	Type1();
	~Type1();
	Time get_start();
	Time get_end();
	virtual void print();
};

///////////////////////////////////////

class Type2 : public Task
{
private:
	Time time_1, time_2;
public:
	Type2();
	~Type2();
	Time get_start();
	Time get_end();
	Time set_start(Time);
	Time set_end(Time);
	virtual void print();
};

///////////////////////////////////////

class ToDoList
{
public:
	Task** tasks;
	int number;
	int read_number();
	void read_tasks();
	void print_tasks();
	void print_task_date();
};