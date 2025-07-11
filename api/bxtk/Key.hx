package bxtk;

enum abstract Key(Int) from Int to Int {
	var none = 0;
	var space = 32;
	var exclam = 33;
	var quotedbl = 34;
	var numbersign = 35;
	var dollar = 36;
	var percent = 37;
	var ampersand = 38;
	var apostrophe = 39;
	var parenleft = 40;
	var parenright = 41;
	var asterisk = 42;
	var plus = 43;
	var comma = 44;
	var minus = 45;
	var period = 46;
	var slash = 47;
	var key0 = 48;
	var key1 = 49;
	var key2 = 50;
	var key3 = 51;
	var key4 = 52;
	var key5 = 53;
	var key6 = 54;
	var key7 = 55;
	var key8 = 56;
	var key9 = 57;
	var colon = 58;
	var semicolon = 59;
	var less = 60;
	var equal = 61;
	var greater = 62;
	var question = 63;
	var at = 64;
	var a = 65;
	var b = 66;
	var c = 67;
	var d = 68;
	var e = 69;
	var f = 70;
	var g = 71;
	var h = 72;
	var i = 73;
	var j = 74;
	var k = 75;
	var l = 76;
	var m = 77;
	var n = 78;
	var o = 79;
	var p = 80;
	var q = 81;
	var r = 82;
	var s = 83;
	var t = 84;
	var u = 85;
	var v = 86;
	var w = 87;
	var x = 88;
	var y = 89;
	var z = 90;
	var bracketleft = 91;
	var backslash = 92;
	var bracketright = 93;
	var asciicircum = 94;
	var underscore = 95;
	var quoteleft = 96;
	var braceleft = 123;
	var bar = 124;
	var braceright = 125;
	var asciitilde = 126;
	var yen = 165;
	var section = 167;
	var special = 4194304;
	var escape = 4194305;
	var tab = 4194306;
	var backtab = 4194307;
	var backspace = 4194308;
	var enter = 4194309;
	var kpEnter = 4194310;
	var insert = 4194311;
	var delete = 4194312;
	var pause = 4194313;
	var print = 4194314;
	var sysreq = 4194315;
	var clear = 4194316;
	var home = 4194317;
	var end = 4194318;
	var left = 4194319;
	var up = 4194320;
	var right = 4194321;
	var down = 4194322;
	var pageup = 4194323;
	var pagedown = 4194324;
	var shift = 4194325;
	var ctrl = 4194326;
	var meta = 4194327;
	var alt = 4194328;
	var capslock = 4194329;
	var numlock = 4194330;
	var scrolllock = 4194331;
	var f1 = 4194332;
	var f2 = 4194333;
	var f3 = 4194334;
	var f4 = 4194335;
	var f5 = 4194336;
	var f6 = 4194337;
	var f7 = 4194338;
	var f8 = 4194339;
	var f9 = 4194340;
	var f10 = 4194341;
	var f11 = 4194342;
	var f12 = 4194343;
	var f13 = 4194344;
	var f14 = 4194345;
	var f15 = 4194346;
	var f16 = 4194347;
	var f17 = 4194348;
	var f18 = 4194349;
	var f19 = 4194350;
	var f20 = 4194351;
	var f21 = 4194352;
	var f22 = 4194353;
	var f23 = 4194354;
	var f24 = 4194355;
	var f25 = 4194356;
	var f26 = 4194357;
	var f27 = 4194358;
	var f28 = 4194359;
	var f29 = 4194360;
	var f30 = 4194361;
	var f31 = 4194362;
	var f32 = 4194363;
	var f33 = 4194364;
	var f34 = 4194365;
	var f35 = 4194366;
	var menu = 4194370;
	var hyper = 4194371;
	var help = 4194373;
	var back = 4194376;
	var forward = 4194377;
	var stop = 4194378;
	var refresh = 4194379;
	var volumedown = 4194380;
	var volumemute = 4194381;
	var volumeup = 4194382;
	var mediaplay = 4194388;
	var mediastop = 4194389;
	var mediaprevious = 4194390;
	var medianext = 4194391;
	var mediarecord = 4194392;
	var homepage = 4194393;
	var favorites = 4194394;
	var search = 4194395;
	var standby = 4194396;
	var openurl = 4194397;
	var launchmail = 4194398;
	var launchmedia = 4194399;
	var launch0 = 4194400;
	var launch1 = 4194401;
	var launch2 = 4194402;
	var launch3 = 4194403;
	var launch4 = 4194404;
	var launch5 = 4194405;
	var launch6 = 4194406;
	var launch7 = 4194407;
	var launch8 = 4194408;
	var launch9 = 4194409;
	var launcha = 4194410;
	var launchb = 4194411;
	var launchc = 4194412;
	var launchd = 4194413;
	var launche = 4194414;
	var launchf = 4194415;
	var globe = 4194416;
	var keyboard = 4194417;
	var jisEisu = 4194418;
	var jisKana = 4194419;
	var kpMultiply = 4194433;
	var kpDivide = 4194434;
	var kpSubtract = 4194435;
	var kpPeriod = 4194436;
	var kpAdd = 4194437;
	var kp0 = 4194438;
	var kp1 = 4194439;
	var kp2 = 4194440;
	var kp3 = 4194441;
	var kp4 = 4194442;
	var kp5 = 4194443;
	var kp6 = 4194444;
	var kp7 = 4194445;
	var kp8 = 4194446;
	var kp9 = 4194447;
	var unknown = 8388607;
}
