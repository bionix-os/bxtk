package bxtk;

enum abstract Mode(Int) from Int to Int {
	var spatial = 0;
	var canvasItem = 1;
	var particles = 2;
	var sky = 3;
	var fog = 4;
}
