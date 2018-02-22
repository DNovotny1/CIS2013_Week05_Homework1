#include<iostream>
#include<string>
using namespace std;

//turns number moth to string
string monthName(int month) {
	switch (month) {
	case 1:
		return "January";
		break;
	case 2:
		return "February";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;
	}
}

//writes out calendars
void calendar(int mon, int year) {
	int days = 0;
	//counts negative for spacing days
	int startDays = 0 ;
	//ends line for each week
	int weekEnd = 1;

	int leapDays = 0;

	// set days in each month
	if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) {days = 31; }
	else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {days = 30; }
	else  {
		if (((year % 4 == 0)&&(year% 100 != 0)) || ((year % 400 == 0))) {days = 29;}
		else { days = 28; }
	}

	//add up leapdays before certain year
	int yr = year - 1;
	while (yr > 0){
		if (((yr % 4 == 0) && (yr % 100 != 0)) || ((yr % 400 == 0))) {
			leapDays++;
		}
		yr--;
	}
	 
	startDays = 365 * year + leapDays ;

	//adds days of the month
	if (mon > 1) { startDays += 31; }
	if (mon > 2) {
		if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 400 == 0))) { startDays += 29; }
		else { startDays += 28; }
	}
	if (mon > 3) { startDays += 31; }
	if (mon > 4) { startDays += 30; }
	if (mon > 5) { startDays += 31; }
	if (mon > 6) { startDays += 30; }
	if (mon > 7) { startDays += 31; }
	if (mon > 8) { startDays += 31; }
	if (mon > 9) { startDays += 30; }
	if (mon > 10) { startDays += 31; }
	if (mon > 11) { startDays += 30; }
	if (mon > 12) { startDays += 31; }

	while (startDays >= 7) { startDays -= 7; }


	// connects to days of week
	//saturday
	if ((startDays+1) % 7 == 0) { startDays = -5; }
	//sunday
	else if ((startDays + 0) % 7 == 0) { startDays = -6; }
	//monday
	else if ((startDays + 6) % 7 == 0) { startDays = 0; }
	//tuesday
	else if ((startDays + 5) % 7 == 0) { startDays = -1; }
	//wed
	else if ((startDays + 4) % 7 == 0) { startDays = -2; }
	//thur
	else if ((startDays + 3) % 7 == 0) { startDays = -3; }
	//fri
	else if ((startDays + 2) % 7 == 0) { startDays = -4; }
	else cout << "Error";

	//writes out days in calendar format
	cout << "    " << monthName(mon) << "  " << year << endl;
	cout << "Su Mo Tu We Th Fr Sa" << endl;
	for (int i =  startDays; i < days + 1; i++) {
		if ((i < 10)&&(i>0)) { cout << " " << i << " "; }
		else if (i >= 10) { cout << i << " "; }
		else  {cout << "   ";}
		
		//ends line after 7 days
		
		if (weekEnd % 7 == 0) {
			cout << endl;
		}
		weekEnd++;
	}
}



//insure inputs fit parameters for month and year
bool inputVerification(int mn, int yr) {
	if ((mn >= 1) && (mn <= 12) && (yr >= 1)) {
		return true;
	}
	else {
		cout << "\nInput needs to be a month (1 through 12) and a year greater than 0";
		return false;
	}
}

int main() {
	//writes out calendar view for given month and year
	bool keepGoing = true;
	char keepGo = 'y';
	do{
		int month = 0;
		int year = 0;
		cout << "\nPlease enter your month: ";
		cin >> month;
		cout << "\nPlease enter your year: ";
		cin >> year;
		//verifys month and year work
		if (inputVerification(month, year)) {
			calendar(month, year);
		}
		//continue
		cout << "\nWould you like to continue?(Y)";
		cin >> keepGo;
		cout << endl;
	} while (keepGo == 'y' || keepGo == 'Y');
}
