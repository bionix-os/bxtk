package bxtk;

enum abstract FileModeEnum(Int) from Int to Int {
	var openFile = 0;
	var openFiles = 1;
	var openDir = 2;
	var openAny = 3;
	var saveFile = 4;
}
