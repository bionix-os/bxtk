package bxtk;

enum abstract TransparencyEnum(Int) from Int to Int {
	var disabled = 0;
	var alpha = 1;
	var alphaScissor = 2;
	var alphaHash = 3;
	var alphaDepthPrePass = 4;
	var max = 5;
}
