package bxtk;

import bxtk.core.Element;

class App {
    public var rootElement(get, default): Element;
    private function get_rootElement(): Element {
        return untyped __lua__("_G.rootElement");
    }

    public var execDir(get, default): String;
    private function get_execDir(): String {
        return untyped __lua__("_G.execDir");
    }

    public function new() {
        init();
    }

    public function init() {
        
    }

    public static function exit() {
        untyped __lua__("_G.exit()");
    }
}