package bxtk..ui;

enum abstract MenuBarLayoutDirection(Int) from Int to Int {
	var inherited = 0;
	var applicationLocale = 1;
	var ltr = 2;
	var rtl = 3;
	var systemLocale = 4;
	var max = 5;
}
