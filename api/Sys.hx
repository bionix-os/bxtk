/*
 * Copyright (C)2005-2019 Haxe Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

import lua.Boot;
import lua.Io;
import lua.Lua;
import lua.lib.luv.Os;
import lua.lib.luv.Misc;
import sys.io.FileInput;
import sys.io.FileOutput;
import bxtk.core.Vector;
import bxtk.core.PlatformService;

@:coreApi
class Sys {
	static var _system_name:String;

	public static inline function print(v:Dynamic):Void {
		return lua.Lib.print(v);
	}

	public static inline function println(v:Dynamic):Void {
		return lua.Lib.println(v);
	}

	public inline static function args():Array<String> {
		var vargs : Vector<String> = untyped __lua__("_G.__args");
		var args = vargs.toArray();
		return args;
	}

	public static function command(cmd:String, ?args:Array<String>):Int {
		var p = new sys.io.Process(cmd, args);
		var code = p.exitCode();
		p.close();
		return code;
	}

	public inline static function cpuTime():Float {
		return lua.Os.clock();
	}

	public inline static function exit(code:Int):Void {
		lua.Os.exit(code);
	}

	public inline static function getChar(echo:Bool):Int {
		return lua.Io.read().charCodeAt(0);
	}

	static function getSystemName():String {
		return PlatformService.osName;
	}

	public static function systemName():String {
		if (_system_name == null)
			_system_name = getSystemName();
		return _system_name;
	}

	public static function environment():Map<String, String> {
		var env = lua.lib.luv.Os.environ();
		return lua.Table.toMap(env);
	}

	@:deprecated("Use programPath instead") public static function executablePath():String {
		return Misc.exepath();
	}

	public inline static function programPath():String {
		return haxe.io.Path.join([getCwd(), Lua.arg[0]]);
	}

	public inline static function getCwd():String
		return haxe.io.Path.addTrailingSlash(Misc.cwd());

	public inline static function setCwd(s:String):Void
		Misc.chdir(s);

	public inline static function getEnv(s:String):String {
		return Os.getenv(s);
	}

	public inline static function putEnv(s:String, v:Null<String>):Void {
		if (v == null)
			return Os.unsetenv(s);
		Os.setenv(s, v);
	}

	public inline static function setTimeLocale(loc:String):Bool {
		// TODO Verify
		return lua.Os.setlocale(loc) != null;
	}

	public static function sleep(seconds:Float):Void
		lua.lib.luv.Thread.sleep(Math.floor(seconds * 1000));

	public inline static function stderr():haxe.io.Output
		return @:privateAccess new FileOutput(Io.stderr);

	public inline static function stdin():haxe.io.Input
		return @:privateAccess new FileInput(Io.stdin);

	public inline static function stdout():haxe.io.Output
		return @:privateAccess new FileOutput(Io.stdout);

	public static function time():Float {
		var stamp = lua.lib.luv.Misc.gettimeofday();
		return stamp.seconds + (stamp.microseconds / 1000000);
	}
}
