#ifndef STUDENTS_H
#define STUDENTS_H

struct Students {
	char lastName[20];
	char firstName[20];
	int IDnum;
	Students();
	void printStudents();
};

#endif
