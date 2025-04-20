package sunaba.core;

@:native("Element")
extern class Element extends BaseObject {
    public var scriptInstance: ScriptInstance;
    public var name: String;
    public var childEnteredTree: Event;
    public var childExitingTree: Event;
    public var childOrderChanged: Event;
    public function new();
    public function fine(path: String): Element;
    public function getParent(): Element;
    public function addChild(child: Element): Void;
    public function addSibling(sibling: Element): Void;
    public function removeChild(child: Element): Void;
    public function getChildren(): lua.Table<Int, Element>;
    public function isNull(): Bool;
    @:native("cast")
    public static function castElement(): Element;
}

abstract ElementAbstract(Element) from Element to Element {
    @:from
    public static function fromElement(element: Element): ElementAbstract {
        var element = Element.castElement(element);
        if (element.isNull()) {
            return null;
        }
        return element;
    }
}