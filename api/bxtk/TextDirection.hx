package bxtk;

enum abstract TextDirection(Int) from Int to Int {
	var auto = 0;
	var ltr = 1;
	var rtl = 2;
	var inherited = 3;
}
